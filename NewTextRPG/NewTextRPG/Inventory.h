#pragma once
#include "Player.h"
#include "Item.h"

class CInventory
{
	CObj* m_pPlayer;
	vector<CObj*> m_vecInventory;
	const size_t m_iSize;

public:
	CInventory();
	~CInventory();

	void SetPlayer(CObj* _pPlayer);

	void EquipItem();
	void ReleaseItem();

	void Initialize();
	void Update();
	void Render();
	void Release();
};

