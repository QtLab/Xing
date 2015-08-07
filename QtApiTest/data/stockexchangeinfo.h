#ifndef STOCKEXCHANGEINFO_H
#define STOCKEXCHANGEINFO_H

#include <QString>
#include <QDate>
#include <QList>
#include <array>
#include "data/commontype.h"

typedef enum {
    DAILY = 1,
    MOVING_5_DAYS = 5,
    MOVING_20_DAYS = 20,
    MOVING_60_DAYS = 60,
    MOVING_240_DAYS = 240
}MOVING_TYPE;

typedef struct _MovingVolumeSumInfo {
    QDate 					date;
    MOVING_TYPE 			movingType;
    long					avgPrice = 0;
    long					totalVolumeSum =0;
    std::array<int, 14>		volumeSum;
}MovingVolumeSumInfo;

class StockExchangeInfo
{
public:
    StockExchangeInfo(const QString& shcode);
    ~StockExchangeInfo();
    MovingVolumeSumInfo* getTotalMovingVolumeSumInfo(MOVING_TYPE type, const QDate& date = QDate::currentDate()) const;
    long getMovingVolumeSum(INVESTORS investor, MOVING_TYPE type, const QDate& date = QDate::currentDate()) const;
    long getMovingAvgPrice(MOVING_TYPE type, const QDate& date = QDate::currentDate()) const ;
    long getMovingTotalVolumeSum(MOVING_TYPE type, const QDate& date = QDate::currentDate()) const ;
    int getNumberOfDates();
    QDate getDateByIndex(int index) const;
private:
    QDate getFromDate(MOVING_TYPE type, QDate toDate) const;
    void initDateList();
    QDate getTargetDate(const QDate& date) const ;
    QString getColumnNameByInvestor(INVESTORS investor) const;

private:
    QString mShcode;
    QList<QDate> mDateList;
};

#endif // STOCKEXCHANGEINFO_H
