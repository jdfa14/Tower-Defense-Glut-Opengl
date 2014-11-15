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

		for (unsigned int i = 0; i < towers.size(); i++){
			towers[i].draw();
		}

		if (showingGrid){//all towers and monsters must be draw before the grid, so the transparency will work properly
			int limit = rc * rc;
			data.Draw(IMG_TOWER_1_TOPLACE + typeOfPlacingTower, mouseTracking.posX, mouseTracking.posY, 1, grids[0].width * 2, grids[0].heith * 2);
			for (int i = 0; i < limit; i++){
				data.Draw(IMG_GRIDGREEN + grids[i].state, grids[i].x, grids[i].y, 0, grids[i].width, grids[i].heith);
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