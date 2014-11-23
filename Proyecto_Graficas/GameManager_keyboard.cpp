#include "GameManager.h"
void GameManager::keyboard(unsigned char key, int x, int y){
	double xMapped = win.getXMapped(x);
	double yMapped = win.getYMapped(y);
	BadAgent *enemy;
	
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
	case 'S':
		wavesManager.nextWave();
		break;
	case 'E':
		//enemies.push_back(*enemy);
		enemy = new BadAgent(data, &path);
		enemy->setSizes(grids[0].width, grids[0].heith, 1);
		enemies.addAtTail(enemy);
		break;
	default:
		break;
	}
}