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

	cout << "1. ���� 2. ������ 3. �ü� 4. �����ϱ� > ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, 32, "����");
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
		strcpy_s(m_tInfo.szName, 32, "������");
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
		strcpy_s(m_tInfo.szName, 32, "�ü�");
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
	cout << "�÷��̾� ����" << endl;
	cout << "����: " << m_tInfo.szName << endl;
	cout << "����(����ġ/�ִ� ����ġ): " << m_tInfo.iLevel << "(" << m_tInfo.iExp << "/" << m_tInfo.iMaxExp << ")" << endl;
	cout << "ü��/�ִ� ü��: " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << "(+ " << m_tInfo.AdditionalHp << ")" << endl;
	cout << "���ݷ�: " << m_tInfo.iPower << "(+ " << m_tInfo.AdditionalPower << ")" << endl;
	cout << "������: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CPlayer::Release()
{
}
