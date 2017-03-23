// do_ref.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "do_ref.h"
#include "afxdialogex.h"
#include "city.hpp"
#include "reg_info.h"
#include "sstream"

// do_ref 对话框

IMPLEMENT_DYNAMIC(do_ref, CDialogEx)

do_ref::do_ref(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG3, pParent)
{

}

do_ref::~do_ref()
{
}

void do_ref::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BOOL  do_ref::OnInitDialog ()
{
	//绑定对象
	Box1 = (CComboBox*)GetDlgItem (IDC_COMBO1);
	Box2 = (CComboBox*)GetDlgItem (IDC_COMBO2);
	edit1 = (CEdit*)GetDlgItem (IDC_EDIT31);
	edit2 = (CEdit*)GetDlgItem (IDC_EDIT32);
	edit3 = (CEdit*)GetDlgItem (IDC_EDIT33);
	edit4 = (CEdit*)GetDlgItem (IDC_EDIT34);
	edit5 = (CEdit*)GetDlgItem (IDC_EDIT35);
	edit6 = (CEdit*)GetDlgItem (IDC_EDIT36);
	edit7 = (CEdit*)GetDlgItem (IDC_EDIT37);
	edit8 = (CEdit*)GetDlgItem (IDC_EDIT38);

	//用户名不可更改，
	qiuwanli::userreg user;
	
	std::fstream input ("userreg", std::ios::in | std::ios::binary);
	user.ParseFromIstream (&input);
	std::string str = user.user_name ();

	//将string to wstring
	std::wstring wname (str.begin (), str.end ());
	edit1->SetWindowText (const_cast<wchar_t*>(wname.c_str ()));
	str = user.user_phone ();
	std::wstring wname1 (str.begin (), str.end ());
	edit3->SetWindowText (const_cast<wchar_t*>(wname1.c_str ()));
	
	//设置控件不可更改
	edit1->EnableWindow (FALSE);
	edit3->EnableWindow (FALSE);

	edit2->SetCueBanner (L"真实姓名", TRUE);
	edit3->SetCueBanner (L"用于找回密码", TRUE);
	edit4->SetCueBanner (L"查找好友", TRUE);
	edit5->SetCueBanner (L"查找好友", TRUE);
	edit6->SetCueBanner (L"用于找回密码", TRUE);
	edit7->SetCueBanner (L"用于验证实名信息", TRUE);

	//遍历填充数据 省份//
	for (int i = 0; i < 31; ++i)
	{
		Box1->InsertString (i, city_info[i][0].c_str ());
	}

	//设置ComboBox
	Box2->ShowWindow (FALSE);

	return TRUE;
}

BEGIN_MESSAGE_MAP (do_ref, CDialogEx)
	ON_BN_CLICKED (IDC_BUTTON2, &do_ref::OnBnClickedButton2)
	ON_BN_CLICKED (IDC_BUTTON1, &do_ref::OnBnClickedButton1)
	ON_CBN_SELCHANGE (IDC_COMBO1, &do_ref::OnCbnSelchangeCombo1)
END_MESSAGE_MAP ()


// do_ref 消息处理程序


//取消
void do_ref::OnBnClickedButton2 ()
{
	// TODO: 在此添加控件通知处理程序代码
	//生成登陆窗口,完成窗体间的切换
	reg_info *tt = new reg_info ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG2, this);
	tt->ShowWindow (SW_SHOW);

	CDialogEx::OnOK ();
}


//验证信息
void do_ref::OnBnClickedButton1 ()
{
	qiuwanli::realuser real;
	CString User;
	edit1->GetWindowText (User);
	real.set_user_id (CT2A (User));
	edit2->GetWindowText (User);
	real.set_user_name_real (CT2A (User));
	edit3->GetWindowText (User);
	real.set_user_phone (CT2A (User));
	edit4->GetWindowText (User);
	real.set_user_qq (CT2A (User));
	edit5->GetWindowText (User);
	real.set_user_mirchat (CT2A (User));
	edit6->GetWindowText (User);
	real.set_user_email (CT2A (User));
	edit7->GetWindowText (User);
	real.set_user_idcard (CT2A (User));
	edit8->GetWindowText (User);
	real.set_user_address (CT2A (User));

	std::wstring liveadress;
	int i = Box1->GetCurSel ();
	int j = Box2->GetCurSel ();
	liveadress=city_info[i][0];
	liveadress += city_info[i][j];
	//将wstring to string
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string u8str = conv.to_bytes (liveadress);

	real.set_user_live_address (u8str);
	auto BriDate= (CDateTimeCtrl*)GetDlgItem (IDC_DATETIMEPICKER1);
	//BriDate->GetCurrentGestureInfo ();

	try {
		//将对象序列化到文件流
		std::fstream output ("userreal", std::ios::out | std::ios::trunc | std::ios::binary);
		if (!real.SerializeToOstream (&output)) {
			std::cerr << "Failed to write address book." << std::endl;
		}
		output.close ();

		boost::asio::io_service io;
		try {
			//qiuwanli::utilty sss;
			//sss.sender (io, "127.0.0.1", 9999, "userreal", "998");
		}
		catch (std::exception& err) {
			std::cerr << err.what () << "\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROE:" << e.what () << std::endl;
	}


	//将数据发到Server端，并跳到登录界面
	CMFCApplication1Dlg *tt = new CMFCApplication1Dlg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG, this);
	tt->ShowWindow (SW_SHOW);

	CDialogEx::OnOK ();
}

void do_ref::OnCbnSelchangeCombo1 ()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Box2->IsWindowVisible())
	{
		Box2->ShowWindow (TRUE);
	}

	//清空 ComBoBox
	Box2->ResetContent ();

	int ii = Box1->GetCurSel ();
	//int ii = Box1->GetEditSel ();
	std::cout << ii << std::endl;
	//遍历填充数据 省份//
	for (int i = 0; i < city_num[ii]; ++i)
	{
		Box2->InsertString (i, city_info[ii][i].c_str ());
	}
	//Box2->UpdateWindow ();
}
