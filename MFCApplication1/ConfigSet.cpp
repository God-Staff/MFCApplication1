// ConfigSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"

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

	///////////////////////////////////
	m_ListControl = (CListCtrl*)GetDlgItem (IDC_LIST6);
	DWORD dwStyle2 = GetWindowLong (m_ListControl->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListControl->m_hWnd, GWL_STYLE, dwStyle2 | LVS_REPORT);

	//����listctrl��������ѡ�����������
	DWORD styles2 = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//��listctrl����5��������
	TCHAR rgtsz2[5][10] = { _T ("�����ǳ�"),_T ("S") ,_T ("S3") ,_T ("S4") ,_T ("S5") };

	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�

	LV_COLUMN lvcolumn2;
	CRect rect2;
	m_ListControl->GetWindowRect (&rect2);
	for (int i = 0; i < 5; i++)
	{
		lvcolumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn2.fmt = LVCFMT_LEFT;
		lvcolumn2.pszText = rgtsz2[i];
		lvcolumn2.iSubItem = i;
		lvcolumn2.iOrder = i;
		lvcolumn2.cx = rect2.Width () / 5;
		m_ListControl->InsertColumn (i, &lvcolumn2);
	}

	m_ListControl->InsertItem (0, L"qq");
	m_ListControl->SetItemText (0, 1, L"mima");
	m_ListControl->InsertItem (1, L"qq");
	m_ListControl->SetItemText (1, 1, L"mima");
	m_ListControl->InsertItem (2, L"qq");
	m_ListControl->SetItemText (2, 1, L"mima");

	return TRUE;
}

void ConfigSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConfigSet, CDialogEx)
	ON_BN_CLICKED (IDC_BUTTON1, &ConfigSet::OnBnClickedButton1)
	ON_NOTIFY (NM_RCLICK, IDC_LIST6, &ConfigSet::OnNMRClickList6)
END_MESSAGE_MAP()


// ConfigSet ��Ϣ�������

//
//void ConfigSet::OnBnClickedButton1 ()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}

void ConfigSet::OnBnClickedButton1 ()
{

	//if (AutoSaveFLG == FALSE ) 
	CString filter ("List Files|*.htm; *.html; *.cpp; *.hpp||");
	CString         filePath, strBuf;
	POSITION        pos = NULL;

	POSITION		w_pos = NULL;

	CFileDialog     selDlg (TRUE, NULL, NULL,	//http://q.hatena.ne.jp/1173014326 ����`�ȥ��åȥե�����Υ�󥯤��{��ʤ���OFN_NODEREFERENCELINKS
		OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_NODEREFERENCELINKS, filter);//OFN_NODEREFERENCELINKS ׷��
	int             err = 0, lbErr = 0;

	// �ե��������ꥹ���å���_��
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
