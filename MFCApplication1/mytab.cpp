// mytab.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "mytab.h"
#include "afxdialogex.h"

// mytab 对话框

IMPLEMENT_DYNAMIC(mytab, CDialog)

mytab::mytab(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FORMVIEW, pParent)
{

}

mytab::~mytab()
{
}

BOOL mytab::OnInitDialog ()
{
	CDialog::Initialize ();
	//用于列表初始化

	pmyListCtrl = (CListCtrl*)GetDlgItem (IDC_LIST2);
	DWORD dwStyle = GetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong (pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	//设置listctrl可以整行选择和网格条纹
	DWORD styles = pmyListCtrl->GetExtendedStyle ();
	pmyListCtrl->SetExtendedStyle (styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//给listctrl设置5个标题栏
	TCHAR rgtsz[5][10] = { _T ("馆员卡号"),_T ("管员姓名"),_T ("性别"),_T ("年龄"),_T ("工作时间") };

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
	pmyListCtrl->InsertItem (1, L"qq");
	pmyListCtrl->SetItemText (1, 1, L"mima");
	pmyListCtrl->InsertItem (2, L"qq");
	pmyListCtrl->SetItemText (2, 1, L"mima");



	//ifstream input ("manager.dat");     //这是我自己需要的读文件操作
	//Manager manager;

	//input.read ((char *)&manager, sizeof (manager));

	//while (input)
	//{
	//	i = 0;
	//	CString strText;
	//	if (manager.tag == '#')
	//	{

	//		strText.Format (TEXT ("%d"), manager.number);

	//		// Insert the item, select every other item.
	//		pmyListCtrl->InsertItem (LVIF_TEXT | LVIF_STATE, i, strText,
	//			(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);

	//		// Initialize the text of the subitems.


	//		strText.Format ("%s", manager.name);          //这里就是要往里面输入的数据，注意坐标
	//		pmyListCtrl->SetItemText (i, 1, strText);

	//		strText.Format ("%s", manager.sex);
	//		pmyListCtrl->SetItemText (i, 2, strText);

	//		strText.Format ("%d", manager.age);
	//		pmyListCtrl->SetItemText (i, 3, strText);

	//		strText.Format ("%d", manager.year);
	//		pmyListCtrl->SetItemText (i, 4, strText);

	//	}
	//	input.read ((char *)&manager, sizeof (manager));
	//};
	//input.close ();

	return TRUE; // return TRUE unless you set the focus to a control
				 // EXCEPTION: OCX Property Pages should return FALSE
}

void mytab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control (pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(mytab, CDialog)
	ON_BN_CLICKED (IDC_BUTTON1, &mytab::OnBnClickedButton1)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST2, &mytab::OnLvnItemchangedList2)
	ON_NOTIFY (NM_RCLICK, IDC_LIST2, &mytab::OnNMRClickList2)
END_MESSAGE_MAP()


// mytab 消息处理程序


void mytab::OnBnClickedButton1 ()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void mytab::OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void mytab::OnNMRClickList2 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//右键响应事件
	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (4); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
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
