#include "GameManager.h"

void GameManager::draw(double time){
	drawBG();
	
	for (unsigned int i = 0; i < buttons->size(); i++)
		(*buttons)[i].drawText();
	
	if (playing){



		for (unsigned int i = 0; i < grids.size(); i++){
			data.Draw(grids[i].img, grids[i].posXY.posX, grids[i].posXY.posY, -1, grids[i].width, grids[i].heith);
		}

		for (Node<BadAgent> * i = enemies.getHead(); i != NULL; i = i->next){
			i->data->draw();
		}

		for (unsigned int i = 0; i < towers.size(); i++){
			towers[i].draw();
		}

		if (showingGrid){//all towers and monsters must be draw before the grid, so the transparency will work properly
			//int limit = rc * rc;
			data.Draw(IMG_TOWER_1_TOPLACE + typeOfPlacingTower, mouseTracking.posX, mouseTracking.posY, 1, grids[0].width * 2, grids[0].heith * 2);
			for (unsigned int i = 0; i < grids.size(); i++){
				data.Draw(IMG_GRIDGREEN + grids[i].state, grids[i].posXY.posX, grids[i].posXY.posY, 0, grids[i].width, grids[i].heith);
			}
			
		}
		
	}
}

void GameManager::updateEnemies(double elapsedTimeMiliSec){
	if (playing){
		for (Node<BadAgent> * i = enemies.getHead(); i != NULL; i = i->next){
			BadAgent *bad = i->data;
			if (bad->isReadyToDestroy()){
				Node<BadAgent> *aux = i;
				i = i->prev;
				enemies.remove(aux);
			}
			else{
				bad->update(elapsedTimeMiliSec);
			}
			if (i == NULL)// in case tha prev returns null
				break;
		}
	}
}

void GameManager::updateTowers(double elapsedTimeMiliSec){
	if (playing){
		for (unsigned int i = 0; i < towers.size(); i++){
			towers[i].update(elapsedTimeMiliSec);
		}
	}
}

void GameManager::refresh(double elapsedTimeMiliSec){
	while (!events.empty())
	{
		button_listener(events.top());
		events.pop();
	}
	
	if (playing){
		wavesManager.update(elapsedTimeMiliSec);
		if (enemies.getSize() == 0 && wavesManager.hasFinished()){
			std::cout << "Level Finished\n";
			gameFinished();
		}
	}
}

void GameManager::drawBG(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, data.GetID(screenState));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3i(-(win.getOrthoWidth() / 2.0),  (win.getOrthoHeight() / 2.0), -3);
	glTexCoord2f(1, 0);	glVertex3i( (win.getOrthoWidth() / 2.0),  (win.getOrthoHeight() / 2.0), -3);
	glTexCoord2f(1, 1);	glVertex3i( (win.getOrthoWidth() / 2.0), -(win.getOrthoHeight() / 2.0), -3);
	glTexCoord2f(0, 1);	glVertex3i(-(win.getOrthoWidth() / 2.0), -(win.getOrthoHeight() / 2.0), -3);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void GameManager::idle(){
	sounds.Update();
	glutPostRedisplay();
}