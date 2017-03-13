#ifndef DO_REF_H
#define DO_REF_H

#include "datadefine.h"

// do_ref 对话框

class do_ref : public CDialogEx
{
	DECLARE_DYNAMIC(do_ref)

public:
	do_ref(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~do_ref();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog ();
	
	DECLARE_MESSAGE_MAP()

	CEdit* edit1;
	CEdit* edit2;
	CEdit* edit3;
	CEdit* edit4;
	CEdit* edit5;
	CEdit* edit6;
	CEdit* edit7;
	CEdit* edit8;

	CComboBox* Box1;
	CComboBox* Box2;

public:
	afx_msg void OnBnClickedButton2 ();
	afx_msg void OnBnClickedButton1 ();
	afx_msg void OnCbnSelchangeCombo1 ();
};

#endif // DO_REF_H

