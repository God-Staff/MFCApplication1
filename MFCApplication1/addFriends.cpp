// addFriends.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "addFriends.h"
#include "afxdialogex.h"


// addFriends �Ի���

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


// addFriends ��Ϣ�������


void addFriends::OnEnKillfocusEdit1 ()
{
	//�û��������ʧȥ����ʱ������û����ĺϷ���
	((CEdit*)GetDlgItem (IDC_EDIT1))->GetWindowText (user_name);

	//
	if (true)
	{

	}
	else
	{
		((CEdit*)GetDlgItem (IDC_EDIT1))->SetWindowText (L"����˺���Ϣ");
	}

}


void addFriends::OnBnClickedOk ()
{
	// �˺Ŵ��ڣ���֤��Ϣ����ȷ�ԣ�MD5��

}
