// ConfigSet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"

// ConfigSet 对话框

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

	//设置listctrl可以整行选择和网格条纹
	DWORD styles2 = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz2[5][10] = { _T ("好友昵称"),_T ("S") ,_T ("S3") ,_T ("S4") ,_T ("S5") };

	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变

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


// ConfigSet 消息处理程序

//
//void ConfigSet::OnBnClickedButton1 ()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

void ConfigSet::OnBnClickedButton1 ()
{

	//if (AutoSaveFLG == FALSE ) 
	CString filter ("List Files|*.htm; *.html; *.cpp; *.hpp||");
	CString         filePath, strBuf;
	POSITION        pos = NULL;

	POSITION		w_pos = NULL;

	CFileDialog     selDlg (TRUE, NULL, NULL,	//http://q.hatena.ne.jp/1173014326 ショートカットファイルのリンクを辿らない　OFN_NODEREFERENCELINKS
		OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_NODEREFERENCELINKS, filter);//OFN_NODEREFERENCELINKS 追加
	int             err = 0, lbErr = 0;

	// ファイル名リスト用メモリ確保
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
	//strBuf.ReleaseBuffer();//コメントアウト//2011.05.31

	//CFileListCreatorDlg::StrToTagSign();
	//CFileListCreatorDlg::SetStrFormat_Func(); //Funcの中で

	strBuf.ReleaseBuffer ();
	DrawMenuBar ();


	return;
}

void ConfigSet::OnNMRClickList6 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//右键响应事件
	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (5); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
	CPoint oPoint; //定义一个用于确定光标位置的位置
	GetCursorPos (&oPoint); //获取当前光标的位置，以便使得菜单可以跟随光标

	m_ListControl->SetExtendedStyle (m_ListControl->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListControl->GetFirstSelectedItemPosition ();  //获取首选中行位置
	if (sSelectedPos == NULL)
	{
		return;
	}
	//选中的1个或多个数据
	while (sSelectedPos)//获取首选中行位置
	{
		int nSelItem = -1;
		nSelItem = m_ListControl->GetNextSelectedItem (sSelectedPos);//获取选中行的索引，通过POSITION转化 

		if (nSelItem >= 0 && nSelItem < m_ListControl->GetItemCount ())
		{
			CString sFullPath = m_ListControl->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //显示当前选中的路径
			kSelectedItem.push_back (sFullPath);
		}

	}

	//在指定位置显示弹出菜单
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}
