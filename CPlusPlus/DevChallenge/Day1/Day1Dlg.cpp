
// Day1Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "Day1.h"
#include "Day1Dlg.h"
#include "afxdialogex.h"
#include "ClipboardHistory.h"

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


// CDay1Dlg ダイアログ



CDay1Dlg::CDay1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DAY1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strLastCopiedText = _T("");
	m_strArrayLog.RemoveAll();
}

void CDay1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDay1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_CLIPBOARDUPDATE, &CDay1Dlg::OnClipboardUpdate)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CDay1Dlg::OnBnClickedButtonLog)
END_MESSAGE_MAP()


// CDay1Dlg メッセージ ハンドラー

BOOL CDay1Dlg::OnInitDialog()
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
	SetWindowText(_T("Clipboard History Viewer"));

	// クリップボード更新のリスナーを追加
	if (!AddClipboardFormatListener(m_hWnd))
	{
		AfxMessageBox(_T("クリップボード監視の登録に失敗しました。"));
	}

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CDay1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDay1Dlg::OnPaint()
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
HCURSOR CDay1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/**
 * @fn
 * @brief	リスナー解除用
 * @param	なし
 * @return	なし
 */
void CDay1Dlg::PostNcDestroy()
{
	TRACE(_T("PostNcDestroy が呼ばれました\n"));

	// クリップボードリスナーを解除
	RemoveClipboardFormatListener(m_hWnd);

	// 基本クラスの PostNcDestroy を呼ぶ
	CDialogEx::PostNcDestroy();
}

/**
 * @fn
 * @brief	クリップボードに更新があった場合、CStringArray型に格納
 * @param	なし
 * @return	なし
 */
LRESULT CDay1Dlg::OnClipboardUpdate(WPARAM wParam, LPARAM lParam)
{
	if (OpenClipboard())  // クリップボードを開く
	{
		HANDLE hData = GetClipboardData(CF_UNICODETEXT);  // Unicode テキストを取得
		if (hData != NULL)
		{
			wchar_t* pszText = static_cast<wchar_t*>(GlobalLock(hData)); // グローバルメモリからポインタを取得
			if (pszText != NULL)
			{
				CString newText(pszText);	// コピーされた新しいテキスト
				GlobalUnlock(hData);		// メモリロック解除

				// 前回コピーされたテキストと比較
				if (newText != m_strLastCopiedText)  // 差異があった場合
				{
					// 差異があれば履歴に追加
					m_strArrayLog.Add(newText);
					m_strLastCopiedText = newText;  // 新しいテキストを保存
				}
			}
		}
		CloseClipboard();  // クリップボードを閉じる
	}
	else
	{
		AfxMessageBox(_T("クリップボードを開けませんでした"));
	}

	return 0;
}

/**
 * @fn
 * @brief	履歴閲覧ボタン
 * @param	なし
 * @return	なし
 */
void CDay1Dlg::OnBnClickedButtonLog()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CClipboardHistory dlg;
	dlg.SetHistoryArray(m_strArrayLog);
	dlg.DoModal();
}
