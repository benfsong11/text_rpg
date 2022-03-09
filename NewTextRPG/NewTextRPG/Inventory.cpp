#include "stdafx.h"
#include "Inventory.h"


CInventory::CInventory()
	: m_iSize(5)
{
	m_pPlayer = nullptr;
}


CInventory::~CInventory()
{
}

void CInventory::SetPlayer(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CInventory::EquipItem()
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render();

		cout << "0. ������ > ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if ((size_t)iInput >= m_vecInventory.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->EquipItem(m_vecInventory[iInput]);
	}
}

void CInventory::ReleaseItem()
{
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
	for (size_t i = 0; i < m_vecInventory.size(); ++i)
	{
		cout << i + 1 << "�� ������" << endl;
		m_vecInventory[i]->Render();
	}
}

void CInventory::Release()
{
	for_each(m_vecInventory.begin(), m_vecInventory.end(), SafeDelete<CObj*>);
	m_vecInventory.clear();
	vector<CObj*>().swap(m_vecInventory);
}
