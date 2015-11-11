#include <QApplication>
#include "updatecenter.h"
#include "core/util/xingthread.h"
#include "service/info/stockinfoupdater.h"
#include "service/info/themeupjongupdater.h"
#include "service/info/UpjongCodeUpdater.h"
#include "service/info/movementupdater.h"
#include "common/ui/shcodeselectiondialog.h"
#include "logger/log.h"
UpdateCenter::UpdateCenter(QueryMngr *queryMngr, QObject *parent)
	: QObject(parent)
	, mQueryMngr(queryMngr)
	, mWorkThread(new XingThread)
	, mStockInfoUpdater(new StockInfoUpdater(mQueryMngr))
	, mThemeUpjongUpdater(new ThemeUpjongUpdater(mQueryMngr))
	, mUpjongCodeUpdater(new UpjongCodeUpdater(mQueryMngr))
	, mMovementUpdater(new MovementUpdater(mQueryMngr))
{
	connect(mStockInfoUpdater, &StockInfoUpdater::updateStockInfoDone, this, [&]()
	{
		emit updateStockInfoDone();
	});
	connect(mThemeUpjongUpdater, &ThemeUpjongUpdater::updateThemeUpjongDone, this, [&]()
	{
		if (mUpjongCodeUpdater->isUpdating())
			return;
		emit updateCodeTableDone();
	});
	connect(mUpjongCodeUpdater, &UpjongCodeUpdater::updateUpjongCodeDone, this, [&]()
	{
		if (mThemeUpjongUpdater->isUpdating())
			return;
		emit updateCodeTableDone();
	});
	connect(mMovementUpdater, &MovementUpdater::updateDone, this, [&]()
	{
		emit updateMovementTableDone();
	});
	moveToThread(mWorkThread);
	mStockInfoUpdater->moveToThread(mWorkThread);
	mThemeUpjongUpdater->moveToThread(mWorkThread);
	mUpjongCodeUpdater->moveToThread(mWorkThread);
	mMovementUpdater->moveToThread(mWorkThread);
	mWorkThread->start();
}

UpdateCenter::~UpdateCenter()
{
	if (mWorkThread->isRunning())
	{
		mWorkThread->quit();
		mWorkThread->deleteLater();
	}
	mStockInfoUpdater->deleteLater();
	mThemeUpjongUpdater->deleteLater();
	mUpjongCodeUpdater->deleteLater();
	mMovementUpdater->deleteLater();
}

void UpdateCenter::updateStockInfo()
{
	if (QThread::currentThread() != mWorkThread)
	{
		QMetaObject::invokeMethod(this, "updateStockInfo", Qt::QueuedConnection);
		return;
	}
	else
	{
		if (mStockInfoUpdater->isUpdating())
		{
			return;
		}
		mStockInfoUpdater->updateStockInfo();
	}
}

void UpdateCenter::updateCodeTable()
{
	if (QThread::currentThread() != mWorkThread)
	{
		QMetaObject::invokeMethod(this, "updateCodeTable", Qt::QueuedConnection);
		return;
	}
	else
	{
		if (mUpjongCodeUpdater->isUpdating() || mThemeUpjongUpdater->isUpdating())
			return;
		mUpjongCodeUpdater->updateUpjongCode();
		mThemeUpjongUpdater->updateThemeUpjong();
	}
}

void UpdateCenter::updateMovementTable(const QString& upcode)
{
	mMovementUpdater->updateByUpcode(upcode);
}

void UpdateCenter::updateMovementTable()
{
	if (QThread::currentThread() == QApplication::instance()->thread())
	{
		ShcodeSelectionDialog dialog(mQueryMngr);
		if (dialog.exec() == QDialog::Accepted) {
			QString upcode = dialog.getSelectedUpcode();
			QMetaObject::invokeMethod(this, "updateMovementTable", Qt::QueuedConnection, Q_ARG(QString, upcode));
		}
		return;
	}
	else
	{
		qCCritical(updateCenter)<< "updateMovementTable should be called in Main Thread";
	}
}