#pragma once
#include "Player.h"
#include "Monster.h"

class CHuntingField
{
private:
	CObj* m_pPlayer;
	CObj* m_pMonster;

public:
	CHuntingField();
	~CHuntingField();

	void SetPlayer(CObj* _pPlayer);

	void Hunt();

	void Initialize();
	void Update();
	void Release();
};

