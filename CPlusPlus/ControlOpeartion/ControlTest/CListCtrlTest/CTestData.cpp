#include "pch.h"
#include "CListCtrlTest.h"
#include "CTestData.h"
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

static char strNameList[][26] =
{
	"���R ���傤��",
	"���V ����",
	"�ߓ� ���q",
	"���� ����",
	"�g�� ����",
	"���� ����",
	"���{ ��",
	"�R�� �a�F",
	"��� ���q",
	"�R�� ����",
	"�镔 �ˎq",
	"�c�� �k���Y",
	"�ɓ� ����",
	"���q �R�I�q",
	"��c �a��",
	"���� ����",
	"�X�c �b��",
	"�g�� ���V",
	"�쌴 �L��",
	"�ɓ� �^��",
	"�V�� �`��",
	"��� ���q",
	"���� �N��",
	"�V�c �a�q",
	"���{ �E��",
	"���� �T�V",
};
void InitRandom()
{
	srand(static_cast<unsigned>(time(nullptr)));  // �V�[�h��ݒ�
}

/**
 * @fn
 * @brief	�R���X�g���N�^
 * @param	�Ȃ�
 * @return	�Ȃ�
 */
CTestData::CTestData()
{
	MakeData();
}

/**
 * @fn
 * @brief	�f�X�g���N�^
 * @param	�Ȃ�
 * @return	�Ȃ�
 */
CTestData::~CTestData()
{

}

/**
 * @fn
 * @brief	�e�X�g�f�[�^�쐬
 * @param	�Ȃ�
 * @return	�Ȃ�
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
 * @brief	�e�X�g�f�[�^�n��
 * @param	int			iRow		�s�ԍ�
 * @param	CString&	strId		ID
 * @param	CString&	strName		���O
 * @param	CString&	strJapanese	����
 * @param	CString&	strMath		���w
 * @param	CString&	strEnglish	�p��
 * @param	CString&	strScience	����
 * @param	CString&	strSS		�Љ�
 * @return	�Ȃ�
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