
// MFCApplication1Dlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "mytab.h"
#include "reg.h"
#include "FriendShared.h"
#include "MyDataStruct.pb.h"
#include "datadefine.h"
#include "client.hpp"
#include "utility.hpp"
#include "checkNet.hpp"
#include <sstream>
#include <random>
#include <cstring>
#include "Main_UI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk ();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED (IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP (CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND ()
	ON_WM_PAINT ()
	ON_WM_QUERYDRAGICON ()
	ON_BN_CLICKED (IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED (IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_EN_KILLFOCUS (IDC_EDIT11, &CMFCApplication1Dlg::OnKillfocusEdit1)
	ON_STN_CLICKED (IDC_STATIC_PIC, &CMFCApplication1Dlg::OnStnClickedStaticPic)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	getUuid ();
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//GetDlgItem (IDD_MFCAPPLICATION1_DIALOG)->SetIcon (m_hIcon, TRUE);

	
	CStatic* pWnd = (CStatic*)GetDlgItem (IDC_STATIC_LOGIN); // �õ� Picture Control ���  
	CImage image;
	image.Load (_T ("res\\FileType\\MusicType.png"));
	HBITMAP hBmp = image.Detach ();
	pWnd->SetBitmap (hBmp);

	//��ʼ��ʱ�����ؼ�ָ�뱣�棬���ڲ���
	//����һЩ��ʼ������
	edit1 = (CEdit*)GetDlgItem (IDC_EDIT11);
	edit1->SetLimitText (20);
	edit1->SetFocus ();
	edit1->SetCueBanner (L"�û���", TRUE);

	edit2 = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit2->SetLimitText (16);
	edit2->SetCueBanner (L"����", TRUE);

	edit3 = (CEdit*)GetDlgItem (IDC_EDIT13);
	edit3->SetLimitText (6);
	edit2->SetCueBanner (L"��֤��", TRUE);

	//boost::asio::io_service io;
	//unsigned int seconds = 15;  // �趨��ʱʱ�䣬�ͻ��˱��������ʱ���������Եص��� reset����
	//HeartBeatService t(&io, seconds);
	////���� io_service::run�� ��ʱ����ʼ��ʱ
	//auto future = boost::async(boost::launch::async, [&]{io.run();});  // better

	//boost::thread io_thread (boost::bind (&boost::asio::io_service::run, &io));

	//boost::this_thread::sleep_for (boost::chrono::seconds (15));   // �ٴεȴ���ʱ
	////EXPECT_TRUE (t.getFlag ());  // �Ѿ���ʱ�����������˱�־λΪtrue
	////testing::internal::CaptureStderr ();  // ��ʱ�˻��д�ӡ��Ϣ�������ӡ
	//io.stop ();
	//io_thread.join ();

	//if (t.getFlag())
	//{
	//	MessageBox (L"FFFFFFF");
	//}else{
	//	MessageBox (L"XXXXXXX");
	//}
	//	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}else{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�
void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Get PC UUID
std::string CMFCApplication1Dlg::getUuid ()
{
	std::string uuidPC{};
	unsigned long s1, s2;
	char sel='1';
	CString MyCpuid;

	__asm {
		mov eax, 01h
		xor edx, edx
		cpuid
		mov s1,edx
		mov s2,eax
	}

	std::string cpu1= std::to_string (s1) + std::to_string (s2);

	__asm {
		mov eax, 03h
		xor ecx, ecx
		xor edx, edx
		cpuid
		mov s1,edx
		mov s2,ecx
	}
	cpu1 = cpu1+std::to_string (s1) + std::to_string (s2);
	
	MyCpuid = cpu1.c_str();
	MessageBox (MyCpuid);
	return uuidPC;
}


//�û���½
void CMFCApplication1Dlg::OnBnClickedOk ()
{
	//��ȡ�ı�
	CString User_ID;
	CString User_Password;
	CString User_Code;

	CEdit* dd = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit1->GetWindowText(User_ID);
	edit2->GetWindowText (User_Password);
	edit3->GetWindowText(User_Code);
	
	//��֤���,����ʹ��ö������
	size_t CheckResult=0;	
	qiuwanli::Users userlogin;
		
	std::string s = CT2A (User_ID);
	userlogin.set_user_id (s);
	s = CT2A (User_Password);
	userlogin.set_user_password_md5 (s);
	userlogin.set_user_type ("haha");
	s = CT2A (User_Code);
	userlogin.set_login_code (s);
	userlogin.set_user_client_uuid ("123456789012");

	//���������л����ļ���
	std::fstream output ("login", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!userlogin.SerializeToOstream (&output)) {
		std::cerr << "Failed to write address book." << std::endl;
	}
	output.close ();
	
	boost::asio::io_service io_ser;
	try { 
		qiuwanli::utilty s;
		//MessageBox (s.StringToWstring (s.getUuid ()).c_str ());
		//s.sender (io_ser, "127.0.0.1", 9999, "login","1001\0");
}		catch (std::exception& err) {
		std::cerr << err.what () << "\n";
	}

	//���շ������������Ϣ


	/************************************************************************/
	/* CODE         //һϵ�е�¼��֤                                        */
	/************************************************************************/


	//�ɹ���֤����ת�����̶Ի���
	CheckResult = 2;
	if (CheckResult==2)
	{
		//������ȷ����������
		Main_UI *tt1 = new Main_UI ();
		tt1->Create (IDD_MFCAPPLICATION1_DIALOG4, this);
		tt1->ShowWindow (SW_SHOW);

		CMFCApplication1Dlg::ShowWindow (FALSE);
	} else	{//��֤ʧ��
		//������Ӧ����������
		if (CheckResult == 4)//�˺Ŵ���
		{
			edit1->SetWindowText (L"�û�������");
			edit1->SetFocus ();
			edit2->SetWindowText (L"");
			edit3->SetWindowText (L"");
		}
		else if(CheckResult == 8)//�������
		{
			edit2->SetWindowText (L"�������");
			edit2->SetFocus ();
			edit3->SetWindowText (L"");
		}
		else if(CheckResult == 16)//��֤�����
		{
			edit3->SetWindowText (L"");
			edit3->SetFocus ();
		}
		//������֤��ͼƬ��������������
		OnStnClickedStaticPic ();
	}
}

void CMFCApplication1Dlg::OnBnClickedCancel ()
{
	reg *tt = new reg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG1, this);
	tt->ShowWindow (SW_SHOW);

	CMFCApplication1Dlg::ShowWindow (FALSE);
}

//���û������������ʱ������û�������ȷ�ԣ��������ݿ��к˶��û��Ƿ����
void CMFCApplication1Dlg::OnKillfocusEdit1 ()
{
	//TODO:�ڴ���ӿؼ�֪ͨ����������
	try{
		//...
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROE:" << e.what () << std::endl;
	}
}


void CMFCApplication1Dlg::OnStnClickedStaticPic ()
{
	std::random_device rd;
	std::mt19937 gen (rd ());
	std::uniform_int_distribution<> dis (100000, 999999);

#ifdef _UNICODE
	std::wostringstream oss;
#else
	ostringstream oss;
#endif

	oss << dis (gen);
	edit3->SetWindowTextW (oss.str ().c_str ());
}


void CAboutDlg::OnBnClickedOk ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK ();
}
