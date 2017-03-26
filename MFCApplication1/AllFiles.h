#ifndef ALLFILES_H
#define ALLFILES_H

#include "datadefine.h"
#include "MyDataStruct.pb.h"

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
	afx_msg void OnCreateUrl2Shared ();
	afx_msg void OnDelectChosedFiles ();
	afx_msg void OnMoveChosedFiles ();
	afx_msg void OnPasteFile2HerePath ();
	afx_msg void OnDownloadFiles ();
	afx_msg void OnCheckFilesProperty ();
	afx_msg void OnCopyFiles ();
	afx_msg void OnUploadFiles2CurrentPath ();
	afx_msg void OnCreateFolder2CurrentPath ();
	afx_msg void OnNMDblclkList5 (NMHDR *pNMHDR, LRESULT *pResult);
};


#endif // ALLFILES_H