#pragma once
#include "datadefine.h"


// reg_info �Ի���

class reg_info : public CDialogEx
{
	DECLARE_DYNAMIC(reg_info)

public:
	reg_info(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~reg_info();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel ();
	afx_msg void OnBnClickedOk ();
};
