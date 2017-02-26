// mytab.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "mytab.h"
#include "afxdialogex.h"

// mytab �Ի���

IMPLEMENT_DYNAMIC(mytab, CDialog)

mytab::mytab(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FORMVIEW, pParent)
{

}

mytab::~mytab()
{
}

BOOL mytab::OnInitDialog ()
{
	CDialog::Initialize ();
	//�����б��ʼ��

	pmyListCtrl = (CListCtrl*)GetDlgItem (IDC_LIST2);
	DWORD dwStyle = GetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles = pmyListCtrl->GetExtendedStyle ();
	pmyListCtrl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz[5][10] = { _T ("��Ա����"),_T ("��Ա����"),_T ("�Ա�"),_T ("����"),_T ("����ʱ��") };

	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�

	LV_COLUMN lvcolumn;
	CRect rect;
	pmyListCtrl->GetWindowRect (&rect);
	for (int i = 0; i < 5; i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width () / 5;
		pmyListCtrl->InsertColumn (i, &lvcolumn);
	}


	//add data
	pmyListCtrl->InsertItem (0, L"qq");
	pmyListCtrl->SetItemText (0, 1, L"mima");
	pmyListCtrl->InsertItem (1, L"qq");
	pmyListCtrl->SetItemText (1, 1, L"mima");
	pmyListCtrl->InsertItem (2, L"qq");
	pmyListCtrl->SetItemText (2, 1, L"mima");



	//ifstream input ("manager.dat");     //�������Լ���Ҫ�Ķ��ļ�����
	//Manager manager;

	//input.read ((char *)&manager, sizeof (manager));

	//while (input)
	//{
	//	i = 0;
	//	CString strText;
	//	if (manager.tag == '#')
	//	{

	//		strText.Format (TEXT ("%d"), manager.number);

	//		// Insert the item, select every other item.
	//		pmyListCtrl->InsertItem (LVIF_TEXT | LVIF_STATE, i, strText,
	//			(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);

	//		// Initialize the text of the subitems.


	//		strText.Format ("%s", manager.name);          //�������Ҫ��������������ݣ�ע������
	//		pmyListCtrl->SetItemText (i, 1, strText);

	//		strText.Format ("%s", manager.sex);
	//		pmyListCtrl->SetItemText (i, 2, strText);

	//		strText.Format ("%d", manager.age);
	//		pmyListCtrl->SetItemText (i, 3, strText);

	//		strText.Format ("%d", manager.year);
	//		pmyListCtrl->SetItemText (i, 4, strText);

	//	}
	//	input.read ((char *)&manager, sizeof (manager));
	//};
	//input.close ();

	return TRUE; // return TRUE unless you set the focus to a control
				 // EXCEPTION: OCX Property Pages should return FALSE
}

void mytab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control (pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(mytab, CDialog)
	ON_BN_CLICKED (IDC_BUTTON1, &mytab::OnBnClickedButton1)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST2, &mytab::OnLvnItemchangedList2)
	ON_NOTIFY (NM_RCLICK, IDC_LIST2, &mytab::OnNMRClickList2)
END_MESSAGE_MAP()


// mytab ��Ϣ�������


void mytab::OnBnClickedButton1 ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void mytab::OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void mytab::OnNMRClickList2 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ҽ���Ӧ�¼�
	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (4); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
	CPoint oPoint; //����һ������ȷ�����λ�õ�λ��
	GetCursorPos (&oPoint); //��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����

	pmyListCtrl->SetExtendedStyle (pmyListCtrl->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = pmyListCtrl->GetFirstSelectedItemPosition ();  //��ȡ��ѡ����λ��
	if (sSelectedPos == NULL)
	{
		return;
	}
	//ѡ�е�1����������
	while (sSelectedPos)//��ȡ��ѡ����λ��
	{
		int nSelItem = -1;
		nSelItem = pmyListCtrl->GetNextSelectedItem (sSelectedPos);//��ȡѡ���е�������ͨ��POSITIONת�� 

		if (nSelItem >= 0 && nSelItem < pmyListCtrl->GetItemCount ())
		{
			CString sFullPath = pmyListCtrl->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //��ʾ��ǰѡ�е�·��
			kSelectedItem.push_back (sFullPath);
		}

	}

	//��ָ��λ����ʾ�����˵�
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);


	*pResult = 0;
}
