#include "GameManager.h"

void GameManager::draw(double time){
	//bgImage->draw();
	drawBG();

	for (unsigned int i = 0; i < buttons->size(); i++)
		(*buttons)[i].drawText(data.GetID(IMG_BUTTONNORMAL), data.GetID(IMG_BUTTONHOVER), data.GetID(IMG_BUTTONPRESSED));
	/*for (unsigned int i = 0; i < images->size(); i++)
		(*images)[i].draw();*/
	//also we need to draw all other objects
}

void GameManager::refresh(double time){
	while (!events.empty())
	{
		button_listener(events.top());
		events.pop();
	}
}

void GameManager::drawBG(){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, data.GetID(screenState));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3i(-(win.getOrthoWidth() / 2.0),  (win.getOrthoHeight() / 2.0), -2);
	glTexCoord2f(1, 0);	glVertex3i( (win.getOrthoWidth() / 2.0),  (win.getOrthoHeight() / 2.0), -2);
	glTexCoord2f(1, 1);	glVertex3i( (win.getOrthoWidth() / 2.0), -(win.getOrthoHeight() / 2.0), -2);
	glTexCoord2f(0, 1);	glVertex3i(-(win.getOrthoWidth() / 2.0), -(win.getOrthoHeight() / 2.0), -2);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}