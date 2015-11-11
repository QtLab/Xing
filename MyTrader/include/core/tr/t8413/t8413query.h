#ifndef T8413QUERY_H
#define T8413QUERY_H

#include <QDate>
#include "core/tr/ctstrquery.h"
#include "core/tr/t8413/t8413item.h"
class T8413Query : public CtsTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QDate edate MEMBER _edate READ edate WRITE setEdate)		//종료일자
	Q_PROPERTY(QString s_time MEMBER _s_time READ s_time WRITE setS_Time)		//장시작시간(HHMMSS)
	Q_PROPERTY(QString e_time MEMBER _e_time READ e_time WRITE setE_Time)		//장종료시간(HHMMSS)
	Q_PROPERTY(long lowend MEMBER _lowend READ lowend WRITE setLowend)		//하한가
	Q_PROPERTY(QDate cts_date MEMBER _cts_date READ cts_date WRITE setCts_Date)		//연속일자
	Q_PROPERTY(long jivolume MEMBER _jivolume READ jivolume WRITE setJivolume)		//전일거래량
	Q_PROPERTY(QString dshmin MEMBER _dshmin READ dshmin WRITE setDshmin)		//동시호가처리시간(MM:분)
	Q_PROPERTY(long dihigh MEMBER _dihigh READ dihigh WRITE setDihigh)		//당일고가
	Q_PROPERTY(long highend MEMBER _highend READ highend WRITE setHighend)		//상한가
	Q_PROPERTY(QString comp_yn MEMBER _comp_yn READ comp_yn WRITE setComp_Yn)		//압축여부(Y:압축N:비압축)
	Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)		//주기구분(2:일3:주4:월)
	Q_PROPERTY(long disiga MEMBER _disiga READ disiga WRITE setDisiga)		//당일시가
	Q_PROPERTY(long jiclose MEMBER _jiclose READ jiclose WRITE setJiclose)		//전일종가
	Q_PROPERTY(long dilow MEMBER _dilow READ dilow WRITE setDilow)		//당일저가
	Q_PROPERTY(long qrycnt MEMBER _qrycnt READ qrycnt WRITE setQrycnt)		//요청건수(최대-압축:2000비압축:500)
	Q_PROPERTY(long jisiga MEMBER _jisiga READ jisiga WRITE setJisiga)		//전일시가
	Q_PROPERTY(long diclose MEMBER _diclose READ diclose WRITE setDiclose)		//당일종가
	Q_PROPERTY(long jihigh MEMBER _jihigh READ jihigh WRITE setJihigh)		//전일고가
	Q_PROPERTY(long jilow MEMBER _jilow READ jilow WRITE setJilow)		//전일저가
	Q_PROPERTY(long rec_count MEMBER _rec_count READ rec_count WRITE setRec_Count)		//레코드카운트
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//단축코드
	Q_PROPERTY(QDate sdate MEMBER _sdate READ sdate WRITE setSdate)		//시작일자
public:
	static T8413Query *createQuery(const QString &shcode, const QString &gubun, long qrycnt, const QDate &sDate, const QDate &eDate, bool comp_yn, QObject *parent=0);
	~T8413Query();
	QDate edate() { return _edate; }
	void setEdate(QDate edate) { _edate = edate; }
	QString s_time() { return _s_time; }
	void setS_Time(QString s_time) { _s_time = s_time; }
	QString e_time() { return _e_time; }
	void setE_Time(QString e_time) { _e_time = e_time; }
	long lowend() { return _lowend; }
	void setLowend(long lowend) { _lowend = lowend; }
	QDate cts_date() { return _cts_date; }
	void setCts_Date(QDate cts_date) { _cts_date = cts_date; }
	long jivolume() { return _jivolume; }
	void setJivolume(long jivolume) { _jivolume = jivolume; }
	QString dshmin() { return _dshmin; }
	void setDshmin(QString dshmin) { _dshmin = dshmin; }
	long dihigh() { return _dihigh; }
	void setDihigh(long dihigh) { _dihigh = dihigh; }
	long highend() { return _highend; }
	void setHighend(long highend) { _highend = highend; }
	QString comp_yn() { return _comp_yn; }
	void setComp_Yn(QString comp_yn) { _comp_yn = comp_yn; }
	QString gubun() { return _gubun; }
	void setGubun(QString gubun) { _gubun = gubun; }
	long disiga() { return _disiga; }
	void setDisiga(long disiga) { _disiga = disiga; }
	long jiclose() { return _jiclose; }
	void setJiclose(long jiclose) { _jiclose = jiclose; }
	long dilow() { return _dilow; }
	void setDilow(long dilow) { _dilow = dilow; }
	long qrycnt() { return _qrycnt; }
	void setQrycnt(long qrycnt) { _qrycnt = qrycnt; }
	long jisiga() { return _jisiga; }
	void setJisiga(long jisiga) { _jisiga = jisiga; }
	long diclose() { return _diclose; }
	void setDiclose(long diclose) { _diclose = diclose; }
	long jihigh() { return _jihigh; }
	void setJihigh(long jihigh) { _jihigh = jihigh; }
	long jilow() { return _jilow; }
	void setJilow(long jilow) { _jilow = jilow; }
	long rec_count() { return _rec_count; }
	void setRec_Count(long rec_count) { _rec_count = rec_count; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	QDate sdate() { return _sdate; }
	void setSdate(QDate sdate) { _sdate = sdate; }
protected:
	explicit T8413Query(QObject *parent=0);
	virtual T8413Item *createItem() override;
	virtual void readOutBlock1() override;
private:
	QDate _edate;		//종료일자
	QString _s_time;		//장시작시간(HHMMSS)
	QString _e_time;		//장종료시간(HHMMSS)
	long _lowend;		//하한가
	QDate _cts_date;		//연속일자
	long _jivolume;		//전일거래량
	QString _dshmin;		//동시호가처리시간(MM:분)
	long _dihigh;		//당일고가
	long _highend;		//상한가
	QString _comp_yn;		//압축여부(Y:압축N:비압축)
	QString _gubun;		//주기구분(2:일3:주4:월)
	long _disiga;		//당일시가
	long _jiclose;		//전일종가
	long _dilow;		//당일저가
	long _qrycnt;		//요청건수(최대-압축:2000비압축:500)
	long _jisiga;		//전일시가
	long _diclose;		//당일종가
	long _jihigh;		//전일고가
	long _jilow;		//전일저가
	long _rec_count;		//레코드카운트
	QString _shcode;		//단축코드
	QDate _sdate;		//시작일자
};
#endif
