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
	cout << "Text RPG�� ���� ���� ȯ���մϴ�!" << endl;
	cout << "������ �����ϰ� ���͸� ó���� �ּ���!" << endl;
	cout << "===========================================" << endl;
	cout << "1. ���� ���� 2. �ҷ����� 3. �����ϱ� > ";
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

		cout << "1. ����� 2. ���� 3. �κ��丮 4. �����ϱ� > ";
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
