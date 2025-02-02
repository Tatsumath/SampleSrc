
// CComboBoxTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "CComboBoxTest.h"
#include "CComboBoxTestDlg.h"
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


// CCComboBoxTestDlg ダイアログ



CCComboBoxTestDlg::CCComboBoxTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCOMBOBOXTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCComboBoxTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCComboBoxTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_TEST, &CCComboBoxTestDlg::OnCbnSelchangeComboTest)
END_MESSAGE_MAP()


// CCComboBoxTestDlg メッセージ ハンドラー

BOOL CCComboBoxTestDlg::OnInitDialog()
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

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_TEST);
	pCombo->InsertString(0, _T("1番目の選択肢"));
	pCombo->InsertString(1, _T("2番目の選択肢"));
	pCombo->InsertString(2, _T("3番目の選択肢"));
	pCombo->AddString(_T("AddStringで加えた"));
	pCombo->AddString(_T("あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめも"));
	pCombo->SetCurSel(1);	// 上から2番目をセット

	//pCombo->AddString(_T("Apple"));		// 1番目にApple
	//pCombo->AddString(_T("Banana"));		// 2番目にBanana
	//pCombo->AddString(_T("Orange"));		// 3番目にOrange
	//pCombo->AddString(_T("Apple Pie"));	// 4番目にApple Pie

	//pCombo->SelectString(-1, _T("Apple"));	// Index0から検索スタート
	//pCombo->SelectString(0, _T("Apple"));		// Index1から検索スタート
	//pCombo->SelectString(-1, _T("Cherry"));	// そんな文字列ない！！

	//pCombo->SetDroppedWidth(500);	// 選択中のボックス幅は500ピクセル

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCComboBoxTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCComboBoxTestDlg::OnPaint()
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
HCURSOR CCComboBoxTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/**
 * @fn
 * @brief	コンボボックスが変更されると呼ばれる
 * @param	なし
 * @return	なし
 */
void CCComboBoxTestDlg::OnCbnSelchangeComboTest()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_TEST);
	int iComboID = pCombo->GetCurSel();	// 選択番号
	CString strMes = _T("");	// メッセージボックス出力内容
	strMes.Format(_T("%d"), iComboID);
	AfxMessageBox(strMes);
}
