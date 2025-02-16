
// PreTranslateMessageTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CPreTranslateMessageTestApp:
// このクラスの実装については、PreTranslateMessageTest.cpp を参照してください
//

class CPreTranslateMessageTestApp : public CWinApp
{
public:
	CPreTranslateMessageTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CPreTranslateMessageTestApp theApp;
