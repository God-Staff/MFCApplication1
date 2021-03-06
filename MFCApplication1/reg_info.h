#ifndef REG_INFO_H
#define REG_INFO_H

#include "datadefine.h"

// reg_info 对话框
class reg_info : public CDialogEx
{
	DECLARE_DYNAMIC(reg_info)

public:
	reg_info(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~reg_info();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//用户同意注册信息的相关事宜
	afx_msg void OnBnClickedCancel ();
	afx_msg void OnBnClickedOk ();
};

#endif
