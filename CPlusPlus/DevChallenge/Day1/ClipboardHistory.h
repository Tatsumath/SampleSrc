#pragma once
#include "afxdialogex.h"


// CClipboardHistory ダイアログ

class CClipboardHistory : public CDialogEx
{
	DECLARE_DYNAMIC(CClipboardHistory)

public:
	CClipboardHistory(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CClipboardHistory();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void SetHistoryArray(const CStringArray& strArray);

private:
	CListCtrl m_ctrlList;
	CStringArray m_strArrayDisp;
};
