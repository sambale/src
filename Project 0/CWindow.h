

#ifndef CWindows_H
#define CWindows_H


#include <algorithm>
#include <string>
#include <iostream>
#include "CDrawing.h"

#pragma comment ( lib, "d3d9.lib" )
#pragma comment ( lib, "d3dx9.lib" )


#define WINDOW_BACKGROUND		D3DCOLOR_ARGB ( 255, 29, 31, 33 )
#define WINDOW_BORDER			D3DCOLOR_ARGB ( 255, 42, 44, 45 )
#define WINDOW_HEAD				D3DCOLOR_ARGB ( 255, 60, 63, 65 )
#define WINDOW_BAR_LEFT			D3DCOLOR_ARGB ( 255, 60, 63, 65 )
#define WINDOW_BAR_RIGHT		D3DCOLOR_ARGB ( 255, 93, 95, 96 )
#define WINDOW_TEXT				D3DCOLOR_ARGB ( 255, 255, 255, 255 )


#define TABCONTROL_DEFAULT		D3DCOLOR_ARGB ( 255, 50, 53, 55 )
#define TABCONTROL_HOVER		D3DCOLOR_ARGB ( 255, 71, 72, 75 )
#define TABCONTROL_ACTIVE		D3DCOLOR_ARGB ( 255, 39, 41, 43 )
#define TABCONTROL_BORDER		D3DCOLOR_ARGB ( 255, 42, 44, 45 )
#define TABCONTROL_TEXT			D3DCOLOR_ARGB ( 255, 255, 255, 255 )
#define TABCONTROL_ACTIVE_LEFT	D3DCOLOR_ARGB ( 255, 222, 50, 60 )

#define CHECKBOX_DEFAULT		D3DCOLOR_ARGB ( 255, 50, 53, 55 )
#define CHECKBOX_HOVER			D3DCOLOR_ARGB ( 255, 71, 72, 75 )
#define CHECKBOX_ACTIVE			D3DCOLOR_ARGB ( 255, 39, 41, 43 )
#define CHECKBOX_ACTIVE_FRONT	D3DCOLOR_ARGB ( 255, 222, 50, 60 )
#define CHECKBOX_BORDER			D3DCOLOR_ARGB ( 255, 42, 44, 45 )
#define CHECKBOX_TEXT			D3DCOLOR_ARGB ( 255, 255, 255, 255 )


#define ENABLE_TEXT				D3DCOLOR_ARGB ( 255, 255, 255, 255 )
#define ENABLE_TEXT_HOVER		D3DCOLOR_ARGB ( 255, 222, 50, 60 )
#define ENABLE_TEXT_ACTIVE		D3DCOLOR_ARGB ( 255, 50, 222, 10 )
#define ENABLE_HOVER			D3DCOLOR_ARGB ( 255, 71, 72, 75 )
#define ENABLE_DEFAULT			D3DCOLOR_ARGB ( 255, 50, 53, 55 )
#define ENABLE_BORDER			D3DCOLOR_ARGB ( 255, 42, 44, 45 )
#define ENABLE_ACTIVE			D3DCOLOR_ARGB ( 255, 39, 41, 43 )

#define TabControl_General		0x1
#define TabControl_Player		0x2
#define TabControl_Viewer		0x3
#define TabControl_Sense		0x4
#define TabControl_Aimming		0x5
#define TabControl_Setting		0x6


extern int TabIndex;
extern int Ticks;




class CWindow : public CDrawing
{
public:

	D3DXVECTOR2 size;
	D3DXVECTOR2 position;

	BOOL IsInBox(float x, float y, float w, float h);
	VOID WINAPI TabControl ( CONST WCHAR * Title, D3DXVECTOR2 position, D3DXVECTOR2 size, int &active, int SetDefault, int Index );
	VOID WINAPI CheckBox ( D3DXVECTOR2 position, CONST WCHAR * title, int &active, int Index );
	VOID WINAPI RadioBox ( D3DXVECTOR2 position, CONST WCHAR * title, int &active, int SetDefault, int Index );
	int GetTextLength ( char *szString, ... );
	VOID WINAPI Form ( D3DXVECTOR2 position );
	VOID WINAPI Window ( D3DXVECTOR2 position, D3DXVECTOR2 size, const char * title );
	VOID WINAPI Enable ( D3DXVECTOR2 position, D3DXVECTOR2 size, bool &imported );



};

extern CWindow Window;


#endif




