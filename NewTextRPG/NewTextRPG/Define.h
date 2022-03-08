#pragma once

typedef struct tagInfo
{
	char szName[32];
	int iLevel;
	int iExp;
	int iMaxExp;
	int iHp;
	int iMaxHp;
	int iPower;
	int iMoney;
	int AdditionalHp;
	int AdditionalPower;
} INFO;

template<typename T>
void SafeDelete(T& rTemp)
{
	if (rTemp)
	{
		delete rTemp;
		rTemp = nullptr;
	}
}

enum ITEM_TYPE
{
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_END
};