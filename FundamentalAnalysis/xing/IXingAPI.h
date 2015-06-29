#ifndef _IXINGAPI_H_
#define _IXINGAPI_H_
#include <QLibrary>
#include <QString>
#include <QMetaType>
#include "util/templatesingleton.h"
#undef UNICODE
#include <qt_windows.h>
//------------------------------------------------------------------------------
// �޽��� ����
// �޽����� ID���� Connect�ÿ� ������ nStartMsgID�� ���Ͽ� ����ϸ� �ȴ�.
#define 	XM_DISCONNECT				1		// �������� ������ �������� ��� �߻�
#define 	XM_RECEIVE_DATA				3		// RequestData�� ��û�� �����Ͱ� �����κ��� �޾��� �� �߻�
#define 	XM_RECEIVE_REAL_DATA		4		// AdviseData�� ��û�� �����Ͱ� �����κ��� �޾��� �� �߻�
#define 	XM_LOGIN					5		// �����κ��� �α��� ��� �޾����� �߻�
#define 	XM_LOGOUT					6		// �����κ��� �α׾ƿ� ��� �޾����� �߻�
#define		XM_TIMEOUT_DATA				7		// RequestData�� ��û�� �����Ͱ� Timeout �� �߻�������
#define 	XM_RECEIVE_LINK_DATA		8		// HTS ���� ���� �����Ͱ� �߻����� ��	: by zzin 2013.11.11
#define 	XM_RECEIVE_REAL_DATA_CHART	10		// �ǽð� �ڵ� ����� �� ��Ʈ ��ȸ ��, ��ǥ�ǽð� �����͸� �޾��� ��  : by zzin 2013.08.14

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Receive Flag
#define		REQUEST_DATA			1
#define		MESSAGE_DATA			2
#define		SYSTEM_ERROR_DATA		3
#define		RELEASE_DATA			4
#define		LINK_DATA				10			// XM_RECEIVE_LINK_DATA �޽����� ���� �÷���
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure ����
#pragma pack( push, 1 )

// ��ȸTR ���� Packet
typedef struct _RECV_PACKET
{
    _RECV_PACKET() { ZeroMemory( this, sizeof(_RECV_PACKET ) ); }

    int					nRqID;						// Request ID
    int					nDataLength;				// ���� ������ ũ��
    int					nTotalDataBufferSize;		// lpData�� �Ҵ�� ũ��
    int					nElapsedTime;				// ���ۿ��� ���ű��� �ɸ��ð�(1/1000��)
    int					nDataMode;					// 1:BLOCK MODE, 2:NON-BLOCK MODE
    char				szTrCode	[10+1];			// AP Code
    char				cCont		[1];			// '0' : ������ȸ ����, '1' : ������ȸ ����
    char				szContKey	[18+1];			// ����Ű, Data Header�� B �� ��쿡�� ���
    char				szUserData	[30+1];			// ����� ������
    char				szBlockName [17];			// Block ��, Block Mode �϶� ���
    unsigned char*		lpData;
} RECV_PACKET, *LPRECV_PACKET;
Q_DECLARE_METATYPE(RECV_PACKET)
Q_DECLARE_OPAQUE_POINTER(LPRECV_PACKET)

// �޽��� ���� Packet
typedef struct
{
    int					nRqID;						// Request ID
    int					nIsSystemError;				// 0:�Ϲݸ޽���, 1:System Error �޽���
    char				szMsgCode[5+1];				// �޽��� �ڵ�
    int					nMsgLength;					// Message ����
    unsigned char*		lpszMessageData;			// Message Data
} MSG_PACKET, *LPMSG_PACKET;
Q_DECLARE_METATYPE(MSG_PACKET)
Q_DECLARE_OPAQUE_POINTER(LPMSG_PACKET)
// �ǽð�TR ���� Packet
typedef struct _REAL_RECV_PACKET
{
    _REAL_RECV_PACKET() { ZeroMemory( this, sizeof( _REAL_RECV_PACKET ) ); }

    char				szTrCode [ 3 + 1];

    int					nKeyLength;
    char				szKeyData[32 + 1];
    char				szRegKey [32 + 1];

    int					nDataLength;
    char*				pszData;
} RECV_REAL_PACKET, *LPRECV_REAL_PACKET;
Q_DECLARE_METATYPE(RECV_REAL_PACKET)
Q_DECLARE_OPAQUE_POINTER(LPRECV_REAL_PACKET)
// HTS���� API�� �����Ǿ� ���ŵǴ� Packet
typedef struct _LINKDATA_RECV_MSG
{
    _LINKDATA_RECV_MSG() { ZeroMemory( this, sizeof( _LINKDATA_RECV_MSG ) );	}

    char				sLinkName[32];
    char				sLinkData[32];
    char				sFiller  [64];
}LINKDATA_RECV_MSG, *LPLINKDATA_RECV_MSG;
Q_DECLARE_METATYPE(LINKDATA_RECV_MSG)
Q_DECLARE_OPAQUE_POINTER(LPLINKDATA_RECV_MSG)
//------------------------------------------------------------------------------

class IXingAPI : public TemplateSingleton<IXingAPI>
{
public:
    IXingAPI ();

//	inline	HMODULE	GetSafeHandle			()											{ return m_hModule; }

public:
    // �ʱ�ȭ ����
    BOOL	Init					();
    BOOL	IsInit					()											{ return m_Lib != NULL; }
    void	Uninit					();

    // ��������
    BOOL	Connect					( HWND hWnd, LPCTSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut=-1, int nSendMaxPacketSize=-1 );
    BOOL	IsConnected				();
    BOOL	Disconnect				();

    // �α���
    BOOL	Login					( HWND hWnd, LPCSTR pszID, LPCSTR pszPwd, LPCSTR pszCertPwd, int nType, BOOL bShowCertErrDlg=TRUE );
    BOOL	Logout					( HWND hWnd );

    int		GetLastError			();
    QString	GetErrorMessage			( int nErrorCode );

    // ��ȸ��TR ����
    int		Request					( HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext=FALSE, const char* pszNextKey="", int nTimeOut=30 );
    BOOL	ReleaseRequestData		( int nRequestID );
    BOOL	ReleaseMessageData		( LPARAM lp );

    // �ǽð�TR ����
    BOOL	AdviseRealData			( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
    BOOL	UnadviseRealData		( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
    BOOL	UnadviseWindow			( HWND hWnd );

    // ���� ����
    int		GetAccountListCount		();
    BOOL	GetAccountList			( int nIndex, LPSTR pszAcc, int nAccSize );
    BOOL	GetAccountName			( LPCTSTR pszAcc, LPSTR pszAccName, int nAccNameSize );
    BOOL	GetAcctDetailName		( LPCTSTR pszAcc, LPSTR pszAcctDetailName, int nAcctDetailNameSize );
    BOOL	GetAcctNickname			( LPCTSTR pszAcc, LPSTR pszAcctNickname, int nAcctNicknameSize );

    // �������
    QString	GetCommMedia			();			// ��Ÿ�ü�� ���Ѵ�.
    QString	GetETKMedia				();			// ����ü�� ���Ѵ�.
    QString	GetClientIP				();			// ����IP�� ���Ѵ�.
    QString	GetServerName			();			// �������� ���Ѵ�.
    QString GetAPIPath				();			// �������� xingAPI�� ���

    void	SetHeaderInfo			( LPCTSTR szType, LPCTSTR szValue );
    void	SetUseAPIVer			( LPCTSTR szUserAPIVer );
    BOOL	SetMode					( LPCTSTR pszMode, LPCTSTR pszValue );

    QString	GetProcBranchNo			();			// ó������ ���Ѵ�.
    BOOL	GetUseOverFuture		();			// �ؿܼ��� ������
    BOOL	GetUseFX				();			// FX ������
    BOOL	IsChartLib				();			// ��Ʈ���̺귯�� ����

    int		GetTRCountPerSec		( LPCTSTR pszCode );				// �ʴ� ���� ���� Ƚ��

    void	SetNotifyFlag			( BOOL bNotifyFlag );	// ��޸޽���, �������� �������� ���� �뺸 ���� (���� ����)

    //------------------------------------------------------------------------------
    // �ΰ� ���� TR ��ȸ
    //     ��ȯ��       - Request() �Լ��� �̿� ��� ����
    //     hWnd			- ��ȸ ����� ���� �������� �ڵ�
    //
    //
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // �ڡڡڡڡ�
    // �ڡڡڡڡ�  [1] ���� �˻�
    // �ڡڡڡڡ�
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    //
    //     pszCode		- "t1807" (HTS '[1807] ����˻�' ���� 'API �� ��������' ������ ������ ������ �˻��ϴ� TR)
    //     lpData		- 'API�� ��������' �� ������ ��ü ��� ����, NULL �Է½� ���ϴ��̾�α� ǥ��
    //
    //     ex) HTS '[1807] ����˻�' ���� 'API �� ��������' ������ ������ "D:\test.adf"
    //			pszCode = "t1833", pszData = "D:\test.adf"
    //			int nReqID = RequestService( hWnd, "t1833", "D:\test.adf" );
    //
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // �ڡڡڡڡ�
    // �ڡڡڡڡ�  [2] ~ [3] ��Ʈ ���ʵ����͸� �̿��� ��ǥ�����͸� ����
    // �ڡڡڡڡ�
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    //
    //	��ǥ�����ʹ� íƮ ���ʵ����͸� ���Ź޾� API���ο��� �����Ͽ� �����ϴ� ������ ��ȸ �� �ǽð� ���信
    //  �ټ� �ð��� �ɸ� �� �ֽ��ϴ�.
    //  �ڷ�ǰԽ��� ���� "ChartApiSample(VC++ 2012)" ������ �����Ͻñ� �ٶ��ϴ�.
    //
    //  �� ��ȸ�� �ǽð� �ڵ������ �ϸ�, �ǽð� ��ǥ������ �߻��� XM_RECEIVE_REAL_DATA_CHART �� �޽����� ����
    //	  WPARAM = �ش� ����
    //	  LPARAM = LPRECV_REAL_PACKET (RECV_REAL_PACKET �� pszData  = ��ȸ TR�� outblock1�� ����)
    //
    //
    //  [2] ��Ʈ ��ǥ������ ��ȸ (HTS '[4201]xing��Ʈ1'�� ���İ����ڳ� ��ǥ�� �����ϸ�, DevCenter �޴� [�ΰ�����-���İ�����] �� ���� ��ǥ ����)
    //
    //     pszCode		- "ChartIndex" (��Ʈ ��ǥ������ ��ȸ�� TR)
    //     lpData		- "ChartIndex" TR�� Inblock�� ������ ����ü
    //
    //     ex) "MACD" ��ǥ������ ��ȸ
    //         ChartIndexInBlock sInBlock;
    //         sInBlock.indexid		= ��ǥID	 // ���� ��ȸ�� ����, '���� ���� - ���� ��ǥ' ��ȸ�� ���� ��ȸ ChartIndexOutBlock�� indexid
    //         sInBlock.indexname	= "MACD"
    //         sInBlock.market		= "1"		 // �ֽ�
    //         ...����..
    //		   RemoveService( hWnd, "ChartIndex", sInBlock.indexid );
    //         int nReqID = RequestService( hWnd, "ChartIndex", &sInBlock );
    //
    //
    // [3] ��Ʈ ���������� ��ȸ (HTS '[4201]xing��Ʈ1'�� ���İ����ڳ� ��ǥ�� �����ϸ�, DevCenter �޴� [�ΰ�����-���İ�����] �� ���� ��ǥ ����)
    //     ���� ������ ��Ʈ ���ʵ����͸� ���� �������� ������ ��, RequestService() ȣ�� �� ��ǥ�����ͷ� �����Ͽ� ����
    //     ("xingAPI ��ġ����/��������/ChartExcelData.xls" ����)
    //
    //     pszCode		- "ChartExcel" (��Ʈ ��ǥ������ ��ȸ�� TR)
    //     lpData		- "ChartExcel" TR�� Inblock�� ������ ����ü
    //
    //     ex) ���� ���� �ð����� �����͸� ���� �������� ��ȯ�Ͽ� ������ ������ "C:\ETRADE\xingAPI\��������\ChartExcelData.xls"
    //         ChartExcelInBlock sInBlock;
    //          sInBlock.indexid		= ��ǥID	 // ���� ��ȸ�� ����, '���� ���� - ���� ��ǥ' ��ȸ�� ���� ��ȸ ChartIndexOutBlock�� indexid
    //         sInBlock.indexname		= "MACD"
    //         sInBlock.excelfilename	= "C:\ETRADE\xingAPI\��������\ChartExcelData.xls"
    //         ...����..
    //         RemoveService( hWnd, "ChartExcel", sInBlock.indexid );
    //         int nReqID = RequestService( hWnd, "ChartExcel", &sInBlock );
    //
    //
    int		RequestService			( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData );


    //------------------------------------------------------------------------------
    // �ΰ� ���� ��ȸ TR ����
    //     ��ȯ��       - �ΰ����񽺿� ���� �޶���
    //     hWnd			- ��ȸ ����� ���� �������� �ڵ�
    //
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // �ڡڡڡڡ�
    // �ڡڡڡڡ�  [1] ���� �˻�
    // �ڡڡڡڡ�
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    //
    //		�ش� ����
    //
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    // �ڡڡڡڡ�
    // �ڡڡڡڡ�  [2] ~ [3] ��Ʈ������ ��ȸ
    // �ڡڡڡڡ�
    // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
    //
    //		��ǥ�����ʹ� íƮ ���ʵ����͸� ���Ź޾� API���ο��� �����Ͽ� �����ϴ� ������
    //      ���� ��ȸ�Ҽ��� API�� ���ϰ� �� �� ������, ������� �ʴ� ��ǥ�� �����ϴ� ���� �����ϴ�.
    //
    //
    //		�� ��ȸ �� �ڵ������ �ǽð��� ������ ���� ȣ����
    //
    //     pszCode		- "ChartIndex" or "ChartExcel"
    //     lpData		- �� TR��  OutBlock�� indexid
    //
    int		RemoveService			( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData );

    //------------------------------------------------------------------------------
    // API ���� HTS�� ���� (API -> HTS) : ������ ���Ҷ����� ��û�Ѵ�
    //     ��ȯ��       - ���� ���� ����
    //     hWnd			- ������ ��û�� �������� �ڵ�
    //
    // [1] ���� ����
    //     pszLinkKey	- &STOCK_CODE				: �ֽ� �����ڵ�
    //                    &ETF_CODE					: ETF �����ڵ�
    //                    &ELW_CODE					: ELW �����ڵ�
    //                    &KONEX_CODE				: �ڳؽ� �����ڵ�
    //                    &FREEBOARD_CODE			: �������� �����ڵ�
    //                    &KSPI_CODE				: �ڽ��� ���� �ڵ�
    //                    &KSQI_CODE				: �ڽ��� ���� �ڵ�
    //                    &FUTURE_CODE				: ���������ڵ�
    //                    &OPTION_CODE				: �ɼ������ڵ�
    //                    &FUTOPT_CODE				: ����/�ɼ� �����ڵ�
    //                    &FUTSP_CODE				: ������������ �����ڵ�
    //                    &STOCK_FUTURE_CODE		: �ֽ� ���� �����ڵ�
    //                    &STOCK_OPTION_CODE		: �ֽ� �ɼ� �����ڵ�
    //                    &STOCK_FUTOPT_CODE		: �ֽ� �����ɼ� �����ڵ�
    //                    &STOCK_FUTSP_CODE			: �ֽ� ������������ �����ڵ�
    //                    &FUTOPT_STOCK_FUTOPT_CODE : �����ɼ� & �ֽ� �����ɼ� �����ڵ�
    //                    &US_CODE					: �ؿ������ڵ�
    //                    &COMMODITY_FUTOPT_CODE	: ��ǰ����/�����ɼ�
    //                    &COMMODITY_FUTURE_CODE	: ��ǰ����
    //                    &COMMODITY_STAR_CODE		: ��Ÿ����
    //                    &CME_FUTURE_CODE			: CME�߰�����
    //                    &EUREX_OPTION_CODE		: EUREX�߰��ɼ�
    //                    &NIGHT_FUTOPT_CODE		: �߰������ɼ�
    //     pszData    	- ��ǰ�� �����ڵ�
    //
    //     ex) �ֽ� ���� ���� : pszLinkKey = "&STOCK_CODE", pszData = "078020"
    //         ���� ���� ���� : pszLinkKey = "&FUTURE_CODE", pszData = "101HC000"
    //
    // [2] HTS ȭ�� ����
    //     pszLinkKey	- &OPEN_SCREEN : ȭ�� ����
    //     pszData    	- ���� ���� ȭ�� ��ȣ
    //
    //     ex) HTS�� '[6602]���ɿ��� �̰����ܰ�' ����
    //         pszLinkKey = &OPEN_SCREEN, pszData = "6602"

    int		RequestLinkToHTS        ( HWND hWnd, LPCTSTR pszLinkKey, LPCTSTR pszData, LPCTSTR pszFiller=NULL );

    //------------------------------------------------------------------------------
    // HTS ���� API�� ���� (HTS -> API) : ����ϸ� �����Ҷ����� �����ȴ�
    //     hWnd			- ������ ���ϴ� �������� �ڵ�
    //
    // �� HTS���� ���� �߻� ��, XM_RECEIVE_LINK_DATA �� �޽����� �߻�
    //	  WPARAM = LINK_DATA,
    //	  LPARAM = LINKDATA_RECV_MSG ����ü ������

    void	AdviseLinkFromHTS		( HWND hWnd );
    void	UnAdviseLinkFromHTS		( HWND hWnd );

    //------------------------------------------------------------------------------
    // �������� ������ �����Ѵ� : ƽíƮ ������ ��� ������·� ���Ź��� ��� ���
    //     ��ȯ��       - ������ ������ ������(pszDest)�� ����
    //
    //     pszSrc		- ������� ������
    //     pszDest		- ������ ������ �����͸� ������ �޸� (Outblock ����ü ������ �ִ� 2000��)
    //	   nSrcLen	    - pszSrc �������� ����
    //
    // ��� ���
    //     ex) t8411 TR �̿��, InBlock�� comp_yn(���࿩��) �ʵ忡 "Y" �Է� �� ��ȸ
    //          ReceiveData() ���� Occurs ��(t8411OutBlock1)�� ����Ǿ� ���ŵǹǷ�, �ش� �� ������ ����
    //
    //			LRESULT t8411_Wnd::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
    //			{
    //				//-------------------------------------------------------------------------------------
    //				// Data�� ����
    //				if( wParam == REQUEST_DATA )
    //				{
    //					LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;
    //
    //					if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock ) == 0 )
    //					{
    //					}
    //					else if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock1 ) == 0 )
    //					{
    //						LPt8411OutBlock1 pOutBlock1 = (LPt8411OutBlock1)pRpData->lpData;
    //
    //						t8411OutBlock1 szOutBlock1[2000];		// ���� ������ �ִ� 2000�� ����
    //						int nDestSize = g_iXingAPI.Decompress((char *)pOutBlock1, (char *)&szOutBlock1[0], pRpData->nDataLength);
    //
    //						// Occurs �� ���
    //						// Header�� 'A' �̸� ��ü���̿��� OutBlock�� ���̸� ������ ������ ���Ѵ�.
    //						if (nDestSize > 0)
    //						{
    //							int nCount = nDestSize / sizeof( t8411OutBlock1 );
    //
    //							for( int i=0; i<nCount; i++ )
    //							{
    //								������ ǥ��
    //							}
    //						}
    //					}
    //				}
    //			}
    //
    int		Decompress				( LPCTSTR pszSrc, LPCTSTR pszDest, int nSrcLen );

    //------------------------------------------------------------------------------
    ~IXingAPI();
protected:
    int		LoadLibHelper		();

protected:
//	HMODULE			m_hModule;
    QLibrary*        m_Lib;
    typedef BOOL	( __stdcall *FP_CONNECT					) ( HWND, LPCTSTR, int, int, int, int );
    typedef BOOL	( __stdcall *FP_ISCONNECTED				) ( );
    typedef BOOL	( __stdcall *FP_DISCONNECT				) ( );
    typedef BOOL	( __stdcall *FP_LOGIN					) ( HWND, LPCSTR, LPCSTR, LPCSTR, int, BOOL );
    typedef BOOL	( __stdcall *FP_LOGOUT					) ( HWND );

    typedef int		( __stdcall *FP_GETLASTERROR			) ( );
    typedef int		( __stdcall *FP_GETERRORMESSAGE			) ( int, LPSTR, int );

    typedef int		( __stdcall *FP_REQUEST					) ( HWND, LPCSTR, LPVOID, int, BOOL, LPCTSTR, int );
    typedef void	( __stdcall *FP_RELEASEREQUESTDATA		) ( int );
    typedef void	( __stdcall *FP_RELEASEMESSAGEDATA		) ( LPARAM );

    typedef BOOL	( __stdcall *FP_ADVISEREALDATA			) ( HWND, LPCTSTR, LPCTSTR, int );
    typedef BOOL	( __stdcall *FP_UNADVISEREALDATA		) ( HWND, LPCTSTR, LPCTSTR, int );
    typedef BOOL	( __stdcall *FP_UNADVISEWINDOW			) ( HWND );

    typedef int		( __stdcall *FP_GETACCOUNTLISTCOUNT		) ( );
    typedef BOOL	( __stdcall *FP_GETACCOUNTLIST			) ( int, LPSTR, int );
    typedef BOOL	( __stdcall *FP_GETACCOUNTNAME			) ( LPCTSTR, LPSTR, int );
    typedef BOOL	( __stdcall *FP_GETACCTDETAILNAME		) ( LPCTSTR, LPSTR, int );
    typedef BOOL	( __stdcall *FP_GETACCTNICKNAME			) ( LPCTSTR, LPSTR, int );

    typedef void	( __stdcall *FP_GETCOMMMEDIA			) ( LPTSTR );
    typedef void	( __stdcall *FP_GETETKMEDIA				) ( LPTSTR );
    typedef void	( __stdcall *FP_GETCLIENTIP				) ( LPTSTR );
    typedef void	( __stdcall *FP_GETSERVERNAME			) ( LPTSTR );
    typedef void	( __stdcall *FP_GETAPIPATH				) ( LPTSTR );

    typedef void	( __stdcall *FP_SETHEADERINFO			) ( LPCTSTR, LPCTSTR );
    typedef void	( __stdcall *FP_SETUSEAPIVER			) ( LPCTSTR );
    typedef void	( __stdcall *FP_SETMODE					) ( LPCTSTR, LPCTSTR );

    typedef void	(__stdcall *FP_GETPROCBRANCHNO			) ( LPTSTR );
    typedef BOOL	(__stdcall *FP_GETUSEOVERFUTURE			) ( );
    typedef BOOL	(__stdcall *FP_GETUSEFX					) ( );

    typedef int		(__stdcall *FP_GETTRCOUNTPERSEC			) ( LPCTSTR );

    typedef void	(__stdcall *FP_SETNOTIFYFLAG			) ( BOOL );

    typedef int		( __stdcall *FP_REQUESTSERVICE			) ( HWND, LPCTSTR, LPCTSTR );
    typedef int		( __stdcall *FP_REMOVESERVICE			) ( HWND, LPCTSTR, LPCTSTR );

    typedef int		( __stdcall *FP_REQUESTLINKTOHTS    	) ( HWND, LPCTSTR, LPCTSTR, LPCTSTR );
    typedef void	( __stdcall *FP_ADVISELINKFROMHTS    	) ( HWND );
    typedef void	( __stdcall *FP_UNADVISELINKFROMHTS    	) ( HWND );

    typedef int		( __stdcall *FP_DECOMPRESS				) ( LPCTSTR, LPCTSTR, int );
    typedef BOOL	( __stdcall *FP_ISCHARTLIB				) ( );

    FP_CONNECT					m_fpConnect;
    FP_ISCONNECTED				m_fpIsConnected;
    FP_DISCONNECT				m_fpDisconnect;
    FP_LOGIN					m_fpLogin;
    FP_LOGOUT					m_fpLogout;

    FP_GETLASTERROR				m_fpGetLastError;
    FP_GETERRORMESSAGE			m_fpGetErrorMessage;

    FP_REQUEST					m_fpRequest;
    FP_ADVISEREALDATA			m_fpAdviseRealData;
    FP_UNADVISEREALDATA			m_fpUnadviseRealData;
    FP_UNADVISEWINDOW			m_fpUnadviseWindow;
    FP_RELEASEREQUESTDATA		m_fpReleaseRequestData;
    FP_RELEASEMESSAGEDATA		m_fpReleaseMessageData;

    FP_GETACCOUNTLISTCOUNT		m_fpGetAccountListCount;
    FP_GETACCOUNTLIST			m_fpGetAccountList;
    FP_GETACCOUNTNAME			m_fpGetAccountName;
    FP_GETACCTDETAILNAME		m_fpGetAcctDetailName;
    FP_GETACCTNICKNAME			m_fpGetAcctNickname;

    FP_GETCOMMMEDIA				m_fpGetCommMedia;
    FP_GETETKMEDIA				m_fpGetETKMedia;
    FP_GETCLIENTIP				m_fpGetClientIP;
    FP_GETSERVERNAME			m_fpGetServerName;
    FP_GETAPIPATH				m_fpGetAPIPath;

    FP_SETHEADERINFO			m_fpSetHeaderInfo;
    FP_SETUSEAPIVER				m_fpSetUseAPIVer;
    FP_SETMODE					m_fpSetMode;

    FP_GETPROCBRANCHNO			m_fpGetProcBranchNo;
    FP_GETUSEOVERFUTURE			m_fpGetUseOverFuture;
    FP_GETUSEFX					m_fpGetUseFX;

    FP_GETTRCOUNTPERSEC			m_fpGetTRCountPerSec;

    FP_SETNOTIFYFLAG			m_fpSetNotifyFlag;

    FP_REQUESTSERVICE			m_fpRequestService;
    FP_REMOVESERVICE			m_fpRemoveService;

    FP_REQUESTLINKTOHTS			m_fpRequestLinkToHTS;
    FP_ADVISELINKFROMHTS		m_fpAdviseLinkFromHTS;
    FP_UNADVISELINKFROMHTS		m_fpUnAdviseLinkFromHTS;

    FP_DECOMPRESS				m_fpDecompress;
    FP_ISCHARTLIB				m_fpIsChartLib;

    bool isInitialized;
};


#pragma pack( pop )

#define UNICODE 1
#endif // _IXINGAPI_H_


