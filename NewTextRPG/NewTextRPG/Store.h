#pragma once
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Define.h"

class CStore
{
private:
	CObj* m_pPlayer;
	CInventory* m_pInventory;
	vector<CObj*> m_vecItem[ITEM_END];

public:
	CStore();
	~CStore();

	void SetPlayer(CObj* _pPlayer);
	void SetInven(CInventory* _pInven);
	vector<CObj*> GetItem();

	void Initialize(void);
	void Update(void);
	void Render(ITEM_TYPE _eType);
	void Release(void);
	void BuyItem(CObj* _pItem);
	void SellItem(void);
};

