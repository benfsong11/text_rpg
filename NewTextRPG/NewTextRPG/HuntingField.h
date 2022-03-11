#pragma once
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

class CHuntingField
{
private:
	CObj* m_pPlayer;
	CObj* m_pMonster;
	CInventory* m_pInventory;

public:
	CHuntingField();
	~CHuntingField();

	void SetPlayer(CObj* _pPlayer);
	void SetInven(CInventory* _pInventory);

	void Hunt();

	void Initialize();
	void Update();
	void Release();
};

