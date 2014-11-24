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

bool WavesManager::hasFinished(){
	return levelFinished;
}

bool WavesManager::hasNextWave(){
	return !waiting.empty();
}

void WavesManager::nextWave(){
	if (!start)// Let the hunger games begin
		start = !start;

	if (hasNextWave()){// The first waiting element will be added to active
		active.addAtTail(waiting.getHead());
		waiting.removeHead();
	}
}

void WavesManager::update(double elapsedTimeMiliSec){
	if (start && !levelFinished){
		for (Node<Wave> *i = active.getHead(); i != NULL; i = i->next){
			i->data->spawn(elapsedTimeMiliSec);
			if (i->data->hasFinished()){
				Node<Wave> *aux = i;
				i = i->prev;
				active.remove(aux);
			}
			if (i == NULL)
				break;
		}

		if (!waiting.empty()){
			waiting.getHead()->data->wait(elapsedTimeMiliSec);// only the next wave will wait
			if (waiting.getHead()->data->isReadyToSpawn()){
				nextWave();
			}
		}

		if (waiting.empty() && active.empty()){
			levelFinished = true;
			std::cout << "WavesManager has finished\n";
		}
	}
}

void WavesManager::loadLevel(LinkedList<Wave> *allWaves){
	reset();
	for (Node<Wave> *i = allWaves->getHead(); i != NULL; i = i->next){
		waiting.addAtTail(i);
	}
}

void WavesManager::loadLevel(std::vector<Wave> *allWaves){
	for (unsigned int i = 0; i < allWaves->size(); i++){
		waiting.addAtTail(&(*allWaves)[i]);
	}
}