#include "Wave.h"


Wave::Wave(cData &data, std::vector<Location> **path, double timeToStart, double timeBetweenMobs){
	this->timeToStart = timeToStart;
	this->data = &data;
	this->path = path;
	timeTNM = timeBetweenMobs;
	timeSLM = timeBetweenMobs;
	pos = -1;
	finished = false;
}

void Wave::setVectorToSpawn(LinkedList<BadAgent> *toSpawn){
	this->toSpawn = toSpawn;
}

double Wave::getTimeToStart(){
	return timeToStart;
}

bool Wave::isReadyToSpawn(){
	return timeToStart <= 0;
}

bool Wave::hasFinished(){
	return finished;
}

void Wave::wait(double elapsedTimeMiliSec){
	if (timeToStart > 0)
		timeToStart -= elapsedTimeMiliSec / 1000.0;
}

void Wave::spawn(double elapsedTimeMiliSec){
	if (!finished)
		if (timeSLM > 0){
			timeSLM -= elapsedTimeMiliSec / 1000;
		}
		else{
			timeSLM = timeTNM;
			pos++;
			if (pos == enemies.size())
				finished = true;
			else
				toSpawn->addAtTail(&enemies[pos]);
		}	
}

void Wave::addMoob(int howMany, int type, int dificulty, int speed){
	for (int i = 0; i < howMany; i++){
		BadAgent newOne(*data, path, type, dificulty, speed);
		enemies.push_back(newOne);
	}
}

