#ifndef FILEDOWNLOG_H
#define FILEDOWNLOG_H

#include "datadefine.h"
#include "ProtoInterface.hpp"
#include <vector>
#include <boost/algorithm/algorithm.hpp>
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
	BOOL UpdateDownLogList ();
	void updownlog ();
	void mergeLog (std::vector <downlogstruct> & del);
	CListCtrl* pmyListCtrl;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	void wirteToFile ();
	std::vector<downlogstruct> downLogRecode;
	void addDownlogItem (downlogstruct& additemlog);
	void removeDownlogItem (downlogstruct& additemlog);
	afx_msg void OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClearDownloadLogList ();
	afx_msg void OnRetryDownloadFiles ();
	afx_msg void OnDelectChosedFileslog ();
	afx_msg void OnDelectChosedFiles ();
};


#endif // FILEDOWNLOG_H

