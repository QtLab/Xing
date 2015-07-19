#include "tr/t1702/t1702item.h"
#include <QDebug>

T1702Item::T1702Item(QObject *parent):TrItem(parent)
{

	DEFINE_PROPERTY_NAME("CTSIDX","cts_idx");
	DEFINE_PROPERTY_NAME("CTSDATE","cts_date");
}
T1702Item::~T1702Item()
{
	qDebug()<<"T1702Item destroyed";
}
