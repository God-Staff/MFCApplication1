// reg_info.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "reg_info.h"
#include "afxdialogex.h"
#include "do_ref.h"


// reg_info �Ի���

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


// reg_info ��Ϣ�������


//ת����Ϣ��д�Ի���
void reg_info::OnBnClickedCancel ()
{
	do_ref *tt = new do_ref ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG3, this);
	tt->ShowWindow (SW_SHOW);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel ();
}


//���ص�½
void reg_info::OnBnClickedOk ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK ();
}
