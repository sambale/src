



#pragma pack(push, 1)

#define r3dPoint3D D3DXVECTOR3
#define r3dMatrix D3DMATRIX
#define r3dBoundBox r3dBox3D

class ClientGameLogic;
class AObject;
class ObjectManager;
class GameObject;
class obj_DroppedItem;
class obj_Player;
class obj_Zombie;


enum E_Bones // 62
{
	Bip01 = 0,
	Bip01_Pelvis = 1,
	Bip01_Spine = 2,
	Bip01_Spine1 = 3,
	Bip01_Spine2 = 4,
	Bip01_Neck = 5,
	Bip01_Head = 6,
	Bip01_L_Clavicle = 7,
	Bip01_L_UpperArm = 8,
	Bip01_L_Forearm = 9,
	Bip01_L_Hand = 10,
	Bip01_L_Finger0 = 11,
	Bip01_L_Finger01 = 12,
	Bip01_L_Finger02 = 13,
	Bip01_L_Finger1 = 14,
	Bip01_L_Finger11 = 15,
	Bip01_L_Finger12 = 16,
	Bip01_L_Finger2 = 17,
	Bip01_L_Finger21 = 18,
	Bip01_L_Finger22 = 19,
	Bip01_L_Finger3 = 20,
	Bip01_L_Finger31 = 21,
	Bip01_L_Finger32 = 22,
	Bip01_L_Finger4 = 23,
	Bip01_L_Finger41 = 24,
	Bip01_L_Finger42 = 25,
	Bip01_L_ForeTwist = 26,
	Bip01_L_ForeTwist1 = 27,
	Bip01_R_Clavicle = 28,
	Bip01_R_UpperArm = 29,
	Bip01_R_Forearm = 30,
	Bip01_R_Hand = 31,
	Bip01_R_Finger0 = 32,
	Bip01_R_Finger01 = 33,
	Bip01_R_Finger02 = 34,
	Bip01_R_Finger1 = 35,
	Bip01_R_Finger11 = 36,
	Bip01_R_Finger12 = 37,
	Bip01_R_Finger2 = 38,
	Bip01_R_Finger21 = 39,
	Bip01_R_Finger22 = 40,
	Bip01_R_Finger3 = 41,
	Bip01_R_Finger31 = 42,
	Bip01_R_Finger32 = 43,
	Bip01_R_Finger4 = 44,
	Bip01_R_Finger41 = 45,
	Bip01_R_Finger42 = 46,
	PrimaryWeaponBone = 47,
	Bip01_R_ForeTwist = 48,
	Bip01_R_ForeTwist1 = 49,
	Weapon_BackLeft = 50,
	Weapon_BackRPG = 51,
	Weapon_BackRight = 52,
	Bip01_L_Thigh = 53,
	Bip01_L_Calf = 54,
	Bip01_L_Foot = 55,
	Bip01_L_Toe0 = 56,
	Weapon_Side = 57,
	Bip01_R_Thigh = 58,
	Bip01_R_Calf = 59,
	Bip01_R_Foot = 60,
	Bip01_R_Toe0 = 61
};

enum Playerstate_e
{
	PLAYER_INVALID = -1,

	PLAYER_IDLE = 0,
	PLAYER_IDLEAIM,

	PLAYER_MOVE_CROUCH,
	PLAYER_MOVE_CROUCH_AIM,
	PLAYER_MOVE_WALK_AIM,
	PLAYER_MOVE_RUN,
	PLAYER_MOVE_SPRINT,
	PLAYER_MOVE_PRONE,
	PLAYER_PRONE_AIM,
	PLAYER_PRONE_UP,
	PLAYER_PRONE_DOWN,
	PLAYER_PRONE_IDLE,

	PLAYER_DIE,

	PLAYER_NUM_STATES,
};

enum EZombieStates // EGlobalStates
{
	ZState_Dead = 0,
	ZState_Sleep,
	ZState_Waking,
	ZState_Idle,
	ZState_Walk,
	ZState_Pursue,
	ZState_Attack,
	ZState_BarricadeAttack,

	ZState_NumStates,
};

enum STORE_CATEGORIES
{
	storecat_INVALID	= 0,
	storecat_Account	= 1,
	storecat_Boost		= 2,
	storecat_LootBox	= 7,

	storecat_Armor		= 11,
	storecat_Backpack	= 12,	
	storecat_Helmet		= 13,
	storecat_HeroPackage	= 16,

	storecat_FPSAttachment  = 19,

	storecat_ASR		= 20,	// Assault Rifles
	storecat_SNP		= 21,	// Sniper rifles
	storecat_SHTG		= 22,	// Shotguns
	storecat_MG			= 23,	// Machine guns
	storecat_HG			= 25,	// handguns
	storecat_SMG		= 26,	// submachineguns
	storecat_GRENADE	= 27,	// grenades and everything that you can throw. Mines shouldn't be in this group!!!
	storecat_UsableItem = 28,	// usable items
	storecat_MELEE		= 29,   // melee items (knifes, etc)
	storecat_Food		= 30,	// food 
	storecat_Water		= 33,	// water

	storecat_NUM_ITEMS, // should be the last one!!
};

enum EGameObjectType
{
	OBJTYPE_Generic				= (1<<0),
	OBJTYPE_Terrain				= (1<<1),		// terrain object
	OBJTYPE_Mesh				= (1<<2),		// mesh object
	OBJTYPE_Road				= (1<<3),		// road object
	OBJTYPE_Building			= (1<<4),		// building object
	OBJTYPE_Human				= (1<<5), // obj_Player
	OBJTYPE_Particle			= (1<<6), // particle emitter
	OBJTYPE_Sound				= (1<<7), // sound emitter
	OBJTYPE_Trees				= (1<<8), // all world trees
	OBJTYPE_ApexDestructible	= (1<<11),
	OBJTYPE_AnimMesh			= (1<<12),
	OBJTYPE_DecalProxy			= (1<<13),
	OBJTYPE_Sprite				= (1<<15),
	OBJTYPE_Vehicle				= (1<<16),
	OBJTYPE_Zombie				= (1<<17),
	OBJTYPE_GameplayItem		= (1<<18),
	OBJTYPE_CollectionProxy		= (1<<19),
	OBJTYPE_ItemSpawnPoint		= (1<<20),
	OBJTYPE_SharedUsableItem	= (1<<21),
};

enum EGameObjectFlags
{
	// object need be skipped in world object list when user traverse objects, 
	// usually used for all special objects like terrain, etc..
	OBJFLAG_SkipCastRay	= (1<<4),

	// object need be skipped when ObjectManager::Draw() loop occur.
	// usually used for objects with special drawing order.
	OBJFLAG_SkipDraw	= (1<<5),		

	OBJFLAG_SkipOcclusionCheck = (1<<6),	// do not check occlusion for this object (usually huge objects, or objects that do not have proper aabb for whatever reason)
	OBJFLAG_ForceSceneBoxBBox = (1<<7),
	OBJFLAG_DisableShadows = (1<<8),
	OBJFLAG_AlwaysDraw	= (1<<9),			// for editor and debug, will always draw an object, no matter what
	OBJFLAG_PlayerCollisionOnly = (1<<10),	// object is collision only for player only
	OBJFLAG_AsyncLoading = (1<<11),

	// internal flags
	OBJFLAG_JustCreated	= (1<<20),		// object is just created
	OBJFLAG_Removed	= (1<<23),			// in undo buffer
	OBJFLAG_Detailed = (1<<24),			//	Is object should be culled using map detailed objects cull radius
	OBJFLAG_ForceSleep = (1<<25),
};

class r3dRenderLayer
{
public:
	__int32 bInited; //0x0000 
	__int32 Version; //0x0004 
	DWORD HLibWin; //0x0008 
	DWORD DeviceType; //0x000C 
	DWORD *pdi; //0x0010 
	IDirect3D9 *pd3d; //0x0014 
	DWORD BackBufferWidth; //0x0018 
	DWORD BackBufferHeight; //0x001C 
	char _0x0020[4]; //0x0020 
	DWORD BackBufferCount; //0x0024 
	char _0x0028[4];
	DWORD MultiSampleQuality; //0x002C 
	char _0x0030[4];
	DWORD hDeviceWindow; //0x0034 
	DWORD Windowed; //0x0038 
	DWORD EnableAutoDepthStencil; //0x003C 
	__int32 refreshRate; //0x0040 
	char _0x0044[12];
	LPDIRECT3DDEVICE9 pD3DDevice; //0x0050 
	char _0x0054[304];
	D3DXVECTOR3 CameraPosition; //0x0184 
	D3DXVECTOR3 DistanceCullRefPos; //0x0190 
	char _0x019C[4];
	D3DXMATRIX ViewMatrix[8]; //0x01A0 
	D3DXMATRIX InvViewMatrix; //0x01E0 
	D3DXMATRIX ProjMatrix; //0x0220 

	D3DXMATRIX GetViewPosition()
	{
		D3DXMATRIX inverseView;
		D3DXMatrixInverse(&inverseView, NULL, &ViewMatrix[0]);
		return D3DXVECTOR3(inverseView._41, inverseView._42, inverseView._43);
	}
};

class ClientGameLogic
{
public:

	int getPing()
	{
		int nPing = *(int*)((DWORD)(this) + 0x10);
		return nPing;
	}

	

	obj_Player* getLocalPlayer()
	{
		obj_Player* pLocalPlayer = (obj_Player*)(*(DWORD*)((DWORD)(this) + offLocalPlayer));

		pLocalPlayer = (obj_Player*)((DWORD)pLocalPlayer ^ xorLocalPlayer);

		return pLocalPlayer;
	}

	GameObject* getPlayerByIndex(int index)
	{
		GameObject* pPlayer = (GameObject*)(*(DWORD*)((DWORD)(this) + 0x18 + (index * 4)));

		pPlayer = (GameObject*)((DWORD)pPlayer ^ xorPlayer);

		return pPlayer;
	}

		int getLocalIndex(void)
	{
		return *(int*)((DWORD)(this) + offLocalPlayer);
	}
};

DWORD pGetFirstObject = 0, pGetNextObject = 0;


#define GET_FIRST_OBJ  0x141D90 // Not used anymore... - TheHexa
#define GET_NEXT_OBJ  0x141DF0 // Not used anymore... - TheHexa

#define XOR_OBJLIST_PTR  0x304CFD16
#define XOR_OBJLIST_MAX  0x13E1855C


class ObjectManager
{
public:
	unsigned char _0000[0x8];				// 0000
	int m_FrameId;							// 0008
	class SceneBox* m_pRootBox;				// 000C
	class ObjectManagerResourceHelper* m_ResourceHelper;	// 0010
	unsigned char _0014[0x18];				// 0014
	int MaxObjects;							// 002C
	class GameObject* pFirstObject;			// 0030
	int NumObjects;							// 0034
	class GameObject* pLastObject;			// 0038
	int bInited;							// 003C
	int CurObjID;							// 0040
	class GameObject** pObjectArray;		// 0044
	int LastFreeObject;						// 0048
	int MaxStaticObjects;					// 004C
	int NumStaticObjects;					// 0050
	class GameObject** pStaticObjectArray;	// 0054
	int LastStaticUpdateIdx;				// 0058
	DWORD m_ObjectList;
	DWORD m_MaxObjects;

	GameObject* getObjectArray()
	{
		return (GameObject*)((uintptr_t)this + 0x44);
	}

	GameObject* GetFirstObject()
	{
		typedef GameObject* (__thiscall *tGetFirstObject)(void*);
		static tGetFirstObject pGetFirstObject = (tGetFirstObject)FindPattern(hGameBase, 0x00FFFFFF, (BYTE*)"\x51\x8B\x48\x00\x89\xC\x24\x80\x34\x24\x00\x80\x74\x24\x00\x00\x80\x74\x24\x00\x00\x80\x74\x24\x00\x00\x8B\x4\x24\x85\xC0\x74\x00\xB9\x00\x00\x00\x00\x85\x88\x00\x00\x00\x00", "xxx?xxxxxx?xxx??xxx??xxx??xxxxxx?x????xx???");

		__asm
		{
			MOV EAX, this
				CALL pGetFirstObject
		}
	}

	GameObject* GetNextObject(GameObject* obj)
	{
		typedef GameObject* (__thiscall *tGetNextObject)(void*, GameObject*);
		static tGetNextObject pGetNextObject = (tGetNextObject)FindPattern(hGameBase, 0x00FFFFFF, (BYTE*)"\x51\x8B\x48\x00\x89\xC\x24\x80\x34\x24\x00\x80\x74\x24\x00\x00\x80\x74\x24\x00\x00\xB2\x00\x30\x54\x24\x00\x8B\x4\x24\x85\xC0\x74\x00\xB9\x00\x00\x00\x00\x85\x88\x00\x00\x00\x00\x74\x00\x8B\x40\x00", "xxx?xxxxxx?xxx??xxx??x?xxx?xxxxxx?x????xx????x?xx");

		__asm
		{
			MOV EAX, obj
				CALL pGetNextObject
		}
	}

	DWORD GetMaxObjects()
	{
		return m_MaxObjects ^ XOR_OBJLIST_MAX;
	}

	DWORD GetObject(int id)
	{
		return	(m_ObjectList ^ XOR_OBJLIST_PTR) + (id * 4);
	}
};


class r3dBox3D
{
public:
	r3dPoint3D 	Org;
	r3dPoint3D 	Size;
};
class r3dString
{
  private:
	char		*data;			// must be FIRST
	int		len, maxlen;
};

class AObject
{
	class AClass* Class;		// 0000
	unsigned char _0004[0x4];	// 0004
};

struct wiInventoryItem
{
	DWORD InventoryID;	// 0000
	char _0004[8];		// 0004
	int ammo;			// 000C
	int quantity;		// 0010
	int itemID;			// 0014
};

class BasePhysicsObject
{
public:
	virtual ~BasePhysicsObject();
	virtual void Move(const D3DXVECTOR3& move, float sharpness = 0.5f);
	virtual void SetPosition(const D3DXVECTOR3& pos);
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
};


class GameObject : public AObject
{
public:
	bool getName(char* name)
	{
		if (*(DWORD*)((DWORD)(this) + 0x218) == NULL)
		{
			return false;
		}

		char* data = *(char**)((DWORD)(this) + 0x218);
		int len = *(int*)((DWORD)(this) + 0x21C);
		int maxlen = *(int*)((DWORD)(this) + 0x220);

		if (len > 63)
		{
			len = 63;
		}

		for (int i = 0; i < len; i++)
		{
			name[i] = data[i];
		}

		return (name[0] != 0);
	}

	BasePhysicsObject* physicObject()
	{
		return (BasePhysicsObject*)((DWORD)(this) + 0x2AC);
	}

	D3DXVECTOR3 getPosition()
	{
		D3DXVECTOR3 vPlayer = *(D3DXVECTOR3*)((DWORD)(this) + 0x24);
		return vPlayer;
	}

	EGameObjectType getObjType()
	{
		EGameObjectType ObjTypeFlags = *(EGameObjectType*)((DWORD)(this) + 0x210);
		return ObjTypeFlags;
	}

	EGameObjectFlags getObjFlags()
	{
		EGameObjectFlags ObjFlags = *(EGameObjectFlags*)((DWORD)(this) + 0x210);
		return ObjFlags;
	}

	UINT32 hashID;				// 0008
	D3DXVECTOR3 vLoadTimePos;	// 000C
	D3DXVECTOR3 vScl;			// 0018
	D3DXVECTOR3 vPos;			// 0024
	D3DXVECTOR3 vLoadTimeRot;	// 0030
	D3DXVECTOR3 vRot;			// 003C
	DWORD NetworkID;			// 0048
	int PrivateFlags;			// 004C
	GameObject* pNextObject;	// 0050
	GameObject* pPrevObject;	// 0054
	D3DXVECTOR3 setPosition;
	int FirstUpdate;			// 0058
	bool wasSetSkipOcclusionCheck; // 005C
	bool m_isSerializable; // 0060
	bool InMainFrustum; // 0064
	enum EGameObjQualityLevel m_MinQualityLevel; // 0068
	enum PrecalculatedMeshVSConsts preparedVSConsts; // 006C
	class SceneBox*	m_SceneBox; // 0070
	r3dBoundBox bbox_local; // 0074
	r3dBoundBox bbox_world; // 00
	float bbox_radius; // 00
	D3DXMATRIX mTransform; // 00
	int m_isActive; // 00	// if > 0 = active. if<=0 - not active and will be deleted soon!
};

class CNetwork
{
public:
	DWORD* impl; // 0000
	int dumpStats_; // 0004
	int lastPing_; // 0008
};//Size=0x0018

class CBone {

public:
	char*       m_BoneName;       //0x00  
	char        pad_04[136];      //0x04
	D3DXMATRIX  BoneMatrix;       //0x8C  
	D3DXMATRIX  SomeMatrix;       //0xCC  
};
class CBoneInfo {

public:
	char       pad_00[20];
	DWORD      oneNum;            //0x14 
	CBone*     pBones;            //0x18 
};

class CSkeleton {

public:
	char       pad_00[40];
	CBoneInfo* BonePtr;           //0x28 
};

class obj_Player
{
public:
	virtual void vFunc0();
	virtual void vFunc1();
	virtual void vFunc2();
	virtual void vFunc3();
	virtual void vFunc4();
	virtual void vFunc5();
	virtual void vFunc6();
	virtual void vFunc7();
	virtual void vFunc8();
	virtual void vFunc9();
	virtual void vFunc10();
	virtual void vFunc11();
	virtual void vFunc12();
	virtual void SetPosition(const D3DXVECTOR3& pos);

	char _0x0004[32];
	D3DXVECTOR3 vPos; //0x0024 
	char _0x0030[480]; //0x0030 
	int m_flags; //0x0210 
	char _0x0214[452]; //0x0214 
	DWORD m_NameXor; //0x03D8 
	char _0x03DC[60]; //0x03DC 
	int m_NameLength; //0x0418 
	char _0x041C[132]; //0x041C 
	int m_BackPackID; //0x04A0 
	int m_IsAlive; //0x04A4 
	char _0x04A8[12]; //0x04A8 
	float m_Health; //0x04B4 
	float m_Hunger; //0x04B8 
	float m_Thirst; //0x04BC 
	char _0x04C0[40]; //0x04C0 
	int m_LocalPlayerSafeZone; //0x04E8 
	char _0x04EC[2920]; //0x04EC 
	bool m_enableRendering; //0x1054 
	char _0x1055[3]; //0x1055 
	float standStillVisiblity; //0x1058 
	float walkVisibility; //0x105C 
	float runVisibility; //0x1060 
	float sprintVisibility; //0x1064 
	char _0x1068[16]; //0x1068 
	float walkNoise; //0x1078 
	float runNoise; //0x107C 
	float sprintNoise; //0x1080 
	float fireNoise; //0x1084 
	char _0x1088[8]; //0x1088 
	float smell; //0x1090 
	float smell2; //0x1094 
	char _0x1098[352]; //0x1098 
	CSkeleton* m_pSkeleton; //0x1220 
	int PlayerState; //0x11FC 
	int PlayerMoveDir; //0x1200 
	char _0x1204[12]; //0x1204 
	//CWeaponInfo* m_pWeaponPrimary; //0x1210 
	//CWeaponInfo* m_pWeaponSecondary; //0x1214 
	char _0x1218[20]; //0x1218 
	int m_SelectedWeapon; //0x122C 
	int m_PrevSelectedWeapon; //0x1230 
	bool m_isPressedFireTrigger; //0x1234 
	bool m_isAiming; //0x1235 
	bool m_isChnagedAiming1; //0x1236 
	bool m_isInScope; //0x1237 
	bool m_isFinishedAiming; //0x1238 
	char _0x1239[3]; //0x1239 
	float m_BloodTimer; //0x123C 
	char _0x1240[8]; //0x1240 
	float m_PickupTime; //0x1248 
	char _0x124C[32]; //0x124C 
	float lastRewardShowTime_; //0x126C 
	float bodyAdjust_x; //0x1270 
	float bodyAdjust_y[2]; //0x1274 
	int boneId_Bip01_Spine1; //0x127C 
	int boneId_Bip01_Spine2; //0x1280 
	int boneId_Bip01_Neck; //0x1284 
	int boneId_Bip01_LUpperArm; //0x1288 
	int boneId_Bip01_RUpperArm; //0x128C 
	int boneId_Bip01_Head; //0x1290 
	int boneId_Bip01_R_Hand; //0x1294 
	int boneId_Bip01_L_Hand; //0x1298 
	float m_SpeedBoost; //0x129C 
	float m_SpeedBoostTime; //0x12A0 
	float m_MorphineShotTime; //0x12A4 
	float m_BandagesEffectTime; //0x12A8 
	D3DXVECTOR3 plr_local_Velocity; //0x12AC 
	float plr_local_moving_speed; //0x12B8 
	float Height; //0x12BC 
	float m_Stamina; //0x12C0 
	float m_StaminaPenaltyTime; //0x12C4 
	char _0x12C8[16]; //0x12C8 
	float m_Breath; //0x12D8 
	float lastDamageRcvd; //0x12DC 
	float lastTimeHit; //0x12E0 
	int lastTimeHitBone; //0x12E4 
	D3DXVECTOR3 lastTimeHitForce; //0x12E8 
	float BloodEffect; //0x12F4 
	int bDead; //0x12F8 
	float TimeOfDeath; //0x12FC 
	STORE_CATEGORIES DeathDamageSource; //0x1300 
	D3DXVECTOR3 PosOfDeath; //0x1304 
	int TimeOfLastRespawn; //0x1310 
	int Dead_KillerID; //0x1314 
	bool DisableKillerView; //0x1318 
	bool bCrouch; //0x1319 
	bool bProne; //0x131A 
	bool bOnGround; //0x131B 
	float fHeightAboveGround; //0x131C 
	float JumpVelocity; //0x1320 
	float JumpStartTime; //0x1324 
	char _0x1328[84];
	D3DXVECTOR3 m_vRecoilCameraAngles; //0x137C 
	char _0x1388[44];
	float m_yaw; //0x13C4 
	float m_pitch; //0x13C8 
	char _0x13BC[12];
	float m_Speed; //0x13C8 
	float m_SpeedStrafe; //0x13CC 
	char _0x13D0[88];
	D3DXMATRIX m_BoneCoeff; //0x145C 
	D3DXMATRIX DrawFullMatrix; //0x1468 
	D3DXMATRIX DrawFullMatrix_Localized; //0x14A8 
	D3DXMATRIX MoveMatrix; //0x14E8 
	char _0x1528[16];
	float afterRespawnTimer; //0x1538 
	float lastWeapDataRep; //0x153C 
	float lastTimeWeaponSwitch; //0x1540 
	D3DXVECTOR3 viewTargetPos; //0x1544 
	D3DXVECTOR3 viewTargetNorm; //0x1550 
	float m_ReticleTargetScale; //0x155C 
	float m_ReticleCurrentScale; //0x1560 
	bool m_isFemaleHero; //0x1564 
	char _0x1568[8];
	bool bAllowToUseWeapons; //0x1570

		float GetYAW()
	{
		return *(float*)((DWORD)this + 0x13BC); // Player% (Trên)
	}

	float GetPITCH()
	{
		return *(float*)((DWORD)this + 0x13C0);// Player% (Dưới)
	}

	int getH()
	{
		return (int)*(float*)((DWORD)(this) + 0x4C4);// InfoMsg_MaxHealthAlready
	}

		bool getPlayerName(char* name)
	{
		BYTE* dwNameXOR = (BYTE*)((DWORD)(this) + 0x3D8); 
		DWORD dwNameLen = *(DWORD*)((DWORD)(this) + 0x418); 

		for (int i = dwNameLen - 1; i >= 0; i--)
		{
			name[i] = dwNameXOR[i] ^ (BYTE)(i - 87);
		}

		return (name[0] != 0);
	}

	bool isAlive()
	{
		return (this->getH() > 0);
	}


	int getHunger()
	{
		return (int)*(float*)((DWORD)(this) + 0x448);
	}

	int getThirst()
	{
		return (int)*(float*)((DWORD)(this) + 0x44C);
	}

	int getToxic()
	{
		return (int)*(float*)((DWORD)(this) + 0x450);
	}

	int SafeZone()
	{
		return (int)*(float*)((DWORD)(this) + 0x508);
	}

	D3DXVECTOR3* getViewAngle()
	{
		return (D3DXVECTOR3*)((DWORD)(this) + 0x0F64);
	}

	void setViewAngle(D3DXVECTOR3 newAngles)
	{
		*(D3DXVECTOR3*)((DWORD)(this) + 0x0F64) = newAngles;
	}

	wiInventoryItem* getInventory(int index)
	{
		return (wiInventoryItem*)((DWORD)(this) + (0x0588 + (index * sizeof(wiInventoryItem))));
	}
};





