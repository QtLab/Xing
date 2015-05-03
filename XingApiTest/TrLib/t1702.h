#ifndef T1702_H
#define T1702_H

#include <QObject>

class XAQuery;

typedef struct _t1702_info
{
    QString date;   //  일자 문자열  8
    int close;         //  종가 정수  8
    QString sign;       //  전일대비구분 문자열  1
    int change;         //  전일대비 정수  8
    float diff;               //등락율 실수  6.2
    int volume;         //  누적거래량 정수  12
    int amt0000;        //  사모펀드 정수  12
    int amt0001;        //  증권 정수  12
    int amt0002;        //  보험 정수  12
    int amt0003;    //  투신 정수  12
    int amt0004;        //  은행 정수  12
    int amt0005;        //  종금 정수  12
    int amt0006;        //  기금 정수  12
    int amt0007;        //  기타법인 정수  12
    int amt0008;        //  개인 정수  12
    int amt0009;        //  등록외국인 정수  12
    int amt0010;           //  미등록외국인 정수  12
    int amt0011;        //  국가외 정수  12
    int amt0018;        //  기관 정수  12
    int amt0088;        //  외인계(등록+미등록) 정수  12
    int amt0099;        //  기타계(기타+국가) 정수  12
} t1702_info;

class t1702 : public QObject
{
    Q_OBJECT
public:
    explicit t1702(QObject *parent = 0);
    void requestTransaction()
signals:
    
public slots:

private:
    XAQuery* xaquery;
    QString startDate;
    QString endDate;

    QString shcode;         //종목코드
    QString todt;               //종료일자
    QString volvalgb;           //금액수량 구분 0:금액, 1:수량, 2:단가
    QString msmdgb;             //매수매도 구분 0:순매수, 1:매수, 2:매도
    QString cumulgb;            //누적구분 0:일간 1:누적
    QString cts_date;
    int cts_idx;
};

#endif // T1702_H
