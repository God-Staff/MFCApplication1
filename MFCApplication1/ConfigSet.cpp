// ConfigSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"
#include <fstream>
#include "utility.hpp"
#include "afxdialogex.h"
#include <string>
// ConfigSet �Ի���

IMPLEMENT_DYNAMIC(ConfigSet, CDialogEx)

ConfigSet::ConfigSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW3, pParent)
{

}

ConfigSet::~ConfigSet()
{
	google::protobuf::ShutdownProtobufLibrary ();
}

BOOL ConfigSet::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();
	
	////
	downpath	= (CEdit*)GetDlgItem (IDC_EDIT41);
	downpath->SetReadOnly (TRUE);
	downSpeed	= (CEdit*)GetDlgItem (IDC_EDIT42);
	UploadSpeed = (CEdit*)GetDlgItem (IDC_EDIT43);
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
		return 0;

	MessageBox (L"�����ļ�");
	return TRUE;
}

void ConfigSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConfigSet, CDialogEx)
	//ON_BN_CLICKED (IDC_BUTTON1, &ConfigSet::OnBnClickedButton1)
	ON_NOTIFY (NM_RCLICK, IDC_LIST6, &ConfigSet::OnNMRClickList6)
	ON_COMMAND (ID_32806, &ConfigSet::OnAddFilesPath)
	ON_COMMAND (ID_32807, &ConfigSet::OnDelectFilesPath)
	ON_COMMAND (ID_32808, &ConfigSet::OnUpdateFilePathList)
	ON_CBN_SELCHANGE (IDC_COMBO1, &ConfigSet::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE (IDC_COMBO2, &ConfigSet::OnCbnSelchangeCombo2)
	ON_BN_CLICKED (IDC_BUTTON2, &ConfigSet::OnBnClickedButton2)
	//ON_BN_CLICKED (IDC_BUTTON3, &ConfigSet::OnBnClickedButton3)
	//ON_BN_CLICKED (IDC_BUTTON4, &ConfigSet::OnBnClickedButton4)
	ON_EN_CHANGE (IDC_EDIT42, &ConfigSet::OnEnChangeEdit42)
	ON_EN_CHANGE (IDC_EDIT43, &ConfigSet::OnEnChangeEdit43)
END_MESSAGE_MAP()


// ConfigSet ��Ϣ�������

BOOL	ConfigSet::configInit ()
{
	qiuwanli::utilty utility;
	qiuwanli::ConfigFile configfile;
	//configFile = &configfile;
	std::fstream input3 ("config", std::ios::in | std::ios::binary);
	if (!input3){
		MessageBox (L"�����ļ���ʧ�ܣ�");
		return FALSE;
	}
		
	if (!configfile.ParseFromIstream(&input3))
	{	//��ʧ��
		MessageBox (L"�����ļ�����ʧ�ܣ�");
		input3.close ();
		return FALSE;
	}
	else 
	{	//���������ļ�
		for (int i = 0; i < configfile.config_size(); ++i)
		{
			MessageBox (L"1234567890" + 1);
			const qiuwanli::Config& config = configfile.config (i);
			std::string value=config.valuestring ();

			if (qiuwanli::Config::Type::Config_Type_ThreadNumUp == config.type ()) 
			{
				box1->SetCurSel (atoi (value.c_str())+1);
				//MessageBox (L"2��");
			}
			if (qiuwanli::Config_Type_ThreadNumDown== config.type ())
			{
				box2->SetCurSel (atoi (value.c_str ())+1);
				//MessageBox (L"3��");
			}
			if (qiuwanli::Config_Type_FileUpSpeed == config.type ())
			{
				UploadSpeed->SetWindowText (utility.StringToWstring (value).c_str());
				//MessageBox (utility.StringToWstring (config.valuestring ().c_str ()).c_str ());
			}
			if (qiuwanli::Config_Type_FileDownSpeed == config.type ())
			{
				downSpeed->SetWindowText (utility.StringToWstring (value).c_str ());
				//MessageBox (utility.StringToWstring (config.valuestring ()).c_str ());
			}
			if (qiuwanli::Config_Type_DownFilePath == config.type ())
			{
				downpath->SetReadOnly (FALSE);
				//��string ת��ΪWstring ��ת��Ϊ LPTSTR 
				downpath->SetWindowText (utility.StringToWstring (value).c_str ());
				downpath->SetReadOnly (TRUE);
				//MessageBox (utility.StringToWstring (config.valuestring ()).c_str ());
			}
			if (qiuwanli::Config_Type_FilePath == config.type ())
			{
				int j = m_ListControl->GetWindowedChildCount ();
				
//#ifdef UNICODE
//				std::wstring stemp = utility.s2ws (value); // Temporary buffer is required
//				LPCWSTR result = stemp.c_str ();
//#else
//				LPCWSTR result = s.c_str ();
//#endif
				m_ListControl->InsertItem (j, utility.StringToWstring (value).c_str ());

				MessageBox (utility.StringToWstring (value).c_str ());
			}
			//config.Clear ();
		}

		input3.close ();
		ConfigSet::UpdateWindow ();
		  
		return TRUE;
	}
}


BOOL	ConfigSet::updateConfig ()
{

	return TRUE;
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


//�ϴ������ٶ����Ƹ��µĴ����¼�

void ConfigSet::OnEnChangeEdit42 ()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void ConfigSet::OnEnChangeEdit43 ()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
