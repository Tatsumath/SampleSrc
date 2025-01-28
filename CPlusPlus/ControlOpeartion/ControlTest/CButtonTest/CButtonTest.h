
// CButtonTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCButtonTestApp:
// このクラスの実装については、CButtonTest.cpp を参照してください
//

class CCButtonTestApp : public CWinApp
{
public:
	CCButtonTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCButtonTestApp theApp;
