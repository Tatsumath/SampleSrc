
// CListCtrlTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "CListCtrlTest.h"
#include "CListCtrlTestDlg.h"
#include "afxdialogex.h"
#include "CTestData.h"

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


// CCListCtrlTestDlg ダイアログ



CCListCtrlTestDlg::CCListCtrlTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLISTCTRLTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bDataInputInit = TRUE;
}

void CCListCtrlTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCListCtrlTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CCListCtrlTestDlg::OnBnClickedButtonInput)
END_MESSAGE_MAP()


// CCListCtrlTestDlg メッセージ ハンドラー

BOOL CCListCtrlTestDlg::OnInitDialog()
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
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_TEST);
	pListCtrl->InsertColumn(0, _T("列1(左寄せ)"), LVCFMT_LEFT, 200);
	pListCtrl->InsertColumn(1, _T("列2(中央寄せ)"), LVCFMT_CENTER, 200);
	pListCtrl->InsertColumn(2, _T("列3(右寄せ)"), LVCFMT_RIGHT, 200);

	LVITEM lvItem{};
	lvItem.mask = LVIF_TEXT;
	CString strTemp = _T("");

	lvItem.iItem = 0;	// 行番号	// 行番号
	// 1行目
	lvItem.iSubItem = 0;	// 列番号
	strTemp = _T("行1列1");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->InsertItem(&lvItem);

	lvItem.iSubItem = 1;	// 列番号
	strTemp = _T("行1列2");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->SetItem(&lvItem);

	lvItem.iSubItem = 2;	// 列番号
	strTemp = _T("行1列3");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->SetItem(&lvItem);


	lvItem.iItem = 1;	// 行番号	// 行番号
	// 1行目
	lvItem.iSubItem = 0;	// 列番号
	strTemp = _T("行2列1");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->InsertItem(&lvItem);

	lvItem.iSubItem = 1;	// 列番号
	strTemp = _T("行2列2");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->SetItem(&lvItem);

	lvItem.iSubItem = 2;	// 列番号
	strTemp = _T("行2列3");
	lvItem.pszText = strTemp.GetBuffer();
	pListCtrl->SetItem(&lvItem);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCListCtrlTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCListCtrlTestDlg::OnPaint()
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
HCURSOR CCListCtrlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/**
 * @fn
 * @brief	データ取込ボタンが押されました
 * @param	なし
 * @return	なし
 */
void CCListCtrlTestDlg::OnBnClickedButtonInput()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_TEST);
	pListCtrl->DeleteAllItems();	// 全削除

	if (m_bDataInputInit)
	{
		m_bDataInputInit = FALSE;	//以降列処理はしなくてよい。
		// 既存の列を削除
		int columnCount = pListCtrl->GetHeaderCtrl()->GetItemCount();
		for (int i = columnCount - 1; i >= 0; i--)
		{
			pListCtrl->DeleteColumn(i);
		}

		//列再設定
		pListCtrl->InsertColumn(0, _T("ID"), LVCFMT_LEFT, 80);
		pListCtrl->InsertColumn(1, _T("名前"), LVCFMT_LEFT, 150);
		pListCtrl->InsertColumn(2, _T("国語"), LVCFMT_LEFT, 70);
		pListCtrl->InsertColumn(3, _T("数学"), LVCFMT_LEFT, 70);
		pListCtrl->InsertColumn(4, _T("英語"), LVCFMT_LEFT, 70);
		pListCtrl->InsertColumn(5, _T("理科"), LVCFMT_LEFT, 70);
		pListCtrl->InsertColumn(6, _T("社会"), LVCFMT_LEFT, 70);
	}

	LVITEM lvItem{};
	lvItem.mask = LVIF_TEXT;
	CString strID = _T("");
	CString strName = _T("");
	CString strJapanese = _T("");
	CString strMath = _T("");
	CString strEnglish = _T("");
	CString strScience = _T("");
	CString strSocialStudy = _T("");

	CTestData TestData;
	for (int iRow = 0; iRow < TestData.iGetStudentNum(); iRow++)
	{
		lvItem.iItem = iRow;

		TestData.GetRowData(iRow, strID, strName, strJapanese, strMath, strEnglish, strScience, strSocialStudy);

		// ID列
		lvItem.iSubItem = 0;
		lvItem.pszText = strID.GetBuffer();
		pListCtrl->InsertItem(&lvItem);

		// 名前列
		lvItem.iSubItem = 1;
		lvItem.pszText = strName.GetBuffer();
		pListCtrl->SetItem(&lvItem);

		// 国語列
		lvItem.iSubItem = 2;
		lvItem.pszText = strJapanese.GetBuffer();
		pListCtrl->SetItem(&lvItem);

		// 数学列
		lvItem.iSubItem = 3;
		lvItem.pszText = strMath.GetBuffer();
		pListCtrl->SetItem(&lvItem);

		// 英語列
		lvItem.iSubItem = 4;
		lvItem.pszText = strEnglish.GetBuffer();
		pListCtrl->SetItem(&lvItem);

		// 理科列
		lvItem.iSubItem = 5;
		lvItem.pszText = strScience.GetBuffer();
		pListCtrl->SetItem(&lvItem);

		// 社会列
		lvItem.iSubItem = 6;
		lvItem.pszText = strSocialStudy.GetBuffer();
		pListCtrl->SetItem(&lvItem);
	}

}
