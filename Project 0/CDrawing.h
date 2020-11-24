

#ifndef CDrawing_H
#define CDrawing_H

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment ( lib, "d3d9.lib" )
#pragma comment ( lib, "d3dx9.lib" )
#include "main.h"


extern	LPD3DXFONT pFont;
extern	LPD3DXLINE pLine;
extern	LPD3DXFONT TabFont;
extern	LPD3DXFONT HeadFont;
LPDIRECT3DDEVICE9 gpDevice = NULL;
IDirect3DDevice9Ex* dx_Device = NULL;
ID3DXLine* p_Line;
ID3DXFont* pFontSmall = 0;
ID3DXLine* pLine = NULL;
ID3DXSprite* textSprite;

ID3DXFont* espFont;
LPD3DXFONT tFont;
ID3DXFont* dx_Font = 0;
LPD3DXFONT m_MenuFont;
LPD3DXFONT m_titleFont;
#define LightBlue				D3DCOLOR_ARGB(220, 0, 220, 220)
D3DCOLOR black = D3DCOLOR_XRGB(0, 0, 0);
D3DCOLOR gray = D3DCOLOR_XRGB(175, 175, 175);
D3DCOLOR white = D3DCOLOR_XRGB(255, 255, 255);
D3DCOLOR red = D3DCOLOR_XRGB(255, 0, 0);
D3DCOLOR orange = D3DCOLOR_XRGB(255, 128, 0);
D3DCOLOR yellow = D3DCOLOR_XRGB(255, 242, 0);
D3DCOLOR green = D3DCOLOR_XRGB(0, 255, 0);
D3DCOLOR lime = D3DCOLOR_XRGB(128, 255, 0);
D3DCOLOR green_dark = D3DCOLOR_XRGB(0, 128, 0);
D3DCOLOR blue = D3DCOLOR_XRGB(0, 0, 255);
D3DCOLOR cyan = D3DCOLOR_XRGB(0, 128, 255);
D3DCOLOR purple = D3DCOLOR_XRGB(255, 0, 255);

#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define D3DFVF_TEXTUREVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)

typedef HRESULT(__stdcall* tGetRenderTargetData)(LPDIRECT3DDEVICE9 pDevice, IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface);
tGetRenderTargetData oGetRenderTargetData;

typedef HRESULT(__stdcall* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;



class CDrawing
{
public:

	

	void DrawText( LPD3DXFONT pFont, D3DXVECTOR2 Pos, DWORD DT, D3DCOLOR Color, CONST WCHAR * fmt, ...);
	void DrawText( LPD3DXFONT pFont, D3DXVECTOR2 Pos, DWORD DT, D3DCOLOR Color, const char * fmt, ...);
	void DrawOutlinedRectangle( D3DXVECTOR2 Pos, D3DXVECTOR2 Size, D3DCOLOR Color);
	void DrawFilledRectangle(D3DXVECTOR2 Pos, D3DXVECTOR2 Size, D3DCOLOR Color);
	void DrawMouse(D3DXVECTOR2 Pos, D3DCOLOR Color);
	void DrawPoints(D3DXVECTOR2 vec2[10],int points,D3DCOLOR Color);
	void DrawCircle(int X, int Y, int radius, int numSides, DWORD Color) ;

};

extern CDrawing Drawing;

#endif
