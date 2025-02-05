#pragma once


class CTestData
{
public:
	CTestData();	// �R���X�g���N�^
	~CTestData();	// �f�X�g���N�^

	void GetRowData(int iRow, CString& strId, CString& strName,
		CString& strJapanese, CString& strMath, CString& strEnglish, CString& strScience, CString& strSS);

	int iGetStudentNum() { return iStudentNum; }	// ���k��

private:
	const int iStudentNum = 26;
	const int iColInfoNum = 7;
	CString strData[26][7];
	void MakeData();
};