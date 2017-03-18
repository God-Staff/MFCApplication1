// AllFiles.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AllFiles.h"
#include "afxdialogex.h"

// AllFiles 对话框

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

	//设置listctrl可以整行选择和网格条纹
	DWORD styles = pmyListCtrl->GetExtendedStyle ();
	pmyListCtrl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz[5][10] = { _T ("文件名称"),_T ("类型"),_T ("大小"),_T ("时间"),_T ("类型") };

	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变

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


// AllFiles 消息处理程序

//
//void AllFiles::OnNMRClickList4 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//
//	*pResult = 0;
//}
//
//
//void AllFiles::OnLvnItemchangedList4 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}
//
//
//void AllFiles::OnLvnItemchangedList5 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}

//启动右键菜单
void AllFiles::OnNMRClickList5 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//右键响应事件
	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (1); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
	CPoint oPoint; //定义一个用于确定光标位置的位置
	GetCursorPos (&oPoint); //获取当前光标的位置，以便使得菜单可以跟随光标

	pmyListCtrl->SetExtendedStyle (pmyListCtrl->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = pmyListCtrl->GetFirstSelectedItemPosition ();  //获取首选中行位置
	if (sSelectedPos == NULL)
	{
		return;
	}
	//选中的1个或多个数据
	while (sSelectedPos)//获取首选中行位置
	{
		int nSelItem = -1;
		nSelItem = pmyListCtrl->GetNextSelectedItem (sSelectedPos);//获取选中行的索引，通过POSITION转化 

		if (nSelItem >= 0 && nSelItem < pmyListCtrl->GetItemCount ())
		{
			CString sFullPath = pmyListCtrl->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //显示当前选中的路径
			kSelectedItem.push_back (sFullPath);
		}

	}

	//在指定位置显示弹出菜单
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);


	*pResult = 0;
}


//文件列表的右键响应事件
void AllFiles::OnCreateUrl2Shared ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnDelectChosedFiles ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnMoveChosedFiles ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnPasteFile2HerePath ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnDownloadFiles ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnCheckFilesProperty ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnCopyFiles ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnUploadFiles2CurrentPath ()
{
	// TODO: 在此添加命令处理程序代码
}


void AllFiles::OnCreateFolder2CurrentPath ()
{
	// TODO: 在此添加命令处理程序代码
}


//左键双击响应事件(代表打开文件夹)
void AllFiles::OnNMDblclkList5 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
