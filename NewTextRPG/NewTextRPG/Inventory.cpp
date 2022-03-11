#include "stdafx.h"
#include "Inventory.h"


CInventory::CInventory()
	: m_iSize(5)
{
	m_pPlayer = nullptr;
	m_vecInventory.reserve(m_iSize);
}


CInventory::~CInventory()
{
}

void CInventory::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CInventory::SetInventory(CObj* _pItem)
{
	m_vecInventory.push_back(_pItem);
}

vector<CObj*> CInventory::GetInventory()
{
	return m_vecInventory;
}


void CInventory::EquipItem()
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render();

		cout << "#. ������ ������ ��ȣ 0. ������ > ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if ((size_t)iInput >= m_vecInventory.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->EquipItem(m_vecInventory[iInput]);
		m_vecInventory.erase(m_vecInventory.begin() + iInput);
	}
}

void CInventory::ReleaseItem()
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render();

		cout << "1. ���� ���� 2. �� ���� 0. �ڷ� ���� > ";
		cin >> iInput;
		// --iInput;

		if (0 >= iInput || 3 <= iInput)
			return;

		// if ((size_t)iInput >= m_vecInventory.size())
			// continue;

		CObj* ReleasedItem = dynamic_cast<CPlayer*>(m_pPlayer)->ReleaseItem(iInput);
		if (ReleasedItem)
		{
			m_vecInventory.push_back(ReleasedItem);
		}
		dynamic_cast<CPlayer*>(m_pPlayer)->ReleaseInven(iInput);
	}
}

void CInventory::SellItem(int _iInput)
{
	static_cast<CPlayer*>(m_pPlayer)->EarnMoney((m_vecInventory[_iInput - 1]->GetInfo().iMoney) / 2);
	m_vecInventory.erase(m_vecInventory.begin() + _iInput - 1);
}

void CInventory::Initialize()
{
	m_vecInventory.reserve(m_iSize);
}

void CInventory::Update()
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. ���� 2. ���� 3. �ڷ� ���� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			EquipItem();
			break;

		case 2:
			ReleaseItem();
			break;

		case 3:
			return;

		default:
			continue;
		}
	}
}

void CInventory::Render()
{
	if (0 == m_vecInventory.size())
	{
		cout << "===========================================" << endl;
		cout << "�������� �����ϴ�." << endl;
		cout << "===========================================" << endl;
	}
	else
	{
		for (size_t i = 0; i < m_vecInventory.size(); ++i)
		{
			cout << i + 1 << "�� ������" << endl;
			cout << "===========================================" << endl;
			cout << "�̸�: " << m_vecInventory[i]->GetInfo().szName << endl;
			cout << "�Ǹ� ����: " << (m_vecInventory[i]->GetInfo().iMoney) / 2 << endl;
			cout << "===========================================" << endl;
		}
	}
}

void CInventory::Release()
{
	for_each(m_vecInventory.begin(), m_vecInventory.end(), SafeDelete<CObj*>);
	m_vecInventory.clear();
	vector<CObj*>().swap(m_vecInventory);
}
