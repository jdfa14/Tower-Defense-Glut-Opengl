#include "Bullet.h"

Bullet::Bullet(BadAgent *toChase, double antiViral, double antiBacterial, int type, double time) : Mobile(){
	setDamages(antiViral, antiBacterial);
	setMaxSpeed(500);
	setInitialSpeeds(100, 100);
	timeToArrive = 3;
	setSizes(50, 50, 1);
	readyToDestroy = false;
	hit = false;
	this->type = type;
	this->time = time;
	chaseHim(toChase);
}

Bullet& Bullet::operator=(const Bullet& element){
	
	//placeableObjects
	setSizes(element.width, element.height, element.volume);
	setPositions(element.x, element.y, element.z);

	//mobile
	setAccelerations(element.accX, element.accY);
	setInitialSpeeds(element.speedX, element.speedY);
	direction = element.direction;
	maxSpeed = element.maxSpeed;
	
	//bullet
	enemyToChase = element.enemyToChase;
	antiVDmg = element.antiVDmg;
	antiBDmg = element.antiBDmg;
	timeToArrive = element.timeToArrive;
	rangeOfAction = element.rangeOfAction;
	xDif = element.xDif;
	yDif = element.yDif;
	type = element.type;
	time = element.time;
	readyToDestroy = element.readyToDestroy;
	hit = element.hit;
	
	return *this;
}

void Bullet::setSizes(double width, double height, double volume){
	Mobile::setSizes(width, height, volume);
}
//Bullet::Bullet() : Mobile (){
//	toChase = NULL;
//	setDamages(1, 1);
//}

void Bullet::setTimeToArrive(double timeInSeconds){
	timeToArrive = timeInSeconds;
}

void Bullet::setDamages(double antiViral, double antiBacterial){
	antiVDmg = antiViral;
	antiBDmg = antiBacterial;
}

void Bullet::chaseHim(BadAgent *toChase){
	this->enemyToChase = toChase;
	toChase->addChaser();
}

void Bullet::update(double elapsedTimeMiliSeconds){
	double xMonster, yMonster;
	if (!hit && !readyToDestroy){
		double distance;
		double wMonster, hMonster;
		enemyToChase->getPositions(xMonster, yMonster);
		enemyToChase->getSizes(wMonster, hMonster);

		distance = sqrt(pow(x - xMonster, 2) + pow(y - yMonster, 2)) - wMonster / 2.0 - width / 2.0;

		Mobile::update(elapsedTimeMiliSeconds);

		if (timeToArrive <= 0.0001)
			timeToArrive = 0.0001;
		else
			timeToArrive -= elapsedTimeMiliSeconds / 1000.0;

		accX = (xMonster - x - speedX * timeToArrive) / (timeToArrive * timeToArrive);
		accY = (yMonster - y - speedY * timeToArrive) / (timeToArrive * timeToArrive);
		//std::cout << "\n time: " << timeToArrive << " Speed: " << actualSpeed;
		//std::cout << "\n distance: " << distance << " x, y: " << x << " , " << y;
		if (distance < 0){
			hit = true;
			xDif = x - xMonster;
			yDif = y - yMonster;
		}
	}
	else if (!readyToDestroy)
	{
		enemyToChase->getPositions(xMonster, yMonster);
		switch (type)
		{
		case 0:// normall towar
			enemyToChase->takeDamaged(antiVDmg, antiBDmg);
			enemyToChase->chaserHasDoneHisJob();
			readyToDestroy = true;
			std::cout << "I HIT!";
			break;
		case 1:// 
			enemyToChase->takeDamaged(antiVDmg, antiBDmg);
			if (!enemyToChase->isAlive())
				time = 0;
			else
				time -= elapsedTimeMiliSeconds / 1000;
			setPositions(xMonster + xDif, yMonster + yDif, 0);
			if (time <= 0){
				enemyToChase->chaserHasDoneHisJob();
				readyToDestroy = true;
			}
			break;
		case 2:
			readyToDestroy = true;
		default:
			break;
		}
	}
}