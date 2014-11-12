#include "GameManager.h"

GameManager::GameManager()
{
	playing = false;
	screenState = 0;
	selectedPlayer = NULL;
}

GlutWindow* GameManager::getWin(){
	return &win;
}

