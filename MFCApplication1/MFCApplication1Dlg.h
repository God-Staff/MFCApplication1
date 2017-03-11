
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "Main_UI.h"
#include "datadefine.h"
#include "login_all.pb.h"
//#include "Utilitys/uuidxx.h"
#include <fstream>

// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CEdit* edit1;
	CEdit* edit2;
	CEdit* edit3;

	//�û���¼��Ϣ�࣬������ʵ��
	qiuwanli::user	*user_login=nullptr;

	//�ļ�ָ��,ָ��asio�����������ݿ�
	std::fstream *net_user=nullptr;

	//���ļ��н�������
	void ListPeople (const qiuwanli::user& user_file);
	void getUserAsio ();

	// ���ɵ���Ϣӳ�亯��
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
