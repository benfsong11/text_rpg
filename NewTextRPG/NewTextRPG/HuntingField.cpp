#include "stdafx.h"
#include "HuntingField.h"


CHuntingField::CHuntingField()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}


CHuntingField::~CHuntingField()
{
	Release();
}

void CHuntingField::SetPlayer(CObj * _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CHuntingField::Hunt()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1. �����ϱ� 2. �������� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pPlayer->SetDamage(m_pMonster->GetInfo().iPower);
			m_pMonster->SetDamage(m_pPlayer->GetInfo().iPower);

			if (0 >= m_pPlayer->GetInfo().iHp)
			{
				cout << "����� ����ϼ̽��ϴ�..." << endl;
				static_cast<CPlayer*>(m_pPlayer)->ReduceExp();
				static_cast<CPlayer*>(m_pPlayer)->ReduceMoney();
				static_cast<CPlayer*>(m_pPlayer)->ResetHp();
				system("pause");
				return;
			}

			if (0 >= m_pMonster->GetInfo().iHp)
			{
				cout << "��ɿ� �����ϼ̽��ϴ�!" << endl;
				static_cast<CPlayer*>(m_pPlayer)->ObtainExp(m_pMonster->GetInfo().iExp);
				static_cast<CPlayer*>(m_pPlayer)->EarnMoney(m_pMonster->GetInfo().iMoney);

				if (m_pPlayer->GetInfo().iExp >= m_pPlayer->GetInfo().iMaxExp)
				{
					static_cast<CPlayer*>(m_pPlayer)->LevelUp();
				}
				system("pause");
				return;
			}
			
			break;
		case 2:
			return;
		default:
			continue;
		}
	}
}

void CHuntingField::Initialize()
{
}

void CHuntingField::Update()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. �ʱ� ���� 2. �߱� ���� 3. ��� ���� 4. �����ϱ� 5. �ڷ� ���� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster;
			static_cast<CMonster*>(m_pMonster)->CreateMonster(iInput);
			break;
		case 2:
			m_pMonster = new CMonster;
			static_cast<CMonster*>(m_pMonster)->CreateMonster(iInput);
			break;
		case 3:
			m_pMonster = new CMonster;
			static_cast<CMonster*>(m_pMonster)->CreateMonster(iInput);
			break;
		case 4:
			break;
		case 5:
			return;
		default:
			continue;
		}

		Hunt();
	}
}

void CHuntingField::Release()
{
	SafeDelete(m_pMonster);
}
