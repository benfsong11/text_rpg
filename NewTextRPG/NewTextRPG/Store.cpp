#include "stdafx.h"
#include "Store.h"


CStore::CStore()
{
	m_pPlayer = nullptr;
	m_pInventory = nullptr;
	m_vecItem[ITEM_WEAPON].reserve(3);
	m_vecItem[ITEM_ARMOR].reserve(3);
}


CStore::~CStore()
{
	Release();
}

void CStore::SetPlayer(CObj * _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CStore::SetInven(CInventory * _pInven)
{
	m_pInventory = _pInven;
}

vector<CObj*> CStore::GetItem()
{
	return m_vecItem[ITEM_END];
}

void CStore::Initialize(void)
{
}

void CStore::Update(void)
{
	int iInput = 0;

	CItem* pBeginnerWeapon = new CItem;
	pBeginnerWeapon->SetItem(ITEM_WEAPON, BEGINNER);
	m_vecItem[ITEM_WEAPON].push_back(pBeginnerWeapon);

	CItem* pIntermediateWeapon = new CItem;
	pIntermediateWeapon->SetItem(ITEM_WEAPON, INTERMEDIATE);
	m_vecItem[ITEM_WEAPON].push_back(pIntermediateWeapon);

	CItem* pAdvancedWeapon = new CItem;
	pAdvancedWeapon->SetItem(ITEM_WEAPON, ADVANCED);
	m_vecItem[ITEM_WEAPON].push_back(pAdvancedWeapon);

	CItem* pBeginnerArmor = new CItem;
	pBeginnerArmor->SetItem(ITEM_ARMOR, BEGINNER);
	m_vecItem[ITEM_ARMOR].push_back(pBeginnerArmor);

	CItem* pIntermediateArmor = new CItem;
	pIntermediateArmor->SetItem(ITEM_ARMOR, INTERMEDIATE);
	m_vecItem[ITEM_ARMOR].push_back(pIntermediateArmor);

	CItem* pAdvancedArmor = new CItem;
	pAdvancedArmor->SetItem(ITEM_ARMOR, ADVANCED);
	m_vecItem[ITEM_ARMOR].push_back(pAdvancedArmor);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. ���� ���� 2. �� ���� 3. �Ǹ� 4. �ڷ� ���� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(ITEM_WEAPON);
			break;

		case 2:
			Render(ITEM_ARMOR);
			break;

		case 3:
			SellItem();
			break;

		case 4:
			return;

		default:
			continue;
		}

	}
}

void CStore::Render(ITEM_TYPE _eType)
{
	int		iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		int i = 1;

		for (vector<CObj*>::iterator iter = m_vecItem[_eType].begin();
			iter != m_vecItem[_eType].end(); ++iter, ++i)
		{
			cout << i << "�� ������" << endl;
			(*iter)->Render();
		}
		cout << "#. ������ ������ ��ȣ 4. �ڷ� ���� > ";
		cin >> iInput;

		if (4 == iInput)
			return;
		BuyItem(m_vecItem[_eType][iInput - 1]);
	}
}

void CStore::Release(void)
{
	for (int i = 0; i < ITEM_END; ++i)
	{
		for_each(m_vecItem[i].begin(), m_vecItem[i].end(), SafeDelete<CObj*>);
		m_vecItem[i].clear();
		vector<CObj*>().swap(m_vecItem[i]);
	}
}

void CStore::BuyItem(CObj* _pItem)
{
	if ((m_pPlayer->GetInfo().iMoney >= _pItem->GetInfo().iMoney) && (m_pInventory->GetInventory().size() < 5))
	{
		m_pPlayer->ButItem(_pItem->GetInfo().iMoney);
		m_pInventory->SetInventory(_pItem);
		cout << "�������� �����ϼ̽��ϴ�!" << endl;	
	}
	else
	{
		cout << "�κ��丮 ĭ�� ���� á�ų� �ܾ��� �����մϴ�." << endl;
	}
	system("pause");
}

void CStore::SellItem(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		m_pPlayer->Render();
		m_pInventory->Render();

		cout << "#. �Ǹ��� ������ ��ȣ 0. �ڷ� ���� > ";
		cin >> iInput;

		if (0 == iInput)
			return;
		m_pInventory->SellItem(iInput);
	}
	
}
