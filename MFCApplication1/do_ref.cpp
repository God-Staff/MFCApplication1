// do_ref.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "do_ref.h"
#include "afxdialogex.h"
#include "city.hpp"
#include "reg_info.h"

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
	//用户名不可更改，
	CString user_name;		//从之前界面传过来的用户名
	edit1 = (CEdit*)GetDlgItem (IDC_EDIT31);
	edit1->SetWindowText (user_name);
	
	
	edit2 = (CEdit*)GetDlgItem (IDC_EDIT32);
	edit2->SetCueBanner (L"真实姓名", TRUE);
	edit3 = (CEdit*)GetDlgItem (IDC_EDIT33);
	edit3->SetCueBanner (L"用于找回密码", TRUE);
	edit4 = (CEdit*)GetDlgItem (IDC_EDIT34);
	edit4->SetCueBanner (L"查找好友", TRUE);
	edit5 = (CEdit*)GetDlgItem (IDC_EDIT35);
	edit5->SetCueBanner (L"查找好友", TRUE);
	edit6 = (CEdit*)GetDlgItem (IDC_EDIT36);
	edit6->SetCueBanner (L"用于找回密码", TRUE);

	edit7 = (CEdit*)GetDlgItem (IDC_EDIT37);
	edit7->SetCueBanner (L"用于验证实名信息", TRUE);
	edit8 = (CEdit*)GetDlgItem (IDC_EDIT38);

	//绑定对象
	Box1 = (CComboBox*)GetDlgItem (IDC_COMBO1);
	Box2 = (CComboBox*)GetDlgItem (IDC_COMBO2);

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
