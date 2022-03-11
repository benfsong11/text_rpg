#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}



CItem::~CItem()
{
}

void CItem::SetItemType(ITEM_TYPE _eType)
{
}

void CItem::SetItem(ITEM_TYPE _eType, ITEM_GRADE _eGrade)
{
	switch (_eType)
	{
	case ITEM_WEAPON:
		switch (_eGrade)
		{
		case BEGINNER:
			strcpy_s(m_tInfo.szName, 32, "�����ϸ� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 0;
			m_tInfo.iPower = 10;
			m_tInfo.iMoney = 100;
			break;
		case INTERMEDIATE:
			strcpy_s(m_tInfo.szName, 32, "�ۼַ��� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 0;
			m_tInfo.iPower = 30;
			m_tInfo.iMoney = 400;
			break;
		case ADVANCED:
			strcpy_s(m_tInfo.szName, 32, "�����μ��̵� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 0;
			m_tInfo.iPower = 70;
			m_tInfo.iMoney = 1000;
			break;
		default:
			break;
		}
		break;
	case ITEM_ARMOR:
		switch (_eGrade)
		{
		case BEGINNER:
			strcpy_s(m_tInfo.szName, 32, "�̱۾��� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 20;
			m_tInfo.iPower = 0;
			m_tInfo.iMoney = 100;
			break;
		case INTERMEDIATE:
			strcpy_s(m_tInfo.szName, 32, "�ۼַ��� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 50;
			m_tInfo.iPower = 0;
			m_tInfo.iMoney = 400;
			break;
		case ADVANCED:
			strcpy_s(m_tInfo.szName, 32, "�����μ��̵� ����");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 100;
			m_tInfo.iPower = 0;
			m_tInfo.iMoney = 1000;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void CItem::EquipItem()
{
}

void CItem::Initialize()
{
}

void CItem::Render()
{
	cout << "===========================================" << endl;
	cout << "�̸�: " << m_tInfo.szName << endl;
	cout << "����: " << m_tInfo.iLevel << endl;
	cout << "ü��: " << m_tInfo.iHp << endl;
	cout << "���ݷ�: " << m_tInfo.iPower << endl;
	cout << "����: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CItem::Release()
{
}
