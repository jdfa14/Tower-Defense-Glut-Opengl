#include "Bullet.h"

Bullet::Bullet(BadAgent &toChase, double antiViral, double antiBacterial) : Mobile(){
	setDamages(antiViral, antiBacterial);
	this->toChase = &toChase;
	setMaxSpeed(100);
	setInitialSpeeds(100, 100);
	timeToArrive = 3;
}

Bullet::Bullet() : Mobile (){
	toChase = NULL;
	setDamages(1, 1);
}

void Bullet::setTimeToArrive(double timeInSeconds){
	timeToArrive = timeInSeconds;
}

void Bullet::setDamages(double antiViral, double antiBacterial){
	antiVDmg = antiViral;
	antiBDmg = antiBacterial;
}

void Bullet::chaseHim(BadAgent &toBeChased){
	this->toChase = &toBeChased;
}

void Bullet::update(double elapsedTimeMiliSeconds){
	Mobile::update(elapsedTimeMiliSeconds);
	
	if (timeToArrive <= 0.1)
		timeToArrive = 0.1;
	else
		timeToArrive -= elapsedTimeMiliSeconds / 1000.0;

	//accX = (toChase->getX() - x - speedX * timeToArrive) / (timeToArrive * timeToArrive);
	//accY = (toChase->getY() - y - speedY * timeToArrive) / (timeToArrive * timeToArrive);
}