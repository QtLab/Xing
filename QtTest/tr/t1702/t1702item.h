#ifndef T1702ITEM
#define T1702ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"

class T1702Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QDate date READ date WRITE setDate)
    Q_PROPERTY(long close READ close WRITE setClose)
    Q_PROPERTY(SIGN sign READ sign WRITE setSign)
    Q_PROPERTY(long change READ change WRITE setChange)
    Q_PROPERTY(long diff READ diff WRITE setDiff)
    Q_PROPERTY(long volume READ volume WRITE setVolume)
    Q_PROPERTY(long amt0000 READ amt0000 WRITE setAmt0000)
    Q_PROPERTY(long amt0001 READ amt0001 WRITE setAmt0001)
    Q_PROPERTY(long amt0002 READ amt0002 WRITE setAmt0002)
    Q_PROPERTY(long amt0003 READ amt0003 WRITE setAmt0003)
    Q_PROPERTY(long amt0004 READ amt0004 WRITE setAmt0004)
    Q_PROPERTY(long amt0005 READ amt0005 WRITE setAmt0005)
    Q_PROPERTY(long amt0006 READ amt0006 WRITE setAmt0006)
    Q_PROPERTY(long amt0007 READ amt0007 WRITE setAmt0007)
    Q_PROPERTY(long amt0008 READ amt0008 WRITE setAmt0008)
    Q_PROPERTY(long amt0009 READ amt0009 WRITE setAmt0009)
    Q_PROPERTY(long amt0010 READ amt0010 WRITE setAmt0010)
    Q_PROPERTY(long amt0011 READ amt0011 WRITE setAmt0011)
    Q_PROPERTY(long amt0018 READ amt0018 WRITE setAmt0018)
    Q_PROPERTY(long amt0088 READ amt0088 WRITE setAmt0088)
    Q_PROPERTY(long amt0099 READ amt0099 WRITE setAmt0099)
public:
    typedef enum{ UP="up", DOWN="down"} SIGN;
    Q_DECLARE_METATYPE(SIGN)

    explicit T1702Item(QObject *parent=0);
    ~T1702Item();

    QDate date() {return mDate;}
    void setDate(const QDate& date) { mDate = date;}

    long close() { return mClose;}
    void setClose(long close){ mClose = close;}

    SIGN sign() { return mSign;}
    void setSign(SIGN sign) {mSign = sign;}

    long change() {return mChange;}
    void setChange(long change) {mChange = change;}

    long diff() { return mDiff; }
    void setDiff(long diff) {mDiff = diff;}

    long volume() { return mVolume; }
    void setVolume(long volume) {mVolume = volume;}

    long amt0000() { return mAmt0000;}
    void setAmt0000(long amt) { mAmt0000 = amt;}

    void amt0001() { return mAmt0001;}
    void setAmt0001(long amt) { mAmt0001 = amt;}

    void amt0002() { return mAmt0002;}
    void setAmt0002(long amt) { mAmt0002 = amt;}

    void amt0003() { return mAmt0003;}
    void setAmt0003(long amt) { mAmt0003 = amt;}

    void amt0004() { return mAmt0004;}
    void setAmt0004(long amt) { mAmt0004 = amt;}

    void amt0005() { return mAmt0005;}
    void setAmt0005(long amt) { mAmt0005 = amt;}

    void amt0006() { return mAmt0006;}
    void setAmt0006(long amt) { mAmt0006 = amt;}

    void amt0007() { return mAmt0007;}
    void setAmt0007(long amt) { mAmt0007 = amt;}

    void amt0008() { return mAmt0008;}
    void setAmt0008(long amt) { mAmt0008 = amt;}

    void amt0009() { return mAmt0009;}
    void setAmt0009(long amt) { mAmt0009 = amt;}

    void amt0010() { return mAmt0010;}
    void setAmt0010(long amt) { mAmt0010 = amt;}

    void amt0011() { return mAmt0011;}
    void setAmt0011(long amt) { mAmt0011 = amt;}

    void amt0018() { return mAmt0018;}
    void setAmt0018(long amt) { mAmt0018 = amt;}

    void amt0088() { return mAmt0088;}
    void setAmt0088(long amt) { mAmt0088 = amt;}

    void amt0099() { return mAmt0099;}
    void setAmt0099(long amt) { mAmt0099 = amt;}

    virtual QStringList getPropertyList() override;
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

