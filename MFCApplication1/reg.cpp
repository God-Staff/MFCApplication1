// reg.cpp : 实现文件
//
#include "stdafx.h"
#include "MFCApplication1.h"
#include "reg.h"
#include "afxdialogex.h"
#include "reg_info.h"
#include "resource.h"
#include "login_all.pb.h"
#include "string"
#include "utility.hpp"
#include "MFCApplication1Dlg.h"

#include <random>
#include <sstream>

// reg 对话框
IMPLEMENT_DYNAMIC(reg, CDialogEx)

reg::reg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG1, pParent)
{}

reg::~reg(){}

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
	ON_EN_KILLFOCUS (IDC_EDIT23, &reg::OnEnKillfocusEdit23)
END_MESSAGE_MAP()


// reg 消息处理程序

//注册
void reg::OnBnClickedCancel ()
{
	qiuwanli::userreg userreg;
	CString User;
	std::string s;
	edit1->GetWindowText (User);
	s = CT2A (User);
	userreg.set_user_name (s);
	edit2->GetWindowText (User);
	s = CT2A (User);
	userreg.set_user_password_md5 (s);
	edit4->GetWindowText (User);
	s = CT2A (User);
	userreg.set_user_phone (s);
	edit5->GetWindowText (User);
	s = CT2A (User);
	userreg.set_reg_code (s);

	try {
		//将对象序列化到文件流
		std::fstream output ("userreg", std::ios::out | std::ios::trunc | std::ios::binary);
		if (!userreg.SerializeToOstream (&output)) {
			std::cerr << "Failed to write address book." << std::endl;
		}
		output.close ();

		asio::io_service io;
		try {
			qiuwanli::utilty s;
			s.sender (io, "127.0.0.1", 9999, "userreg", "996\0");
		}
		catch (std::exception& err) {
			std::cerr << err.what () << "\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROE:" << e.what () << std::endl;
	}
	
	//注册成功

	//生成新窗口，并切换
	reg_info *tt = new reg_info ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG2, this);
	tt->ShowWindow (SW_SHOW);

	reg::ShowWindow (FALSE);

	//注册失败
	//错误类型
}


//取消
void reg::OnBnClickedOk ()
{
	//生成登陆窗口,完成窗体间的切换
	CMFCApplication1Dlg *tt = new CMFCApplication1Dlg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG, this);
	tt->ShowWindow (SW_SHOW);
	reg::ShowWindow (FALSE);
}

//重新获取验证码
void reg::OnBnClickedCancel2 ()
{
	//随机生成6位验证码，并将其通过流操作，转化为LPCTSTR格式
	std::random_device rd;
	std::mt19937 gen (rd ());
	std::uniform_int_distribution<> dis (100000, 999999);
	
#ifdef _UNICODE
	std::wostringstream oss;
#else
	ostringstream oss;
#endif

	oss << dis (gen);
	edit5->SetWindowTextW (oss.str ().c_str ());
}

//验证密码正确性
void reg::OnEnKillfocusEdit23 ()
{
	CString ps1,ps2;
	edit2->GetWindowText (ps1);
	edit3->GetWindowText (ps2);
	if (!ps1.Compare(ps2))
	{
		edit2->SetWindowText (L"");
		edit2->SetCueBanner (L"前后两次密码不同", TRUE);
		edit3->SetWindowText (L"");
		edit3->SetCueBanner (L"请重新输入密码", TRUE);
	}
}
