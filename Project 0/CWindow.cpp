
#include <Windows.h>
#include "CWindow.h"


CWindow Window;

int TabIndex = 1;
int Ticks = 0;


BOOL CWindow::IsInBox( float x, float y, float w, float h )
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}
VOID WINAPI CWindow::Enable ( D3DXVECTOR2 position, D3DXVECTOR2 size, bool &imported )
{


	static bool Holding = false;

	DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_DEFAULT );
	DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_BORDER );
	DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 5, position.y + ( size.y / 2 ) ), D3DXVECTOR2 ( size.x - 10, 3 ), ENABLE_TEXT );

	if ( IsInBox ( position.x, position.y, size.x, size.y ) )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_HOVER );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_BORDER );
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 5, position.y + ( size.y / 2 )), D3DXVECTOR2 ( size.x - 10, 3 ), ENABLE_TEXT_HOVER );
	}

	if ( (( GetAsyncKeyState ( VK_LBUTTON ) && Ticks > 35 ) || ( GetAsyncKeyState ( VK_RBUTTON ) && Ticks > 35 )) && IsInBox ( position.x, position.y, size.x, size.y ) && !Holding )
	{

		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_ACTIVE );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y ), size, ENABLE_BORDER );
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 5, position.y + ( size.y / 2 ) ), D3DXVECTOR2 ( size.x - 10, 3 ), ENABLE_TEXT_ACTIVE );

		if ( !imported )
			imported = true;

		if ( imported )
			imported = false;

		Holding = true;
	}
	else if ( Holding && !( GetAsyncKeyState ( VK_LBUTTON ) || GetAsyncKeyState ( VK_RBUTTON ) ) )
	{
		Holding = false;
	}


	


		

}
VOID WINAPI CWindow::CheckBox ( D3DXVECTOR2 position, CONST WCHAR * title, int &active, int Index )
{
	Ticks++;
	static D3DXVECTOR2 size = D3DXVECTOR2 ( 12, 12 );
	static bool Holding = false;
	static int padding_buttom = 20;
	if ( (( GetAsyncKeyState ( VK_LBUTTON ) && Ticks > 35 ) || ( GetAsyncKeyState ( VK_RBUTTON ) && Ticks > 35 )) && IsInBox ( position.x, position.y + Index * padding_buttom, size.x, size.y ) && !Holding )
	{
		if ( active == 0 || active == -1 )
			active = 1;
		else if ( active == 1 )
			active = 0;

		Ticks = 0;
		Holding = true;
	}
	else if ( Holding && !( GetAsyncKeyState ( VK_LBUTTON ) || GetAsyncKeyState ( VK_RBUTTON ) ) )
	{
		Holding = false;
	}

	if ( active != 1 )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_DEFAULT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}
	if ( IsInBox ( position.x, position.y + Index * padding_buttom, size.x, size.y ) )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_HOVER );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}

	if ( active == 1 )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_ACTIVE );
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 2, position.y + 2 + Index * padding_buttom ), D3DXVECTOR2 ( size.x - 3, size.y - 3 ), CHECKBOX_ACTIVE_FRONT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}
}

VOID WINAPI CWindow::RadioBox ( D3DXVECTOR2 position, CONST WCHAR * title, int &active, int SetDefault, int Index )
{
	Ticks++;
	static D3DXVECTOR2 size = D3DXVECTOR2 ( 12, 12 );
	static bool Holding = false;
	static int padding_buttom = 20;
	if ( (( GetAsyncKeyState ( VK_LBUTTON ) && Ticks > 35 ) || ( GetAsyncKeyState ( VK_RBUTTON ) && Ticks > 35 )) && IsInBox ( position.x, position.y + Index * padding_buttom, size.x, size.y ) && !Holding )
	{
		active = SetDefault;

		Ticks = 0;
		Holding = true;
	}
	else if ( Holding && !( GetAsyncKeyState ( VK_LBUTTON ) || GetAsyncKeyState ( VK_RBUTTON ) ) )
	{
		Holding = false;
	}

	if ( active != SetDefault )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_DEFAULT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}
	if ( IsInBox ( position.x, position.y + Index * padding_buttom, size.x, size.y ) )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_HOVER );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}

	if ( active == SetDefault )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_ACTIVE );
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 2, position.y + 2 + Index * padding_buttom ), D3DXVECTOR2 ( size.x - 3, size.y - 3 ), CHECKBOX_ACTIVE_FRONT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x, position.y + Index * padding_buttom ), size, CHECKBOX_BORDER );
		DrawText ( pFont, D3DXVECTOR2 ( position.x + 19, position.y - 3 + Index * padding_buttom ), DT_LEFT, CHECKBOX_TEXT, L"%s", title );
	}
}

VOID WINAPI CWindow::TabControl ( CONST WCHAR * Title, D3DXVECTOR2 position, D3DXVECTOR2 size, int &active, int SetDefault, int Index )
{
	float x = position.x;
	float y = position.y;
	float w = size.x;
	float h = size.y;

	static bool Holding = false;
	if ( ( GetAsyncKeyState ( VK_LBUTTON ) || GetAsyncKeyState ( VK_RBUTTON ) ) && IsInBox ( x,  y + Index * 45, w, h ) && !Holding )
	{
		active = SetDefault;
		Ticks = 0;
		Holding = true;
		
	}
	else if ( Holding && !( GetAsyncKeyState ( VK_LBUTTON ) || GetAsyncKeyState ( VK_RBUTTON ) ) )
	{
		Holding = false;
	}

	
	if ( active != SetDefault )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), TABCONTROL_DEFAULT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), WINDOW_BACKGROUND );
		DrawText ( pFont, D3DXVECTOR2 ( x + ( w / 2 ), y + 12 + Index * 45 ), DT_CENTER, WINDOW_TEXT, L"%s", Title );
	}
	if ( IsInBox ( x, y + Index * 45, w, h ) )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), TABCONTROL_HOVER );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), WINDOW_BACKGROUND );//border window form
		DrawText ( pFont, D3DXVECTOR2 ( x  + ( w / 2 ), y + 12 + Index * 45 ), DT_CENTER, WINDOW_TEXT, L"%s", Title );
	}
	if ( active == SetDefault )
	{
		DrawFilledRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), TABCONTROL_ACTIVE );
		DrawFilledRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( 3, h ), TABCONTROL_ACTIVE_LEFT );
		DrawOutlinedRectangle ( D3DXVECTOR2 ( x, y + Index * 45 ), D3DXVECTOR2 ( w, h ), WINDOW_BACKGROUND );//border window form
		DrawText ( pFont, D3DXVECTOR2 ( x + ( w / 2 ), y + 12 + Index * 45 ), DT_CENTER, WINDOW_TEXT, L"%s", Title );
	}
	

	return;
}



VOID WINAPI CWindow::Window ( D3DXVECTOR2 position, D3DXVECTOR2 size, const char * title )
{
	if ( pFont != NULL && pLine != NULL && HeadFont != NULL )
	{
		
		position = position;
		size = size;

		DrawFilledRectangle ( position, size, WINDOW_BACKGROUND ); //background

		DrawFilledRectangle ( position, D3DXVECTOR2 ( 110, size.y ), WINDOW_BAR_LEFT );//menu bar left
		DrawOutlinedRectangle ( position, D3DXVECTOR2 ( 110, size.y ), WINDOW_BORDER );//border window form

		//DrawFilledRectangle ( D3DXVECTOR2 ( position.x + size.x - 20, position.y ), D3DXVECTOR2 ( 15, size.y ), WINDOW_BAR_RIGHT );//menu bar right
		//DrawOutlinedRectangle ( D3DXVECTOR2 ( position.x + size.x - 20, position.y ), D3DXVECTOR2 ( 15, size.y ), WINDOW_BORDER );//border window form


		// head title bar
		DrawFilledRectangle ( position, D3DXVECTOR2 ( size.x, 30 ), WINDOW_HEAD ); //head window form
		
		DrawOutlinedRectangle ( position, size, WINDOW_BORDER );

		//Window Form center
		DrawFilledRectangle ( D3DXVECTOR2 ( position.x + 115, position.y + 35 ), D3DXVECTOR2 ( size.x - 120, size.y - 35 ), WINDOW_BAR_LEFT );

		static bool OnReturn;
		Enable ( D3DXVECTOR2 ( position.x + size.x - 25, position.y + 5 ), D3DXVECTOR2 ( 20, 20 ), OnReturn );

		/// <summary>
		/// tab control for selected
		TabControl ( L"Player",			D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_General, 0 );
		TabControl ( L"Zombie",			D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_Player, 1 );
		TabControl ( L"Misc",			D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_Viewer, 2 );
		TabControl ( L"Item",		D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_Sense, 3 );
		TabControl ( L"Aimbot",			D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_Aimming, 4 );
		TabControl ( L"Player And Zombie",		D3DXVECTOR2 ( position.x + 5, position.y + 30 ), D3DXVECTOR2 ( 105, 40 ), TabIndex, TabControl_Setting, 5 );
		/// </summary>
		int len = GetTextLength ( "%s", title );
		DrawText ( HeadFont, D3DXVECTOR2 ( ( position.x + ( len / 2 ) ) + ( size.x / 2 ) - 2, position.y + 7 ), DT_CENTER, WINDOW_TEXT, "%s", title );


		if ( TabIndex == TabControl_Setting )
		{
			std::string about;

			about += "  Sambale.hxtml.com";
			about += "  www.facebook.com/sambale.hxtml";

			DrawText ( pFont, D3DXVECTOR2 ( position.x + 125, position.y + 110 ), DT_LEFT, WINDOW_TEXT, about.c_str() );

		}
		POINT Cur;
		GetCursorPos(&Cur);
		ScreenToClient(GetForegroundWindow(),&Cur);
		DrawMouse(D3DXVECTOR2((float)Cur.x,(float)Cur.y),D3DCOLOR_RGBA(255,255,000,255));


	}
}









int CWindow::GetTextLength ( char *szString, ... )
{
	char szText[512];
	memset(szText,0,512);
	strcpy(szText,szString);
	unsigned int i = 0, iStrLen = 0;
	while (i < strlen(szText))
	{
		switch(szText[i])
		{
		case ' ':
			iStrLen += 5;
			break;
		case 'e':
			iStrLen += 6;
			break;
		case 'i':
			iStrLen += 2;
			break;
		case 'j':
			iStrLen += 3;
			break;
		case 'k':
			iStrLen += 6;
			break;
		case 'l':
			iStrLen += 2;
			break;
		case 't':
			iStrLen += 3;
			break;
		case 'L':
			iStrLen += 7;
			break;
		case 'm':
			iStrLen += 10;
			break;
		case 'o':
			iStrLen += 7;
			break;
		case 'r':
			iStrLen += 4;
			break;
		case 'v':
			iStrLen += 7;
			break;
		case 'w':
			iStrLen += 9;
			break;
		case 'y':
			iStrLen += 7;
			break;
		case 'x':
			iStrLen += 7;
			break;
		case 'A':
			iStrLen += 7;
			break;
		case 'B':
			iStrLen += 7;
			break;
		case 'C':
			iStrLen += 7;
			break;
		case 'G':
			iStrLen += 8;
			break;
		case 'H':
			iStrLen += 7;
			break;
		case 'I':
			iStrLen += 2;
			break;
		case 'K':
			iStrLen += 7;
			break;
		case 'M':
			iStrLen += 9;
			break;
		case 'O':
			iStrLen += 7;
			break;
		case 'P':
			iStrLen += 7;
			break;
		case 'Q':
			iStrLen += 7;
			break;
		case 'R':
			iStrLen += 6;
			break;
		case 'V':
			iStrLen += 7;
			break;
		case 'W':
			iStrLen += 11;
			break;
		case 'X':
			iStrLen += 8;
			break;
		case 'Y':
			iStrLen += 7;
			break;
		default:
			iStrLen += 5;
			break;
		}
		i++;
	}
	return iStrLen;
}
