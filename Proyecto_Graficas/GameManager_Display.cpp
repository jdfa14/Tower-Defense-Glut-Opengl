#include "GameManager.h"

void GameManager::draw(double time){
	bgImage->draw2D();

	for (unsigned int i = 0; i < buttons->size(); i++)
		(*buttons)[i].draw();
	for (unsigned int i = 0; i < images->size(); i++)
		(*images)[i].draw2D();
	//also we need to draw all other objects
}

void GameManager::refresh(double time){
	while (!events.empty())
	{
		button_listener(events.top());
		events.pop();
	}
}