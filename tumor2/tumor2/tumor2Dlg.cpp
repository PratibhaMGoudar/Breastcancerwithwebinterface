
// tumor1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "tumor2.h"
#include "tumor2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define INPUT_clump_thickness 1623
#define INPUT_u_cell_size 24522
#define INPUT_u_cell_shape 11648
#define INPUT_marg_adhesion 5583
#define INPUT_Ep_cell_size 16960
#define INPUT_Bare_nuclei 27574
#define INPUT_Bland_Chromatin 8765
#define INPUT_Normal_Nucleoli 31000
#define INPUT_Mitosis 12496

#define OUTPUT_Benign 12932
#define OUTPUT_Malignant 15680

#define clrGreen1 RGB(204,255,229)
#define clrRed1 RGB(255,204,204)






// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
	//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

														// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctumor1Dlg dialog



Ctumor2Dlg::Ctumor2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUMOR2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctumor2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER2, m_slide2);
	DDX_Control(pDX, IDC_SLIDER15, m_slide15);
	DDX_Control(pDX, IDC_SLIDER16, m_slide16);
	DDX_Control(pDX, IDC_SLIDER13, m_slide13);
	DDX_Control(pDX, IDC_SLIDER14, m_slide14);
	DDX_Control(pDX, IDC_SLIDER11, m_slide11);
	DDX_Control(pDX, IDC_SLIDER12, m_slide12);
	DDX_Control(pDX, IDC_SLIDER9, m_slide9);
	DDX_Control(pDX, IDC_SLIDER10, m_slide10);
	DDX_Control(pDX, IDC_EDIT3, m_editSlide2);
	DDX_Control(pDX, IDC_EDIT4, m_editSlide15);
	DDX_Control(pDX, IDC_EDIT5, m_editSlide16);
	DDX_Control(pDX, IDC_EDIT6, m_editSlide13);
	DDX_Control(pDX, IDC_EDIT7, m_editSlide14);
	DDX_Control(pDX, IDC_EDIT8, m_editSlide11);
	DDX_Control(pDX, IDC_EDIT9, m_editSlide12);
	DDX_Control(pDX, IDC_EDIT10, m_editSlide9);
	DDX_Control(pDX, IDC_EDIT11, m_editSlide10);
}

BEGIN_MESSAGE_MAP(Ctumor2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &Ctumor2Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Ctumor2Dlg::OnNMCustomdrawSlider2)
END_MESSAGE_MAP()


// Ctumor1Dlg message handlers

BOOL Ctumor2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here


	CString s;
	int initialValue = 0;
	s.Format(_T("%d"), initialValue);

	this->m_slide2.SetRange(0, 10, TRUE);
	this->m_slide2.SetPos(initialValue);
	this->m_editSlide2.SetWindowTextW(s);

	this->m_slide15.SetRange(0, 10, TRUE);
	this->m_slide15.SetPos(initialValue);
	this->m_editSlide15.SetWindowTextW(s);

	this->m_slide16.SetRange(0, 10, TRUE);
	this->m_slide16.SetPos(initialValue);
	this->m_editSlide16.SetWindowTextW(s);

	this->m_slide13.SetRange(0, 10, TRUE);
	this->m_slide13.SetPos(initialValue);
	this->m_editSlide13.SetWindowTextW(s);

	this->m_slide14.SetRange(0, 10, TRUE);
	this->m_slide14.SetPos(initialValue);
	this->m_editSlide14.SetWindowTextW(s);

	this->m_slide11.SetRange(0, 10, TRUE);
	this->m_slide11.SetPos(initialValue);
	this->m_editSlide11.SetWindowTextW(s);

	this->m_slide12.SetRange(0, 10, TRUE);
	this->m_slide12.SetPos(initialValue);
	this->m_editSlide12.SetWindowTextW(s);

	this->m_slide9.SetRange(0, 10, TRUE);
	this->m_slide9.SetPos(initialValue);
	this->m_editSlide9.SetWindowTextW(s);

	this->m_slide10.SetRange(0, 10, TRUE);
	this->m_slide10.SetPos(initialValue);
	this->m_editSlide10.SetWindowTextW(s);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctumor2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctumor2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CDC* pdc = this->GetDC();

		CRect rc;
		CRect rcClient;

		this->GetClientRect(&rcClient);
		rc.left = rcClient.right - 244;
		rc.bottom = 34;

		pdc->FillSolidRect(&rc, clrGreen1);
		this->ReleaseDC(pdc);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctumor2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Ctumor2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CString s;
	if (pScrollBar)
	{
		int iResult = 0;
		int iValue = 0;

		iValue = this->m_slide2.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_clump_thickness, iValue);
		this->m_editSlide2.SetWindowTextW(s);

		iValue = this->m_slide15.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_u_cell_size, iValue);
		this->m_editSlide15.SetWindowTextW(s);

		iValue = this->m_slide16.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_u_cell_shape, iValue);
		this->m_editSlide16.SetWindowTextW(s);

		iValue = this->m_slide13.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_marg_adhesion, iValue);
		this->m_editSlide13.SetWindowTextW(s);

		iValue = this->m_slide14.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_Ep_cell_size, iValue);
		this->m_editSlide14.SetWindowTextW(s);

		iValue = this->m_slide11.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_Bare_nuclei, iValue);
		this->m_editSlide11.SetWindowTextW(s);

		iValue = this->m_slide12.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_Bland_Chromatin, iValue);
		this->m_editSlide12.SetWindowTextW(s);

		iValue = this->m_slide9.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_Normal_Nucleoli, iValue);
		this->m_editSlide9.SetWindowTextW(s);

		iValue = this->m_slide10.GetPos();
		s.Format(_T("%d"), iValue);
		iResult = ::tmAISystem_SetValue(1, INPUT_Mitosis, iValue);
		this->m_editSlide10.SetWindowTextW(s);

		iResult = ::tmAISystem_Execute(1);

		double dResultBenign = 0;
		double dResultMalig = 0;

		iResult = ::tmAISystem_GetSystemOutputValue(1, OUTPUT_Benign, &dResultBenign);
		iResult = ::tmAISystem_GetSystemOutputValue(1, OUTPUT_Malignant, &dResultMalig);

		CDC* pdc = this->GetDC();
		pdc->SetBkMode(TRANSPARENT);
		CRect rc;
		CRect rcClient;
		this->GetClientRect(&rcClient);
		rc.CopyRect(&rcClient);
		rc.left = rcClient.right - 244;
		rc.bottom = 34;

		if (dResultBenign > dResultMalig)
		{
			pdc->FillSolidRect(&rc, clrGreen1);
			pdc->DrawText(L"Tumor class: likely BENIGN", &rc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
		}
		else
		{
			pdc->FillSolidRect(&rc, clrRed1);
			pdc->DrawText(L"Tumor class: likely MALIGNANT", &rc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
		}
		this->ReleaseDC(pdc);
	}
	UpdateData(FALSE);

}

void Ctumor2Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void Ctumor2Dlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
