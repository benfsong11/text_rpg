#include "stdafx.h"
#include "GameStage.h"


CGameStage::CGameStage()
{
	m_pPlayer = nullptr;
	m_pHuntingField = nullptr;
	m_pStore = nullptr;
}

CGameStage::~CGameStage()
{
	Release();
}

void CGameStage::Initialize()
{
	int iInput = 0;

	cout << "===========================================" << endl;
	cout << "Text RPG에 오신 것을 환영합니다!" << endl;
	cout << "직업을 선택하고 몬스터를 처리해 주세요!" << endl;
	cout << "===========================================" << endl;
	cout << "1. 게임 시작 2. 불러오기 3. 종료하기 > ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer;
		}
		static_cast<CPlayer*>(m_pPlayer)->SelectJob();
		break;
	case 2:
		break;
	case 3:
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

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료하기 > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (!m_pHuntingField)
			{
				m_pHuntingField = new CHuntingField;
				m_pHuntingField->SetPlayer(m_pPlayer);
			}
			m_pHuntingField->Update();
			break;
		case 2:
			if (!m_pStore)
			{
				m_pStore = new CStore;
				m_pStore->Initialize();
				m_pStore->SetPlayer(m_pPlayer);
				// m_pStore->Set_Inven(m_pInven);
			}
			m_pStore->Update();
			break;
		case 3:
			break;
		case 4:
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
}
