#include "GameManager.h"

void GameManager::button_listener(int id){
	std::vector<Button> *levelbuttons;
	std::vector<Grid> *auxGridData;


	// fomr 1 to 4 are navigation orders (0 is back)
	// bigger than that are action orders
	
	if (id < 4){
		//loading screen
		if (hereYouAre[screenState][id] == ERRORNAV){
			std::cout << "Fatal error, trying to navigate from screen #" << screenState << " with invalid option #" << id << std::endl;
			return;
		}
		if (screenState == HISTORY){
			loadScreen(hereYouAre[screenState][id]);
			if (id != 0){// if its not a back button
				levelbuttons = selectedPlayer->getLevelButtons();
				if (buttons->size() > 2)//delete previous buttons if the case
				for (unsigned int i = 0; i < levelbuttons->size(); i++)
					buttons->pop_back();

				for (unsigned int i = 0; i < levelbuttons->size(); i++){
					buttons->push_back((*levelbuttons)[i]);
				}
				selectedPlayer->setNewPlayer(false);
			}
			//selectedPlayer->savePlayer(); deactivated for testing, you MUST uncomment this line
		}
		else{
			loadScreen(hereYouAre[screenState][id]);
		}
		
	}
	else{//where is 4 and five?? its a magical mistery
		//6 show player data
		switch (id)
		{
		case 6:// SELECT PLAYER goTo(levelSelection)
		case 7:
		case 8:
			selectedPlayer = &players[id - 6];
			levels = selectedPlayer->getAllLevels();
			levelbuttons = selectedPlayer->getLevelButtons();

			if (selectedPlayer->isNewPlayer()){
				loadScreen(hereYouAre[screenState][2]);
			}
			else{
				loadScreen(hereYouAre[screenState][1]);
				if (buttons->size() > 1)//delete previous buttons if the case
				for (unsigned int i = 0; i < levelbuttons->size(); i++)
					buttons->pop_back();

				for (unsigned int i = 0; i < levelbuttons->size(); i++){
					buttons->push_back((*levelbuttons)[i]);
				}
			}

			break;

		case 9://level selection goTo(Play)
		case 10:
		case 11:
		case 12:
		case 13:
			levelSelected = 0; // id - 9
			if (hereYouAre[screenState][1] == ERRORNAV){
				std::cout << "Fatal error, trying to navigate from screen #" << screenState << " with invalid option #" << 1 << std::endl;
				return;
			}
			getReadyToPlay();

			auxGridData = levelsData[levelSelected].getGridData();
			wavesManager.loadLevel(levelsData[levelSelected].getWaves());

			for (unsigned i = 0; i < grids.size(); i++){
				grids[i].placeable = (*auxGridData)[i].placeable;
				grids[i].img = (*auxGridData)[i].img;
				grids[i].state = (*auxGridData)[i].state;
				grids[i].tileType = (*auxGridData)[i].tileType;
			}
			path = levelsData[levelSelected].getPathData();
			loadScreen(hereYouAre[screenState][1]);
			break;
			//special back from playing
		case 19:
			// resetomg al game stuff
			playing = false;
			showingGrid = false;
			for (int i = 0; i < rc * rc; i++){
				grids[i].placeable = true;
				grids[i].state = GRD_STATE_PLACEABLE;
			}
			enemies.clear();
			towers.clear();

			loadScreen(hereYouAre[screenState][0]);
			//tower buttons
			break;
		case 20:
		case 21:
		case 22:
		case 23:
			typeOfPlacingTower = id - 20;
			showingGrid = true;
			break;
		default:
			break;
		}
	}
}

void GameManager::pasiveMouse(int x, int y){
	for (unsigned int i = 0; i < buttons->size(); i++){
		(*buttons)[i].mouseState(x, y, false);
	}

	//seleccionado
	if (playing){
		mouseTracking.posX = x;
		mouseTracking.posY = y;

		if (x >= -500 && x < 250 && y >= -500 && y <= 357){ // isOnMap
			isOnMap = true;
			selectGrid(x, y);
		}
		else{
			isOnMap = false;
		}
	}
	
}

void GameManager::rigthClick(int x, int y, int state)// state up or down
{
	if (state == GLUT_DOWN)
	{

	}
	else
	{

	}
}

void GameManager::leftClick(int x, int y, int state)
{
	if (state == GLUT_DOWN){
		for (unsigned int i = 0; i < buttons->size(); i++){
			(*buttons)[i].mouseState(x, y, true);
		}
	}
	else {
		if (playing){
			if (showingGrid){
				if (isOnMap){
					if (canPlace){
						Tower toPlace(data, enemies, grids[selectedIndexes[0]].posXY.posX + grids[selectedIndexes[0]].width / 2.0, grids[selectedIndexes[0]].posXY.posY - grids[selectedIndexes[0]].heith / 2.0, 0, typeOfPlacingTower);
						toPlace.setSizes(grids[selectedIndexes[0]].width * 2, grids[selectedIndexes[0]].heith * 2, 1);
						towers.push_back(toPlace);
						grids[selectedIndexes[0]].placeable = false;
						grids[selectedIndexes[1]].placeable = false;
						grids[selectedIndexes[2]].placeable = false;
						grids[selectedIndexes[3]].placeable = false;
						grids[selectedIndexes[0]].state = GRD_STATE_NOTPLACEABLE;
						grids[selectedIndexes[1]].state = GRD_STATE_NOTPLACEABLE;
						grids[selectedIndexes[2]].state = GRD_STATE_NOTPLACEABLE;
						grids[selectedIndexes[3]].state = GRD_STATE_NOTPLACEABLE;

						showingGrid = false;
					}
				}
			}
		}
	}
}

void GameManager::middleClick(int x, int y, int state){
	if (state == GLUT_DOWN){

	}
	else {

	}
}