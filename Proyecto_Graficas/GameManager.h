#pragma once
#include <string>
#include <stack>
#include <vector>	
#include "GlutWindow.h"
#include "Player.h"
#include "Tower.h"
#include "Button.h"
#include "Screen.h"
#include "Level.h"
#include "cData.h"

class GameManager
{
private:
	// only 3 static players could be created
	std::vector<Player> players;
	Player *selectedPlayer;
	std::vector<Level> *levels;

	GlutWindow win;// all the data from the window

	std::stack<int> events;

	//Objects
	std::vector<Tower> *towers;
	//std::vector<BadAgent> enemies;//maybe it will be not implemented

	//visual controls
	std::vector<Screen> screens;
	std::vector<Button> *buttons;
	std::vector<Texture> *images;
	Texture *bgImage;
	
	

	Screen mainScreen;
	bool playing;

	//Matriz de navegacion
	int screenState;
	//0 back, 1 foward1, 2 foward2... 
	int **hereYouAre;


public:

	Button *test3;
	cData data;

	const std::string MENU = "Menu";
	const std::string LEVEL = "Level";

	enum SCREENTYPE{
		MAIN,
		PLAYERSELECT,
		INSTRUCTIONS,
		CREDITS,
		LEVELSELECT,
		PLAYLEVEL,
		NUMBER_OF_SCREENS,
		ERRORNAV
	};
	
	GameManager();

	//gets
	GlutWindow *getWin();

	//sets

	//methods
	void init(); // this will load everything necesary also will show an loading screen or something
	void pasiveMouse(int x, int y); // this will triger events from mouse moving
	void rigthClick(int x, int y, int state);//actions for right click
	void leftClick(int x, int y, int state);//same but for left
	void middleClick(int x, int y, int state);
	void button_listener(int id);//it will do the actions from buttons
	void draw(double time);//it will draw all the objects (time in miliseconds)
	void refresh(double time);//it will actualice everything that is needed

	//functions
	bool loadScreen(int i);

	//Glut functions
	void begin();
	void drawBG();

};

