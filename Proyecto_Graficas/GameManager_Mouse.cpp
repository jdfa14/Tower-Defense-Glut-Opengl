#include "GameManager.h"

void GameManager::button_listener(int id){
	// fomr 1 to 4 are navigation orders (0 is back)
	// bigger than that are action orders
	if (id < 4){
		//loading screen
		if (hereYouAre[screenState][id] > 4)
			return;//error
		loadScreen(hereYouAre[screenState][id]);
	}
	else{
		std::vector<Button> *levelbuttons;
		//6 show player data
		switch (id)
		{
		case 6://load player to level selection
		case 7:
		case 8:
			selectedPlayer = &players[id - 6];
			loadScreen(hereYouAre[screenState][1]);
			levels = selectedPlayer->getAllLevels();
			levelbuttons = selectedPlayer->getLevelButtons();

			if (buttons->size() > 1)//delete previous buttons if the case
				for (unsigned int i = 0; i < levelbuttons->size(); i++)
					buttons->pop_back();

			for (unsigned int i = 0; i < levelbuttons->size(); i++){
				buttons->push_back((*levelbuttons)[i]);
			}
			break;

		case 9://level selection
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
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
	test3->mouseState(x, y,false);
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
	}
}

void GameManager::middleClick(int x, int y, int state){
	if (state == GLUT_DOWN){

	}
	else {

	}
}