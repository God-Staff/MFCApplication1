// ConfigSet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"
#include <fstream>


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

	//设置listctrl可以整行选择和网格条纹
	DWORD styles2 = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz2[8] = { _T ("备份目录") };

	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变

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

	//获取配置文件，填充数据
	//配置加载失败，退出
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


// ConfigSet 消息处理程序

//
//void ConfigSet::OnBnClickedButton1 ()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

BOOL	ConfigSet::configInit ()
{
	std::ifstream *conf;
	conf->open ("config.ini");
	if (!conf)
	{	//打开失败
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

	CFileDialog     selDlg (TRUE, NULL, NULL,	//不按快捷方式文件的链接 OFN_NODEREFERENCELINKS
		OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_NODEREFERENCELINKS, filter);//OFN_NODEREFERENCELINKS 追加
	int             err = 0, lbErr = 0;

	// 内存保留给文件名列表
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


//Config 右键响应事件
void ConfigSet::OnAddFilesPath ()
{
	// TODO: 在此添加命令处理程序代码
	
	//获取列表的行数，便于在尾部添加新增路径
	int i = m_ListControl->GetWindowedChildCount ();

	////获取文件夹路径
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT ("");

	BROWSEINFO      sInfo;
	::ZeroMemory (&sInfo, sizeof (BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T ("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder (&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
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

	//将文件路径写入到配置文件
	//TODO:
}


void ConfigSet::OnDelectFilesPath ()
{
	//删除选中的Path

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

	//将文件路径写入到配置文件
	//TODO:
}


void ConfigSet::OnUpdateFilePathList ()
{
	// 更新AllFiles的文件列表或者是上传文件
	
}


void ConfigSet::OnCbnSelchangeCombo1 ()
{
	//并行上传设置数量改变时执行变更,将变更数据保存到配置文件
	box1->GetCurSel ();

}


void ConfigSet::OnCbnSelchangeCombo2 ()
{
	//并行下载设置数量改变时执行变更
	box2->GetCurSel ();
	
}


void ConfigSet::OnBnClickedButton2 ()
{
	//设置文件下载目录

	////获取文件夹路径
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT ("");

	BROWSEINFO      sInfo;
	::ZeroMemory (&sInfo, sizeof (BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T ("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder (&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
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
	// 更改密码时的响应事件

}



void ConfigSet::OnBnClickedButton4 ()
{
	// 获取手机的验证码
}
