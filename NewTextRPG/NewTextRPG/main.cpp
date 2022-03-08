// NewTextRPG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GameStage.h"


int main()
{
	CGameStage GameStage;

	GameStage.Initialize();
	GameStage.Update();

    return 0;
}

