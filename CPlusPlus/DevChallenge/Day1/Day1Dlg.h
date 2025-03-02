
// Day1Dlg.h : ヘッダー ファイル
//

#pragma once


// CDay1Dlg ダイアログ
class CDay1Dlg : public CDialogEx
{
// コンストラクション
public:
	CDay1Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DAY1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnClipboardUpdate(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLog();

	CString m_strLastCopiedText;	// 最後にコピーされたテキスト
	CStringArray m_strArrayLog;		// クリップボード履歴格納用
};
