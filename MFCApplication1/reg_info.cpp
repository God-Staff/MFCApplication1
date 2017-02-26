// reg_info.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "reg_info.h"
#include "afxdialogex.h"
#include "do_ref.h"


// reg_info 对话框

IMPLEMENT_DYNAMIC(reg_info, CDialogEx)

reg_info::reg_info(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG2, pParent)
{

}

reg_info::~reg_info()
{
}

void reg_info::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(reg_info, CDialogEx)
	ON_BN_CLICKED (IDCANCEL, &reg_info::OnBnClickedCancel)
	ON_BN_CLICKED (IDOK, &reg_info::OnBnClickedOk)
END_MESSAGE_MAP()


// reg_info 消息处理程序


//转到信息填写对话框
void reg_info::OnBnClickedCancel ()
{
	do_ref *tt = new do_ref ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG3, this);
	tt->ShowWindow (SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel ();
}


//返回登陆
void reg_info::OnBnClickedOk ()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK ();
}
