// reg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "reg.h"
#include "afxdialogex.h"
#include "reg_info.h"
#include "resource.h"


// reg 对话框

IMPLEMENT_DYNAMIC(reg, CDialogEx)

reg::reg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG1, pParent)
{

}

reg::~reg()
{
}

BOOL reg::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	//
	edit1 = (CEdit*)GetDlgItem (IDC_EDIT21);
	edit1->SetLimitText (20);
	edit1->SetCueBanner (L"请输入用户名", TRUE);
	edit2 = (CEdit*)GetDlgItem (IDC_EDIT22);
	edit2->SetCueBanner (L"密码");
	edit3 = (CEdit*)GetDlgItem (IDC_EDIT23);
	edit3->SetCueBanner (L"再次输入密码", TRUE);
	edit4 = (CEdit*)GetDlgItem (IDC_EDIT24);
	edit4->SetCueBanner (L"用于接收验证码", TRUE);
	edit5 = (CEdit*)GetDlgItem (IDC_EDIT25);
	//

	return TRUE;
}

void reg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(reg, CDialogEx)
	ON_BN_CLICKED (IDCANCEL, &reg::OnBnClickedCancel)
	ON_BN_CLICKED (IDOK, &reg::OnBnClickedOk)
	ON_BN_CLICKED (IDCANCEL2, &reg::OnBnClickedCancel2)
END_MESSAGE_MAP()


// reg 消息处理程序


void reg::OnBnClickedCancel ()
{
	reg_info *tt = new reg_info ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG2, this);
	tt->ShowWindow (SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel ();

}


void reg::OnBnClickedOk ()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK ();

}

//重新获取验证码
void reg::OnBnClickedCancel2 ()
{
	// TODO: 在此添加控件通知处理程序代码
}
