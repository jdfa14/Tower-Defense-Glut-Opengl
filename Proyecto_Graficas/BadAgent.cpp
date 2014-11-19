#include "BadAgent.h"

BadAgent::BadAgent(cData &data, std::vector<Location> &path, int type, int dificulty) : Mobile() {
	this->data = &data;
	this->path = &path;
	getReadyToFight(type,dificulty);
	
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
	hitPoints = hitPoints - antiVDMG *(1.0 - defAntiV / 100.0) - antiBDMG * (1.0 - defAntiB / 100.0);
}

void BadAgent::update(double elapsedTimeMiliSec){
	if (!destroying){
		Mobile::update(elapsedTimeMiliSec);
		if (hitPoints <= 0){
			destroying = true;
		}
		std::cout << "Walking to [" << (*path)[pathIndex].posX << "," << (*path)[pathIndex].posY << "] ";
		if (amICloseEnought()){// si esta lo suficientemente cerca de la siguiente grid
			if (nextStept()){// si ya llego al final
				pathIndex = 0;
				x = (*path)[0].posX;
				y = (*path)[0].posY;
				// GO AGAIN!! KILL THAT EVIL PLAYER
				// Here we should do some dmg to the player
			}
		}
	}
	else if (!readyToDestroy){
		//some preparation before destroying
		if (waitForMultipleObjects <= 0)
			readyToDestroy = true;
	}
}

void BadAgent::draw(){
	Mobile::draw(data->GetID(img));
}

bool BadAgent::isAlive(){
	return !destroying;
}

void BadAgent::getReadyToFight(int type, int dif){
	
	switch (type)
	{
	case BA_TYPE_BACTERIA:
		img = IMG_BACTERIA;
		hitPoints = 100 + 50 * dif;
		setDefs(50, 10);
		setMaxSpeed(100 + 20 * dif); // units per second
		setSizes(25, 25, 1);
		break;
	case BA_TYPE_VIRUS:
		img = IMG_VIRUS;
		hitPoints = 75 + 30 * dif;
		setDefs(10, 70);
		setMaxSpeed(200 + 50 * dif);
		setSizes(25, 25, 1);
		break;
	case BA_TYPE_BOSS_BACTERIA:
		img = IMG_BACTERIA;
		hitPoints = 1000 + 200 * dif;
		setDefs(90, 25);
		setMaxSpeed(100);
		setSizes(50, 50, 1);
		break;
	case BA_TYPE_BOSS_VIRUS:
		img = IMG_VIRUS;
		hitPoints = 1000 + 100 * dif;
		setDefs(10, 100);
		setMaxSpeed(100);
		setSizes(50, 50, 1);
		break;
	default:
		std::cout << "Error not valid type: " << type << " deleting...\n";
		destroying = true;
		readyToDestroy = true;
		break;
	}

	x = (*path)[0].posX;
	y = (*path)[0].posY;
	setInitialSpeeds(500, 500); // it will be redirected and reduced
	goTo((*path)[1].posX, (*path)[1].posY);
}

//AUTOBOT!

void BadAgent::goTo(double x, double y){
	double distX = abs(x - this->x);
	double distY = abs(y - this->y);
	double h = sqrt(distX * distX + distY * distY);
	double angleY = asin(distY * sin(90 * DEG_TO_RAD) / h);//angle between X and H in RADS
	double angleX = asin(distX * sin(90 * DEG_TO_RAD) / h);//angle between Y and H in RADS
	double auxX = sin(angleX) / sin(90 * DEG_TO_RAD);
	double auxY = sin(angleY) / sin(90 * DEG_TO_RAD);

	
	speedX = x >= this->x ? sqrt(actualSpeed) * auxX : -sqrt(actualSpeed) * auxX;
	speedY = y >= this->y ? sqrt(actualSpeed) * auxY : -sqrt(actualSpeed) * auxY;

	accX = x >= this->x ? sqrt(acc) * auxX : -sqrt(acc) * auxX;
	accY = y >= this->y ? sqrt(acc) * auxY : -sqrt(acc) * auxY;
}

bool BadAgent::nextStept(){
	pathIndex++;
	if (pathIndex == path->size())
		return true; // mission complete! do damage and stuff

	goTo((*path)[pathIndex].posX, (*path)[pathIndex].posY);
	distanceToTarget = pow((*path)[pathIndex].posX - x, 2) + pow((*path)[pathIndex].posY - y, 2);
	return false;//Come one! you can do it, DESTROY THE PLAYER!
}

bool BadAgent::amICloseEnought(){
	distanceToTarget = pow((*path)[pathIndex].posX - x, 2) + pow((*path)[pathIndex].posY - y, 2);
	std::cout << " Distance: " << distanceToTarget << "\n";
	return distanceToTarget < 650; // 24 grid width, 27 gird heigth av ~ 25 ^ 2
}