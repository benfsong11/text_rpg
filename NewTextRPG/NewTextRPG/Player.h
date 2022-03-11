#pragma once
#include "Obj.h"
#include "Define.h"

class CPlayer : public CObj
{
private:

public:
	CPlayer();
	virtual ~CPlayer();

	void LoadData();

	void SelectJob();

	void ResetHp();
	void EarnMoney(int _iMoney);
	void LevelUp();
	void ObtainExp(int _iExp);
	void ReduceExp();
	void ReduceMoney();
	void EquipItem(CObj* _pItem);
	void ReleaseItem(int _iInput);

	virtual void Initialize();
	virtual void Render();
	virtual void Release();
};

