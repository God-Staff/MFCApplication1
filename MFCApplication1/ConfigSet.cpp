// ConfigSet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ConfigSet.h"
#include "afxdialogex.h"
#include <fstream>
#include "utility.hpp"
#include "afxdialogex.h"
#include <string>
// ConfigSet 对话框

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
		return 0;

	MessageBox (L"配置文件");
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


// ConfigSet 消息处理程序

BOOL	ConfigSet::configInit ()
{
	qiuwanli::utilty utility;
	qiuwanli::ConfigFile configfile;
	//configFile = &configfile;
	std::fstream input3 ("config", std::ios::in | std::ios::binary);
	if (!input3){
		MessageBox (L"配置文件打开失败！");
		return FALSE;
	}
		
	if (!configfile.ParseFromIstream(&input3))
	{	//打开失败
		MessageBox (L"配置文件加载失败！");
		input3.close ();
		return FALSE;
	}
	else 
	{	//解析配置文件
		for (int i = 0; i < configfile.config_size(); ++i)
		{
			MessageBox (L"1234567890" + 1);
			const qiuwanli::Config& config = configfile.config (i);
			std::string value=config.valuestring ();

			if (qiuwanli::Config::Type::Config_Type_ThreadNumUp == config.type ()) 
			{
				box1->SetCurSel (atoi (value.c_str())+1);
				//MessageBox (L"2！");
			}
			if (qiuwanli::Config_Type_ThreadNumDown== config.type ())
			{
				box2->SetCurSel (atoi (value.c_str ())+1);
				//MessageBox (L"3！");
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
				//将string 转化为Wstring 再转化为 LPTSTR 
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


//上传下载速度限制更新的触发事件

void ConfigSet::OnEnChangeEdit42 ()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ConfigSet::OnEnChangeEdit43 ()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
