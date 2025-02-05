
// CListCtrlTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCListCtrlTestApp:
// このクラスの実装については、CListCtrlTest.cpp を参照してください
//

class CCListCtrlTestApp : public CWinApp
{
public:
	CCListCtrlTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCListCtrlTestApp theApp;
