
// MFCApplication1Dlg.h : ͷ�ļ�
//
#ifndef MFC_DLG_H
#define MFC_DLG_H

#include "Main_UI.h"
#include "datadefine.h"
#include "MyDataStruct.pb.h"
#include <fstream>
//�����ⲿEXE
#include <shellapi.h>
#include "utility.hpp"
#include <ShlObj.h>

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
	//�ؼ�ָ�룬���ڲ���
	HICON m_hIcon;
	CEdit* edit1 = nullptr;
	CEdit* edit2 = nullptr;
	CEdit* edit3 = nullptr;

	//�û���¼��Ϣ�࣬������ʵ��
	qiuwanli::user	*user_login = nullptr;

	////����ָ����ڲ���
	//asio::io_service *io_service=nullptr;
	//asio::ip::tcp::socket *s = nullptr;
	//asio::ip::tcp::resolver *reslover = nullptr;

	//�ļ�ָ��,ָ��asio�����������ݿ�
	//std::fstream *net_user=nullptr;

	//���ļ��н�������
	void ListPeople (const qiuwanli::user& user_file);
	//void getUserAsio ();

	// ���ɵ���Ϣӳ�亯��

	//���ظ���� CDialogEx::OnInitDialog()����
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//�Ȼ�ȡPC���������кź�MAC��ַ������CPU��ţ�������Ψһ��UUID
	std::string getUuid ();
	//�û���¼
	afx_msg void OnBnClickedOk ();
	//ע���˺�
	afx_msg void OnBnClickedCancel ();
	//���˺��������ʱ���ӷ���˲�ѯ�û���Ϣ��������Ӧ����
	afx_msg void OnKillfocusEdit1 ();
	//ˢ����֤��
	//�������6λ��֤�룬������ͨ����������ת��ΪLPCTSTR��ʽ
	afx_msg void OnStnClickedStaticPic ();
};

#endif // MFC_DLG_H