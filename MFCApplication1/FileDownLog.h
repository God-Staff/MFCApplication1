#pragma once
#include "datadefine.h"


// FileDownLog �Ի���

class FileDownLog : public CDialogEx
{
	DECLARE_DYNAMIC(FileDownLog)

public:
	FileDownLog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FileDownLog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW1 };
#endif

protected:

	CListCtrl* pmyListCtrl;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult);
};
