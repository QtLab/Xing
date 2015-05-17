#ifndef T8430_H
#define T8430_H

#include "xing/IXingAPI.h"
#include "tr/TrQuery.h"
#include <qtconcurrentrun.h>
#include <QFuture>
#include <QFutureWatcher>


///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식종목조회 ( BLOCK,HEADTYPE=A )
#pragma pack( push, 1 )

#define NAME_t8430     "t8430"

// 기본입력
typedef struct _t8430InBlock
{
    char    gubun               [   1];    // [string,    1] 구분(0:전체1:코스피2:코스닥)    StartPos 0, Length 1
} t8430InBlock, *LPt8430InBlock;
#define NAME_t8430InBlock     "t8430InBlock"

// 출력1                          , occurs
typedef struct _t8430OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                          StartPos 0, Length 20
    char    shcode              [   6];    // [string,    6] 단축코드                        StartPos 20, Length 6
    char    expcode             [  12];    // [string,   12] 확장코드                        StartPos 26, Length 12
    char    etfgubun            [   1];    // [string,    1] ETF구분(1:ETF)                  StartPos 38, Length 1
    char    uplmtprice          [   8];    // [long  ,    8] 상한가                          StartPos 39, Length 8
    char    dnlmtprice          [   8];    // [long  ,    8] 하한가                          StartPos 47, Length 8
    char    jnilclose           [   8];    // [long  ,    8] 전일가                          StartPos 55, Length 8
    char    memedan             [   5];    // [string,    5] 주문수량단위                    StartPos 63, Length 5
    char    recprice            [   8];    // [long  ,    8] 기준가                          StartPos 68, Length 8
    char    gubun               [   1];    // [string,    1] 구분(1:코스피2:코스닥)          StartPos 76, Length 1
} t8430OutBlock, *LPt8430OutBlock;
#define NAME_t8430OutBlock     "t8430OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _T8430Item
{
    QString hname;
    QString shcode;
    QString expcode;
    bool isETF;
    long uplmtprice;
    long dnlmtprice;
    long jniclose;
    QString memedan;
    long recprice;
    bool isKOSPI;
} t8430Item, *LPt8430Item;

class T8430 : public TrQuery
{
public:
    explicit T8430(const QWidget &widget, MODE mode, QObject *parent = 0);
    ~T8430();
    typedef enum { ALL=0, KOSPI, KOSDAQ } MODE;
private:
    bool m_workDone;
    const MODE m_mode;



    QList<LPt8430Item> handleData(LPRECV_PACKET packet);
    QFuture<QList<LPt8430Item>> mFuture;
    QFutureWatcher<QList<LPt8430Item>> mFutureWatcher;
signals:
    void workDone(const QList<LPt8430Item> & itemList);

private slots:
    void dataProcessed();
public slots:
    int sendRequest();
    void dataReceived(LPRECV_PACKET packet);
    void messageReceived(LPMSG_PACKET packet);
    void errorReceived(LPMSG_PACKET packet);
    void releaseReceived(int requestId);
    bool hasMoreRequest();

};

#endif // T8430_H
