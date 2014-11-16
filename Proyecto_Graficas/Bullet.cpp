#include "Bullet.h"

Bullet::Bullet(std::vector<BadAgent> *enemies, int pos, double antiViral, double antiBacterial, int type, double time) : Mobile(){
	setDamages(antiViral, antiBacterial);
	this->pos = pos;
	setMaxSpeed(500);
	setInitialSpeeds(100, 100);
	timeToArrive = 3;
	setSizes(50, 50, 1);
	readyToDestroy = false;
	hit = false;
	this->type = type;
	this->time = time;
	this->enemies = enemies;
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
	pos = element.pos;
	std::vector<BadAgent> *enemies = element.enemies;
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

void Bullet::chaseHim(int pos){
	this->pos = pos;
}

void Bullet::update(double elapsedTimeMiliSeconds){
	
	double xMonster, yMonster;
	(*enemies)[pos].getPositions(xMonster, yMonster);
	
	if (!hit){
		double distance;
		double wMonster, hMonster;
		(*enemies)[pos].getSizes(wMonster, hMonster);

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
		
		switch (type)
		{
		case 0:// normall towar
			(*enemies)[pos].takeDamaged(antiVDmg, antiBDmg);
			(*enemies)[pos].chaserHasDoneHisJob();
			readyToDestroy = true;
			std::cout << "I HIT!";
			break;
		case 1:// 
			(*enemies)[pos].takeDamaged(antiVDmg, antiBDmg);
			time -= elapsedTimeMiliSeconds / 1000;
			setPositions(xMonster + xDif, yMonster + yDif, 0);
			if (time <= 0){
				(*enemies)[pos].chaserHasDoneHisJob();
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