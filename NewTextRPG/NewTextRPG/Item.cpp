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
			strcpy_s(m_tInfo.szName, 32, "파프니르 무기");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 0;
			m_tInfo.iPower = 10;
			m_tInfo.iMoney = 100;
			break;
		case INTERMEDIATE:
			strcpy_s(m_tInfo.szName, 32, "앱솔랩스 무기");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 0;
			m_tInfo.iPower = 30;
			m_tInfo.iMoney = 400;
			break;
		case ADVANCED:
			strcpy_s(m_tInfo.szName, 32, "아케인셰이드 무기");
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
			strcpy_s(m_tInfo.szName, 32, "이글아이 갑옷");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 20;
			m_tInfo.iPower = 0;
			m_tInfo.iMoney = 100;
			break;
		case INTERMEDIATE:
			strcpy_s(m_tInfo.szName, 32, "앱솔랩스 갑옷");
			m_tInfo.iLevel = 1;
			m_tInfo.iHp = 50;
			m_tInfo.iPower = 0;
			m_tInfo.iMoney = 400;
			break;
		case ADVANCED:
			strcpy_s(m_tInfo.szName, 32, "아케인셰이드 갑옷");
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
	cout << "구매 가능 장비 정보" << endl;
	cout << "이름: " << m_tInfo.szName << endl;
	cout << "레벨: " << m_tInfo.iLevel << endl;
	cout << "체력: " << m_tInfo.iHp << endl;
	cout << "공격력: " << m_tInfo.iPower << endl;
	cout << "가격: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CItem::Release()
{
}
