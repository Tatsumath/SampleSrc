﻿
// CEditTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCEditTestApp:
// このクラスの実装については、CEditTest.cpp を参照してください
//

class CCEditTestApp : public CWinApp
{
public:
	CCEditTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCEditTestApp theApp;
