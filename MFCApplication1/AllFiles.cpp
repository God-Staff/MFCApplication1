// AllFiles.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AllFiles.h"
#include "afxdialogex.h"
#include "utility.hpp"
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

	//�����ļ����ݣ�allFiles����䱨��
	updateList ();

	return TRUE;
}

void AllFiles::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AllFiles, CDialogEx)
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
			kSelectedItem.push_back (sFullPath);
		}

	}

	//��ָ��λ����ʾ�����˵�
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}

//�ļ��б���Ҽ���Ӧ�¼�

//ѡ���ļ��б����ɷ�������
void AllFiles::OnCreateUrl2Shared ()
{
	// TODO: �ڴ���������������
}

//ɾ�������ļ�
void AllFiles::OnDelectChosedFiles ()
{
	// TODO: �ڴ���������������
}

//�ļ����ļ��м�����Ŀ¼���ƶ�
void AllFiles::OnMoveChosedFiles ()
{
	// TODO: �ڴ���������������
}

//ճ���ļ����ļ��м�����Ŀ¼
void AllFiles::OnPasteFile2HerePath ()
{
	// TODO: �ڴ���������������
}

//�����ļ�
void AllFiles::OnDownloadFiles ()
{
	// TODO: �ڴ���������������
}

//�ļ����ļ�������
void AllFiles::OnCheckFilesProperty ()
{
	// TODO: �ڴ���������������
}

//����
void AllFiles::OnCopyFiles ()
{
	// TODO: �ڴ���������������
}

//�ϴ�
void AllFiles::OnUploadFiles2CurrentPath ()
{
	// TODO: �ڴ���������������
}

//�����ļ��У��Ǹ��ڵ㣩
void AllFiles::OnCreateFolder2CurrentPath ()
{
	//�������壬�����ļ�������
	
}


//���˫����Ӧ�¼�(������ļ���)
void AllFiles::OnNMDblclkList5 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	*pResult = 0;
}

//�����ļ��б�
bool AllFiles::updateList ()
{
	qiuwanli::utilty uu;
	qiuwanli::AllFiles allfilesList;
	std::fstream allfilein ("MakePath4FileOrDir", std::ios::in | std::ios::binary);
	if (!allfilein) {
		MessageBox(L"�����ļ���ʧ�ܣ�");
		return FALSE;
	}

	if (!allfilesList.ParseFromIstream (&allfilein))
	{
		MessageBox (L"�����ļ�����ʧ�ܣ�");
		allfilein.close ();
		return FALSE;
	}
	else
	{	//���������ļ�
		for (int i = 0; i < allfilesList.filespath_size(); ++i)
		{
			qiuwanli::Path4FilesOrDir ff = allfilesList.filespath (i);
			
			pmyListCtrl->InsertItem (i, uu.StringToWstring (ff.pathorname ()).c_str ());
			pmyListCtrl->SetItemText (i, 1, uu.StringToWstring (ff.pathtypes ()).c_str ());

		}
	}
	
	allfilein.close ();
	return true;
}