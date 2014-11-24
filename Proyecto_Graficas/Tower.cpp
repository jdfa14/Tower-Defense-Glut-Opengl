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
		setRange(200);
		break;
	case YELLOW_TOWER:
		dmgAntiBacterial = 2;
		dmgAntiViral = 0.7;
		setTimeToShot(0.5);
		setRange(100);
		break;
	case PILL_TOWER:
		dmgAntiBacterial = 0;
		dmgAntiViral = 0;
		setTimeToShot(0);
		setRange(200);
		break;
	}
}

Tower::Tower(cData &data, LinkedList<BadAgent> &enemies, double x, double y, double z, int type){
	StaticObject::StaticObject();
	this->data = &data;
	this->enemies = &enemies;
	srand(time(NULL));
	setPositions(x, y, z);
	setSizes(50, 50, 1);
	timeBetweenShots = 0;
	setType(type);
}

Tower::~Tower(){
	bullets.clear();
}

void Tower::update(double elapsedTimeMiliSec){
	if (type != 2){// tower # 2 cant shot
		//updating every bullet
		/*for (std::vector<Bullet>::iterator i = bullets.begin(); i != bullets.end(); i++){
			if (i->isReadyToDestroy()){
				bullets.erase(i);
				break;
			}
		}

		for (std::vector<Bullet>::iterator i = bullets.begin(); i != bullets.end(); i++){
				i->update(elapsedTimeMiliSec);
		}*/

		for (unsigned int i = 0; i < bullets.size();){
			if (bullets[i].isReadyToDestroy()){
				bullets.erase(bullets.begin() + i);
			}
			else{
				bullets[i].update(elapsedTimeMiliSec);
				i++;
			}
		}
			

		// update time
		if (timeBetweenShots > 0)
			timeBetweenShots -= elapsedTimeMiliSec;

		//check perimeter
		if (timeBetweenShots <= 0){
			for (Node<BadAgent> *i = enemies->getHead(); i != NULL; i = i->next){
				double xEnem, yEnem, distance;
				BadAgent *bad = i->data;
				bad->getPositions(xEnem, yEnem);
				if (bad->isAlive()){
					distance = pow(x - xEnem, 2) + pow(y - yEnem, 2);
					if (distance < range){
						shot(bad);
						timeBetweenShots = timeToShot;
						break;
					}
				}
			}

			//for (unsigned int i = 0; i < enemies->size(); i++){
			//	//check if is in range
			//	double xEnem, yEnem, distance;
			//	(*enemies)[i].getPositions(xEnem, yEnem);
			//	if ((*enemies)[i].isAlive()){// ignore already death
			//		distance = pow(x - xEnem, 2) + pow(y - yEnem, 2);
			//		//std::cout << "Distance: " << distance << " range:  " << range << std::endl;
			//		if (distance < range){
			//			shot(i);
			//			timeBetweenShots = timeToShot;
			//			break;
			//		}
			//	}
			//}
			
		}
	}
	else{

	}
}

void Tower::draw(){
	drawText(data->GetID(IMG_TOWER1NORMAL + (type * 3) + level));
	for (unsigned int i = 0; i < bullets.size(); i++)
		bullets[i].draw(data->GetID(IMG_TOWER1NORMAL + type * 3));// NEEED CHANGE IMG!
}

void Tower::shot(BadAgent* toChase){
	Bullet toShot(toChase, dmgAntiViral, dmgAntiBacterial, type);
	toShot.setPositions(x, y, z + 1);
	toShot.setInitialSpeeds(0, 0);
	toShot.setSizes(25, 25, 1);
	bullets.push_back(toShot);
}

bool Tower::didHeJustClickedMe(double x, double y){
	return (x + width / 2.0 > x && x > x - width / 2.0 &&
			y + height / 2.0 > y && y > y - height / 2.0);
}