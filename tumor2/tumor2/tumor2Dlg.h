
// tumor2Dlg.h : header file
//

#pragma once


// Ctumor2Dlg dialog
class Ctumor2Dlg : public CDialogEx
{
// Construction
public:
	Ctumor2Dlg(CWnd* pParent = NULL);	// standard constructor

	CSliderCtrl m_slide2;
	CSliderCtrl m_slide15;
	CSliderCtrl m_slide16;
	CSliderCtrl m_slide13;
	CSliderCtrl m_slide14;
	CSliderCtrl m_slide11;
	CSliderCtrl m_slide12;
	CSliderCtrl m_slide9;
	CSliderCtrl m_slide10;

	CSliderCtrl m_editSlide2;
	CSliderCtrl m_editSlide15;
	CSliderCtrl m_editSlide16;
	CSliderCtrl m_editSlide13;
	CSliderCtrl m_editSlide14;
	CSliderCtrl m_editSlide11;
	CSliderCtrl m_editSlide12;
	CSliderCtrl m_editSlide9;
	CSliderCtrl m_editSlide10;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUMOR2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void Ctumor2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar * pScrollBar);
	void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
};
