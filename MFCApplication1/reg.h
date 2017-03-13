#ifndef REG_H
#define REG_H

#include "datadefine.h"

// reg 对话框
class reg : public CDialogEx
{
	DECLARE_DYNAMIC(reg)

public:
	reg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~reg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG1 };
#endif

protected:
	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	CEdit* edit1;
	CEdit* edit2;
	CEdit* edit3;
	CEdit* edit4;
	CEdit* edit5;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel ();
	afx_msg void OnBnClickedOk ();
	afx_msg void OnBnClickedCancel2 ();
};

#endif // REG_H
