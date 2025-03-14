﻿
// PreTranslateMessageTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "PreTranslateMessageTest.h"
#include "PreTranslateMessageTestDlg.h"
#include "afxdialogex.h"
#include "SubDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPreTranslateMessageTestDlg ダイアログ



CPreTranslateMessageTestDlg::CPreTranslateMessageTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRETRANSLATEMESSAGETEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bTabFlag = FALSE;
}

void CPreTranslateMessageTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPreTranslateMessageTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_KILLFOCUS(IDC_EDIT_SAMPLE, &CPreTranslateMessageTestDlg::OnEnKillfocusEditSample)
	ON_BN_CLICKED(IDC_BUTTON_NEWDIALOG, &CPreTranslateMessageTestDlg::OnBnClickedButtonNewdialog)
END_MESSAGE_MAP()


// CPreTranslateMessageTestDlg メッセージ ハンドラー

BOOL CPreTranslateMessageTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CPreTranslateMessageTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CPreTranslateMessageTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CPreTranslateMessageTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/**
 * @fn
 * @brief	エディットボックスキルフォーカス処理
 * @param	なし
 * @return	なし
 */
void CPreTranslateMessageTestDlg::OnEnKillfocusEditSample()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CWnd* pWndCancel = GetDlgItem(IDCANCEL);
	CWnd* pWndFocus = GetFocus();
	if (pWndCancel == pWndFocus)
	{
		if (m_bTabFlag == TRUE)
		{
			// これは、Tabキーが押された場合
			// ⇒チェックはしたいので関数を抜けない
			m_bTabFlag = FALSE;	// もとに戻しておく
		}
		else
		{
			// キャンセルボタンが押されたのでチェックせず終わる
			return;
		}
	}

	// それ以外はチェック処理を進める
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_SAMPLE);
	CString strText;
	pEdit->GetWindowText(strText);		// エディットボックス内のテキストを取得します

	if (strText.GetLength() >= 5)
	{
		AfxMessageBox(_T("5桁以上入力されています。"));
	}

}

BOOL CPreTranslateMessageTestDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。
	if (pMsg->message == WM_KEYDOWN)	
	{
		// キーが押されました

		if (pMsg->wParam == VK_TAB)
		{
			// タブキーが押されたので、フラグを立てます
			m_bTabFlag = TRUE;
		}

		if (pMsg->wParam == VK_RIGHT)
		{
			// 「→」キーを押すと次のコントロールへフォーカス
			NextDlgCtrl();
		}
		else if (pMsg->wParam == VK_LEFT)
		{
			// 「←」キーを押すと前のコントロールへフォーカス
			PrevDlgCtrl();
		}

		if (pMsg->wParam == VK_ESCAPE)
		{
			CSubDialog dlg(_T("Escから起動しましたね。"));
			dlg.DoModal();
			delete dlg;
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CPreTranslateMessageTestDlg::OnBnClickedButtonNewdialog()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CSubDialog dlg(_T("実はEscからも起動できます。"));
	if (dlg.DoModal() == IDOK)
	{
		// 特に何もしない
	}
}
