#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	m_pEmpty = nullptr;
}


CPlayer::~CPlayer()
{
	Release();
}


void CPlayer::LoadData()
{
	FILE* fp = nullptr;
	errno_t	err = fopen_s(&fp, "../Data/Save.dat", "rb");

	if (0 == err)
	{
		INFO tInfo = {};

		fread(&tInfo, sizeof(INFO), 1, fp);
		// fread(&m_loadVec, sizeof(vector<CObj*>), 1, fp);

		m_tInfo = tInfo;

		cout << "불러오기 성공" << endl;
		fclose(fp);
	}
	else
		cout << "불러오기 실패" << endl;

	system("pause");

}

vector<CObj*> CPlayer::GetLoadVec()
{
	return m_loadVec;
}


void CPlayer::SelectJob()
{
	system("cls");

	int iInput = 0;

	cout << "1. 전사 2. 마법사 3. 궁수 4. 불러오기 5. 종료하기 > ";
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
		m_tInfo.iMoney = 10000; // 나중에 0으로 바꾸기
		m_tInfo.AdditionalHp = 0;
		m_tInfo.AdditionalPower = 0;
		strcpy_s(m_tInfo.szWeaponName, 32, "");
		strcpy_s(m_tInfo.szArmorName, 32, "");
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
		strcpy_s(m_tInfo.szWeaponName, 32, "");
		strcpy_s(m_tInfo.szArmorName, 32, "");
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
		strcpy_s(m_tInfo.szWeaponName, 32, "");
		strcpy_s(m_tInfo.szArmorName, 32, "");
		break;
	case 4:
		LoadData();
		break;
	case 5:
		exit(0);
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

void CPlayer::EquipItem(CObj* _pItem)
{
	// 장비가 가지고 있는 HP값이 0인 경우 -> 무기인 경우
	if (_pItem->GetInfo().iHp == 0)
	{
		m_vecInven[ITEM_WEAPON].push_back(_pItem);
		strcpy_s(m_tInfo.szWeaponName, 32, _pItem->GetInfo().szName);
		m_tInfo.AdditionalPower = _pItem->GetInfo().iPower;
		m_tInfo.iPower += m_tInfo.AdditionalPower;
	}
	// 장비가 가지고 있는 공격력값이 0인 경우 -> 방어구인 경우
	else if (_pItem->GetInfo().iPower == 0)
	{
		m_vecInven[ITEM_ARMOR].push_back(_pItem);
		strcpy_s(m_tInfo.szArmorName, 32, _pItem->GetInfo().szName);
		m_tInfo.AdditionalHp = _pItem->GetInfo().iHp;
		m_tInfo.iHp += m_tInfo.AdditionalHp;
		m_tInfo.iMaxHp += m_tInfo.AdditionalHp;
	}
		
	
}

CObj* CPlayer::ReleaseItem(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		if (1 == m_vecInven[ITEM_WEAPON].size())
		{
			strcpy_s(m_tInfo.szWeaponName, 32, "");
			m_tInfo.iPower -= m_tInfo.AdditionalPower;
			m_tInfo.AdditionalPower = 0;
			return m_vecInven[ITEM_WEAPON][_iInput - 1];
		}
		else
		{
			cout << "해제할 아이템이 없습니다." << endl;
			system("pause");
			return m_pEmpty;
		}
	case 2:
		if (1 == m_vecInven[ITEM_ARMOR].size())
		{
			strcpy_s(m_tInfo.szArmorName, 32, "");
			m_tInfo.iHp -= m_tInfo.AdditionalHp;
			m_tInfo.iMaxHp -= m_tInfo.AdditionalHp;
			m_tInfo.AdditionalHp = 0;
			return m_vecInven[ITEM_ARMOR][_iInput - 2];
		}
		else
		{
			cout << "해제할 아이템이 없습니다." << endl;
			system("pause");
			return m_pEmpty;
		}
	default:
		break;
	}
}

void CPlayer::ReleaseInven(int _iInput)
{
	if (1 == m_vecInven[_iInput - 1].size())
		m_vecInven[_iInput - 1].erase(m_vecInven[_iInput - 1].begin());
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
	cout << "착용 무기: " << m_tInfo.szWeaponName << endl;
	cout << "착용 방어구:" << m_tInfo.szArmorName << endl;
	cout << "소지금: " << m_tInfo.iMoney << endl;
	cout << "===========================================" << endl;
}

void CPlayer::Release()
{
	for_each(m_vecInven[ITEM_END].begin(), m_vecInven[ITEM_END].end(), SafeDelete<CObj*>);
	m_vecInven[ITEM_END].clear();
	vector<CObj*>().swap(m_vecInven[ITEM_END]);

	SafeDelete(m_pEmpty);
}
