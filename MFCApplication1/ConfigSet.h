#pragma once
#include "datadefine.h"


// ConfigSet 对话框

class ConfigSet : public CDialogEx
{
	DECLARE_DYNAMIC(ConfigSet)

public:
	ConfigSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ConfigSet();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW3 };
#endif

protected:
	CListCtrl*  m_ListControl;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1 ();
	afx_msg void OnNMRClickList6 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAddFilesPath ();
	afx_msg void OnDelectFilesPath ();
	afx_msg void OnUpdateFilePathList ();
};
