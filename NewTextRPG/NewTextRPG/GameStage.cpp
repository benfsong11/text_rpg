#include "stdafx.h"
#include "GameStage.h"


CGameStage::CGameStage()
{
	m_pPlayer = nullptr;
	m_pHuntingField = nullptr;
	m_pStore = nullptr;
	m_pInventory = nullptr;
}

CGameStage::~CGameStage()
{
	Release();
}

void CGameStage::SaveData()
{
	FILE* fp = nullptr;
	errno_t	err = fopen_s(&fp, "../Data/Save.dat", "wb");


	if (0 == err)
	{
		fwrite(&(m_pPlayer->GetInfo()), sizeof(INFO), 1, fp);
		// fwrite(&(m_pInventory->GetInventory()), sizeof(vector<CObj*>), 1, fp);
		
		cout << "���� ����" << endl;
		fclose(fp);
	}
	else
		cout << "���� ����" << endl;

	system("pause");
	
}

void CGameStage::Initialize()
{
	int iInput = 0;

	cout << "===========================================" << endl;
	cout << "Text RPG�� ���� ���� ȯ���մϴ�!" << endl;
	cout << "������ �����ϰ� ���͸� ó���� �ּ���!" << endl;
	cout << "===========================================" << endl;
	cout << "1. ���� ���� 2. �����ϱ� > ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer;
		}
		if (!m_pInventory)
		{
			m_pInventory = new CInventory;
			m_pInventory->Initialize();
			m_pInventory->SetPlayer(m_pPlayer);
		}
		static_cast<CPlayer*>(m_pPlayer)->SelectJob();
		break;
	case 2:
		return;
	default:
		break;
	}
}

void CGameStage::Update()
{
	int iInput = 0;


	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. ����� 2. ���� 3. �κ��丮 4. �����ϱ� 5. �����ϱ� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (!m_pHuntingField)
			{
				m_pHuntingField = new CHuntingField;
				m_pHuntingField->SetPlayer(m_pPlayer);
				m_pHuntingField->SetInven(m_pInventory);
			}
			m_pHuntingField->Update();
			break;
		case 2:
			if (!m_pStore)
			{
				m_pStore = new CStore;
				m_pStore->Initialize();
				m_pStore->SetPlayer(m_pPlayer);
				m_pStore->SetInven(m_pInventory);
			}
			m_pStore->Update();
			break;
		case 3:
			if (nullptr != m_pInventory)
			{
				/*if (0 < static_cast<CPlayer*>(m_pPlayer)->GetLoadVec().size())
					m_pInventory->SetLoadInven(static_cast<CPlayer*>(m_pPlayer)->GetLoadVec());*/
				m_pInventory->Update();
				
			}
			break;
		case 4:
			SaveData();
			break;
		case 5:
			return;
		default:
			continue;
		}
	}
}

void CGameStage::Release()
{
	SafeDelete(m_pPlayer);
	SafeDelete(m_pHuntingField);
	SafeDelete(m_pStore);
	SafeDelete(m_pInventory);
}
