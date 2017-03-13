
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "Main_UI.h"
#include "datadefine.h"
#include "login_all.pb.h"
//#include "Utilitys/uuidxx.h"
#include <fstream>
//调用外部EXE
#include <shellapi.h>
#include "utility.hpp"
#include <ShlObj.h>

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
	CEdit* edit1 = nullptr;
	CEdit* edit2 = nullptr;
	CEdit* edit3 = nullptr;

	//用户登录信息类，创建个实例
	qiuwanli::user	*user_login = nullptr;

	////定义指针便于操作
	//asio::io_service *io_service=nullptr;
	//asio::ip::tcp::socket *s = nullptr;
	//asio::ip::tcp::resolver *reslover = nullptr;

	//文件指针,指向asio发送来的数据块
	//std::fstream *net_user=nullptr;

	//从文件中解析对象
	void ListPeople (const qiuwanli::user& user_file);
	//void getUserAsio ();

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
