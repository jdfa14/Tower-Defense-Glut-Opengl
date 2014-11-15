#include "GameManager.h"
void GameManager::keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 27://ESC
		//exit(1);
		if (playing){
			if (showingGrid){// placing a tower
				//cancel the action
				showingGrid = false;
				break;
			}
		}
		else{
			if (screenState == 0)
				exit(0);
			button_listener(0);
		}
		break;
	default:
		break;
	}
}