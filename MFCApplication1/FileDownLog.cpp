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
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST2, &FileDownLog::OnLvnItemchangedList2)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST9, &FileDownLog::OnLvnItemchangedList9)
	ON_NOTIFY (NM_RCLICK, IDC_LIST9, &FileDownLog::OnNMRClickList9)
	ON_COMMAND (ID_32795, &FileDownLog::OnClearDownloadLogList)
	ON_COMMAND (ID_32796, &FileDownLog::OnRetryDownloadFiles)
	ON_COMMAND (ID_32797, &FileDownLog::OnDelectChosedFileslog)
	ON_COMMAND (ID_32798, &FileDownLog::OnDelectChosedFiles)
	ON_NOTIFY (LVN_KEYDOWN, IDC_LIST9, &FileDownLog::OnLvnKeydownList9)
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

	//�����ļ����ؼ�¼��DownLog�����������
	UpdateDownLogList ();

	return TRUE;
}


//void FileDownLog::OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}


void FileDownLog::OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

//�Ҽ��˵���Ӧ�¼�
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

//��������б�
void FileDownLog::OnClearDownloadLogList ()
{
	//ɾ��downlog�ļ��������¼�����������б�
	if (remove ("downlog") != 0)
		MessageBox (L"downlog Delect Fail");

	//������ʾ���ؼ�¼
	UpdateDownLogList ();
}

//��������ѡ���ļ�
void FileDownLog::OnRetryDownloadFiles ()
{
	//��ѡ���б���ӵ������ض���

	//�������ؼ�¼��ɾ����Ӧ��¼

}

//ɾ��ѡ�м�¼
void FileDownLog::OnDelectChosedFileslog ()
{
	int i = 0;
	int n = 0;
	int to_delete[max_select_item];

	POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
	if (pos == NULL)
		MessageBox (L"��ѡ���¼");
	else
		while (pos)
			to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
	unsigned int  count = pmyListCtrl->GetSelectedCount ();

	n = pmyListCtrl->GetSelectedCount ();//��ѡ��������
	int k = 0;
	for (i = 0; i < n; i++)
	{
		pmyListCtrl->DeleteItem (to_delete[i] - k);//����ɾ����
		k++;
	}
}

//ɾ��ѡ���ļ�
void FileDownLog::OnDelectChosedFiles ()
{
	int i = 0;
	int n = 0;
	int to_delete[max_select_item];
	CString pathstring{};
	CString namestring{};
	POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
	if (pos == NULL)
		MessageBox (L"��ѡ���¼");
	else
		while (pos)
			to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
	unsigned int  count = pmyListCtrl->GetSelectedCount ();

	n = pmyListCtrl->GetSelectedCount ();//��ѡ��������
	int k = 0;
	for (i = 0; i < n; i++)
	{
		//��ȡ��Ӧ���ļ�����·������
		pathstring = pmyListCtrl->GetItemText (to_delete[i] - k, 0);
		namestring = pmyListCtrl->GetItemText (to_delete[i] - k, 1);

		//���ַ������ӣ�������Ӧ�ļ�
		if (remove ("") != 0)
			MessageBox (L"** �ļ�ɾ��ʧ�ܣ�");
		k++;
	}
}


BOOL	FileDownLog::UpdateDownLogList ()
{
	qiuwanli::utilty utility;
	qiuwanli::FileDownLogFile log;
	std::fstream input ("downlog", std::ios::in | std::ios::binary);
	if (!input) {
		MessageBox (L"�����ļ���ʧ�ܣ�");
		return FALSE;
	}

	if (!log.ParseFromIstream (&input))
	{	//��ʧ��
		MessageBox (L"�����ļ�����ʧ�ܣ�");
		input.close ();
		return FALSE;
	}
	else
	{	//���������ļ�
		for (int i = 0; i < log.filelog_size(); ++i)
		{
			const qiuwanli::FileDownLog& downlog =log.filelog(i);

			pmyListCtrl->InsertItem (i, utility.StringToWstring(downlog.filename ()).c_str());
			pmyListCtrl->SetItemText (i, 1, utility.StringToWstring (downlog.filepath ()).c_str ());
			pmyListCtrl->SetItemText (i, 2, utility.StringToWstring (downlog.filesize ()).c_str ());
			pmyListCtrl->SetItemText (i, 3, utility.StringToWstring (downlog.downtime ()).c_str ());
			pmyListCtrl->SetItemText (i, 4, utility.StringToWstring (downlog.status ()).c_str ());
		}

		input.close ();
		//FileDownLog::UpdateWindow ();
		return TRUE;
	}
}

//��ȡ��ѡ��Ӧ�б����ʼλ��
//ѡ���ļ�ʱ����סdel������ɾ��
void FileDownLog::OnLvnKeydownList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i = 0;
	int n = 0;
	int to_delete[65535];

	if (pLVKeyDow->wVKey == VK_DELETE)
	{
		POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
		if (pos == NULL)
		{
			TRACE0 ("No  items were selected!/n");
		}
		else
		{
			while (pos)
			{
				to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
			}
		}
		n = pmyListCtrl->GetSelectedCount ();//��ѡ��������
		int k = 0;
		for (i = 0; i < n; i++)
		{
			pmyListCtrl->DeleteItem (to_delete[i] - k);//����ɾ����
			k++;
		}
	}

	*pResult = 0;
}


//ɾ��ѡ�е��б��¼
//void FileDownLog::OnLvnKeydownList9 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	int i = 0;
//	int n = 0;
//	int to_delete[65535];
//
//	if (pLVKeyDow->wVKey == VK_DELETE)
//	{
//		POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
//		if (pos == NULL)
//		{
//			TRACE0 ("No  items were selected!/n");
//		}
//		else
//		{
//			while (pos)
//			{
//				to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
//			}
//		}
//		n = pmyListCtrl->GetSelectedCount ();//��ѡ��������
//		int k = 0;
//		for (i = 0; i < n; i++)
//		{
//			pmyListCtrl->DeleteItem (to_delete[i] - k);//����ɾ����
//			k++;
//		}
//	}
//
//	*pResult = 0;
//}
