#pragma once
#include "afxdialogex.h"


// CSubDialog ダイアログ

class CSubDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDialog)

public:
	CSubDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	CSubDialog(CString strText, CWnd* pParent = nullptr);
	virtual ~CSubDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SUB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
private:
	CString m_strStatic;
public:
	virtual BOOL OnInitDialog();
};
