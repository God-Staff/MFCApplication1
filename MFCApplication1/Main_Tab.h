#pragma once
#include "datadefine.h"



// Main_Tab

class Main_Tab : public CWinAppEx
{
	DECLARE_DYNCREATE(Main_Tab)

protected:
	Main_Tab();           // 动态创建所使用的受保护的构造函数
	virtual ~Main_Tab();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


