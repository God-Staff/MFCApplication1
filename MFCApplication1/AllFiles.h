#pragma once
#include "datadefine.h"

// AllFiles �Ի���

class AllFiles : public CDialogEx
{
	DECLARE_DYNAMIC(AllFiles)

public:
	AllFiles(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AllFiles();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW4 };
#endif

protected:
	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CListCtrl* pmyListCtrl;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMRClickList4 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList4 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList5 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList5 (NMHDR *pNMHDR, LRESULT *pResult);
};
