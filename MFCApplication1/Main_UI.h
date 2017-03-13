#ifndef MAIN_UI_H
#define MAIN_UI_H

#include "ConfigSet.h"
#include "do_ref.h"
#include "mytab.h"
#include "FileDownLog.h"
#include "AllFiles.h"
#include "FriendShared.h"
#include "datadefine.h"

// Main_UI 对话框

class Main_UI : public CDialogEx
{
	DECLARE_DYNAMIC(Main_UI)

public:
	Main_UI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Main_UI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG4 };
#endif

protected:
	virtual BOOL OnInitDialog ();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	FriendShared*	fileshared;
	FileDownLog*	filedownlog;
	AllFiles*		allfiles;
	ConfigSet*		mysetting;
	mytab*			mytabui;

	int change_table;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticpic21 ();
	afx_msg void OnStnClickedStaticpic23 ();
	afx_msg void OnStnClickedStaticpic22 ();
	afx_msg void OnStnClickedStaticpic24 ();
	afx_msg void OnStnClickedStaticpic25 ();

	void swithTable (int i);

};

#endif // MAIN_UI_H
