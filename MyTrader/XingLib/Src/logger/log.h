#ifndef LOG_H
#define LOG_H

#include <QLoggingCategory>
#include <QtSql/QSqlError>
Q_DECLARE_LOGGING_CATEGORY(xaSession)
Q_DECLARE_LOGGING_CATEGORY(xaQuery)
Q_DECLARE_LOGGING_CATEGORY(queryMngr)
Q_DECLARE_LOGGING_CATEGORY(loginMngr)
Q_DECLARE_LOGGING_CATEGORY(trQuery)
Q_DECLARE_LOGGING_CATEGORY(stockInfoUpdater)
Q_DECLARE_LOGGING_CATEGORY(stockInfoMngr)
Q_DECLARE_LOGGING_CATEGORY(movementUpdater)
Q_DECLARE_LOGGING_CATEGORY(stockExchangeMngr)
Q_DECLARE_LOGGING_CATEGORY(stockExchangeInfo)
Q_DECLARE_LOGGING_CATEGORY(Main)
Q_DECLARE_LOGGING_CATEGORY(mainWindow)
Q_DECLARE_LOGGING_CATEGORY(upjongCodeUpdater)
Q_DECLARE_LOGGING_CATEGORY(themeUpjongUpdater)
Q_DECLARE_LOGGING_CATEGORY(updateCenter)
Q_DECLARE_LOGGING_CATEGORY(stockChart);
#define query_error(category, query) qCCritical(category)<<"QueryError : "<<query.lastError()<<endl<<query.executedQuery()

#endif // LOG_H
