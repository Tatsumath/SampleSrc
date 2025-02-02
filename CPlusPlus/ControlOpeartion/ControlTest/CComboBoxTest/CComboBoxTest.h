
// CComboBoxTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCComboBoxTestApp:
// このクラスの実装については、CComboBoxTest.cpp を参照してください
//

class CCComboBoxTestApp : public CWinApp
{
public:
	CCComboBoxTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCComboBoxTestApp theApp;
