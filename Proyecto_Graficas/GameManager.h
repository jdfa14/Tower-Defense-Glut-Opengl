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
#include "Grid.h"
#include "LevelData.h"
#include "LinkedList.h"
#include "WavesManager.h"
#include "Wave.h"
#include "Sound.h"

#define MAP_INIT_X -125
#define MAP_INIT_Y -71.42

#define GM_FORMAT_TIME		0
#define GM_FORMAT_NUMBER	1
#define GM_FORMAT_LIFE		2

class GameManager
{
private:
	//Img and Audio data
	cData data;
	Sound sounds;

	// only 3 static players could be created
	std::vector<Player> players;
	Player *selectedPlayer;
	std::vector<Level> *levels;

	GlutWindow win;// all the data from the window

	std::stack<int> events;

	//Objects
	LinkedList<Tower> towers;
	LinkedList<BadAgent> enemies;
	//std::vector<BadAgent> enemies;//maybe it will be not implemented
	std::vector<LevelData> levelsData;
	WavesManager wavesManager;

	//visual controls
	std::vector<Screen> screens;
	std::vector<Button> *buttons;
	std::vector<Texture> *images;
	std::vector<Grid> grids;

	Button sellButton;
	Button upgradeButton;

	Texture *bgImage;

	//Matriz de navegacion
	int screenState;
	//0 back, 1 foward1, 2 foward2... 
	int **hereYouAre;

	//grid and playing stuff
	std::vector<Location> *path;

	
	bool showingGrid;// only if placing a towa will be true
	bool isOnMap;
	bool canPlace;
	int typeOfPlacingTower;
	Location mouseTracking;
	void selectGrid(double x, double y);
	int selectedIndexes[4];
	int rc; // 20 x 20 little grids

	//Data while playing
	int scoreInLevel;
	int dnaInLevel;
	int levelSelected;
	int playerHitPoints;
	double timeInLevel;
	bool playing;
	bool wavesStarted;
	bool finished;
	bool victory;
	Node<Tower> *selectedTower;

	void writeData(int data, double x, double y,int format);
	void getReadyToPlay();
	void gameFinished();

public:
	

	const std::string MENU = "Menu";
	const std::string LEVEL = "Level";

	enum SCREENTYPE{
		MAIN,
		PLAYERSELECT,
		INSTRUCTIONS,
		CREDITS,
		LEVELSELECT,
		PLAYLEVEL,
		HISTORY,
		NUMBER_OF_SCREENS,
		ERRORNAV
	};
	
	GameManager();
	~GameManager();

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
	void updateTowers(double elapsedTimeInMili);
	void updateEnemies(double elapsedTimeInMili);

	//functions
	bool loadScreen(int i);

	//Glut functions
	void begin();
	void drawBG();
	void keyboard(unsigned char key, int x, int y);
	void idle();

};

