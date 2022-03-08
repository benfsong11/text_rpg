#pragma once
#include "Define.h"

class CObj
{
protected:
	INFO m_tInfo;

public:
	CObj();
	virtual ~CObj();

	INFO GetInfo();
	void SetDamage(int _iPower);
	
	void ButItem(int _iPrice);

	virtual void Initialize() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};

