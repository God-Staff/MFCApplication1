// FriendShared.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FriendShared.h"
#include "afxdialogex.h"

// FriendShared 对话框

IMPLEMENT_DYNAMIC(FriendShared, CDialogEx)

FriendShared::FriendShared(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW2, pParent)
{
}

//用于窗体数据的初始化
BOOL FriendShared::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();
	
	//初始化列表
	m_ListControl = (CListCtrl*)GetDlgItem (IDC_LIST8);
	DWORD dwStyle = GetWindowLong (m_ListControl->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListControl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	//设置listctrl可以整行选择和网格条纹
	DWORD styles = m_ListControl->GetExtendedStyle ();
	m_ListControl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz[2][10] = { _T ("好友昵称"),_T ("S") };

	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变
	LV_COLUMN lvcolumn;
	CRect rect;
	m_ListControl->GetWindowRect (&rect);
	for (int i = 0; i < 2; i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width () / 2;
		m_ListControl->InsertColumn (i, &lvcolumn);
	}

	//add data
	m_ListControl->InsertItem (0, L"qq");
	m_ListControl->SetItemText (0, 1, L"mima");
	m_ListControl->InsertItem (1, L"qq");
	m_ListControl->SetItemText (1, 1, L"mima");
	m_ListControl->InsertItem (2, L"qq");
	m_ListControl->SetItemText (2, 1, L"mima");

	///////////////////////////////////
	//初始化列表2
	m_ListContro2 = (CListCtrl*)GetDlgItem (IDC_LIST7);
	DWORD dwStyle2 = GetWindowLong (m_ListContro2->m_hWnd, GWL_STYLE);
	SetWindowLong (m_ListContro2->m_hWnd, GWL_STYLE, dwStyle2 | LVS_REPORT);

	//设置listctrl可以整行选择和网格条纹
	DWORD styles2 = m_ListContro2->GetExtendedStyle ();
	m_ListContro2->SetExtendedStyle (styles2 | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz2[5][10] = { _T ("好友昵称"),_T ("S") ,_T ("S3") ,_T ("S4") ,_T ("S5") };

	//修改数组大小，可以确定分栏数和没栏长度，如果修改下面的数据（蓝色部分）也要跟着改变

	LV_COLUMN lvcolumn2;
	CRect rect2;
	m_ListContro2->GetWindowRect (&rect2);
	for (int i = 0; i < 5; i++)
	{
		lvcolumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn2.fmt = LVCFMT_LEFT;
		lvcolumn2.pszText = rgtsz2[i];
		lvcolumn2.iSubItem = i;
		lvcolumn2.iOrder = i;
		lvcolumn2.cx = rect2.Width () / 5;
		m_ListContro2->InsertColumn (i, &lvcolumn2);
	}

	m_ListContro2->InsertItem (0, L"qq");
	m_ListContro2->SetItemText (0, 1, L"mima");
	m_ListContro2->InsertItem (1, L"qq");
	m_ListContro2->SetItemText (1, 1, L"mima");
	m_ListContro2->InsertItem (2, L"qq");
	m_ListContro2->SetItemText (2, 1, L"mima");

	return TRUE;
}

FriendShared::~FriendShared(){}

void FriendShared::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FriendShared, CDialogEx)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST1, &FriendShared::OnLvnItemchangedList1)
	//ON_NOTIFY (NM_RCLICK, IDC_LIST1, &FriendShared::OnNMRClickList1)
	//ON_NOTIFY (NM_RCLICK, IDC_LIST4, &FriendShared::OnNMRClickList4)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST8, &FriendShared::OnLvnItemchangedList8)
	ON_NOTIFY (NM_RCLICK, IDC_LIST8, &FriendShared::OnNMRClickList8)
	ON_NOTIFY (NM_RCLICK, IDC_LIST7, &FriendShared::OnNMRClickList7)
END_MESSAGE_MAP()


void FriendShared::OnNMRClickList8 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (0); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
	CPoint oPoint; //定义一个用于确定光标位置的位置
	GetCursorPos (&oPoint); //获取当前光标的位置，以便使得菜单可以跟随光标

	m_ListContro2->SetExtendedStyle (m_ListContro2->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListContro2->GetFirstSelectedItemPosition ();  //获取首选中行位置
	if (sSelectedPos == NULL)
	{
		return;
	}
	//选中的1个或多个数据
	while (sSelectedPos)//获取首选中行位置
	{
		int nSelItem = -1;
		nSelItem = m_ListContro2->GetNextSelectedItem (sSelectedPos);//获取选中行的索引，通过POSITION转化 

		if (nSelItem >= 0 && nSelItem < m_ListContro2->GetItemCount ())
		{
			CString sFullPath = m_ListContro2->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //显示当前选中的路径
			kSelectedItem.push_back (sFullPath);
		}

	}

	//在指定位置显示弹出菜单
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}

void FriendShared::OnNMRClickList7 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (2); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
	CPoint oPoint; //定义一个用于确定光标位置的位置
	GetCursorPos (&oPoint); //获取当前光标的位置，以便使得菜单可以跟随光标

	m_ListContro2->SetExtendedStyle (m_ListContro2->GetExtendedStyle () | LVS_EX_FULLROWSELECT);

	POSITION sSelectedPos = m_ListContro2->GetFirstSelectedItemPosition ();  //获取首选中行位置
	if (sSelectedPos == NULL)
	{
		return;
	}
	//选中的1个或多个数据
	while (sSelectedPos)//获取首选中行位置
	{
		int nSelItem = -1;
		nSelItem = m_ListContro2->GetNextSelectedItem (sSelectedPos);//获取选中行的索引，通过POSITION转化 

		if (nSelItem >= 0 && nSelItem < m_ListContro2->GetItemCount ())
		{
			CString sFullPath = m_ListContro2->GetItemText (nSelItem, 1);
			//MessageBox(sFullPath ); //显示当前选中的路径
			kSelectedItem.push_back (sFullPath);
		}

	}

	//在指定位置显示弹出菜单
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this);

	*pResult = 0;
}


