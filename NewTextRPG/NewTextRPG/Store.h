#pragma once
#include "Player.h"
#include "Define.h"

class CStore
{
private:
	CObj* m_pPlayer;
	vector<CObj*> m_vecItem[ITEM_END];

public:
	CStore();
	~CStore();

	void SetPlayer(CObj* _pPlayer);

	void Initialize(void);
	void Update(void);
	void Render(ITEM_TYPE _eType);
	void Release(void);
	void BuyItem(CObj* pItem);
	void SellItem(void);
};

