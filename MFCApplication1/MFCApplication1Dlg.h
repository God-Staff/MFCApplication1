
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "Main_UI.h"
#include "datadefine.h"
//#include "Utilitys/login_all.pb.h"
//#include "Utilitys/uuidxx.h"


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CEdit* edit1;
	CEdit* edit2;
	CEdit* edit3;

	//用户登录信息类，创建个实例
	//qiuwanli::user	*user;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	std::string getUuid ();
	afx_msg void OnBnClickedOk ();
	afx_msg void OnBnClickedCancel ();
	afx_msg void OnKillfocusEdit1 ();
	//afx_msg void OnClickPic (CCmdUI *pCmdUI);
	afx_msg void OnStnClickedStaticPic ();
};
