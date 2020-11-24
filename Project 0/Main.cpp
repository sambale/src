
#include <Windows.h>
#include <detours.h>
#include "CDrawing.h"
#include "CWindow.h"

typedef HRESULT ( __stdcall * tEndScene ) ( LPDIRECT3DDEVICE9 );
tEndScene pEndScene;

int hack[10][30] = { 0 };

VOID WINAPI CWindow::Form ( D3DXVECTOR2 position )
{
	if ( TabIndex == TabControl_General )
	{
		CheckBox ( position, L"Player ESP",									hack[0][0], 0 );
		CheckBox ( position, L"Player 3D Box",									hack[0][1], 1 );
		CheckBox ( position, L"Player 2D Box",									hack[0][2], 2 );
		CheckBox ( position, L"Player Skeleton",									hack[0][3], 3 );
		CheckBox ( position, L"Player Shield",									hack[0][4], 4 );
		CheckBox ( position, L"Player Distase",									hack[0][5], 5 );
	//}
	//else if ( TabIndex == TabControl_Player )
	//{
	//	CheckBox ( position, L"Zombie ESP",									hack[1][0], 0 );
	//	CheckBox ( position, L"Zombie 3D box",									hack[1][1], 1 );
	//	CheckBox ( position, L"Zombie 2D Box",									hack[1][2], 2 );
	//	CheckBox ( position, L"Zombie Skeleton",									hack[1][3], 3 );
	//	CheckBox ( position, L"Zombie Shield",									hack[1][4], 4 );
	//	CheckBox ( position, L"Zombie Distase",									hack[1][5], 5 );
	////}
	//else if ( TabIndex == TabControl_Viewer )
	//{
	//	CheckBox ( position, L"Super Jump",									hack[2][0], 0 );
	//	CheckBox ( position, L"No Clip",									hack[2][1], 1 );
	//	CheckBox ( position, L"Night Vision",									hack[2][2], 2 );
	//	CheckBox ( position, L"RapidFire",									hack[2][3], 3 );
	//	CheckBox ( position, L"Fast Hands",									hack[2][4], 4 );
	//	CheckBox ( position, L"Player Magect",									hack[2][5], 5 );
	//	CheckBox ( position, L"Magic Bullet",									hack[2][6], 6 );
	//	CheckBox ( position, L"InstaPickup",									hack[2][7], 7 );
	//	CheckBox ( position, L"Auto 30 HP",									hack[2][8], 8 );
	//}
	//else if ( TabIndex == TabControl_Sense )
	//{
	//	CheckBox ( position, L"Item ESP",									hack[3][0], 0 );
	//	CheckBox ( position, L"Item Esp 3D Box",									hack[3][1], 1 );
	//	CheckBox ( position, L"Item Esp 2D Box",									hack[3][2], 2 );
	//	CheckBox ( position, L"Distase Item",									hack[3][3], 3 );
	//}
	//else if ( TabIndex == TabControl_Aimming )
	//{
	//	CheckBox ( position, L"Aimbot HEAD",									hack[4][0], 0 );
	//}
	//else if ( TabIndex == TabControl_Setting )
	//{
	//	CheckBox ( position, L"Nguoi Choi Xung Quanh",									hack[5][0], 0 );
	//	CheckBox ( position, L"Zombie Xung Quanh",									hack[5][1], 1 );





		/*
		CheckBox ( position, L"",										hack[4][2], 2 );
		CheckBox ( position, L"แสดงเส้นนำทางผู้เล่น",							hack[4][3], 3 );
		CheckBox ( position, L"แสดงกรอบรอบตัวผู้เล่น",						hack[4][4], 4 );
		CheckBox ( position, L"แสดงการฆ่าและตายผู้เล่น",						hack[4][5], 5 );
		CheckBox ( position, L"แสดงชื่อทีม",								hack[4][6], 6 );
		CheckBox ( position, L"ยกเลิกการปิดกั้นระหว่างทีม",						hack[4][7], 7 );
		*/
	}

	
}

HRESULT __stdcall myEndScene ( LPDIRECT3DDEVICE9 pDevice )
{

	if ( pLine == NULL )
		D3DXCreateLine ( pDevice, &pLine );
	
	if ( pFont == NULL )
		D3DXCreateFontA(pDevice, 15, 0, FW_MEDIUM, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", & pFont);
	
	if ( HeadFont == NULL )
		D3DXCreateFontA(pDevice, 16, 0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", & HeadFont);
	

	static BOOL Init = FALSE;
	static BOOL Holding;
	static D3DVIEWPORT9 pViewport;
	static D3DXVECTOR2 HoldingPosition, position, size;

	pDevice->GetViewport( &pViewport );
	if ( pLine != NULL && pFont != NULL )
	{
		
		while ( !Init )
		{
			position.x = 35;
			position.y = 35;
			size.x = 500;
			size.y = 380;
			Init = TRUE;
		}

		if((GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON)) && Window.IsInBox( position.x, position.y, size.x, 30 ) && !Holding) 
		{
			POINT cur;
			GetCursorPos(&cur);
			ScreenToClient(GetForegroundWindow(),&cur);

			HoldingPosition = D3DXVECTOR2((float)cur.x-position.x,(float)cur.y-position.y);
			
			Holding = TRUE;
		}
		else if(Holding && (GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON))) 
		{
			POINT Cur;
			GetCursorPos(&Cur);
			ScreenToClient(GetForegroundWindow(),&Cur);
			D3DXVECTOR2 NewPosition = D3DXVECTOR2((float)Cur.x,(float)Cur.y)-HoldingPosition;
		
			if((NewPosition.x<15) && (NewPosition.y<15))
				position = D3DXVECTOR2(2,2);
			else if((NewPosition.x+size.x>pViewport.Width-15) && (NewPosition.y<2))
				position = D3DXVECTOR2(pViewport.Width-size.x-2,2);
			else if((NewPosition.x<15) && (NewPosition.y+size.y>pViewport.Height-15))
				position = D3DXVECTOR2(2,pViewport.Height-size.y-2);
			else if((NewPosition.x+size.x>pViewport.Width-15) && (NewPosition.y+size.y>pViewport.Height-15))
				position = D3DXVECTOR2(pViewport.Width-size.x-2,pViewport.Height-size.y-2);
			else if(NewPosition.x<15)
				position = D3DXVECTOR2(2,NewPosition.y);
			else if(NewPosition.x+size.x>pViewport.Width-15)
				position = D3DXVECTOR2(pViewport.Width-size.x-2,NewPosition.y);
			else if(NewPosition.y<15)
				position = D3DXVECTOR2(NewPosition.x,2);
			else if(NewPosition.y+size.y>pViewport.Height-15)
				position = D3DXVECTOR2(NewPosition.x,pViewport.Height-size.y-2);
			else
				position = NewPosition;
		}
		else if(Holding && !(GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON))) 
		{
			HoldingPosition = D3DXVECTOR2(0.0f,0.0f);
			Holding = FALSE;
		}


	Window.Window ( position, size, "LightZ Pulic Hack" );
	Window.Window ( position, size, "Hack By Sambale" );
	Window.Form ( D3DXVECTOR2 ( position.x + 125, position.y + 45 ) );

	}

	return pEndScene ( pDevice );
}


LRESULT CALLBACK MsgProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

DWORD VTable ( int index )
{
	WNDCLASSEX wc = {sizeof(WNDCLASSEX),CS_CLASSDC, MsgProc, 0L,0L,GetModuleHandle(NULL),NULL,NULL,NULL,NULL,"DX",NULL};
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindow("DX",NULL,WS_OVERLAPPEDWINDOW,100,100,300,300,GetDesktopWindow(),NULL,wc.hInstance,NULL);
	LPDIRECT3D9 pD3D = Direct3DCreate9( D3D_SDK_VERSION );
	D3DPRESENT_PARAMETERS d3dpp; 
	ZeroMemory( &d3dpp, sizeof(d3dpp) );
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	LPDIRECT3DDEVICE9 pd3dDevice;
	pD3D->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&pd3dDevice);
	DWORD* pVTable = (DWORD*)pd3dDevice;
	pVTable = (DWORD*)pVTable[0];
	return pVTable[index];
	DestroyWindow(hWnd);
}

BOOL VisableTable ()
{

	if ( VTable ( 42 ) != NULL )
	{
		return TRUE;
	}

	return FALSE;
}


DWORD WINAPI MyThread ( LPVOID )
{

	while ( GetModuleHandleA ( "ntdll.dll" ) == NULL )
	{
		Sleep ( 500 );
	}

	if ( VisableTable() )
	{
		pEndScene = ( tEndScene ) DetourFunction ( (PBYTE)VTable ( 42 ), (PBYTE)myEndScene );
	}

	return FALSE;
}

BOOL WINAPI DllMain ( HMODULE hModule, DWORD fdwReason, LPVOID )
{
	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		CreateThread ( 0, 0, MyThread, 0, 0, 0 );
	}
	return TRUE;
}