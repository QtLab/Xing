#ifndef T1102ITEM_H
#define T1102ITEM_H

#include <QObject>
#include <QString>
#include <Qtime>
#include <Qdate>
#include "tr/tritem.h"
class T1102Item : public TrItem
{
    Q_OBJECT
public:
    T1102Item();
    ~T1102Item();

private:
    QString    _hname               ;    // [string,   20] �ѱ۸�
    long    _price               ;    // [long  ,    8] ���簡
    bool    _sign                ;    // [string,    1] ���ϴ�񱸺�
    long    _change              ;    // [long  ,    8] ���ϴ��
    float    _diff                ;    // [float ,  6.2] �����
    long    _volume              ;    // [long  ,   12] �����ŷ���
    long    _recprice            ;    // [long  ,    8] ���ذ�
    long    _avg                 ;    // [long  ,    8] �������
    long    _uplmtprice          ;    // [long  ,    8] ���Ѱ�
    long    _dnlmtprice          ;    // [long  ,    8] ���Ѱ�
    long    _jnilvolume          ;    // [long  ,   12] ���ϰŷ���
    long    _volumediff          ;    // [long  ,   12] �ŷ�����
    char    _open                ;    // [long  ,    8] �ð�
    char    _opentime            ;    // [string,    6] �ð��ð�
    char    _high                ;    // [long  ,    8] ��
    char    _hightime            ;    // [string,    6] ���ð�
    char    _low                 ;    // [long  ,    8] ����
    char    _lowtime             ;    // [string,    6] �����ð�
    char    _high52w             ;    // [long  ,    8] 52�ְ�
    char    _high52wdate         ;    // [string,    8] 52�ְ���
    char    _low52w              ;    // [long  ,    8] 52������
    char    _low52wdate          ;    // [string,    8] 52��������
    char    _exhratio            ;    // [float ,  6.2] ������
    char    _per                 ;    // [float ,  6.2] PER
    char    _pbrx                ;    // [float ,  6.2] PBRX
    char    _listing             ;    // [long  ,   12] �����ֽļ�(õ)
    char    _jkrate              ;    // [long  ,    8] ���ű���
    char    _memedan             ;    // [string,    5] ��������
    char    _offernocd1          ;    // [string,    3] �ŵ����ǻ��ڵ�1
    char    _bidnocd1            ;    // [string,    3] �ż����ǻ��ڵ�1
    char    _offerno1            ;    // [string,    6] �ŵ����ǻ��1
    char    _bidno1              ;    // [string,    6] �ż����ǻ��1
    char    _dvol1               ;    // [long  ,    8] �Ѹŵ�����1
    char    _svol1               ;    // [long  ,    8] �Ѹż�����1
    char    _dcha1               ;    // [long  ,    8] �ŵ�����1
    char    _scha1               ;    // [long  ,    8] �ż�����1
    char    _ddiff1              ;    // [float ,  6.2] �ŵ�����1
    char    _sdiff1              ;    // [float ,  6.2] �ż�����1
    char    _offernocd2          ;    // [string,    3] �ŵ����ǻ��ڵ�2
    char    _bidnocd2            ;    // [string,    3] �ż����ǻ��ڵ�2
    char    _offerno2            ;    // [string,    6] �ŵ����ǻ��2
    char    _bidno2              ;    // [string,    6] �ż����ǻ��2
    char    _dvol2               ;    // [long  ,    8] �Ѹŵ�����2
    char    _svol2               ;    // [long  ,    8] �Ѹż�����2
    char    _dcha2               ;    // [long  ,    8] �ŵ�����2
    char    _scha2               ;    // [long  ,    8] �ż�����2
    char    _ddiff2              ;    // [float ,  6.2] �ŵ�����2
    char    _sdiff2              ;    // [float ,  6.2] �ż�����2
    char    _offernocd3          ;    // [string,    3] �ŵ����ǻ��ڵ�3
    char    _bidnocd3            ;    // [string,    3] �ż����ǻ��ڵ�3
    char    _offerno3            ;    // [string,    6] �ŵ����ǻ��3
    char    _bidno3              ;    // [string,    6] �ż����ǻ��3
    char    _dvol3               ;    // [long  ,    8] �Ѹŵ�����3
    char    _svol3               ;    // [long  ,    8] �Ѹż�����3
    char    _dcha3               ;    // [long  ,    8] �ŵ�����3
    char    _scha3               ;    // [long  ,    8] �ż�����3
    char    _ddiff3              ;    // [float ,  6.2] �ŵ�����3
    char    _sdiff3              ;    // [float ,  6.2] �ż�����3
    char    _offernocd4          ;    // [string,    3] �ŵ����ǻ��ڵ�4
    char    _bidnocd4            ;    // [string,    3] �ż����ǻ��ڵ�4
    char    _offerno4            ;    // [string,    6] �ŵ����ǻ��4
    char    _bidno4              ;    // [string,    6] �ż����ǻ��4
    char    _dvol4               ;    // [long  ,    8] �Ѹŵ�����4
    char    _svol4               ;    // [long  ,    8] �Ѹż�����4
    char    _dcha4               ;    // [long  ,    8] �ŵ�����4
    char    _scha4               ;    // [long  ,    8] �ż�����4
    char    _ddiff4              ;    // [float ,  6.2] �ŵ�����4
    char    _sdiff4              ;    // [float ,  6.2] �ż�����4
    char    _offernocd5          ;    // [string,    3] �ŵ����ǻ��ڵ�5
    char    _bidnocd5            ;    // [string,    3] �ż����ǻ��ڵ�5
    char    _offerno5            ;    // [string,    6] �ŵ����ǻ��5
    char    _bidno5              ;    // [string,    6] �ż����ǻ��5
    char    _dvol5               ;    // [long  ,    8] �Ѹŵ�����5
    char    _svol5               ;    // [long  ,    8] �Ѹż�����5
    char    _dcha5               ;    // [long  ,    8] �ŵ�����5
    char    _scha5               ;    // [long  ,    8] �ż�����5
    char    _ddiff5              ;    // [float ,  6.2] �ŵ�����5
    char    _sdiff5              ;    // [float ,  6.2] �ż�����5
    char    _fwdvl               ;    // [long  ,   12] �ܱ���ŵ��հ����
    char    _ftradmdcha          ;    // [long  ,   12] �ܱ���ŵ��������
    char    _ftradmddiff         ;    // [float ,  6.2] �ܱ���ŵ�����
    char    _fwsvl               ;    // [long  ,   12] �ܱ���ż��հ����
    char    _ftradmscha          ;    // [long  ,   12] �ܱ���ż��������
    char    _ftradmsdiff         ;    // [float ,  6.2] �ܱ���ż�����
    char    _vol                 ;    // [float ,  6.2] ȸ����
    char    _shcode              ;    // [string,    6] �����ڵ�
    char    _value               ;    // [long  ,   12] �����ŷ����
    char    _jvolume             ;    // [long  ,   12] ���ϵ��ð��ŷ���
    char    _highyear            ;    // [long  ,    8] �����ְ�
    char    _highyeardate        ;    // [string,    8] �����ְ�����
    char    _lowyear             ;    // [long  ,    8] ����������
    char    _lowyeardate         ;    // [string,    8] ������������
    char    _target              ;    // [long  ,    8] ��ǥ��
    char    _capital             ;    // [long  ,   12] �ں���
    char    _abscnt              ;    // [long  ,   12] �����ֽļ�
    char    _parprice            ;    // [long  ,    8] �׸鰡
    char    _gsmm                ;    // [string,    2] ����
    char    _subprice            ;    // [long  ,    8] ��밡
    char    _total               ;    // [long  ,   12] �ð��Ѿ�
    char    _listdate            ;    // [string,    8] ������
    char    _name                ;    // [string,   10] ���б��
    char    _bfsales             ;    // [long  ,   12] ���б�����
    char    _bfoperatingincome   ;    // [long  ,   12] ���б⿵������
    char    _bfordinaryincome    ;    // [long  ,   12] ���б�������
    char    _bfnetincome         ;    // [long  ,   12] ���б������
    char    _bfeps               ;    // [float , 13.2] ���б�EPS
    char    _name2               ;    // [string,   10] �����б��
    char    _bfsales2            ;    // [long  ,   12] �����б�����
    char    _bfoperatingincome2  ;    // [long  ,   12] �����б⿵������
    char    _bfordinaryincome2   ;    // [long  ,   12] �����б�������
    char    _bfnetincome2        ;    // [long  ,   12] �����б������
    char    _bfeps2              ;    // [float , 13.2] �����б�EPS
    char    _salert              ;    // [float ,  7.2] ����������
    char    _opert               ;    // [float ,  7.2] �����񿵾�����
    char    _ordrt               ;    // [float ,  7.2] ������������
    char    _netrt               ;    // [float ,  7.2] �����������
    char    _epsrt               ;    // [float ,  7.2] ������EPS
    char    _info1               ;    // [string,   10] ������
    char    _info2               ;    // [string,   10] ����/�޵��
    char    _info3               ;    // [string,   10] ����/���屸��
    char    _info4               ;    // [string,   12] ����/�Ҽ��Ǳ���
    char    _janginfo            ;    // [string,   10] �屸��
    char    _t_per               ;    // [float ,  6.2] T.PER
    char    _tonghwa             ;    // [string,    3] ��ȭISO�ڵ�
    char    _dval1               ;    // [long  ,   18] �Ѹŵ����1
    char    _sval1               ;    // [long  ,   18] �Ѹż����1
    char    _dval2               ;    // [long  ,   18] �Ѹŵ����2
    char    _sval2               ;    // [long  ,   18] �Ѹż����2
    char    _dval3               ;    // [long  ,   18] �Ѹŵ����3
    char    _sval3               ;    // [long  ,   18] �Ѹż����3
    char    _dval4               ;    // [long  ,   18] �Ѹŵ����4
    char    _sval4               ;    // [long  ,   18] �Ѹż����4
    char    _dval5               ;    // [long  ,   18] �Ѹŵ����5
    char    _sval5               ;    // [long  ,   18] �Ѹż����5
    char    _davg1               ;    // [long  ,    8] �Ѹŵ���ܰ�1
    char    _savg1               ;    // [long  ,    8] �Ѹż���ܰ�1
    char    _davg2               ;    // [long  ,    8] �Ѹŵ���ܰ�2
    char    _savg2               ;    // [long  ,    8] �Ѹż���ܰ�2
    char    _davg3               ;    // [long  ,    8] �Ѹŵ���ܰ�3
    char    _savg3               ;    // [long  ,    8] �Ѹż���ܰ�3
    char    _davg4               ;    // [long  ,    8] �Ѹŵ���ܰ�4
    char    _savg4               ;    // [long  ,    8] �Ѹż���ܰ�4
    char    _davg5               ;    // [long  ,    8] �Ѹŵ���ܰ�5
    char    _savg5               ;    // [long  ,    8] �Ѹż���ܰ�5
    char    _ftradmdval          ;    // [long  ,   18] �ܱ���ŵ����
    char    _ftradmsval          ;    // [long  ,   18] �ܱ���ż����
    char    _ftradmdavg          ;    // [long  ,    8] �ܱ���ŵ���ܰ�
    char    _ftradmsavg          ;    // [long  ,    8] �ܱ���ż���ܰ�
    char    _info5               ;    // [string,    8] ��������ȯ��
    char    _spac_gubun          ;    // [string,    1] ����μ�����ȸ�翩��
    char    _issueprice          ;    // [long  ,    8] ���డ��
    char    _alloc_gubun         ;    // [string,    1] ������뱸���ڵ�(1:��й߻�2:��
    char    _alloc_text          ;    // [string,    8] ������뱸��
    char    _shterm_text         ;    // [string,   10] �ܱ����/VI�ߵ�

};

#endif // T1102ITEM_H
