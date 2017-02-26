#pragma once
#include "datadefine.h"


// FileDownLog 对话框

class FileDownLog : public CDialogEx
{
	DECLARE_DYNAMIC(FileDownLog)

public:
	FileDownLog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FileDownLog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW1 };
#endif

protected:

	CListCtrl* pmyListCtrl;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult);
};
