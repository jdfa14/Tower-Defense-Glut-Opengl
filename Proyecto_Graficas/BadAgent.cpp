#include "BadAgent.h"

BadAgent::BadAgent() : Mobile() {
	hitPoints = 10;
	setDefs(0, 0);
	vulnerable = true;
	destroying = false;
	readyToDestroy = false;
	waitForMultipleObjects = 0;
}

void BadAgent::addChaser(){
	waitForMultipleObjects += 1;
}

void BadAgent::chaserHasDoneHisJob(){
	waitForMultipleObjects -= 1;
}

void BadAgent::setDefs(double defAntiVirus, double defAntiBacterial){
	defAntiB = defAntiBacterial;
	defAntiV = defAntiVirus;
}

void BadAgent::getPositions(double &x, double &y){
	x = this->x;
	y = this->y;
}

void BadAgent::getSizes(double &w, double &h){
	w = this->width;
	h = this->height;
}

double BadAgent::getHP(){
	return hitPoints;
}

bool BadAgent::isReadyToDestroy(){
	return readyToDestroy;
}

void BadAgent::takeDamaged(double antiVDMG, double antiBDMG){
	hitPoints = hitPoints - (antiVDMG - defAntiV) - (antiBDMG - defAntiB);
}

void BadAgent::update(double elapsedTimeMiliSec){
	if (!destroying){
		Mobile::update(elapsedTimeMiliSec);
		if (hitPoints <= 0){
			destroying = true;
		}
	}
	else if (!readyToDestroy){
		//some preparation before destroying
		if (waitForMultipleObjects <= 0)
			readyToDestroy = true;
	}
}

void BadAgent::draw(int tex_id){
	Mobile::draw(tex_id);
}

bool BadAgent::isAlive(){
	return !destroying;
}