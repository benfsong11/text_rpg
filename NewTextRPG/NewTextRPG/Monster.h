#pragma once
#include "Obj.h"
class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();

	void CreateMonster(int _iInput);

	virtual void Initialize();
	virtual void Render();
	virtual void Release();
};

