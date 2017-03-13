#pragma once
#include "datadefine.h"
#include "config.pb.h"
#include "utility.hpp"

// ConfigSet �Ի���

class ConfigSet : public CDialogEx
{
	DECLARE_DYNAMIC(ConfigSet)

public:
	ConfigSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ConfigSet();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW3 };
#endif

protected:
	qiuwanli::ConfigFile *configFile=nullptr;
	BOOL		configInit ();			//���������ļ�
	BOOL		updateConfig ();		//���������ļ�

	CEdit		*downpath		= nullptr;
	CEdit		*downSpeed		= nullptr;
	CEdit		*UploadSpeed	= nullptr;
	CComboBox	*box1			= nullptr;
	CComboBox	*box2			= nullptr;
	CListCtrl	*m_ListControl	= nullptr;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog ();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1 ();
	afx_msg void OnNMRClickList6 (NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAddFilesPath ();
	afx_msg void OnDelectFilesPath ();
	afx_msg void OnUpdateFilePathList ();
	afx_msg void OnCbnSelchangeCombo1 ();
	afx_msg void OnCbnSelchangeCombo2 ();
	afx_msg void OnBnClickedButton2 ();
	//afx_msg void OnBnClickedButton3 ();
	//afx_msg void OnBnClickedButton4 ();
};
