#include "GameManager.h"

GameManager::GameManager() : sellButton("Sell Tower"), upgradeButton("Upgrade Tower")
{
	showingGrid = false;
	playing = false;
	screenState = 0;
	selectedPlayer = NULL;
	selectedIndexes[0] = -1;
	selectedIndexes[1] = -1;
	selectedIndexes[2] = -1;
	selectedIndexes[3] = -1;
	selectedTower = NULL;
}

GameManager::~GameManager(){
	towers.clear();
	enemies.clear();
	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		delete hereYouAre[i];
	}
	delete hereYouAre;
}

GlutWindow* GameManager::getWin(){
	return &win;
}

void GameManager::getReadyToPlay(){
	playing = true;
	wavesStarted = false;
	finished = false;
	victory = false;
	scoreInLevel = 0;
	dnaInLevel = 0;
	timeInLevel = 0;
	playerHitPoints = 100;
	dnaInLevel = 375;
}

void GameManager::gameFinished(){
	playing = false;
	Level data = selectedPlayer->getLevel(levelSelected);
	Level newData;
	selectedTower = NULL;
	sellButton.setEnable(false);
	upgradeButton.setEnable(false);
	if (victory){// only if victory
		newData.completed = true;
		newData.score = scoreInLevel;
		newData.locked = false;
		
		if (!data.completed){// if the leve was not completed
			if (levelSelected < 4)// just 0 1 2 3
				selectedPlayer->unlock(levelSelected + 1);// unlock the next level
			selectedPlayer->setNewLevelScore(levelSelected, newData);// has to be after, since this has the savePlayer included
		}
		else if (data.score < scoreInLevel){// or if was completed but a higger score has been reached
			selectedPlayer->setNewLevelScore(levelSelected, newData);
		}

	}
}

