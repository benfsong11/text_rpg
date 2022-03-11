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
	int AdditionalHp; // �� �������� ������ �߰� ü��
	int AdditionalPower; // ���� �������� ������ �߰� ���ݷ�
	char szWeaponName[32]; // �÷��̾ ������ ������ �̸�
	char szArmorName[32]; // �÷��̾ ������ ���� �̸�
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