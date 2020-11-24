

#pragma warning ( disable : 4244 )


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#include <fstream>
#include <iostream>
#include "CDrawing.h"

LPD3DXFONT pFont;
LPD3DXLINE pLine;
LPD3DXFONT TabFont;
LPD3DXFONT HeadFont;


CDrawing Drawing;



void CDrawing::DrawText( LPD3DXFONT pFont, D3DXVECTOR2 Pos, DWORD DT, D3DCOLOR Color, CONST WCHAR * fmt, ...)
{
	RECT rect, bRect[9];
	SetRect(&rect, (int)Pos.x, (int)Pos.y, (int)Pos.x, (int)Pos.y);

	WCHAR buf[1024] = { 0 };
	va_list va_alist;
	va_start(va_alist, fmt);
	vswprintf(buf, fmt, va_alist);
	va_end(va_alist);

	int xcount = 0, ycount = 0;
	for (int i = 0; i< 9; i++)
	{
		SetRect(&bRect[i], (int)Pos.x - 1 + xcount, (int)Pos.y - 1 + ycount, (int)Pos.x, (int)Pos.y);
		pFont->DrawTextW(NULL, buf, -1, &bRect[i], DT | DT_NOCLIP, D3DCOLOR_ARGB(255, 20, 20, 20));
		xcount++;
		if (xcount == 3)
		{
			ycount++;
			xcount = 0;
		}
	}
	pFont->DrawTextW(NULL, buf, -1, &rect, DT | DT_NOCLIP, Color);
	return;
}

void CDrawing::DrawText( LPD3DXFONT pFont, D3DXVECTOR2 Pos, DWORD DT, D3DCOLOR Color, const char * fmt, ...)
{
	RECT rect, bRect[9];
	SetRect(&rect, (int)Pos.x, (int)Pos.y, (int)Pos.x, (int)Pos.y);

	char buf[1024] = { 0 };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf(buf, fmt, va_alist);
	va_end(va_alist);

	int xcount = 0, ycount = 0;
	for (int i = 0; i< 9; i++)
	{
		SetRect(&bRect[i], (int)Pos.x - 1 + xcount, (int)Pos.y - 1 + ycount, (int)Pos.x, (int)Pos.y);
		pFont->DrawText(NULL, buf, -1, &bRect[i], DT | DT_NOCLIP, D3DCOLOR_ARGB(255, 20, 20, 20));
		xcount++;
		if (xcount == 3)
		{
			ycount++;
			xcount = 0;
		}
	}
	pFont->DrawText(NULL, buf, -1, &rect, DT | DT_NOCLIP, Color);
	return;
}

void CDrawing::DrawOutlinedRectangle( D3DXVECTOR2 Pos, D3DXVECTOR2 Size, D3DCOLOR Color)
{
	D3DXVECTOR2 points[5];
	points[0] = D3DXVECTOR2(Pos.x, Pos.y);
	points[1] = D3DXVECTOR2(Pos.x + Size.x, Pos.y);
	points[2] = D3DXVECTOR2(Pos.x + Size.x, Pos.y + Size.y);
	points[3] = D3DXVECTOR2(Pos.x, Pos.y + Size.y);
	points[4] = D3DXVECTOR2(Pos.x, Pos.y);

	ID3DXLine *dLine = pLine;
	BOOL antianalias = dLine->GetAntialias();
	BOOL gllines = dLine->GetGLLines();
	float width = dLine->GetWidth();
	dLine->SetAntialias(false);
	dLine->SetGLLines(false);
	dLine->SetWidth(1.0f);

	dLine->Begin();
	dLine->Draw(points, 5, Color);
	dLine->End();
	dLine->SetAntialias(antianalias);
	dLine->SetGLLines(gllines);
	dLine->SetWidth(width);
	return;
}

void CDrawing::DrawFilledRectangle(D3DXVECTOR2 Pos, D3DXVECTOR2 Size, D3DCOLOR Color)
{
	D3DXVECTOR2 points[2];

	points[0] = Pos+D3DXVECTOR2((Size.x/2),0);
	points[1] = D3DXVECTOR2(Pos.x+(Size.x/2),Pos.y+Size.y);

	ID3DXLine *dLine = pLine;
	BOOL antianalias = dLine->GetAntialias();
	BOOL gllines = dLine->GetGLLines();
	float width = dLine->GetWidth();
	dLine->SetAntialias(false);
	dLine->SetGLLines(false);
	dLine->SetWidth(Size.x);
	dLine->Begin();
	dLine->Draw(points,2,Color);
	dLine->End();
	dLine->SetAntialias(antianalias);
	dLine->SetGLLines(gllines);
	dLine->SetWidth(width);
	return;
}
void CDrawing::DrawCircle(int X, int Y, int radius, int numSides, DWORD Color) 
{ 

    D3DXVECTOR2 Line[128]; 
    float Step = 3.14159265 * 2.0 / numSides; 
    int Count = 0; 
    for (float a=0; a < 3.14159265 * 2.0; a += Step) 
    { 
        float X1 = radius * cos(a) + X; 
        float Y1 = radius * sin(a) + Y; 
        float X2 = radius * cos(a+Step) + X; 
        float Y2 = radius * sin(a+Step) + Y; 
        Line[Count].x = X1; 
        Line[Count].y = Y1; 
        Line[Count+1].x = X2; 
        Line[Count+1].y = Y2; 
        Count += 2; 
    } 
    pLine->Begin(); 
    pLine->Draw(Line,Count,Color); 
    pLine->End(); 
	return;
}

void CDrawing::DrawPoints(D3DXVECTOR2 vec2[10],int points,D3DCOLOR Color)
{
	ID3DXLine *dLine = pLine;
	BOOL antianalias = dLine->GetAntialias();
	BOOL gllines = dLine->GetGLLines();
	float width = dLine->GetWidth();
	dLine->SetAntialias(true);
	dLine->SetGLLines(false);
	dLine->SetWidth(1.0f);
	dLine->Begin();
	dLine->Draw(vec2,points,Color);
	dLine->End();
	dLine->SetAntialias(antianalias);
	dLine->SetGLLines(gllines);
	dLine->SetWidth(width);
	return;
}




void CDrawing::DrawMouse(D3DXVECTOR2 Pos, D3DCOLOR Color)
{
	float bList[9] = {12,10,8,6,5,4,3,2,1};
	float cList[6] = {8,6,4,3,2,1};

	for(int i=0;i<9;i++)
		this->DrawFilledRectangle(D3DXVECTOR2(Pos.x+i,Pos.y+i),D3DXVECTOR2(1,bList[i]),D3DCOLOR_RGBA(000,000,000,255));
	for(int i=0;i<6;i++)
		this->DrawFilledRectangle(D3DXVECTOR2(Pos.x+(i+1),Pos.y+(i+2)),D3DXVECTOR2(1,cList[i]),Color);
	return;
}



