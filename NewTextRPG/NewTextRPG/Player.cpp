#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::SelectJob()
{
	system("cls");

	int iInput = 0;

	cout << "1. 전사 2. 마법사 3. 궁수 4. 종료하기 > ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, 32, "전사");
		m_tInfo.iLevel = 1;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iMaxHp = 100;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 20;
		m_tInfo.iMoney = 0;
		m_tInfo.AdditionalHp = 0;
		m_tInfo.AdditionalPower = 0;
		break;
	case 2:
		strcpy_s(m_tInfo.szName, 32, "마법사");
		m_tInfo.iLevel = 1;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iMaxHp = 45;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 40;
		m_tInfo.iMoney = 0;
		m_tInfo.AdditionalHp = 0;
		m_tInfo.AdditionalPower = 0;
		break;
	case 3:
		strcpy_s(m_tInfo.szName, 32, "궁수");
		m_tInfo.iLevel = 1;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iMaxHp = 60;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iPower = 30;
		m_tInfo.iMoney = 0;
		m_tInfo.AdditionalHp = 0;
		m_tInfo.AdditionalPower = 0;
		break;
	case 4:
		return;
	default:
		break;
	}
}

void CPlayer::ResetHp()
{
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void CPlayer::EarnMoney(int _iMoney)
{
	m_tInfo.iMoney += _iMoney;
}

void CPlayer::LevelUp()
{
	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		++(m_tInfo.iLevel);
		m_tInfo.iExp = 0;
		m_tInfo.iMaxHp += 20;
		m_tInfo.iPower += 10;
	}
}

void CPlayer::ObtainExp(int _iExp)
{
	m_tInfo.iExp += _iExp;
}

void CPlayer::ReduceExp()
{
	m_tInfo.iExp -= 20;

	if (0 >= m_tInfo.iExp)
	{
		m_tInfo.iExp = 0;
	}
}

void CPlayer::ReduceMoney()
{
	m_tInfo.iMoney -= 20;

	if (0 >= m_tInfo.iMoney)
	{
		m_tInfo.iMoney = 0;
	}
}

void CPlayer::Initialize()
{
}

void CPlayer::Render()
{
	cout << "===========================================" << endl;
	cout << "플레이어 정보" << endl;
	cout << "직업: " << m_tInfo.szName << endl;
	cout << "레벨(경험치/최대 경험치): " << m_tInfo.iLevel << "(" << m_tInfo.iExp << "/" << m_tInfo.iMaxExp << ")" << endl;
	cout << "체력/최대 체력: " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << "(+ " << m_tInfo.AdditionalHp << ")" << endl;
	cout << "공격력: " << m_tInfo.iPower << "(+ " << m_tInfo.AdditionalPower << ")" << endl;
	cout << "소지금: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CPlayer::Release()
{
}
