// SubDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "PreTranslateMessageTest.h"
#include "afxdialogex.h"
#include "SubDialog.h"


// CSubDialog ダイアログ

IMPLEMENT_DYNAMIC(CSubDialog, CDialogEx)

CSubDialog::CSubDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SUB, pParent)
{
	m_strStatic = _T("");
}

CSubDialog::CSubDialog(CString strText, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SUB, pParent)
{
	m_strStatic = strText;
}

CSubDialog::~CSubDialog()
{
}

void CSubDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_SUB, m_strStatic);
}


BEGIN_MESSAGE_MAP(CSubDialog, CDialogEx)
END_MESSAGE_MAP()


// CSubDialog メッセージ ハンドラー

BOOL CSubDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}
