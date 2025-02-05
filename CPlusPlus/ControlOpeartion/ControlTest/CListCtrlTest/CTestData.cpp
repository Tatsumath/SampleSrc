#include "pch.h"
#include "CListCtrlTest.h"
#include "CTestData.h"
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

static char strNameList[][26] =
{
	"松山 きょうこ",
	"中澤 元博",
	"近藤 愛子",
	"勝又 美樹",
	"吉川 直美",
	"安藤 千代美",
	"杉本 清",
	"山崎 和彦",
	"手塚 晴子",
	"山口 梨紗",
	"磯部 祥子",
	"田中 耕太郎",
	"伊藤 周作",
	"金子 由紀子",
	"野田 和美",
	"猪俣 歩美",
	"森田 恵美",
	"吉川 靖之",
	"川原 有紗",
	"伊藤 真衣",
	"齋藤 義徳",
	"川上 純子",
	"阿部 哲矢",
	"新田 和子",
	"松本 勇次",
	"松原 裕之",
};
void InitRandom()
{
	srand(static_cast<unsigned>(time(nullptr)));  // シードを設定
}

/**
 * @fn
 * @brief	コンストラクタ
 * @param	なし
 * @return	なし
 */
CTestData::CTestData()
{
	MakeData();
}

/**
 * @fn
 * @brief	デストラクタ
 * @param	なし
 * @return	なし
 */
CTestData::~CTestData()
{

}

/**
 * @fn
 * @brief	テストデータ作成
 * @param	なし
 * @return	なし
 */
void CTestData::MakeData()
{
	for (int iRow = 0; iRow < iStudentNum; iRow++)
	{
		CString strID = _T("");
		strID.Format(_T("%04d"), iRow + 1);
		strData[iRow][0] = strID;

		strData[iRow][1] = strNameList[iRow];
		for (int iCol = 2; iCol < iColInfoNum; iCol++)
		{
			int iRand = rand() % 101;
			CString strScore = _T("");
			strScore.Format(_T("%d"), iRand);

			strData[iRow][iCol] = strScore;
		}
	}
}

/**
 * @fn
 * @brief	テストデータ渡し
 * @param	int			iRow		行番号
 * @param	CString&	strId		ID
 * @param	CString&	strName		名前
 * @param	CString&	strJapanese	国語
 * @param	CString&	strMath		数学
 * @param	CString&	strEnglish	英語
 * @param	CString&	strScience	理科
 * @param	CString&	strSS		社会
 * @return	なし
 */
void CTestData::GetRowData(	int iRow, 
							CString& strId, 
							CString& strName,
							CString& strJapanese, 
							CString& strMath, 
							CString& strEnglish, 
							CString& strScience, 
							CString& strSS)
{
	strId = strData[iRow][0];
	strName = strData[iRow][1];
	strJapanese = strData[iRow][2];
	strMath = strData[iRow][3];
	strEnglish = strData[iRow][4];
	strScience = strData[iRow][5];
	strSS = strData[iRow][6];
}