#pragma once
#include "datadefine.h"

// AllFiles 对话框

class AllFiles : public CDialogEx
{
	DECLARE_DYNAMIC(AllFiles)

public:
	AllFiles(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AllFiles();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW4 };
#endif

protected:
	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CListCtrl* pmyListCtrl;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMRClickList4 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList4 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList5 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList5 (NMHDR *pNMHDR, LRESULT *pResult);
};
