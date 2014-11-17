#include "GameManager.h"

void GameManager::draw(double time){
	//bgImage->draw();
	drawBG();
	
	for (unsigned int i = 0; i < buttons->size(); i++)
		(*buttons)[i].drawText(data.GetID(IMG_BUTTONNORMAL), data.GetID(IMG_BUTTONHOVER), data.GetID(IMG_BUTTONPRESSED));
	/*for (unsigned int i = 0; i < images->size(); i++)
		(*images)[i].draw();*/
	//also we need to draw all other objects

	
	if (playing){

		for (unsigned int i = 0; i < grids.size(); i++){
			data.Draw(grids[i].img, grids[i].posXY.posX, grids[i].posXY.posY, -1, grids[i].width + 1, grids[i].heith + 1.5);
		}

		for (Node * i = enemies.getHead(); i != NULL; i = i->next){
			i->data->draw();
		}

		/*for (unsigned int i = 0; i < enemies.size(); i++){
			enemies[i].draw();
		}*/

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

void GameManager::refresh(double elapsedTimeMiliSec){
	while (!events.empty())
	{
		button_listener(events.top());
		events.pop();
	}

	if (playing){
		for (Node * i = enemies.getHead(); i != NULL; i = i->next){
			BadAgent *bad = i->data;
			if (bad->isReadyToDestroy()){
				Node *aux = i;
				i = i->prev;
				enemies.remove(aux);
			}
			else{
				bad->update(elapsedTimeMiliSec);
			}
			if (i == NULL)// in case tha prev returns null
				break;
		}

		/*for (unsigned int i = 0; i < enemies.size();){
			if (enemies[i].isReadyToDestroy()){
				enemies.erase(enemies.begin() + i);
			}
			else{
				enemies[i].update(elapsedTimeMiliSec);
				i++;
			}
		}*/
		/*for (unsigned int i = 0; i < enemies.size(); i++){
			enemies[i].update(elapsedTimeMiliSec);
		}*/
		for (unsigned int i = 0; i < towers.size(); i++){
			towers[i].update(elapsedTimeMiliSec);
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