/**
 * \file CanadianExperience.cpp
 *
 * \author 
 */

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CanadianExperience.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// \cond
BEGIN_MESSAGE_MAP(CCanadianExperienceApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CCanadianExperienceApp::OnAppAbout)
END_MESSAGE_MAP()
/// \endcond

/**
 * Constructor
 */
CCanadianExperienceApp::CCanadianExperienceApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("CanadianExperience.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/// The one and only CCanadianExperienceApp object
CCanadianExperienceApp theApp;


/** CCanadianExperienceApp initialization
 * \return TRUE if successful */
BOOL CCanadianExperienceApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	// The one and only window has been initialized, so show and update it
    pFrame->MoveWindow(100, 100, 1000, 800);
    pFrame->ShowWindow(SW_SHOW);
    pFrame->UpdateWindow();
	return TRUE;
}

/** Exit this program 
 * \return exit code */
int CCanadianExperienceApp::ExitInstance()
{
    Gdiplus::GdiplusShutdown(gdiplusToken);
    AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}


/** The About dialog box */
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

/** Constructor */
CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

/** Exchange data between the class and the dialog box 
 * \param pDX structure that controls the data exchange */
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

/** App command to run the dialog */
void CCanadianExperienceApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCanadianExperienceApp message handlers



