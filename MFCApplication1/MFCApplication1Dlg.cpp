
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "mytab.h"
#include "reg.h"
#include "FriendShared.h"
#include "login_all.pb.h"


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

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

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
	//edit1->SetWindowText (L"�û���");
	edit1->SetFocus ();
	edit1->SetCueBanner (L"�û���", TRUE);

	edit2 = (CEdit*)GetDlgItem (IDC_EDIT12);
	edit2->SetLimitText (16);
	//edit2->SetFocus ();
	edit2->SetCueBanner (L"����", TRUE);
	//edit2->SetWindowText (L"����");

	edit3 = (CEdit*)GetDlgItem (IDC_EDIT13);
	edit3->SetLimitText (6);
	//edit3->SetWindowText (L"��֤��");

	qiuwanli::user Login_ip;
	Login_ip.set_user_id ("1234567");
	Login_ip.set_user_name ("xiaoqiang");
		
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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



//�û���½
void CMFCApplication1Dlg::OnBnClickedOk ()
{
	//��ȡ�ı�
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
	
	//��֤���,����ʹ��ö������
	unsigned int CheckResult=0;			

	std::wstring str_user = L"root";
	std::wstring str_password = L"root";
	std::wstring str_code = L"1234";
	//���û�ID��ͬ��...
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

	/************************************************************************/
	/* CODE         //һϵ�е�¼��֤                                        */
	/************************************************************************/


	//�ɹ���֤����ת�����̶Ի���


	if (CheckResult==2)
	{
		//������ȷ����������
		Main_UI *tt = new Main_UI ();
		tt->Create (IDD_MFCAPPLICATION1_DIALOG4, this);
		tt->ShowWindow (SW_SHOW);

		/*mytab *tt = new mytab ();
		tt->Create (IDD_FORMVIEW, this);
		tt->ShowWindow (SW_SHOW);
		tt->UpdateWindow ();*/
	}
	else	//��֤ʧ��
	{
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
		//������֤��ͼƬ
		// TODO
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// CDialogEx::OnOK ();
}


void CMFCApplication1Dlg::OnBnClickedCancel ()
{
	//GetDlgItem (IDC_EDIT2);
	reg *tt = new reg ();
	tt->Create (IDD_MFCAPPLICATION1_DIALOG1, this);
	tt->ShowWindow (SW_SHOW);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel ();
}

//���û������������ʱ������û�������ȷ�ԣ��������ݿ��к˶��û��Ƿ����
void CMFCApplication1Dlg::OnKillfocusEdit1 ()
{
	//TODO:�ڴ���ӿؼ�֪ͨ����������
}

//ˢ����֤��
void CMFCApplication1Dlg::OnStnClickedStaticPic ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//GetDlgItem (IDC_EDIT2);
	//mytab *tt = new mytab ();
	//tt->Create (IDD_FORMVIEW, this);
	//tt->ShowWindow (SW_SHOW);
	//tt->UpdateWindow ();

}


void CAboutDlg::OnBnClickedOk ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK ();
}
