#include "Tower.h"

void Tower::setTimeToShot(double timeInSeconds){
	timeToShot = timeInSeconds * 1000;
}

void Tower::setRange(double range){
	this->range = range * range; // we save the square to save operations
}

void Tower::setType(int type){
	this->type = type;
	switch (type)
	{
	case WHITE_TOWER:
		dmgAntiBacterial = 10;
		dmgAntiViral = 3;
		setTimeToShot(1);
		setRange(300);
		break;
	case YELLOW_TOWER:
		dmgAntiBacterial = 2;
		dmgAntiViral = 0.7;
		setTimeToShot(0.5);
		setRange(200);
		break;
	case PILL_TOWER:
		dmgAntiBacterial = 0;
		dmgAntiViral = 0;
		setTimeToShot(0);
		setRange(200);
		break;
	}
}

Tower::Tower(cData &data, std::vector<BadAgent> &enemies, double x, double y, double z, int type){
	StaticObject::StaticObject();
	this->data = &data;
	this->enemies = &enemies;

	setPositions(x, y, z);
	setSizes(50, 50, 1);
	timeBetweenShots = 0;
	setType(type);
}

void Tower::update(double elapsedTimeMiliSec){
	if (type != 3){
		//updating every bullet
		for (unsigned int i = 0; i < bullets.size(); i++)
			bullets[i].update(elapsedTimeMiliSec);

		// update time
		if (timeBetweenShots > 0)
			timeBetweenShots -= elapsedTimeMiliSec;

		//check perimeter
		if (timeBetweenShots <= 0){
			for (unsigned int i = 0; i < enemies->size(); i++){
				//check if is in range
				double xEnem, yEnem, distance;
				(*enemies)[i].getPositions(xEnem, yEnem);
				if ((*enemies)[i].isAlive()){// ignore already death
					distance = pow(x - xEnem, 2) + pow(y - yEnem, 2);
					//std::cout << "Distance: " << distance << " range:  " << range << std::endl;
					if (distance < range){
						shot(i);
						timeBetweenShots = timeToShot;
						break;
					}
				}
			}
			
		}
	}
	else{

	}
}

void Tower::draw(){
	drawText(data->GetID(IMG_TOWER1NORMAL + (type * 3) + level));
	for (unsigned int i = 0; i < bullets.size(); i++)
		bullets[i].draw(data->GetID(IMG_TOWER1NORMAL));// NEEED CHANGE IMG!
}

void Tower::shot(int pos){
	Bullet toShot(enemies,pos, dmgAntiViral, dmgAntiBacterial, type);
	toShot.setPositions(x, y, z);
	bullets.push_back(toShot);
}