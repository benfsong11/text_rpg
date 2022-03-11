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
		
		cout << "저장 성공" << endl;
		fclose(fp);
	}
	else
		cout << "저장 실패" << endl;

	system("pause");
	
}

void CGameStage::Initialize()
{
	int iInput = 0;

	cout << "===========================================" << endl;
	cout << "Text RPG에 오신 것을 환영합니다!" << endl;
	cout << "직업을 선택하고 몬스터를 처리해 주세요!" << endl;
	cout << "===========================================" << endl;
	cout << "1. 게임 시작 2. 종료하기 > ";
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

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 저장하기 5. 종료하기 > ";
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
