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
	int AdditionalHp; // 방어구 장착으로 오르는 추가 체력
	int AdditionalPower; // 무기 장착으로 오르는 추가 공격력
	char szWeaponName[32]; // 플레이어가 장착한 무기의 이름
	char szArmorName[32]; // 플레이어가 장착한 방어구의 이름
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

enum ITEM_GRADE
{
	BEGINNER,
	INTERMEDIATE,
	ADVANCED
};