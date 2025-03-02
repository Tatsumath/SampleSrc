// ClipboardHistory.cpp : 実装ファイル
//

#include "pch.h"
#include "Day1.h"
#include "afxdialogex.h"
#include "ClipboardHistory.h"


// CClipboardHistory ダイアログ

IMPLEMENT_DYNAMIC(CClipboardHistory, CDialogEx)

CClipboardHistory::CClipboardHistory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOG, pParent)
{

}

CClipboardHistory::~CClipboardHistory()
{
}

void CClipboardHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LOG, m_ctrlList);
}


BEGIN_MESSAGE_MAP(CClipboardHistory, CDialogEx)
END_MESSAGE_MAP()


// CClipboardHistory メッセージ ハンドラー

BOOL CClipboardHistory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください
	m_ctrlList.InsertColumn(0, _T("Clipboard History"), LVCFMT_LEFT, 500);

	LVITEM lvItem{};
	lvItem.mask = LVIF_TEXT;
	CString strTemp = _T("");

	for (int iRow = 0; iRow < m_strArrayDisp.GetCount(); iRow++)
	{
		lvItem.iItem = iRow;	// 行番号
		lvItem.iSubItem = 0;	// 列番号
		strTemp = m_strArrayDisp.GetAt(iRow);
		lvItem.pszText = strTemp.GetBuffer();
		m_ctrlList.InsertItem(&lvItem);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

/**
 * @fn
 * @brief	履歴内容受け渡し
 * @param	CStringArray&	履歴配列
 * @return	なし
 */
void CClipboardHistory::SetHistoryArray(const CStringArray& strArray)
{
	m_strArrayDisp.Copy(strArray);
}
