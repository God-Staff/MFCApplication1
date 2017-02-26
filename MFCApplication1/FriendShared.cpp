// FriendShared.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FriendShared.h"
#include "afxdialogex.h"

// FriendShared �Ի���

IMPLEMENT_DYNAMIC(FriendShared, CDialogEx)

FriendShared::FriendShared(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW2, pParent)
{
}

//���ڴ������ݵĳ�ʼ��
BOOL FriendShared::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();
	
	//��ʼ���б�
	m_ListControl = (CListCtrl*)GetDlgItem (IDC_LIST8);
	DWORD dwStyle = GetWindowLong (m_ListControl->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListControl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz[2][10] = { _T ("�����ǳ�"),_T ("S") };

	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�
	LV_COLUMN lvcolumn;
	CRect rect;
	m_ListControl->GetWindowRect (&rect);
	for (int i = 0; i < 2; i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width () / 2;
		m_ListControl->InsertColumn (i, &lvcolumn);
	}

	//add data
	m_ListControl->InsertItem (0, L"qq");
	m_ListControl->SetItemText (0, 1, L"mima");
	m_ListControl->InsertItem (1, L"qq");
	m_ListControl->SetItemText (1, 1, L"mima");
	m_ListControl->InsertItem (2, L"qq");
	m_ListControl->SetItemText (2, 1, L"mima");

	///////////////////////////////////
	//��ʼ���б�2
	m_ListContro2 = (CListCtrl*)GetDlgItem (IDC_LIST7);
	DWORD dwStyle2 = GetWindowLong (m_ListContro2->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListContro2->m_hWnd, GWL_STYLE, dwStyle2 | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles2 = m_ListContro2->GetExtendedStyle ();
	m_ListContro2->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz2[5][10] = { _T ("�����ǳ�"),_T ("S") ,_T ("S3") ,_T ("S4") ,_T ("S5") };

	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�

	LV_COLUMN lvcolumn2;
	CRect rect2;
	m_ListContro2->GetWindowRect (&rect2);
	for (int i = 0; i < 5; i++)
	{
		lvcolumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn2.fmt = LVCFMT_LEFT;
		lvcolumn2.pszText = rgtsz2[i];
		lvcolumn2.iSubItem = i;
		lvcolumn2.iOrder = i;
		lvcolumn2.cx = rect2.Width () / 5;
		m_ListContro2->InsertColumn (i, &lvcolumn2);
	}

	m_ListContro2->InsertItem (0, L"qq");
	m_ListContro2->SetItemText (0, 1, L"mima");
	m_ListContro2->InsertItem (1, L"qq");
	m_ListContro2->SetItemText (1, 1, L"mima");
	m_ListContro2->InsertItem (2, L"qq");
	m_ListContro2->SetItemText (2, 1, L"mima");

	return TRUE;
}

FriendShared::~FriendShared(){}

void FriendShared::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FriendShared, CDialogEx)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST1, &FriendShared::OnLvnItemchangedList1)
	//ON_NOTIFY (NM_RCLICK, IDC_LIST1, &FriendShared::OnNMRClickList1)
	//ON_NOTIFY (NM_RCLICK, IDC_LIST4, &FriendShared::OnNMRClickList4)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST8, &FriendShared::OnLvnItemchangedList8)
	ON_NOTIFY (NM_RCLICK, IDC_LIST8, &FriendShared::OnNMRClickList8)
	ON_NOTIFY (NM_RCLICK, IDC_LIST7, &FriendShared::OnNMRClickList7)
END_MESSAGE_MAP()


void FriendShared::OnNMRClickList8 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (0); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
	CPoint oPoint; //����һ������ȷ�����λ�õ�λ��
	GetCursorPos (&oPoint); //��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����

	m_ListContro2->SetExtendedStyle (m_ListContro2->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListContro2->GetFirstSelectedItemPosition ();  //��ȡ��ѡ����λ��
	if (sSelectedPos == NULL)
	{
		return;
	}
	//ѡ�е�1����������
	while (sSelectedPos)//��ȡ��ѡ����λ��
	{
		int nSelItem = -1;
		nSelItem = m_ListContro2->GetNextSelectedItem (sSelectedPos);//��ȡѡ���е�������ͨ��POSITIONת�� 

		if (nSelItem >= 0 && nSelItem < m_ListContro2->GetItemCount ())
		{
			CString sFullPath = m_ListContro2->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //��ʾ��ǰѡ�е�·��
			kSelectedItem.push_back (sFullPath);
		}

	}

	//��ָ��λ����ʾ�����˵�
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}

void FriendShared::OnNMRClickList7 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (2); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
	CPoint oPoint; //����һ������ȷ�����λ�õ�λ��
	GetCursorPos (&oPoint); //��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����

	m_ListContro2->SetExtendedStyle (m_ListContro2->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListContro2->GetFirstSelectedItemPosition ();  //��ȡ��ѡ����λ��
	if (sSelectedPos == NULL)
	{
		return;
	}
	//ѡ�е�1����������
	while (sSelectedPos)//��ȡ��ѡ����λ��
	{
		int nSelItem = -1;
		nSelItem = m_ListContro2->GetNextSelectedItem (sSelectedPos);//��ȡѡ���е�������ͨ��POSITIONת�� 

		if (nSelItem >= 0 && nSelItem < m_ListContro2->GetItemCount ())
		{
			CString sFullPath = m_ListContro2->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //��ʾ��ǰѡ�е�·��
			kSelectedItem.push_back (sFullPath);
		}

	}

	//��ָ��λ����ʾ�����˵�
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}


