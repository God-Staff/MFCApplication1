#ifndef MYTAB_H
#define MYTAB_H

#include "datadefine.h"

// mytab �Ի���
class mytab : public CDialog
{
	DECLARE_DYNAMIC(mytab)

public:
	mytab(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~mytab();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif

protected:
	CListCtrl* pmyListCtrl;
	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL UpdateDownLogList ();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	afx_msg void OnBnClickedButton1 ();
	afx_msg void OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList2 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAllFliesStartDownload ();
	afx_msg void OnAllFilesDowning2Pause ();
	afx_msg void OnRemoveAllDowningFlies ();
	afx_msg void OnStartChosedFiles2Downing ();
	afx_msg void OnPusedChosedFilesDowning ();
	afx_msg void OnDelectChosedFilesFromList ();
	afx_msg void OnChangePriority4Files ();
};
#endif // MYTAB_H
