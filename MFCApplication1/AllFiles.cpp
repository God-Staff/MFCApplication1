// AllFiles.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AllFiles.h"
#include "afxdialogex.h"

// AllFiles �Ի���

IMPLEMENT_DYNAMIC(AllFiles, CDialogEx)

AllFiles::AllFiles(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW4, pParent)
{

}

AllFiles::~AllFiles()
{
}

BOOL AllFiles::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	pmyListCtrl = (CListCtrl*)GetDlgItem (IDC_LIST5);
	DWORD dwStyle = GetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles = pmyListCtrl->GetExtendedStyle ();
	pmyListCtrl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz[5][10] = { _T ("�ļ�����"),_T ("����"),_T ("��С"),_T ("ʱ��"),_T ("����") };

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

	return TRUE;
}

void AllFiles::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AllFiles, CDialogEx)
	/*ON_NOTIFY (NM_RCLICK, IDC_LIST4, &AllFiles::OnNMRClickList4)*/
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST4, &AllFiles::OnLvnItemchangedList4)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST5, &AllFiles::OnLvnItemchangedList5)
	ON_NOTIFY (NM_RCLICK, IDC_LIST5, &AllFiles::OnNMRClickList5)
	ON_COMMAND (ID_32783, &AllFiles::OnCreateUrl2Shared)
	ON_COMMAND (ID_32784, &AllFiles::OnDelectChosedFiles)
	ON_COMMAND (ID_32785, &AllFiles::OnMoveChosedFiles)
	ON_COMMAND (ID_32786, &AllFiles::OnPasteFile2HerePath)
	ON_COMMAND (ID_32787, &AllFiles::OnDownloadFiles)
	ON_COMMAND (ID_32788, &AllFiles::OnCheckFilesProperty)
	ON_COMMAND (ID_32789, &AllFiles::OnCopyFiles)
	ON_COMMAND (ID_32790, &AllFiles::OnUploadFiles2CurrentPath)
	ON_COMMAND (ID_32791, &AllFiles::OnCreateFolder2CurrentPath)
	ON_NOTIFY (NM_DBLCLK, IDC_LIST5, &AllFiles::OnNMDblclkList5)
END_MESSAGE_MAP()


// AllFiles ��Ϣ�������

//
//void AllFiles::OnNMRClickList4 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//
//	*pResult = 0;
//}
//
//
//void AllFiles::OnLvnItemchangedList4 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}
//
//
//void AllFiles::OnLvnItemchangedList5 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}

//�����Ҽ��˵�
void AllFiles::OnNMRClickList5 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ҽ���Ӧ�¼�
	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (1); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
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


//�ļ��б���Ҽ���Ӧ�¼�
void AllFiles::OnCreateUrl2Shared ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnDelectChosedFiles ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnMoveChosedFiles ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnPasteFile2HerePath ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnDownloadFiles ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnCheckFilesProperty ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnCopyFiles ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnUploadFiles2CurrentPath ()
{
	// TODO: �ڴ���������������
}


void AllFiles::OnCreateFolder2CurrentPath ()
{
	// TODO: �ڴ���������������
}


//���˫����Ӧ�¼�(������ļ���)
void AllFiles::OnNMDblclkList5 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
