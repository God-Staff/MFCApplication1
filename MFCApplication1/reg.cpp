// reg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "reg.h"
#include "afxdialogex.h"
#include "reg_info.h"
#include "resource.h"


// reg �Ի���

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
	edit1->SetCueBanner (L"�������û���", TRUE);
	edit2 = (CEdit*)GetDlgItem (IDC_EDIT22);
	edit2->SetCueBanner (L"����");
	edit3 = (CEdit*)GetDlgItem (IDC_EDIT23);
	edit3->SetCueBanner (L"�ٴ���������", TRUE);
	edit4 = (CEdit*)GetDlgItem (IDC_EDIT24);
	edit4->SetCueBanner (L"���ڽ�����֤��", TRUE);
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


// reg ��Ϣ�������


void reg::OnBnClickedCancel ()
{
	reg_info *tt = new reg_info ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG2, this);
	tt->ShowWindow (SW_SHOW);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel ();

}


void reg::OnBnClickedOk ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK ();

}

//���»�ȡ��֤��
void reg::OnBnClickedCancel2 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
