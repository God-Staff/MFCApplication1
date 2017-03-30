
// MFCApplication1Dlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框

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


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//GetDlgItem (IDD_MFCAPPLICATION1_DIALOG)->SetIcon (m_hIcon, TRUE);

	
	CStatic* pWnd = (CStatic*)GetDlgItem (IDC_STATIC_LOGIN); // 得到 Picture Control 句柄  
	CImage image;
	image.Load (_T ("res\\FileType\\MusicType.png"));
	HBITMAP hBmp = image.Detach ();
	pWnd->SetBitmap (hBmp);

	//初始化时，将控件指针保存，便于操作
	//并作一些初始化设置
	edit1 = (CEdit*)GetDlgItem (IDC_EDIT11);
	edit1->SetLimitText (20);
	edit1->SetFocus ();
	edit1->SetCueBanner (L"用户名", TRUE);

	edit2 = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit2->SetLimitText (16);
	edit2->SetCueBanner (L"密码", TRUE);

	edit3 = (CEdit*)GetDlgItem (IDC_EDIT13);
	edit3->SetLimitText (6);
	edit2->SetCueBanner (L"验证码", TRUE);

	//boost::asio::io_service io;
	//unsigned int seconds = 15;  // 设定超时时间，客户端必须在这个时间内周期性地调用 reset函数
	//HeartBeatService t(&io, seconds);
	////调用 io_service::run， 定时器开始计时
	//auto future = boost::async(boost::launch::async, [&]{io.run();});  // better

	//boost::thread io_thread (boost::bind (&boost::asio::io_service::run, &io));

	//boost::this_thread::sleep_for (boost::chrono::seconds (15));   // 再次等待超时
	////EXPECT_TRUE (t.getFlag ());  // 已经超时，并且设置了标志位为true
	////testing::internal::CaptureStderr ();  // 超时了会有打印信息，捕获打印
	//io.stop ();
	//io_thread.join ();

	//if (t.getFlag())
	//{
	//	MessageBox (L"FFFFFFF");
	//}else{
	//	MessageBox (L"XXXXXXX");
	//}
	//	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
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


//用户登陆
void CMFCApplication1Dlg::OnBnClickedOk ()
{
	//获取文本
	CString User_ID;
	CString User_Password;
	CString User_Code;

	CEdit* dd = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit1->GetWindowText(User_ID);
	edit2->GetWindowText (User_Password);
	edit3->GetWindowText(User_Code);
	
	//验证结果,可以使用枚举类型
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

	//将对象序列化到文件流
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

	//接收服务端送来的信息


	/************************************************************************/
	/* CODE         //一系列登录验证                                        */
	/************************************************************************/


	//成功验证，跳转到网盘对话框
	CheckResult = 2;
	if (CheckResult==2)
	{
		//密码正确，进入网盘
		Main_UI *tt1 = new Main_UI ();
		tt1->Create (IDD_MFCAPPLICATION1_DIALOG4, this);
		tt1->ShowWindow (SW_SHOW);

		CMFCApplication1Dlg::ShowWindow (FALSE);
	} else	{//验证失败
		//共享相应的数据清理
		if (CheckResult == 4)//账号错误
		{
			edit1->SetWindowText (L"用户名错误");
			edit1->SetFocus ();
			edit2->SetWindowText (L"");
			edit3->SetWindowText (L"");
		}
		else if(CheckResult == 8)//密码错误
		{
			edit2->SetWindowText (L"密码错误");
			edit2->SetFocus ();
			edit3->SetWindowText (L"");
		}
		else if(CheckResult == 16)//验证码错误
		{
			edit3->SetWindowText (L"");
			edit3->SetFocus ();
		}
		//更新验证码图片，随机生成随机数
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

//当用户输入完成密码时，检查用户名的正确性，并从数据库中核对用户是否存在
void CMFCApplication1Dlg::OnKillfocusEdit1 ()
{
	//TODO:在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK ();
}
