#pragma once
#include "datadefine.h"



// Main_Tab

class Main_Tab : public CWinAppEx
{
	DECLARE_DYNCREATE(Main_Tab)

protected:
	Main_Tab();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~Main_Tab();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


