#ifndef T1702ITEM
#define T1702ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
#include "tr/t1702/t1702.h"
class T1702Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QDate date MEMBER mDate READ date)
    Q_PROPERTY(long close MEMBER mClose READ close)
    Q_PROPERTY(SIGN sign MEMBER mSign READ sign)
    Q_PROPERTY(long change MEMBER mChange READ change)
    Q_PROPERTY(long diff MEMBER mDiff READ diff)
    Q_PROPERTY(long volume MEMBER mVolume READ volume)
    Q_PROPERTY(long amt0000 MEMBER mAmt0000 READ amt0000)
    Q_PROPERTY(long amt0001 MEMBER mAmt0001 READ amt0001)
    Q_PROPERTY(long amt0002 MEMBER mAmt0002 READ amt0002)
    Q_PROPERTY(long amt0003 MEMBER mAmt0003 READ amt0003)
    Q_PROPERTY(long amt0004 MEMBER mAmt0004 READ amt0004)
    Q_PROPERTY(long amt0005 MEMBER mAmt0005 READ amt0005)
    Q_PROPERTY(long amt0006 MEMBER mAmt0006 READ amt0006)
    Q_PROPERTY(long amt0007 MEMBER mAmt0007 READ amt0007)
    Q_PROPERTY(long amt0008 MEMBER mAmt0008 READ amt0008)
    Q_PROPERTY(long amt0009 MEMBER mAmt0009 READ amt0009)
    Q_PROPERTY(long amt0010 MEMBER mAmt0010 READ amt0010)
    Q_PROPERTY(long amt0011 MEMBER mAmt0011 READ amt0011)
    Q_PROPERTY(long amt0018 MEMBER mAmt0018 READ amt0018)
    Q_PROPERTY(long amt0088 MEMBER mAmt0088 READ amt0088)
    Q_PROPERTY(long amt0099 MEMBER mAmt0099 READ amt0099)
    Q_ENUMS(SIGN)
public:
    typedef enum{ UP=5, DOWN=2} SIGN;


    explicit T1702Item(LPt1702OutBlock1 outblock, QObject *parent=0);
    ~T1702Item();

    QDate date() {return mDate;}
    long close() { return mClose;}
    SIGN sign() { return mSign;}
    long change() {return mChange;}
    long diff() { return mDiff; }
    long volume() { return mVolume; }
    long amt0000() { return mAmt0000;}
    long amt0001() { return mAmt0001;}
    long amt0002() { return mAmt0002;}
    long amt0003() { return mAmt0003;}
    long amt0004() { return mAmt0004;}
    long amt0005() { return mAmt0005;}
    long amt0006() { return mAmt0006;}
    long amt0007() { return mAmt0007;}
    long amt0008() { return mAmt0008;}
    long amt0009() { return mAmt0009;}
    long amt0010() { return mAmt0010;}
    long amt0011() { return mAmt0011;}
    long amt0018() { return mAmt0018;}
    long amt0088() { return mAmt0088;}
    long amt0099() { return mAmt0099;}

private:
    QDate   mDate;            //일자
    long    mClose;             //종가
    SIGN    mSign;          //전일대비구분
    long    mChange;            //전일대비
    float   mDiff;              //등락율
    long    mVolume;            //누적거래량
    long    mAmt0000;           //사모펀드
    long    mAmt0001;           //증권
    long    mAmt0002;           //보험
    long    mAmt0003;           //투신
    long    mAmt0004;           //은행
    long    mAmt0005;           //종금
    long    mAmt0006;           //기금
    long    mAmt0007;           //기타법인
    long    mAmt0008;           //개인
    long    mAmt0009;           //등록외국인
    long    mAmt0010;           //미등록외국인
    long    mAmt0011;           //국가외
    long    mAmt0018;           //기관
    long    mAmt0088;           //외인계(등록+미등록)
    long    mAmt0099;           //기타계(기타+국가)
};

#endif // T1702ITEM

