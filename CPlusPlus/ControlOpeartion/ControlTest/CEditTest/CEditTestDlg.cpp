﻿
// CEditTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "CEditTest.h"
#include "CEditTestDlg.h"
#include "afxdialogex.h"

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


// CCEditTestDlg ダイアログ



CCEditTestDlg::CCEditTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CEDITTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCEditTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCEditTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_TEST, &CCEditTestDlg::OnEnChangeEditTest)
	ON_EN_SETFOCUS(IDC_EDIT_TEST, &CCEditTestDlg::OnEnSetfocusEditTest)
	ON_EN_KILLFOCUS(IDC_EDIT_TEST, &CCEditTestDlg::OnEnKillfocusEditTest)
END_MESSAGE_MAP()


// CCEditTestDlg メッセージ ハンドラー

BOOL CCEditTestDlg::OnInitDialog()
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
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEST);
	pEdit->SetWindowText(_T("Edit Controlにテキストを設定します。"));	// テキスト設定
	pEdit->SetLimitText(20);

	//pEdit->ShowWindow(SW_HIDE);	// 非表示
	pEdit->ShowWindow(SW_SHOW);	// 表示

	//pEdit->EnableWindow(FALSE);	// 非活性
	pEdit->EnableWindow(TRUE);	// 活性

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCEditTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCEditTestDlg::OnPaint()
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
HCURSOR CCEditTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/**
 * @fn
 * @brief	エディットボックスの中身が更新されるたびに呼ばれる
 * @param	なし
 * @return	なし
 */
void CCEditTestDlg::OnEnChangeEditTest()
{
	AfxMessageBox(_T("Change関数が呼ばれました"));
}

/**
 * @fn
 * @brief	エディットボックスにフォーカスがセットされると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCEditTestDlg::OnEnSetfocusEditTest()
{
	AfxMessageBox(_T("Set Focus関数が呼ばれました"));
}

/**
 * @fn
 * @brief	エディットボックスからフォーカスが外れると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCEditTestDlg::OnEnKillfocusEditTest()
{
	AfxMessageBox(_T("Kill Focus関数が呼ばれました"));

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEST);
	CString strText;				// テキストを格納します
	pEdit->GetWindowText(strText);	// テキスト取得
	AfxMessageBox(strText);			// ちゃんと取得できてるか確認
	
}
