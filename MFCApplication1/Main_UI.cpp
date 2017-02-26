// Main_UI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Main_UI.h"
#include "afxdialogex.h"


// Main_UI �Ի���

IMPLEMENT_DYNAMIC(Main_UI, CDialogEx)

Main_UI::Main_UI(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG4, pParent)
{

}

Main_UI::~Main_UI()
{
}

//��ʼ������
BOOL Main_UI::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	//��ʼ���ؼ�
	allfiles = new AllFiles ();
	allfiles->Create (IDD_FORMVIEW4, this);
	allfiles->ShowWindow (SW_SHOW);

	filedownlog = new FileDownLog ();
	filedownlog->Create (IDD_FORMVIEW1, this);
	filedownlog->ShowWindow (FALSE);

	mytabui		= new mytab ();
	mytabui->Create (IDD_FORMVIEW, this);
	mytabui->ShowWindow (FALSE);

	mysetting	= new ConfigSet ();
	mysetting->Create (IDD_FORMVIEW3, this);
	mysetting->ShowWindow (FALSE);

	fileshared	= new FriendShared ();
	fileshared->Create (IDD_FORMVIEW2);
	fileshared->ShowWindow (FALSE);

	/*GROUP* group = new GROUP ();
	group=(GROUP*)GetDlgItem(IDC_STATIC_GROUP1);*/
	//
	change_table= 1;

	return TRUE;
}

void Main_UI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Main_UI, CDialogEx)
	ON_STN_CLICKED (IDC_STATIC_pic_21, &Main_UI::OnStnClickedStaticpic21)
	ON_STN_CLICKED (IDC_STATIC_pic_23, &Main_UI::OnStnClickedStaticpic23)
	ON_STN_CLICKED (IDC_STATIC_pic_22, &Main_UI::OnStnClickedStaticpic22)
	ON_STN_CLICKED (IDC_STATIC_pic_24, &Main_UI::OnStnClickedStaticpic24)
	ON_STN_CLICKED (IDC_STATIC_pic_25, &Main_UI::OnStnClickedStaticpic25)
END_MESSAGE_MAP()


// Main_UI ��Ϣ�������

void Main_UI::OnStnClickedStaticpic21 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	swithTable (1);

	UpdateWindow ();
}



void Main_UI::OnStnClickedStaticpic22 ()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	swithTable (2);
	//MessageBox (L"sdf");
	UpdateWindow ();
}


void Main_UI::OnStnClickedStaticpic23 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	swithTable (3);
	UpdateWindow ();
}


void Main_UI::OnStnClickedStaticpic24 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	swithTable (4);
	UpdateWindow ();
}


void Main_UI::OnStnClickedStaticpic25 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	swithTable (5);

	UpdateWindow ();

	//���н�������ݵĸ���
	//TODO
}


//�л�����Ӧ�Ľ���
void Main_UI::swithTable (int i)
{
	if (i != change_table)
	{
		//��ʾ�� i ������
		switch (i)
		{
		case 1:
			allfiles->ShowWindow (SW_SHOW);
			break;
		case 2:
			mytabui->ShowWindow (SW_SHOW);
			break;
		case 3:
			filedownlog->ShowWindow (SW_SHOW);
			break;
		case 4:
			fileshared->ShowWindow (SW_SHOW);
			break;
		case 5:
			mysetting->ShowWindow (SW_SHOW);
			break;
		default:
			break;
		}

		//����֮ǰ�Ľ���
		switch (change_table)
		{
		case 1:
			allfiles->ShowWindow (FALSE);
			break;
		case 2:
			mytabui->ShowWindow (FALSE);
			break;
		case 3:
			filedownlog->ShowWindow (FALSE);
			break;
		case 4:
			fileshared->ShowWindow (FALSE);
			break;
		case 5:
			mysetting->ShowWindow (FALSE);
			break;
		default:
			break;
		}
	}
	change_table = i;

}
