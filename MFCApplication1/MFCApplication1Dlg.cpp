
// MFCApplication1Dlg.cpp : 实现文件
//
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "mytab.h"
#include "reg.h"
#include "FriendShared.h"
#include "login_all.pb.h"
#include "datadefine.h"
#include "client.hpp"
#include "utility.cpp"

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

	////初始化网络连接
	//try
	//{
	//	asio::io_service io_service1;
	//	io_service = std::move (&io_service1);

	//	asio::ip::tcp::socket s1 (io_service1);
	//	s = std::move (&s1);
	//	asio::ip::tcp::resolver resolver1 (io_service1);
	//	reslover = std::move (&resolver1);
	//	asio::connect (s1, resolver1.resolve ({ "127.0.0.1","9999" }));
	//}
	//catch (std::exception& e)
	//{
	//	std::cerr << "Exception: " << e.what () << "\n";
	//}


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
	//edit1->SetWindowText (L"用户名");
	edit1->SetFocus ();
	edit1->SetCueBanner (L"用户名", TRUE);

	edit2 = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit2->SetLimitText (16);
	//edit2->SetFocus ();
	edit2->SetCueBanner (L"密码", TRUE);
	//edit2->SetWindowText (L"密码");

	edit3 = (CEdit*)GetDlgItem (IDC_EDIT13);
	edit3->SetLimitText (6);
	//edit3->SetWindowText (L"验证码");

	qiuwanli::user Login_ip;
	Login_ip.set_user_id ("1234567");
	Login_ip.set_user_name ("xiaoqiang");
		
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Get PC UUID
std::string CMFCApplication1Dlg::getUuid ()
{
	std::string uuidPC{};
	/*uuidxx::uuid uu= uuidxx::uuid::Generate ();
	uuidPC = uu.ToString (true).c_str ();
	std::cout << "UUID:" << uuidPC << std::endl;*/
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
	//edit2->SetPasswordChar (NULL);
	edit2->GetWindowText (User_Password);
	//dd->GetWindowTextW (User_Password);
	//edit2->SetPasswordChar ('*');
	//edit2->GetWindowText (User_Password);
	edit3->GetWindowText(User_Code);
	
	//验证结果,可以使用枚举类型
	size_t CheckResult=0;	

	try
	{
		qiuwanli::user userlogin;
		userlogin.set_login_code ("we");
		userlogin.set_user_id ("123");
		userlogin.set_user_client_uuid ("s23");
		userlogin.set_user_password_md5 ("415");
		userlogin.set_user_type ("345");

		//将对象序列化到文件流
		std::fstream output ("login", std::ios::out | std::ios::trunc | std::ios::binary);
		if (!userlogin.SerializeToOstream (&output)) {
			std::cerr << "Failed to write address book." << std::endl;
		}
		//userlogin.SerializePartialToOstream(&output);
		output.close ();

		asio::io_service io;
		//::sendfile ("login");
		try { 
			qiuwanli::sender (io, "127.0.0.1", 9999, "./login"); 
}
		catch (std::exception& err) {
			std::cerr << err.what () << "\n";
		}

		//send Data
		//std::cout << "Enter message: ";
		//char request[max_length];
		//CString  req;
		//edit1->GetWindowText (req);
		////request = req.ToString().c_str ();
		////std::cin.getline (request, max_length);
		//size_t request_length = req.StringLength (req);
		//asio::write (s, asio::buffer (req, request_length));

		////Get Data
		//char reply[max_length];
		//size_t reply_length = asio::read (s,
		//	asio::buffer (reply, request_length));
		//std::cout << "Reply is: ";
		//std::cout.write (reply, reply_length);
		//std::cout << "\n";

	}
	catch (const std::exception& e)
	{
		std::cout << "ERROE:" << e.what () << std::endl;
	}

	//user_login->set_user_id ("");
	//user_login->set_user_name ("");
	//user_login->set_user_password_md5 ("");
	//user_login->set_login_code ("");
	//user_login->set_user_client_uuid ("");

	//try{
	//	using namespace std; // For atoi.
	//	const char* host = "127.0.0.1";
	//	const char* port = "9999";
	//	int thread_count =  (4);
	//	size_t block_size =  (8);
	//	size_t session_count = (4);
	//	int timeout = (30);

	//	asio::io_service ios;

	//	asio::ip::tcp::resolver r (ios);
	//	asio::ip::tcp::resolver::iterator iter =
	//		r.resolve (asio::ip::tcp::resolver::query (host, port));

	//	client c (ios, iter, block_size, session_count, timeout);

	//	std::list<asio::thread*> threads;
	//	while (--thread_count > 0)
	//	{
	//		asio::thread* new_thread = new asio::thread (
	//			boost::bind (&asio::io_service::run, &ios));
	//		threads.push_back (new_thread);
	//	}

	//	ios.run ();

	//	while (!threads.empty ())
	//	{
	//		threads.front ()->join ();
	//		delete threads.front ();
	//		threads.pop_front ();
	//	}
	//}	catch (std::exception& e)	{
	//	std::cerr << "Exception: " << e.what () << "\n";
	//}


	std::wstring str_user = L"root";
	std::wstring str_password = L"root";
	std::wstring str_code = L"1234";
	//若用户ID相同则...
	if (!str_user.compare (User_ID.GetString()))
	{
		CheckResult = 2;
	}
	else if (str_password.compare(User_Password.GetString ()))
	{
		CheckResult = 4;
	}
	else if (str_code.compare (User_Code.GetString ()))
	{
		CheckResult = 8;
	}


	//send Data
	//char request[max_length]="get Login_User:userid";
	//std::cin.getline (request, max_length);
	//size_t request_length = std::strlen (request);
	//asio::write (s, asio::buffer (request, request_length));

	/************************************************************************/
	/* CODE         //一系列登录验证                                        */
	/************************************************************************/


	//成功验证，跳转到网盘对话框

	if (CheckResult==2)
	{
		//密码正确，进入网盘
		Main_UI *tt = new Main_UI ();
		tt->Create (IDD_MFCAPPLICATION1_DIALOG4, this);
		tt->ShowWindow (SW_SHOW);

		/*mytab *tt = new mytab ();
		tt->Create (IDD_FORMVIEW, this);
		tt->ShowWindow (SW_SHOW);
		tt->UpdateWindow ();*/
	}
	else	//验证失败
	{
		//尽享相应的数据清理
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
		//更新验证码图片
		// TODO
	}

	// TODO: 在此添加控件通知处理程序代码
	// CDialogEx::OnOK ();
}


void CMFCApplication1Dlg::ListPeople (const qiuwanli::user& user_file)
{
	//for (int i = 0; i < user_file.size; i++)
	//{
	//	const tutorial::Person& person = address_book.person (i);

	//	cout << "Person ID: " << person.id () << endl;
	//	cout << "  Name: " << person.name () << endl;
	//	if (person.has_email ()) {
	//		cout << "  E-mail address: " << person.email () << endl;
	//	}

	//	for (int j = 0; j < person.phone_size (); j++) {
	//		const tutorial::Person::PhoneNumber& phone_number = person.phones (j);

	//		switch (phone_number.type ()) {
	//		case tutorial::Person::MOBILE:
	//			cout << "  Mobile phone #: ";
	//			break;
	//		case tutorial::Person::HOME:
	//			cout << "  Home phone #: ";
	//			break;
	//		case tutorial::Person::WORK:
	//			cout << "  Work phone #: ";
	//			break;
	//		}
	//		cout << phone_number.number () << endl;
	//	}
	//}
}


void CMFCApplication1Dlg::OnBnClickedCancel ()
{
	//GetDlgItem (IDC_EDIT2);
	reg *tt = new reg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG1, this);
	tt->ShowWindow (SW_SHOW);
	
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel ();
}

//当用户输入完成密码时，检查用户名的正确性，并从数据库中核对用户是否存在
void CMFCApplication1Dlg::OnKillfocusEdit1 ()
{
	//TODO:在此添加控件通知处理程序代码
	try
	{
		qiuwanli::user userlogin;
		userlogin.set_login_code ("we");
		userlogin.set_user_id ("123");
		userlogin.set_user_client_uuid ("s23");
		userlogin.set_user_password_md5 ("415");
		userlogin.set_user_type ("345");
		
		//将对象序列化到文件流
		std::fstream output ("login", std::ios::out | std::ios::trunc | std::ios::binary);
		if (!userlogin.SerializeToOstream (&output)) {
			std::cerr << "Failed to write address book." << std::endl;
		}

		//qiuwanli::sendfile ("login");
		//sender (*io_service, "127.0.0.1", 9999, "login");

		//send Data
		//std::cout << "Enter message: ";
		//char request[max_length];
		//CString  req;
		//edit1->GetWindowText (req);
		////request = req.ToString().c_str ();
		////std::cin.getline (request, max_length);
		//size_t request_length = req.StringLength (req);
		//asio::write (s, asio::buffer (req, request_length));

		////Get Data
		//char reply[max_length];
		//size_t reply_length = asio::read (s,
		//	asio::buffer (reply, request_length));
		//std::cout << "Reply is: ";
		//std::cout.write (reply, reply_length);
		//std::cout << "\n";

	}
	catch (const std::exception& e)
	{
		std::cout << "ERROE:" << e.what () << std::endl;
	}
}

//刷新验证码
void CMFCApplication1Dlg::OnStnClickedStaticPic ()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetDlgItem (IDC_EDIT2);
	//mytab *tt = new mytab ();
	//tt->Create (IDD_FORMVIEW, this);
	//tt->ShowWindow (SW_SHOW);
	//tt->UpdateWindow ();

}


void CAboutDlg::OnBnClickedOk ()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK ();
}
