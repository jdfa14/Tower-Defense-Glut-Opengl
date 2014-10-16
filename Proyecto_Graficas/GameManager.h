#pragma once
#include <vector>
#include <map>
#include "Tower.h"
#include "BadAgent.h"
#include "Button.h"
#include "structs.h"

using namespace std;
class GameManager
{
public:
	GameManager(){
		timePlaying = 0;
		isPlaying = false;
		level = 0;
	}
	~GameManager();
	void loadLevel(){}
	void prepareList(){}
	void prepareLevel(){}
	void prepareMaps(string levelname){

	}
	void showGrid(bool wannaShow){}
	void changeActiveWindow(int toWindow){}
	void buttonAction(int thisButton){}
private:
	double timePlaying;//time playing in a level
	bool isPlaying;// true if playing a level false if not
	int level;// level that will be played
	void(*button)(void); //pointer to a function
	void(*drawPoint)(void);// pointer to the draw function 
	map<char, string> sprites_map;//
	map<string, GLuint> images;
	vector<Location> path;
	vector<GLuint> spritesBackground; //sprites to draw as bg
	vector<Tower> towers;
	vector<BadAgent> enemies;
	vector<Button> buttons;
};

