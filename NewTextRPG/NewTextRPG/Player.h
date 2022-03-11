#pragma once
#include "Obj.h"
#include "Define.h"

class CPlayer : public CObj
{
private:
	vector<CObj*> m_vecInven[ITEM_END]; // 플레이어가 장착한 장비의 벡터
	CObj* m_pEmpty; // 해제할 아이템이 없을 경우 반환할 nullptr 객체
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
	CObj* ReleaseItem(int _iInput);
	void ReleaseInven(int _iInput);

	virtual void Initialize();
	virtual void Render();
	virtual void Release();
};

