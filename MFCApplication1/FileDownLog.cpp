// FileDownLog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileDownLog.h"
#include "afxdialogex.h"


// FileDownLog �Ի���

IMPLEMENT_DYNAMIC(FileDownLog, CDialogEx)

FileDownLog::FileDownLog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW1, pParent)
{

}

FileDownLog::~FileDownLog()
{
}

void FileDownLog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileDownLog, CDialogEx)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST2, &FileDownLog::OnLvnItemchangedList2)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST9, &FileDownLog::OnLvnItemchangedList9)
	ON_NOTIFY (NM_RCLICK, IDC_LIST9, &FileDownLog::OnNMRClickList9)
	ON_COMMAND (ID_32795, &FileDownLog::OnClearDownloadLogList)
	ON_COMMAND (ID_32796, &FileDownLog::OnRetryDownloadFiles)
	ON_COMMAND (ID_32797, &FileDownLog::OnDelectChosedFileslog)
	ON_COMMAND (ID_32798, &FileDownLog::OnDelectChosedFiles)
END_MESSAGE_MAP()


// FileDownLog ��Ϣ�������


BOOL FileDownLog::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	pmyListCtrl = (CListCtrl*)GetDlgItem (IDC_LIST9);
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
	pmyListCtrl->InsertItem (1, L"qq");
	pmyListCtrl->SetItemText (1, 1, L"mima");
	pmyListCtrl->InsertItem (2, L"qq");
	pmyListCtrl->SetItemText (2, 1, L"mima");

	return TRUE;
}


void FileDownLog::OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void FileDownLog::OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void FileDownLog::OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ҽ���Ӧ�¼�
	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (3); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
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


//���ؼ�¼���Ҽ���Ӧ�¼�
void FileDownLog::OnClearDownloadLogList ()
{
	// TODO: �ڴ���������������
}


void FileDownLog::OnRetryDownloadFiles ()
{
	// TODO: �ڴ���������������
}


void FileDownLog::OnDelectChosedFileslog ()
{
	// TODO: �ڴ���������������
}


void FileDownLog::OnDelectChosedFiles ()
{
	// TODO: �ڴ���������������
}
