#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:


public:
	CPlayer();
	virtual ~CPlayer();

	void SelectJob();

	void ResetHp();
	void EarnMoney(int _iMoney);
	void LevelUp();
	void ObtainExp(int _iExp);
	void ReduceExp();
	void ReduceMoney();
	void EquipItem(CObj* _pItem);
	void ReleaseItem(CObj* _pItem);

	virtual void Initialize();
	virtual void Render();
	virtual void Release();
};

