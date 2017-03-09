// addFriends.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "addFriends.h"
#include "afxdialogex.h"


// addFriends 对话框

IMPLEMENT_DYNAMIC(addFriends, CDialog)

addFriends::addFriends(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

addFriends::~addFriends()
{
}

void addFriends::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL addFriends::OnInitDialog ()
{
	CDialog::OnInitDialog();

	return TRUE;
}



BEGIN_MESSAGE_MAP(addFriends, CDialog)
	ON_EN_KILLFOCUS (IDC_EDIT1, &addFriends::OnEnKillfocusEdit1)
	ON_BN_CLICKED (IDOK, &addFriends::OnBnClickedOk)
END_MESSAGE_MAP()


// addFriends 消息处理程序


void addFriends::OnEnKillfocusEdit1 ()
{
	//用户名输入框失去焦点时，检查用户名的合法性
	((CEdit*)GetDlgItem (IDC_EDIT1))->GetWindowText (user_name);

	//
	if (true)
	{

	}
	else
	{
		((CEdit*)GetDlgItem (IDC_EDIT1))->SetWindowText (L"检查账号信息");
	}

}


void addFriends::OnBnClickedOk ()
{
	// 账号存在，验证信息的正确性（MD5）

}
