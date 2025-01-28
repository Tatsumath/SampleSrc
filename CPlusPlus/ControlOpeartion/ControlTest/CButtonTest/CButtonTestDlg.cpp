
// CButtonTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "CButtonTest.h"
#include "CButtonTestDlg.h"
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


// CCButtonTestDlg ダイアログ



CCButtonTestDlg::CCButtonTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CBUTTONTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCButtonTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCButtonTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CCButtonTestDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_CHECK_TEST, &CCButtonTestDlg::OnBnClickedCheckTest)
	ON_BN_CLICKED(IDC_RADIO_TEST1, &CCButtonTestDlg::OnBnClickedRadioTest1)
	ON_BN_CLICKED(IDC_RADIO_TEST2, &CCButtonTestDlg::OnBnClickedRadioTest2)
END_MESSAGE_MAP()


// CCButtonTestDlg メッセージ ハンドラー

/**
 * @fn
 * @brief	初期表示処理
 * @param	なし
 * @return	BOOL	TRUE
 */
BOOL CCButtonTestDlg::OnInitDialog()
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
	SetWindowText(_T("ボタンを押してみよう！！"));
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON_TEST);	// ボタンポインタ
	pButton->SetWindowText(_T("ここを押す"));
	pButton = (CButton*)GetDlgItem(IDC_CHECK_TEST);				// チェックボックスポインタ
	pButton->SetWindowText(_T("チェック状態を考えよう！"));
	pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST1);			// ラジオボタン1ポインタ
	pButton->SetWindowText(_T("ラジオボタン1"));
	pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST2);			// ラジオボタン2ポインタ
	pButton->SetWindowText(_T("ラジオボタン2"));

	//pButton = (CButton*)GetDlgItem(IDC_CHECK_TEST);				// チェックボックスポインタ
	//pButton->SetCheck(BST_CHECKED);		// チェックボックスにチェックします
	//pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST1);			// ラジオボタン1ポインタ
	//pButton->SetCheck(BST_CHECKED);		// ラジオボタン1ニチェックします

	pButton = (CButton*)GetDlgItem(IDC_BUTTON_TEST);
	pButton->EnableWindow(FALSE);	// 初期状態で、ボタンは非活性に
	pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST1);
	pButton->EnableWindow(FALSE);	// 初期状態で、ラジオボタン1は非活性に
	pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST2);
	pButton->EnableWindow(FALSE);	// 初期状態で、ラジオボタン2は非活性に

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCButtonTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCButtonTestDlg::OnPaint()
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
HCURSOR CCButtonTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/**
 * @fn
 * @brief	ボタンが押されると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCButtonTestDlg::OnBnClickedButtonTest()
{
	//AfxMessageBox(_T("ボタンが押されました。"));

	/*
	// チェックボックス状態取得
	CButton* pButton = (CButton*)GetDlgItem(IDC_CHECK_TEST);	// チェックボックスポインタ
	if (pButton->GetCheck() == BST_CHECKED)
	{
		// チェックボックスはチェック状態
		AfxMessageBox(_T("チェックボックスにチェックがあります"));
	}
	else
	{
		// チェックボックスはチェックされていない
		AfxMessageBox(_T("チェックボックスにチェックがありません"));
	}

	// ラジオボタン状態取得
	pButton = (CButton*)GetDlgItem(IDC_RADIO_TEST1);	// ラジオボタン1ポインタ
	if (pButton->GetCheck() == BST_CHECKED)
	{
		// ラジオボタン1はチェック状態
		AfxMessageBox(_T("ラジオボタン1が選択されています"));
	}
	else
	{
		// ラジオボタン1はチェックされていない
		AfxMessageBox(_T("ラジオボタン1が選択されていません"));
	}
	*/

	AfxMessageBox(_T("成功です！！"));
}

/**
 * @fn
 * @brief	チェックボックスが変更されると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCButtonTestDlg::OnBnClickedCheckTest()
{
	//AfxMessageBox(_T("チェックボックスが変更されました。"));

	// ポインタ宣言
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON_TEST);
	CButton* pButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_TEST);
	CButton* pButtonRadio1 = (CButton*)GetDlgItem(IDC_RADIO_TEST1);
	CButton* pButtonRadio2 = (CButton*)GetDlgItem(IDC_RADIO_TEST2);

	// チェックボックスの状態により、ラジオボタン押下可否を設定
	if (pButtonCheck->GetCheck() == BST_CHECKED)
	{
		// チェックされました。⇒ラジオボタン1だけ押下可能に
		pButtonRadio1->EnableWindow(TRUE);
		pButton->EnableWindow(FALSE);
		pButtonRadio2->EnableWindow(FALSE);

		// ラジオボタンは初期化します
		pButtonRadio1->SetCheck(BST_UNCHECKED);
		pButtonRadio2->SetCheck(BST_UNCHECKED);
	}
	else
	{
		// ラジオボタン2がチェックされてる⇒ボタンが押せるように!!
		if (pButtonRadio2->GetCheck() == BST_CHECKED)
		{
			pButton->EnableWindow(TRUE);

			pButtonRadio1->EnableWindow(FALSE);
		}
		else
		{
			// ラジオボタン2が選択されてない場合、初めからやり直し
			pButton->EnableWindow(FALSE);
			pButtonRadio1->EnableWindow(FALSE);
			pButtonRadio2->EnableWindow(FALSE);
			// ラジオボタンは初期化します
			pButtonRadio1->SetCheck(BST_UNCHECKED);
			pButtonRadio2->SetCheck(BST_UNCHECKED);
		}
	}
}

/**
 * @fn
 * @brief	ラジオボタン1が押されると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCButtonTestDlg::OnBnClickedRadioTest1()
{
	//AfxMessageBox(_T("ラジオボタン1が押されました。"));
	CButton* pButtonRadio1 = (CButton*)GetDlgItem(IDC_RADIO_TEST1);
	if (pButtonRadio1->GetCheck() == BST_CHECKED)
	{
		// ラジオボタン1が選択されると、ラジオボタン2が押せるようになる
		CButton* pButtonRadio2 = (CButton*)GetDlgItem(IDC_RADIO_TEST2);
		pButtonRadio2->EnableWindow(TRUE);
	}
}

/**
 * @fn
 * @brief	ラジオボタン2が押されると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCButtonTestDlg::OnBnClickedRadioTest2()
{
	//AfxMessageBox(_T("ラジオボタン2が押されました。"));
	// 特にイベントは起こらない
}
