#ifndef REG_H
#define REG_H

#include "datadefine.h"

// reg �Ի���
class reg : public CDialogEx
{
	DECLARE_DYNAMIC(reg)

public:
	reg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~reg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG1 };
#endif

protected:
	virtual BOOL OnInitDialog ();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	CEdit* edit1;
	CEdit* edit2;
	CEdit* edit3;
	CEdit* edit4;
	CEdit* edit5;

	DECLARE_MESSAGE_MAP()
public:
	//��֤�û�ע����Ϣ���û����Լ��������Ч��
	afx_msg void OnBnClickedCancel ();
	//���û�����ע��ʱ�����ص���¼����
	afx_msg void OnBnClickedOk ();
	//�������6λ���ִ��桰���»�ȡ��֤�롱
	afx_msg void OnBnClickedCancel2 ();
	//���ڶ��������������ʱ,��֤�������Ч�Ժ�һ����
	afx_msg void OnEnKillfocusEdit23 ();
	afx_msg void OnEnKillfocusEdit21 ();
};

#endif // REG_H
