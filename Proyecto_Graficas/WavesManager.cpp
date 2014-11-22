#include "WavesManager.h"


WavesManager::WavesManager()
{
	start = false;
	levelFinished = false;
}

void WavesManager::reset(){
	start = false;
	levelFinished = false;
	waiting.clear();
	active.clear();
}

bool WavesManager::hasNextWave(){
	return !waiting.empty();
}

void WavesManager::nextWave(){
	if (!start)// Let the hunger games begin
		start = !start;

	if (hasNextWave()){// The first waiting element will be added to active
		active.push_back(waiting[0]);
		//waiting.erase(waiting.begin);
	}
}

void WavesManager::update(double elapsedTimeMiliSec){
	for (int i = 0; i < active.size(); i++){
		active[i].spawn(elapsedTimeMiliSec);
	}
	if (!waiting.empty()){
		waiting[0].wait(elapsedTimeMiliSec);// only the next wave will wait
		if (waiting[0].isReadyToSpawn()){
			nextWave();
		}
	}
}
