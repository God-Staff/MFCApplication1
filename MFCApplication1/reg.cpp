// reg.cpp : ʵ���ļ�
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

// reg �Ի���
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
	ON_EN_KILLFOCUS (IDC_EDIT23, &reg::OnEnKillfocusEdit23)
END_MESSAGE_MAP()


// reg ��Ϣ�������

//ע��
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
		//���������л����ļ���
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
	
	//ע��ɹ�

	//�����´��ڣ����л�
	reg_info *tt = new reg_info ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG2, this);
	tt->ShowWindow (SW_SHOW);

	reg::ShowWindow (FALSE);

	//ע��ʧ��
	//��������
}


//ȡ��
void reg::OnBnClickedOk ()
{
	//���ɵ�½����,��ɴ������л�
	CMFCApplication1Dlg *tt = new CMFCApplication1Dlg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG, this);
	tt->ShowWindow (SW_SHOW);
	reg::ShowWindow (FALSE);
}

//���»�ȡ��֤��
void reg::OnBnClickedCancel2 ()
{
	//�������6λ��֤�룬������ͨ����������ת��ΪLPCTSTR��ʽ
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

//��֤������ȷ��
void reg::OnEnKillfocusEdit23 ()
{
	CString ps1,ps2;
	edit2->GetWindowText (ps1);
	edit3->GetWindowText (ps2);
	if (!ps1.Compare(ps2))
	{
		edit2->SetWindowText (L"");
		edit2->SetCueBanner (L"ǰ���������벻ͬ", TRUE);
		edit3->SetWindowText (L"");
		edit3->SetCueBanner (L"��������������", TRUE);
	}
}
