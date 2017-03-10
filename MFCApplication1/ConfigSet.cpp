// ConfigSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"
#include <fstream>


// ConfigSet �Ի���

IMPLEMENT_DYNAMIC(ConfigSet, CDialogEx)

ConfigSet::ConfigSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW3, pParent)
{

}

ConfigSet::~ConfigSet()
{
}

BOOL ConfigSet::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	////
	downpath	= (CEdit*)GetDlgItem (IDC_EDIT41);
	downpath->SetReadOnly (TRUE);
	downSpeed	= (CEdit*)GetDlgItem (IDC_EDIT42);
	UploadSpeed = (CEdit*)GetDlgItem (IDC_EDIT43);
	OldPS		= (CEdit*)GetDlgItem (IDC_EDIT44);
	NewPS		= (CEdit*)GetDlgItem (IDC_EDIT46);
	PhoneCode	= (CEdit*)GetDlgItem (IDC_EDIT45);
	box1		= (CComboBox*)GetDlgItem (IDC_COMBO1);
	box2		= (CComboBox*)GetDlgItem (IDC_COMBO2);

	///////////////////////////////////
	m_ListControl = (CListCtrl*)GetDlgItem (IDC_LIST6);
	DWORD dwStyle2 = GetWindowLong (m_ListControl->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListControl->m_hWnd, GWL_STYLE, dwStyle2 | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles2 = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz2[8] = { _T ("����Ŀ¼") };

	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�

	LV_COLUMN lvcolumn2;
	CRect rect2;
	m_ListControl->GetWindowRect (&rect2);
	for (int i = 0; i < 1; i++)
	{
		lvcolumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn2.fmt = LVCFMT_LEFT;
		lvcolumn2.pszText = rgtsz2;
		lvcolumn2.iSubItem = i;
		lvcolumn2.iOrder = i;
		lvcolumn2.cx = rect2.Width ();
		m_ListControl->InsertColumn (i, &lvcolumn2);
	}

	//��ȡ�����ļ����������
	//���ü���ʧ�ܣ��˳�
	if (!configInit ())
		return;

	/*m_ListControl->InsertItem (0, L"qq");
	m_ListControl->InsertItem (1, L"qq");
	m_ListControl->InsertItem (2, L"qq");*/
	m_ListControl->InsertItem (0 ,L"mima");

	return TRUE;
}

void ConfigSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConfigSet, CDialogEx)
	ON_BN_CLICKED (IDC_BUTTON1, &ConfigSet::OnBnClickedButton1)
	ON_NOTIFY (NM_RCLICK, IDC_LIST6, &ConfigSet::OnNMRClickList6)
	ON_COMMAND (ID_32806, &ConfigSet::OnAddFilesPath)
	ON_COMMAND (ID_32807, &ConfigSet::OnDelectFilesPath)
	ON_COMMAND (ID_32808, &ConfigSet::OnUpdateFilePathList)
	ON_CBN_SELCHANGE (IDC_COMBO1, &ConfigSet::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE (IDC_COMBO2, &ConfigSet::OnCbnSelchangeCombo2)
	ON_BN_CLICKED (IDC_BUTTON2, &ConfigSet::OnBnClickedButton2)
	ON_BN_CLICKED (IDC_BUTTON3, &ConfigSet::OnBnClickedButton3)
	ON_BN_CLICKED (IDC_BUTTON4, &ConfigSet::OnBnClickedButton4)
END_MESSAGE_MAP()


// ConfigSet ��Ϣ�������

//
//void ConfigSet::OnBnClickedButton1 ()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}

BOOL	ConfigSet::configInit ()
{
	std::ifstream *conf;
	conf->open ("config.ini");
	if (!conf)
	{	//��ʧ��
		return FALSE;
	} else {

		config.GetCachedSize ();
		config.ParseFromIstream (conf);

		return TRUE;
	}
}


void ConfigSet::OnBnClickedButton1 ()
{

	//if (AutoSaveFLG == FALSE ) 
	CString filter ("List Files|*.htm; *.html; *.cpp; *.hpp||");
	CString         filePath, strBuf;
	POSITION        pos = NULL;

	POSITION		w_pos = NULL;

	CFileDialog     selDlg (TRUE, NULL, NULL,	//������ݷ�ʽ�ļ������� OFN_NODEREFERENCELINKS
		OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_NODEREFERENCELINKS, filter);//OFN_NODEREFERENCELINKS ׷��
	int             err = 0, lbErr = 0;

	// �ڴ汣�����ļ����б�
	if (!err)
	{
		try
		{
			selDlg.GetOFN ().lpstrFile = strBuf.GetBuffer (MAX_PATH * 100);
			selDlg.GetOFN ().nMaxFile = MAX_PATH * 100;
		}
		catch (...) { err = 1; }
	}
	if (!err) if (selDlg.DoModal () != IDOK) err = 1;

	if (selDlg.GetStartPosition () != NULL) {
		w_pos = selDlg.GetStartPosition ();
	}

	if (!err) if ((pos = selDlg.GetStartPosition ()) == NULL) err = 1;
	if (!err)
	{
		while (pos)
		{
			filePath = selDlg.GetNextPathName (pos);
			if (!err)
			{
				ULONGLONG tempCnt;
			}
			//if (err) break;
		}
		UpdateData (FALSE);
	}

	BOOL ReadErrorFLG = FALSE;

	if (!err) if ((pos = w_pos) == NULL) err = 1;
	if (!err)
	{

		while (pos)
		{
			filePath = selDlg.GetNextPathName (pos);
			if (!err)
			{
				//lbErr = CFileListCreatorDlg::importFileList_Func(filePath);
				MessageBox (filePath);
				int tempINT=0;
				//tempINT = CFileListCreatorDlg::importFileList_Func (filePath, FALSE);
				if (tempINT == 0) {
					//err = 1;
					ReadErrorFLG = TRUE;
				}
			}
			//if (err) break;
		}
		UpdateData (FALSE);
	}
	//strBuf.ReleaseBuffer();//�����ȥ�����//2011.05.31

	//CFileListCreatorDlg::StrToTagSign();
	//CFileListCreatorDlg::SetStrFormat_Func(); //Func���Ф�

	strBuf.ReleaseBuffer ();
	DrawMenuBar ();

	return;
}

void ConfigSet::OnNMRClickList6 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ҽ���Ӧ�¼�
	std::vector<CString> kSelectedItem; //���ѡ���
	CMenu menu, *pSubMenu; //��������Ҫ�õ���cmenu����
	menu.LoadMenu (IDR_MENU1); //װ���Զ�����Ҽ��˵�

	pSubMenu = menu.GetSubMenu (5); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
	CPoint oPoint; //����һ������ȷ�����λ�õ�λ��
	GetCursorPos (&oPoint); //��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����

	m_ListControl->SetExtendedStyle (m_ListControl->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListControl->GetFirstSelectedItemPosition ();  //��ȡ��ѡ����λ��
	if (sSelectedPos == NULL)
	{
		return;
	}
	//ѡ�е�1����������
	while (sSelectedPos)//��ȡ��ѡ����λ��
	{
		int nSelItem = -1;
		nSelItem = m_ListControl->GetNextSelectedItem (sSelectedPos);//��ȡѡ���е�������ͨ��POSITIONת�� 

		if (nSelItem >= 0 && nSelItem < m_ListControl->GetItemCount ())
		{
			CString sFullPath = m_ListControl->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //��ʾ��ǰѡ�е�·��
			kSelectedItem.push_back (sFullPath);
		}

	}

	//��ָ��λ����ʾ�����˵�
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}


//Config �Ҽ���Ӧ�¼�
void ConfigSet::OnAddFilesPath ()
{
	// TODO: �ڴ���������������
	
	//��ȡ�б��������������β���������·��
	int i = m_ListControl->GetWindowedChildCount ();

	////��ȡ�ļ���·��
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT ("");

	BROWSEINFO      sInfo;
	::ZeroMemory (&sInfo, sizeof (BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T ("��ѡ��һ���ļ��У�");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// ��ʾ�ļ���ѡ��Ի���  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder (&sInfo);
	if (lpidlBrowse != NULL)
	{
		// ȡ���ļ�����  
		if (::SHGetPathFromIDList (lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree (lpidlBrowse);
	}
	///////

	m_ListControl->InsertItem (i, strFolderPath);
	//MessageBox (strFolderPath);

	//���ļ�·��д�뵽�����ļ�
	//TODO:
}


void ConfigSet::OnDelectFilesPath ()
{
	//ɾ��ѡ�е�Path

	POSITION pos = m_ListControl->GetFirstSelectedItemPosition ();
	if (pos == NULL)
		TRACE0 ("No items were selected!\n");
	else
	{
		while (pos)
		{
			int nItem = m_ListControl->GetNextSelectedItem (pos);
			m_ListControl->DeleteItem (nItem);
		}
	}

	//���ļ�·��д�뵽�����ļ�
	//TODO:
}


void ConfigSet::OnUpdateFilePathList ()
{
	// ����AllFiles���ļ��б�������ϴ��ļ�
	
}


void ConfigSet::OnCbnSelchangeCombo1 ()
{
	//�����ϴ����������ı�ʱִ�б��,��������ݱ��浽�����ļ�
	box1->GetCurSel ();

}


void ConfigSet::OnCbnSelchangeCombo2 ()
{
	//�����������������ı�ʱִ�б��
	box2->GetCurSel ();
	
}


void ConfigSet::OnBnClickedButton2 ()
{
	//�����ļ�����Ŀ¼

	////��ȡ�ļ���·��
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT ("");

	BROWSEINFO      sInfo;
	::ZeroMemory (&sInfo, sizeof (BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T ("��ѡ��һ���ļ��У�");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// ��ʾ�ļ���ѡ��Ի���  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder (&sInfo);
	if (lpidlBrowse != NULL)
	{
		// ȡ���ļ�����  
		if (::SHGetPathFromIDList (lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree (lpidlBrowse);
	}
	
	///////
	downpath->SetReadOnly (FALSE);
	downpath->SetWindowTextW (szFolderPath);
	downpath->SetReadOnly (TRUE);
}


void ConfigSet::OnBnClickedButton3 ()
{
	// ��������ʱ����Ӧ�¼�

}



void ConfigSet::OnBnClickedButton4 ()
{
	// ��ȡ�ֻ�����֤��
}
