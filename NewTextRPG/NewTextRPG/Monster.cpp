#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::CreateMonster(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, 32, "��");
		m_tInfo.iLevel = 1;
		m_tInfo.iExp = 15;
		m_tInfo.iMaxHp = 30;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 10;
		m_tInfo.iMoney = 30;
		break;
	case 2:
		strcpy_s(m_tInfo.szName, 32, "���");
		m_tInfo.iLevel = 3;
		m_tInfo.iExp = 25;
		m_tInfo.iMaxHp = 50;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 30;
		m_tInfo.iMoney = 50;
		break;
	case 3:
		strcpy_s(m_tInfo.szName, 32, "�Ǹ�");
		m_tInfo.iLevel = 5;
		m_tInfo.iExp = 35;
		m_tInfo.iMaxHp = 70;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 50;
		m_tInfo.iMoney = 100;
		break;
	default:
		break;
	}
}

void CMonster::Initialize()
{
}

void CMonster::Render()
{
	cout << "===========================================" << endl;
	cout << "���� ����" << endl;
	cout << "�̸�: " << m_tInfo.szName << endl;
	cout << "����(óġ �� ȹ�� ����ġ): " << m_tInfo.iLevel << "(" << m_tInfo.iExp << ")" << endl;
	cout << "ü��/�ִ� ü��: " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << endl;
	cout << "���ݷ�: " << m_tInfo.iPower << endl;
	cout << "óġ �� ȹ�� �ݾ�: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CMonster::Release()
{
}
