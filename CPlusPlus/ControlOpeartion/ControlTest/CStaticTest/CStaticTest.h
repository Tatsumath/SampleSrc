
// CStaticTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCStaticTestApp:
// このクラスの実装については、CStaticTest.cpp を参照してください
//

class CCStaticTestApp : public CWinApp
{
public:
	CCStaticTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCStaticTestApp theApp;
