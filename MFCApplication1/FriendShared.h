#pragma once
#include "datadefine.h"
#include "addFriends.h"


// FriendShared �Ի���

class FriendShared : public CDialogEx
{
	DECLARE_DYNAMIC(FriendShared)

public:
	FriendShared(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FriendShared();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW2 };
#endif

protected:
	CListCtrl*  m_ListControl;
	CListCtrl*  m_ListContro2;

	virtual BOOL FriendShared::OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnNMRClickList7 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList8 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAddFriends ();
	afx_msg void OnDelFriend ();
	afx_msg void OnShared2Friends ();
	afx_msg void OnchangeMark ();
	afx_msg void OnDelectSharedURL ();
	afx_msg void OnSendUrl2Friends ();
	afx_msg void OnAddSharedUrl ();
};
