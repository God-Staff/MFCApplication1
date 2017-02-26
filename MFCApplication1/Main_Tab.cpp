// Main_Tab.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Main_Tab.h"


// Main_Tab

IMPLEMENT_DYNCREATE(Main_Tab, CWinAppEx)

Main_Tab::Main_Tab()
{
}

Main_Tab::~Main_Tab()
{
}

BOOL Main_Tab::InitInstance()
{
	// TODO:    在此执行任意逐线程初始化
	return TRUE;
}

int Main_Tab::ExitInstance()
{
	// TODO:    在此执行任意逐线程清理
	return CWinAppEx::ExitInstance();
}

BEGIN_MESSAGE_MAP(Main_Tab, CWinAppEx)
END_MESSAGE_MAP()


// Main_Tab 消息处理程序
