// 1. 헤더 파일
/* 여러 헤더 파일을 포함
   MFC에서 제공하는 각종 클래스 정의, 데이터 타입, 매크로 등 선언 */
#include <afxwin.h>


   // 2. 클래스 선언부
   // WimMain() 함수 기능과 윈도우 프로시저 기능을 적절히 분할하여 두 개의 클래스로 제공함
   /* 대부분은 CWinApp, CFrameWnd 클래스를 그대로 사용하지 않고,
      C++ 상속 기능으로 새로운 클래스를 만들고 일부 기능을 재정의하여 사용*/

      // 응용 프로그램 클래스를 선언
      // CWinApp: 응용 프로그램의 초기화 코드, 메시지 루프, 종료 코드 제공
class CHelloApp :public CWinApp
{
public:
    virtual BOOL InitInstance();
};

// 메인 윈도우 클래스를 선언
// CFrameWnd: 메인 윈도우 기능 제공
class CMainFrame :public CFrameWnd
{
public:
    CMainFrame();

protected:
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    DECLARE_MESSAGE_MAP()
};


// 3. 응용 프로그램 객체
// 응용 프로그램 객체 선언
CHelloApp theApp;


// 4. 클래스 정의부
/* 내부에 숨겨진 WinMain() 함수는 프로그램이 시작되면 응용 프로그램 객체의 InitInstance() 함수(초기화 함수) 호출
   InitInstance() 함수는 반드시 재정의 해야함

   재정의한 InitInstance() 함수는
   1. 메인 윈도우 기능을 가진 CMainFrame 객체를 동적으로 생성
   2. ShowWindow() 멤버함수를 호출하여 윈도우를 화면에 나타냄 */
BOOL CHelloApp::InitInstance()
{
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    // 초기화 작업이 성공적으로 끝났으면 TRUE 리턴
    // 숨겨진 WinMain() 함수는 Init 함수의 리턴값이 FALSE면 진행하지 않고 프로그램 종료함
    return TRUE;
}

// 메인 윈도우 클래스 정의
// CFrameWnd 클래스에서 파생한 클래스
// m_pMainWnd = new CMainFrame;로 객체 생성 시 호출되는 생성자
CMainFrame::CMainFrame()
{
    // 
    Create(NULL, _T("HelloMFC"));
}

void CMainFrame::OnPaint()
{
    CPaintDC dc(this);
    const TCHAR* msg = _T("Hello, MFC");
    dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
    MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"));
}


// 5. 메시지 맵
// 메시지 맵 선언
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()