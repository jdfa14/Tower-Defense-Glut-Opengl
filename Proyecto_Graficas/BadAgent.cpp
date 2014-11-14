#include "BadAgent.h"

BadAgent::BadAgent() : Mobile() {
	hitPoints = 0;
	setDefs(0, 0);
	vulnerable = true;
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

void BadAgent::takeDamaged(double antiVDMG, double antiBDMG){
	hitPoints = hitPoints - (antiVDMG - defAntiV) - (antiBDMG - defAntiB);
}

void BadAgent::update(double elapsedTimeMiliSec){
	Mobile::update(elapsedTimeMiliSec);
}

void BadAgent::draw(int tex_id){
	Mobile::draw(tex_id);
}