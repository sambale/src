/* 
 * @file	main.h
 * @author  Nov/Asbra.net <johan@asbra.net>
 * @version	1.0.130520
 */
#include <Windows.h>
#include <detours.h>

#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")

#pragma once
#define uint unsigned int







bool quit = false;
bool hooked = false;


HMODULE hGameBase = NULL;
HMODULE hHackModule = NULL;

DWORD offLocalPlayer = 0, xorLocalPlayer = 0;
DWORD xorPlayer = 0x4AC38963;
class D3DLayer* D3D = NULL;
class r3dRenderLayer* pRenderer = NULL;
class ClientGameLogic* pGame = NULL;
class ObjectManager* pGameWorld = NULL;

#define VALID( x ) ( x != NULL && HIWORD( x ) )

#include "hooks.h"
#include "CDrawing.h"
#include "CWindow.h"
#include "classes.h"


IDirect3DSurface9* pCleanFrame = NULL;
IDirect3DSurface9* pBackBuffer = NULL;
