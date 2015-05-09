#include "IXingAPI.h"

IXingAPI::~IXingAPI(){
     Uninit();
}

BOOL IXingAPI::Init(LPCTSTR szPath)
{
    if( IsInit() ) return TRUE;

    return LoadLibHelper( szPath );
}

BOOL IXingAPI::LoadLibHelper( LPCTSTR szPath )
{
    m_Lib=new QLibrary("xingAPI");

    return m_Lib->load();
}

void IXingAPI::Uninit()
{
    m_Lib->unload();
    delete m_Lib;
    m_Lib=NULL;
}

BOOL IXingAPI::Connect( HWND hWnd, LPCTSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut, int nSendMaxPacketSize )
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib   ) return FALSE;
    if( NULL == m_fpConnect ) m_fpConnect = (FP_CONNECT)m_Lib->resolve("ETK_Connect");
    Q_ASSERT( m_fpConnect );
    if( NULL == m_fpConnect ) return FALSE;
	return m_fpConnect( hWnd, pszSvrIP, nPort, nStartMsgID, nTimeOut, nSendMaxPacketSize );
}

BOOL IXingAPI::IsConnected()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return FALSE;
    if( NULL == m_fpIsConnected ) m_fpIsConnected = (FP_ISCONNECTED)m_Lib->resolve("ETK_IsConnected");
    Q_ASSERT( m_fpIsConnected );
    if( NULL == m_fpIsConnected ) return FALSE;
    return m_fpIsConnected();
}

BOOL IXingAPI::Disconnect()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return FALSE;
    if( NULL == m_fpDisconnect	) m_fpDisconnect = (FP_DISCONNECT)m_Lib->resolve("ETK_Disconnect");
    Q_ASSERT( m_fpDisconnect );
    if( NULL == m_fpDisconnect	) return FALSE;
    return m_fpDisconnect();
}

BOOL IXingAPI::Login( HWND hWnd, LPCSTR pszID, LPCSTR pszPwd, LPCSTR pszCertPwd, int nType, BOOL bShowCertErrDlg )
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib )	return FALSE;
    if( NULL == m_fpLogin )	m_fpLogin = (FP_LOGIN)m_Lib->resolve("ETK_Login");
    Q_ASSERT( m_fpLogin );
    if( NULL == m_fpLogin )	return FALSE;
	return m_fpLogin( hWnd, pszID, pszPwd, pszCertPwd, nType, bShowCertErrDlg );
}

BOOL IXingAPI::Logout( HWND hWnd )
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib  ) return FALSE;
    if( NULL == m_fpLogout ) m_fpLogout = (FP_LOGOUT)m_Lib->resolve("ETK_Logout");
    Q_ASSERT( m_fpLogout );
    if( NULL == m_fpLogout ) return FALSE;
    return m_fpLogout( hWnd );
}

int	IXingAPI::GetLastError()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib  ) return FALSE;
    if( NULL == m_fpGetLastError ) m_fpGetLastError = (FP_GETLASTERROR)m_Lib->resolve("ETK_GetLastError");
    Q_ASSERT( m_fpGetLastError );
    if( NULL == m_fpGetLastError ) return FALSE;
    return m_fpGetLastError();
}

QString	IXingAPI::GetErrorMessage( int nErrorCode )
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib  ) return "";
    if( NULL == m_fpGetErrorMessage ) m_fpGetErrorMessage = (FP_GETERRORMESSAGE)m_Lib->resolve("ETK_GetErrorMessage");
    Q_ASSERT( m_fpGetErrorMessage );
    if( NULL == m_fpGetErrorMessage ) return "";

    char szData[1024] = { 0 };
    m_fpGetErrorMessage( nErrorCode, szData, sizeof( szData ) );
    return szData;
}

int IXingAPI::Request( HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext, LPCTSTR pszNextKey, int nTimeOut )
{
    if( NULL ==m_Lib )	return -1;

    if( NULL == m_fpRequest )
        m_fpRequest = (FP_REQUEST)m_Lib->resolve("ETK_Request");

    if( NULL == m_fpRequest )	return -1;

	return m_fpRequest(hWnd, pszCode, lpData, nDataSize, bNext, pszNextKey, nTimeOut);
}

BOOL IXingAPI::AdviseRealData ( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpAdviseRealData )
        m_fpAdviseRealData = (FP_ADVISEREALDATA)m_Lib->resolve("ETK_AdviseRealData");

    if( NULL == m_fpAdviseRealData )	return FALSE;

    return m_fpAdviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseRealData( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpUnadviseRealData )
        m_fpUnadviseRealData = (FP_UNADVISEREALDATA)m_Lib->resolve("ETK_UnadviseRealData");

    if( NULL == m_fpUnadviseRealData )	return FALSE;

    return m_fpUnadviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseWindow( HWND hWnd )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpUnadviseWindow )
        m_fpUnadviseWindow = (FP_UNADVISEWINDOW)m_Lib->resolve("ETK_UnadviseWindow");

    if( NULL == m_fpUnadviseWindow )	return FALSE;

    return m_fpUnadviseWindow(hWnd);
}

BOOL IXingAPI::ReleaseRequestData( int nRequestID )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpReleaseRequestData )
        m_fpReleaseRequestData = (FP_RELEASEREQUESTDATA)m_Lib->resolve("ETK_ReleaseRequestData");

    if( NULL == m_fpReleaseRequestData )	return FALSE;

    m_fpReleaseRequestData(nRequestID);
    return TRUE;
}

BOOL IXingAPI::ReleaseMessageData(LPARAM lp)
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpReleaseMessageData )
        m_fpReleaseMessageData = (FP_RELEASEMESSAGEDATA)m_Lib->resolve("ETK_ReleaseMessageData");

    if( NULL == m_fpReleaseMessageData )	return FALSE;

    m_fpReleaseMessageData(lp);
    return TRUE;
}

int	IXingAPI::GetAccountListCount()
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpGetAccountListCount )
        m_fpGetAccountListCount = (FP_GETACCOUNTLISTCOUNT)m_Lib->resolve("ETK_GetAccountListCount");

    if( NULL == m_fpGetAccountListCount )	return 0;

    return m_fpGetAccountListCount();
}

BOOL IXingAPI::GetAccountList( int nIndex, LPSTR pszAcc, int nAccSize )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpGetAccountList )
        m_fpGetAccountList = (FP_GETACCOUNTLIST)m_Lib->resolve( "ETK_GetAccountList");

    if( NULL == m_fpGetAccountList )	return FALSE;

    return m_fpGetAccountList( nIndex, pszAcc, nAccSize );
}

BOOL IXingAPI::GetAccountName( LPCTSTR pszAcc, LPSTR pszAccName, int nAccNameSize )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpGetAccountName )
        m_fpGetAccountName = (FP_GETACCOUNTNAME)m_Lib->resolve("ETK_GetAccountName");

    if( NULL == m_fpGetAccountName )	return FALSE;

    return m_fpGetAccountName( pszAcc, pszAccName, nAccNameSize );
}

BOOL IXingAPI::GetAcctDetailName( LPCTSTR pszAcc, LPSTR pszAcctDetailName, int nAcctDetailNameSize )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpGetAcctDetailName )
        m_fpGetAcctDetailName = (FP_GETACCTDETAILNAME)m_Lib->resolve("ETK_GetAcctDetailName");

    if( NULL == m_fpGetAcctDetailName )	return FALSE;

    return m_fpGetAcctDetailName( pszAcc, pszAcctDetailName, nAcctDetailNameSize );
}

BOOL IXingAPI::GetAcctNickname( LPCTSTR pszAcc, LPSTR pszAcctNickname, int nAcctNicknameSize )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpGetAcctNickname )
        m_fpGetAcctNickname = (FP_GETACCTNICKNAME)m_Lib->resolve("ETK_GetAcctNickname");

    if( NULL == m_fpGetAcctNickname )	return FALSE;

    return m_fpGetAcctNickname( pszAcc, pszAcctNickname, nAcctNicknameSize );
}

QString	IXingAPI::GetCommMedia()
{
    if( NULL == m_Lib )	return "";

    if( NULL == m_fpGetCommMedia )
        m_fpGetCommMedia = (FP_GETCOMMMEDIA)m_Lib->resolve("ETK_GetCommMedia" );

    if( NULL == m_fpGetCommMedia )	return "";

    TCHAR szMedia[256] = { 0 };
    m_fpGetCommMedia( szMedia );
    return szMedia;
}

QString	IXingAPI::GetETKMedia()
{
    if( NULL == m_Lib )	return "";

    if( NULL == m_fpGetETKMedia )
        m_fpGetETKMedia = (FP_GETETKMEDIA)m_Lib->resolve("ETK_GetETKMedia" );

    if( NULL == m_fpGetETKMedia )	return "";

	TCHAR szMedia[256] = { 0 };
    m_fpGetETKMedia( szMedia );
    return szMedia;
}

QString	IXingAPI::GetClientIP()
{
    if( NULL == m_Lib )	return "";

    if( NULL == m_fpGetClientIP )
        m_fpGetClientIP = (FP_GETCLIENTIP)m_Lib->resolve( "ETK_GetClientIP" );

    if( NULL == m_fpGetClientIP )	return "";

    TCHAR szIP[256] = { 0 };
    m_fpGetClientIP( szIP );
    return szIP;
}

QString	IXingAPI::GetServerName()
{
    if( NULL == m_Lib )	return "";

    if( NULL == m_fpGetServerName )
        m_fpGetServerName = (FP_GETSERVERNAME)m_Lib->resolve("ETK_GetServerName" );

    if( NULL == m_fpGetServerName )	return "";

    TCHAR szName[256] = { 0 };
    m_fpGetServerName( szName );
    return szName;
}

QString	IXingAPI::GetAPIPath()
{
    if( NULL == m_Lib )	return "";
    char* funcName = "ETK_GetAPIPath";
    if( NULL == m_fpGetAPIPath )
        m_fpGetAPIPath = (FP_GETAPIPATH)m_Lib->resolve( funcName );

    if( NULL == m_fpGetAPIPath )	return "";

    TCHAR szPath[256] = { 0 };
    m_fpGetAPIPath( szPath );
    return (LPSTR)szPath;
}

void IXingAPI::SetHeaderInfo( LPCTSTR szType, LPCTSTR szValue )
{
    if( NULL == m_Lib )	return;

    if( NULL == m_fpSetHeaderInfo )
        m_fpSetHeaderInfo = (FP_SETHEADERINFO)m_Lib->resolve( "ETK_SetHeaderInfo" );

    if( NULL == m_fpSetHeaderInfo )	return;

    m_fpSetHeaderInfo( szType, szValue );
}

void IXingAPI::SetUseAPIVer( LPCTSTR szUserAPIVer )
{
    if( NULL == m_Lib )	return;

    if( NULL == m_fpSetUseAPIVer )
        m_fpSetUseAPIVer = (FP_SETUSEAPIVER)m_Lib->resolve( "ETK_SetUseAPIVer" );

    if( NULL == m_fpSetUseAPIVer )	return;

    m_fpSetUseAPIVer( szUserAPIVer );
}

BOOL IXingAPI::SetMode( LPCTSTR pszMode, LPCTSTR pszValue )
{
    if( NULL == m_Lib )	return FALSE;

    if( NULL == m_fpSetMode )
        m_fpSetMode = (FP_SETMODE)m_Lib->resolve( "ETK_SetMode" );

    if( NULL == m_fpSetMode ) return FALSE;

    m_fpSetMode( pszMode, pszValue );
    return TRUE;
}

QString	IXingAPI::GetProcBranchNo()
{
    if( NULL == m_Lib )	return "";

    if( NULL == m_fpGetProcBranchNo )
        m_fpGetProcBranchNo = (FP_GETPROCBRANCHNO)m_Lib->resolve( "ETK_GetProcBranchNo" );

    if( NULL == m_fpGetProcBranchNo )	return "";

    TCHAR szProcBranchNo[256] = { 0 };
    m_fpGetProcBranchNo( szProcBranchNo );
    return szProcBranchNo;
}

BOOL IXingAPI::GetUseOverFuture()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return FALSE;
    if( NULL == m_fpGetUseOverFuture ) m_fpGetUseOverFuture = (FP_GETUSEOVERFUTURE)m_Lib->resolve( "ETK_GetUseOverFuture" );
    Q_ASSERT( m_fpGetUseOverFuture );
    if( NULL == m_fpGetUseOverFuture ) return FALSE;
    return m_fpGetUseOverFuture();
}

BOOL IXingAPI::GetUseFX()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return FALSE;
    if( NULL == m_fpGetUseFX ) m_fpGetUseFX = (FP_GETUSEFX)m_Lib->resolve( "ETK_GetUseFX" );
    Q_ASSERT( m_fpGetUseFX );
    if( NULL == m_fpGetUseFX ) return FALSE;
    return m_fpGetUseFX();
}

int IXingAPI::GetTRCountPerSec( LPCTSTR pszCode )
{
    if( NULL == m_Lib )	return -1;

    if( NULL == m_fpGetTRCountPerSec )
        m_fpGetTRCountPerSec = (FP_GETTRCOUNTPERSEC)m_Lib->resolve( "ETK_GetTRCountPerSec" );

    if( NULL == m_fpGetTRCountPerSec )	return -1;

    return m_fpGetTRCountPerSec( pszCode );
}

void IXingAPI::SetNotifyFlag( BOOL bNotifyFlag )
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return;

    if( NULL == m_fpSetNotifyFlag ) m_fpSetNotifyFlag = (FP_SETNOTIFYFLAG)m_Lib->resolve( "ETK_SetNotifyFlag" );
    Q_ASSERT( m_fpSetNotifyFlag );
    if( NULL == m_fpSetNotifyFlag ) return;

    m_fpSetNotifyFlag( bNotifyFlag );
}

int IXingAPI::RequestService( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData )
{
    if( NULL == m_Lib )	return -1;

    if( NULL == m_fpRequestService )
        m_fpRequestService = (FP_REQUESTSERVICE)m_Lib->resolve( "ETK_RequestService" );

    if( NULL == m_fpRequestService )	return -1;

    return m_fpRequestService( hWnd, pszCode, pszData );
}

int IXingAPI::RemoveService( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData )
{
    if( NULL == m_Lib )	return -1;

    if( NULL == m_fpRemoveService )
        m_fpRemoveService = (FP_REMOVESERVICE)m_Lib->resolve( "ETK_RemoveService" );

    if( NULL == m_fpRemoveService )	return -1;

    return m_fpRemoveService( hWnd, pszCode, pszData );
}

int IXingAPI::RequestLinkToHTS( HWND hWnd, LPCTSTR pszLinkKey, LPCTSTR pszData, LPCTSTR pszFiller )
{
    if( NULL == m_Lib )	return -1;

    if( NULL == m_fpRequestLinkToHTS )
        m_fpRequestLinkToHTS = (FP_REQUESTLINKTOHTS)m_Lib->resolve( "ETK_RequestLinkToHTS" );

    if( NULL == m_fpRequestLinkToHTS )	return -1;

    return m_fpRequestLinkToHTS( hWnd, pszLinkKey, pszData, pszFiller );
}

void IXingAPI::AdviseLinkFromHTS( HWND hWnd )
{
    if( NULL == m_Lib )	return;

    if( NULL == m_fpAdviseLinkFromHTS )
        m_fpAdviseLinkFromHTS = (FP_ADVISELINKFROMHTS)m_Lib->resolve( "ETK_AdviseLinkFromHTS" );

    if( NULL == m_fpAdviseLinkFromHTS )	return;

    m_fpAdviseLinkFromHTS( hWnd );
}

void IXingAPI::UnAdviseLinkFromHTS( HWND hWnd )
{
    if( NULL == m_Lib )	return;

    if( NULL == m_fpUnAdviseLinkFromHTS )
        m_fpUnAdviseLinkFromHTS = (FP_UNADVISELINKFROMHTS)m_Lib->resolve( "ETK_UnAdviseLinkFromHTS" );

    if( NULL == m_fpUnAdviseLinkFromHTS )	return;

    m_fpUnAdviseLinkFromHTS( hWnd );
}

int IXingAPI::Decompress( LPCTSTR pszSrc, LPCTSTR pszDest, int nSrcLen )
{
    if( NULL == m_Lib )	return -1;

    if( NULL == m_fpDecompress )
        m_fpDecompress = (FP_DECOMPRESS)m_Lib->resolve( "ETK_Decompress" );

    if( NULL == m_fpDecompress )	return -1;

    return m_fpDecompress( pszSrc, pszDest, nSrcLen );
}

BOOL IXingAPI::IsChartLib()
{
    Q_ASSERT( m_Lib );
    if( NULL == m_Lib		) return FALSE;
    if( NULL == m_fpIsChartLib ) m_fpIsChartLib = (FP_ISCHARTLIB)m_Lib->resolve( "ETK_IsChartLib" );
    Q_ASSERT( m_fpIsChartLib );
    if( NULL == m_fpIsChartLib ) return FALSE;
    return m_fpIsChartLib();
}

