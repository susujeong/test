// 1. ��� ����
/* ���� ��� ������ ����
   MFC���� �����ϴ� ���� Ŭ���� ����, ������ Ÿ��, ��ũ�� �� ���� */
#include <afxwin.h>


   // 2. Ŭ���� �����
   // WimMain() �Լ� ��ɰ� ������ ���ν��� ����� ������ �����Ͽ� �� ���� Ŭ������ ������
   /* ��κ��� CWinApp, CFrameWnd Ŭ������ �״�� ������� �ʰ�,
      C++ ��� ������� ���ο� Ŭ������ ����� �Ϻ� ����� �������Ͽ� ���*/

      // ���� ���α׷� Ŭ������ ����
      // CWinApp: ���� ���α׷��� �ʱ�ȭ �ڵ�, �޽��� ����, ���� �ڵ� ����
class CHelloApp :public CWinApp
{
public:
    virtual BOOL InitInstance();
};

// ���� ������ Ŭ������ ����
// CFrameWnd: ���� ������ ��� ����
class CMainFrame :public CFrameWnd
{
public:
    CMainFrame();

protected:
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    DECLARE_MESSAGE_MAP()
};


// 3. ���� ���α׷� ��ü
// ���� ���α׷� ��ü ����
CHelloApp theApp;


// 4. Ŭ���� ���Ǻ�
/* ���ο� ������ WinMain() �Լ��� ���α׷��� ���۵Ǹ� ���� ���α׷� ��ü�� InitInstance() �Լ�(�ʱ�ȭ �Լ�) ȣ��
   InitInstance() �Լ��� �ݵ�� ������ �ؾ���

   �������� InitInstance() �Լ���
   1. ���� ������ ����� ���� CMainFrame ��ü�� �������� ����
   2. ShowWindow() ����Լ��� ȣ���Ͽ� �����츦 ȭ�鿡 ��Ÿ�� */
BOOL CHelloApp::InitInstance()
{
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    // �ʱ�ȭ �۾��� ���������� �������� TRUE ����
    // ������ WinMain() �Լ��� Init �Լ��� ���ϰ��� FALSE�� �������� �ʰ� ���α׷� ������
    return TRUE;
}

// ���� ������ Ŭ���� ����
// CFrameWnd Ŭ�������� �Ļ��� Ŭ����
// m_pMainWnd = new CMainFrame;�� ��ü ���� �� ȣ��Ǵ� ������
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
    MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));
}


// 5. �޽��� ��
// �޽��� �� ����
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()