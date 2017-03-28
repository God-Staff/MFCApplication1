// FileDownLog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileDownLog.h"
#include "afxdialogex.h"


// FileDownLog 对话框

IMPLEMENT_DYNAMIC(FileDownLog, CDialogEx)

FileDownLog::FileDownLog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FORMVIEW1, pParent)
{

}

FileDownLog::~FileDownLog()
{
}

void FileDownLog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileDownLog, CDialogEx)
	//ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST2, &FileDownLog::OnLvnItemchangedList2)
	ON_NOTIFY (LVN_ITEMCHANGED, IDC_LIST9, &FileDownLog::OnLvnItemchangedList9)
	ON_NOTIFY (NM_RCLICK, IDC_LIST9, &FileDownLog::OnNMRClickList9)
	ON_COMMAND (ID_32795, &FileDownLog::OnClearDownloadLogList)
	ON_COMMAND (ID_32796, &FileDownLog::OnRetryDownloadFiles)
	ON_COMMAND (ID_32797, &FileDownLog::OnDelectChosedFileslog)
	ON_COMMAND (ID_32798, &FileDownLog::OnDelectChosedFiles)
	ON_NOTIFY (LVN_KEYDOWN, IDC_LIST9, &FileDownLog::OnLvnKeydownList9)
END_MESSAGE_MAP()


// FileDownLog 消息处理程序


BOOL FileDownLog::OnInitDialog ()
{
	CDialogEx::OnInitDialog ();

	pmyListCtrl = (CListCtrl*)GetDlgItem (IDC_LIST9);
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

	//解析文件下载记录（DownLog），填充数据
	UpdateDownLogList ();
	updownlog ();

	return TRUE;
}


void FileDownLog::OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

//右键菜单响应事件
void FileDownLog::OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//右键响应事件
	std::vector<CString> kSelectedItem; //多个选中项。
	CMenu menu, *pSubMenu; //定义下面要用到的cmenu对象
	menu.LoadMenu (IDR_MENU1); //装载自定义的右键菜单

	pSubMenu = menu.GetSubMenu (3); //获取第一个弹出菜单，所以第一个菜单必须有子菜单
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


//下载记录的右键响应事件

//清空下载列表
void FileDownLog::OnClearDownloadLogList ()
{
	//删除downlog文件，并重新加载下载完成列表
	//以覆盖方式重新打开，即为清空是文件数据
	std::fstream output1 ("downlog", std::ios::out | std::ios::trunc | std::ios::binary);
	output1.close ();

	//更新显示下载记录
	UpdateDownLogList ();
	updownlog ();
}

//重新下载选中文件
void FileDownLog::OnRetryDownloadFiles ()
{
	//将选中列表添加到待下载队列

	//并从下载记录中删除对应记录

}

//删除选中记录,
void FileDownLog::OnDelectChosedFileslog ()
{
	int i = 0;
	int n = 0;
	int to_delete[max_select_item];

	CString pathstring;
	CString namestring;
	CString size;
	CString downtime;
	CString status;

	POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
	if (pos == NULL)
		MessageBox (L"请选择记录");
	else
		while (pos)
			to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);

	unsigned int  count = pmyListCtrl->GetSelectedCount ();

	n = pmyListCtrl->GetSelectedCount ();//被选择总数；
	int k = 0;

	std::vector <downlogstruct> del;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string delfile;
	for (i = 0; i < n; i++)
	{
		//获取对应的文件名和路径名称
		pathstring = pmyListCtrl->GetItemText (to_delete[i] - k, 0);
		namestring = pmyListCtrl->GetItemText (to_delete[i] - k, 1);
		size = pmyListCtrl->GetItemText (to_delete[i] - k, 2);
		downtime = pmyListCtrl->GetItemText (to_delete[i] - k, 3);
		status = pmyListCtrl->GetItemText (to_delete[i] - k, 4);


		//将要删除的记录添加到待删除列表，便于统计完成时一次性删除
		del.push_back (std::move(downlogstruct (
			conv.to_bytes (namestring), conv.to_bytes (pathstring), conv.to_bytes (size),
			conv.to_bytes (downtime), conv.to_bytes (status)))
		);
		k++;
	}

	mergeLog (del);
	updownlog ();
}

//删除选中文件
void FileDownLog::OnDelectChosedFiles ()
{
	int i = 0;
	int n = 0;
	int to_delete[max_select_item];
	
	CString pathstring;
	CString namestring;
	CString size;
	CString downtime;
	CString status;
	POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
	if (pos == NULL)
		MessageBox (L"请选择记录");
	else
		while (pos)
			to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);

	unsigned int  count = pmyListCtrl->GetSelectedCount ();

	n = pmyListCtrl->GetSelectedCount ();//被选择总数；
	int k = 0;

	std::vector <downlogstruct> del;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string delfile;
	for (i = 0; i < n; i++)
	{
		//获取对应的文件名和路径名称
		pathstring = pmyListCtrl->GetItemText (to_delete[i] - k, 0);
		namestring = pmyListCtrl->GetItemText (to_delete[i] - k, 1);		
		size = pmyListCtrl->GetItemText (to_delete[i] - k, 2);
		downtime = pmyListCtrl->GetItemText (to_delete[i] - k, 3);
		status = pmyListCtrl->GetItemText (to_delete[i] - k, 4);


		//将要删除的记录添加到待删除列表，便于统计完成时一次性删除
		del.push_back (std::move (downlogstruct(
			conv.to_bytes(namestring), conv.to_bytes (pathstring), conv.to_bytes (size), 
			conv.to_bytes (downtime), conv.to_bytes (status)
		)));

		//将字符串连接，产出对应文件
		delfile=conv.to_bytes (pathstring)+"\\"+ conv.to_bytes (namestring);
		if (remove (delfile.c_str()) != 0)
			MessageBox (L"文件删除失败！");
		k++;
	}

	//从中间层删除数据，并将MFC显示更新
	mergeLog (del);
	updownlog ();
}

//将数据;久化
void wirteToFile ()
{
	std::fstream tofile ("downlog", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!tofile)
		return;
	qiuwanli::FileDownLogFile downlog;
	qiuwanli::BufInterface buf;
	//downlogstruct item;

	for (auto iter = downLogRecode.begin(); iter != downLogRecode.end (); ++iter)
	{
		//item = *iter;
		buf.MakeDownlog (
			downlog.add_filelog (),iter->str1, iter->str2, iter->str3,
			iter->str4, iter->str5);
	}

	if (!downlog.SerializeToOstream (&tofile)) {
		std::cerr << "Failed to write Downlog:" << std::endl;
	}
	tofile.close ();
}

//将要删除的记录添在统计完成时一次性删除//
void FileDownLog::mergeLog (std::vector <downlogstruct> & del)
{
	auto iter1 = del.begin ();
	auto iter21 = downLogRecode.begin ();
	auto iter22 = downLogRecode.begin ();
	for (;;)
	{
		for (iter21=iter22;iter21!=downLogRecode.end();++iter21)
		{
			if (iter1->str1==iter21->str1 && iter1->str2==iter21->str2)
			{
				downLogRecode.erase (iter21);
				iter22 = (--iter21);
			}
		}
		++iter1;
		if (iter1==del.end())
			break;
	}
	
	wirteToFile ();
	updownlog ();
}

//将数据在入到内存
BOOL	FileDownLog::UpdateDownLogList ()
{
	qiuwanli::FileDownLogFile log;
	std::fstream filedownlogin ("downlog", std::ios::in | std::ios::binary);
	if (!filedownlogin) {
		MessageBox (L"配置文件打开失败！");
		return FALSE;
	}

	if (!log.ParseFromIstream (&filedownlogin))
	{	//打开失败
		MessageBox (L"配置文件加载失败！");
		filedownlogin.close ();
		return FALSE;
	}
	else
	{	//解析配置文件
		for (int i = 0; i < log.filelog_size(); ++i)
		{
			const qiuwanli::FileDownLog& downlog =log.filelog(i);
			downLogRecode.push_back (std::move(
				downlogstruct (downlog.filename(), downlog.filepath (),
					downlog.filesize (), downlog.downtime (), downlog.status ()))
			);
		}
	}

	filedownlogin.close ();
	return TRUE;
}

//更新list显示数据
void FileDownLog::updownlog ()
{
	qiuwanli::utilty utility;
	int i = 0;
	for (auto iter=downLogRecode.begin(); iter !=downLogRecode.end(); ++iter)
	{
		pmyListCtrl->InsertItem (i, utility.StringToWstring (iter->str1).c_str ());
		pmyListCtrl->SetItemText (i, 1, utility.StringToWstring (iter->str2).c_str ());
		pmyListCtrl->SetItemText (i, 2, utility.StringToWstring (iter->str3).c_str ());
		pmyListCtrl->SetItemText (i, 3, utility.StringToWstring (iter->str4).c_str ());
		pmyListCtrl->SetItemText (i, 4, utility.StringToWstring (iter->str5).c_str ());
		++i;
	}

	FileDownLog::UpdateWindow ();
}

//
void FileDownLog::addDownlogItem (downlogstruct& add)
{
	downLogRecode.push_back (add);
	updownlog ();
}

//下载记录移除接口
void FileDownLog::removeDownlogItem (downlogstruct& add)
{
	for (auto iter=downLogRecode.begin();iter!=downLogRecode.end();++iter)
	{
		if (iter->str1.compare (add.str1) && iter->str2.compare (add.str2))
			downLogRecode.erase (iter);
	}

	updownlog ();
}
//获取多选对应列表的起始位置
//选中文件时，按住del按键，删除
//void FileDownLog::OnLvnKeydownList9 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	int i = 0;
//	int n = 0;
//	int to_delete[65535];
//
//	if (pLVKeyDow->wVKey == VK_DELETE)
//	{
//		POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
//		if (pos == NULL)
//		{
//			TRACE0 ("No  items were selected!/n");
//		}
//		else
//		{
//			while (pos)
//			{
//				to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
//			}
//		}
//		n = pmyListCtrl->GetSelectedCount ();//被选择总数；
//		int k = 0;
//		for (i = 0; i < n; i++)
//		{
//			pmyListCtrl->DeleteItem (to_delete[i] - k);//依依删除；
//			k++;
//		}
//	}
//
//	*pResult = 0;
//}

//删除选中的列表记录
//void FileDownLog::OnLvnKeydownList9 (NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	int i = 0;
//	int n = 0;
//	int to_delete[65535];
//
//	if (pLVKeyDow->wVKey == VK_DELETE)
//	{
//		POSITION  pos = pmyListCtrl->GetFirstSelectedItemPosition ();
//		if (pos == NULL)
//		{
//			TRACE0 ("No  items were selected!/n");
//		}
//		else
//		{
//			while (pos)
//			{
//				to_delete[i++] = pmyListCtrl->GetNextSelectedItem (pos);
//			}
//		}
//		n = pmyListCtrl->GetSelectedCount ();//被选择总数；
//		int k = 0;
//		for (i = 0; i < n; i++)
//		{
//			pmyListCtrl->DeleteItem (to_delete[i] - k);//依依删除；
//			k++;
//		}
//	}
//
//	*pResult = 0;
//}
