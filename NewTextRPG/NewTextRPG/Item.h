#pragma once
#include "Obj.h"
#include "Define.h"

class CItem : public CObj
{
private:
	ITEM_TYPE m_eType;

public:
	CItem();
	virtual ~CItem();

	void SetItemType(ITEM_TYPE _eType);
	void SetItem(ITEM_TYPE _eType, ITEM_GRADE _eGrade);
	void EquipItem();

	virtual void Initialize();
	virtual void Render();
	virtual void Release();
};

