#pragma once
#include "Define.h"
#include "Obj.h"
#include "Player.h"
#include "HuntingField.h"
#include "Store.h"

class CGameStage
{
private:
	CObj* m_pPlayer;
	CHuntingField* m_pHuntingField;
	CStore* m_pStore;

public:
	CGameStage();
	~CGameStage();
	
	void Initialize();
	void Update();
	void Release();
};

