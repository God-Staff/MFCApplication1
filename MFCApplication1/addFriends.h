#ifndef _ADDFRIENDS_H_
#define _ADDFRIENDS_H_

#include "datadefine.h"

// addFriends �Ի���

class addFriends : public CDialog
{
	DECLARE_DYNAMIC(addFriends)

public:
	addFriends(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~addFriends();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	CString user_name;
	int		user_Info_type;
	CString user_Info;

	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnKillfocusEdit1 ();
	afx_msg void OnBnClickedOk ();
};

#endif // _ADDFRIENDS_H_