#pragma once


class CTestData
{
public:
	CTestData();	// コンストラクタ
	~CTestData();	// デストラクタ

	void GetRowData(int iRow, CString& strId, CString& strName,
		CString& strJapanese, CString& strMath, CString& strEnglish, CString& strScience, CString& strSS);

	int iGetStudentNum() { return iStudentNum; }	// 生徒数

private:
	const int iStudentNum = 26;
	const int iColInfoNum = 7;
	CString strData[26][7];
	void MakeData();
};