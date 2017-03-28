#ifndef FILEDOWNLOG_H
#define FILEDOWNLOG_H

#include "datadefine.h"
#include "ProtoInterface.hpp"
#include <vector>
#include <boost/unordered/>
#include <boost/algorithm/algorithm.hpp>
//���ڴ洢���ؼ�¼����
class downlogstruct
{
public:
	downlogstruct (std::string  str11, std::string  str22, std::string  str33, std::string  str44, std::string  str55) :
		str1 (str11), str2 (str22), str3 (str33) , str4 (str44), str5 (str55) {}
	std::string  str1;
	std::string  str2;
	std::string  str3;
	std::string  str4;
	std::string  str5;

};

std::vector<downlogstruct> downLogRecode;
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
	//void OnKeydownListFile (NMHDR * pNMHDR, LRESULT * pResult);
	CListCtrl* pmyListCtrl;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	void addDownlogItem (downlogstruct& additemlog);
	void removeDownlogItem (downlogstruct& additemlog);
	//afx_msg void OnLvnItemchangedList2 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList9 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClearDownloadLogList ();
	afx_msg void OnRetryDownloadFiles ();
	afx_msg void OnDelectChosedFileslog ();
	afx_msg void OnDelectChosedFiles ();
	afx_msg void OnLvnKeydownList9 (NMHDR *pNMHDR, LRESULT *pResult);
};


#endif // FILEDOWNLOG_H

