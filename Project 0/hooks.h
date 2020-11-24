#include "CDrawing.h"


HRESULT __stdcall hGetRenderTargetData( LPDIRECT3DDEVICE9 pDevice, IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface )
{
    if( pCleanFrame == NULL || pBackBuffer == NULL )
    {
        
        return D3D_OK;
    }
    else if( pRenderTarget == pBackBuffer )
    {
       
        D3DXLoadSurfaceFromSurface( pDestSurface, NULL, NULL, pCleanFrame, NULL, NULL, D3DX_FILTER_NONE, 0 );
        D3DXLoadSurfaceFromSurface( pRenderTarget, NULL, NULL, pCleanFrame, NULL, NULL, D3DX_FILTER_NONE, 0 );

        return D3D_OK;
    }

    return oGetRenderTargetData( pDevice, pRenderTarget, pDestSurface );
}


HRESULT __stdcall hEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	gpDevice = pDevice;

	static bool firstCall = true;
	if (firstCall == true)
	{
		// Create line so we can draw
		D3DXCreateLine(pDevice, &pLine);

		LPDIRECT3DSURFACE9 renderTarget = NULL;
		D3DSURFACE_DESC desc;

		pDevice->GetRenderTarget(0, &renderTarget);
		renderTarget->GetDesc(&desc);
		renderTarget->Release();

		pDevice->CreateOffscreenPlainSurface(desc.Width, desc.Height, desc.Format, D3DPOOL_SYSTEMMEM, &pCleanFrame, NULL);

		firstCall = false;
	}

	obj_Player* g_pLocal = NULL;
	g_pLocal = (obj_Player*)pGame->getLocalPlayer();

	// Get the games pointer to the back buffer. This is useful to check if they are requesting a screenshot.
	static DWORD pBackBufferAddr = 0;
	
	if (pBackBufferAddr != 0 &&
		** (DWORD**)pBackBufferAddr != NULL &&
		*(DWORD*)(**(DWORD**)(pBackBufferAddr)+0xAC628) != NULL)
	{
		pBackBuffer = *(IDirect3DSurface9**)(**(DWORD**)(pBackBufferAddr)+0xAC628);
		static IDirect3DSurface9* pOldBackBuffer = NULL;

		if (pOldBackBuffer != pBackBuffer)
		{
			//Log->Write("pBackBuffer %p", pBackBuffer);
			pOldBackBuffer = pBackBuffer;
		}
	}
	if (!tFont || tFont == NULL)
	{
		D3DXCreateFont(pDevice, 16, 0, FW_BOLD, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, FF_DONTCARE, DEFAULT_PITCH, "Segoe WP", &tFont);


		D3DXCreateSprite(pDevice, &textSprite);
	}




	if (getCleanFrame && pGameWorld->m_FrameId != lastFrameId)
	{
		oGetRenderTargetData(pDevice, pBackBuffer, pCleanFrame);
		getCleanFrame = false;
	}
	lastFrameId = pGameWorld->m_FrameId;

	static DWORD endTick = 500;
	if (GetTickCount() >= endTick)
	{
		getCleanFrame = true;
		endTick = GetTickCount() + 5000; // Take new clean frame every 5 seconds
	}

	pDevice->GetViewport(&viewport);

	static DWORD renderState = 0;
	pDevice->GetRenderState(D3DRS_ZFUNC, &renderState);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);

	// Get pointer to local player class
	localPlayer = pGame->getLocalPlayer();

	// Check if we are spawned inside a server
	if (localPlayer && pGameWorld && pGameWorld->bInited)
	{
		D3DXMATRIX matTmp = *(D3DXMATRIX*)((DWORD)pRenderer + 0x220);
		if (matTmp.m[3][3] != 1.f)
		{
			matProj = matTmp;
			matView = *(D3DXMATRIX*)((DWORD)pRenderer + 0x1A0);
		}

		static char espText[1024] = { 0 }, name[64] = { 0 };

		// Get the first object from the object manager
		GameObject* object = pGameWorld->GetFirstObject();

		do
		{
			if (object == NULL || object == (GameObject*)localPlayer)
				continue;

			EGameObjectType objectType = object->getObjType();

			if (!(objectType & OBJTYPE_Human) &&		// Is it a player?
				!(objectType & OBJTYPE_Zombie) &&		// Is it a zombie?
				!(objectType & OBJTYPE_GameplayItem))// Is it loot?
				continue;								// Nope

			D3DXVECTOR3 screen, box, screenHead;
			D3DCOLOR color = white;

			memset(espText, 0, 1024);

			// Get distance to the object
			D3DXVECTOR3 vecDist = localPlayer->vPos - object->vPos;
			float distance = D3DXVec3Length(&vecDist);

			if (objectType & OBJTYPE_Human)
			{
				// The object is a player
				obj_Player* player = (obj_Player*)object;

				// If the player is dead, skip it
				if (!player->isAlive())
					continue;
				D3DXVECTOR3 lPos, vHead;
				// You will have to figure out visibility check on your own ;)

				



				// Get screen coordinates from world position
				if (WorldToScreen(player->vPos, &screen))
				{
					D3DXVECTOR3 headVec = D3DXVECTOR3(player->vPos.x, player->vPos.y + 1.75f/*approx. better to use bones*/, player->vPos.z);

					float flHealth = player->getH();

					// Get screen coordinates of the players head from world position
					if (WorldToScreen(headVec, &screenHead))
						if (PlayerESP == true)
						{
						
							

							box.y = ((screen.y - screenHead.y) > 1.f) ? screen.y - screenHead.y : 1.f;
							box.x = box.y / 2.75f;

							drawText(screen.x + (box.x / 2) + 5, screen.y - box.y, orange, DT_LEFT, espFont, "PLAYER");
							drawText(screen.x + (box.x / 2) + 8, screen.y - box.y + 10, purple, DT_LEFT, espFont, "[ %0.1fm ]", distance);

							DrawLine(screen.x - (box.x / 2), screen.y - box.y, screen.x - (box.x / 2) + box.x, screen.y - box.y, lime);
							DrawLine(screen.x - (box.x / 2) + box.x, screen.y - box.y, screen.x - (box.x / 2) + box.x, screen.y - box.y + box.y, lime);
							DrawLine(screen.x - (box.x / 2) + box.x, screen.y - box.y + box.y, screen.x - (box.x / 2), screen.y - box.y + box.y, lime);
							DrawLine(screen.x - (box.x / 2), screen.y - box.y + box.y, screen.x - (box.x / 2), screen.y - box.y, lime);

							


							if (flHealth == 100)
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, green, black);
							if ((flHealth >= 91) && (flHealth <= 100))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, green, black);
							if ((flHealth >= 81) && (flHealth <= 90))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, green, black);
							if ((flHealth >= 71) && (flHealth <= 80))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, green, black);
							if ((flHealth >= 61) && (flHealth <= 70))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, yellow, black);
							if ((flHealth >= 51) && (flHealth <= 60))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, yellow, black);
							if ((flHealth >= 41) && (flHealth <= 50))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, yellow, black);
							if ((flHealth >= 31) && (flHealth <= 40))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, yellow, black);
							if ((flHealth >= 21) && (flHealth <= 30))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, red, black);
							if ((flHealth >= 11) && (flHealth <= 20))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, red, black);
							if ((flHealth >= 1) && (flHealth <= 10))
								DrawHealthBar(screen.x - 10, screen.y - 30 / distance, flHealth, 35, 5, red, black);


							if ((flHealth >= 0) && (flHealth <= 10))
								drawText(screen.x + (box.x / 2), screen.y, red, DT_LEFT, espFont, "Player_DEAD");

						}
				}
			}