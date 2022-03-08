#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
}


CObj::~CObj()
{
}

INFO CObj::GetInfo()
{
	return m_tInfo;
}

void CObj::SetDamage(int _iPower)
{
	m_tInfo.iHp -= _iPower;
}

void CObj::ButItem(int _iPrice)
{
	m_tInfo.iMoney -= _iPrice;
}
