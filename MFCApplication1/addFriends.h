#pragma once


// addFriends 对话框

class addFriends : public CDialog
{
	DECLARE_DYNAMIC(addFriends)

public:
	addFriends(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~addFriends();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	CString user_name;
	int		user_Info_type;
	CString user_Info;

	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnKillfocusEdit1 ();
	afx_msg void OnBnClickedOk ();
};
