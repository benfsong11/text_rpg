#pragma once
#include "Player.h"
#include "Item.h"

class CInventory
{
private:
	CObj* m_pPlayer;
	vector<CObj*> m_vecInventory;
	const size_t m_iSize;

public:
	CInventory();
	~CInventory();

	void SetPlayer(CObj* _pPlayer);
	void CInventory::SetLoadInven(vector<CObj*>& _vec);
	void SetInventory(CObj* _pItem);
	vector<CObj*> GetInventory();

	void EquipItem();
	void ReleaseItem();
	void SellItem(int _iInput);

	void Initialize();
	void Update();
	void Render();
	void Release();
};

