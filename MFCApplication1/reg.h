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
	//验证用户注册信息，用户名以及密码的有效性
	afx_msg void OnBnClickedCancel ();
	//当用户不想注册时，返回到登录界面
	afx_msg void OnBnClickedOk ();
	//随机生成6位数字代替“重新获取验证码”
	afx_msg void OnBnClickedCancel2 ();
	//当第二次输入密码完成时,验证密码的有效性和一致性
	afx_msg void OnEnKillfocusEdit23 ();
	afx_msg void OnEnKillfocusEdit21 ();
};

#endif // REG_H
