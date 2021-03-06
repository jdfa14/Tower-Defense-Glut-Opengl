#include "GameManager.h"
#include <fstream>
#include "json\json.h"

void GameManager::init(){

	//for this, we need the ortho already with all his values
	double width = win.getOrthoWidth();
	double height = win.getOrthoHeight();
	const int cant = 4;

	//setting grids positions
	rc = 20.0;

	double mapWidth = (win.getOrthoWidth() + ((double)MAP_INIT_X * 2.0) - 20); // 750 - 20 margins
	double mapHeight = (win.getOrthoHeight() + ((double)MAP_INIT_Y * 2.0) - 20);// 857.15 - 20

	double gridWidth = mapWidth / rc; //24.333333;
	double gridHeight = mapHeight / rc; //27.90533333;

	double initX;
	double initY = mapHeight / 2.0 - gridHeight / 2.0 + (double)MAP_INIT_Y;
	std::cout << "Postitioning grids\n";
	for (int i = 0; i < rc; i++){
		initX = -mapWidth / 2.0 + gridWidth / 2.0 + (double)MAP_INIT_X;
		for (int j = 0; j < rc; j++){
			Grid aux;
			aux.posXY.posX =  initX;
			aux.posXY.posY =  initY;
			aux.width = gridWidth + 1.5;//visual hard coded fix
			aux.heith = gridHeight + 1;//visual hard codded fix
			aux.state = GRD_STATE_PLACEABLE;
			aux.placeable = true;
			grids.push_back(aux);
			initX += gridWidth;
		}
		initY -= gridHeight;
	}

	//loading Levels
	std::cout << "Loading data from leves... 00%";
	for (int i = 0; i < 5; i++){
		LevelData level(data,enemies,&path);
		level.loadData("levels/level_" + std::to_string(i) + ".json", grids);
		std::cout << "\b\b\b" + std::to_string((i + 1) * 20) + "%";
		levelsData.push_back(level);
	}
	std::cout << "\n";

	// we initialize the navigation path mat
	std::cout << "Just a few more thinghs... \n";
	int mat[NUMBER_OF_SCREENS][cant] = {
		//Back			fwrd1			fwrd1 //fwrd1
		{ ERRORNAV,		PLAYERSELECT,	INSTRUCTIONS, CREDITS }, // Main
		{ MAIN,			LEVELSELECT,    HISTORY, ERRORNAV }, // Player select
		{ MAIN,			ERRORNAV,		ERRORNAV, ERRORNAV }, // Instructions
		{ MAIN,			ERRORNAV,		ERRORNAV, ERRORNAV }, // Credits
		{ PLAYERSELECT, PLAYLEVEL,		ERRORNAV, ERRORNAV }, // Level Select
		{ LEVELSELECT,	ERRORNAV,		ERRORNAV, ERRORNAV },  // Playing level
		{ PLAYERSELECT, LEVELSELECT,	ERRORNAV, ERRORNAV } // HISTORY
	};

	hereYouAre = new int*[NUMBER_OF_SCREENS];
	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		hereYouAre[i] = new int[cant]; // since the +1 one is the back
	}

	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		for (int j = 0; j < cant; j++)
			hereYouAre[i][j] = mat[i][j];
	}

	
}

bool GameManager::loadScreen(int i){
	std::cout << "Showing screen: " << i << std::endl;
	if (i >= NUMBER_OF_SCREENS){
		std::cout << "A wild potato has appeared!" << std::endl;
		return false;
	}
	buttons = screens[i].getButtons();
	images = screens[i].getImages();
	//towers = screens[i].getTowers();
	screenState = i;
	return true;
}

void GameManager::begin(){
	glClearColor(0.5, 0.0, 1.0, 0.0);
	glColor3ub(255, 255, 255);//color de linea
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glShadeModel(GL_SMOOTH);//sombreado plano
	
	//loading images
	data.Load();

	double width = win.getOrthoWidth();
	double height = win.getOrthoHeight();


	//we load players info from jsons
	std::cout << "Loading players \n";
	for (int i = 1; i < 4; i++){
		Player aux("Player " + std::to_string(i), data);
		aux.loadPlayer(events);
		std::cout << "Player " << i << " loaded\n";
		players.push_back(aux);
	}

	//we load all posible screens
	std::cout << "Loading screens \n";
	for (int i = MAIN; i < NUMBER_OF_SCREENS; i = i + 1){
		Screen newScreen(data);
		newScreen.loadLevel(i, &events);
		switch (i)
		{
		case 0: newScreen.setName("Main"); break;
		case 1: newScreen.setName("Player Selection"); break;
		case 2: newScreen.setName("Instructions"); break;
		case 3: newScreen.setName("Credits"); break;
		case 4: newScreen.setName("Level Selection"); break;
		case 5: newScreen.setName("Play Level"); break;
		default: break;
		}

		screens.push_back(newScreen);
		std::cout << "Screen " << i << " loaded\n";
	}

	std::cout << "Starting \n";
	loadScreen(screenState);
	sounds.Load();
	sounds.Play(0);

	sellButton.setToolTip("You will get 80% of total cost");
	sellButton.setPositions(375, -250, 0);
	sellButton.setSizes(250, 100, 1);
	sellButton.setImages(data.GetID(IMG_BUTTONNORMAL), data.GetID(IMG_BUTTONHOVER), data.GetID(IMG_BTN_TOOLTIP), data.GetID(IMG_BUTTONNORMAL));
	sellButton.setEventsStack(&events);
	sellButton.setID(26);

	upgradeButton.setPositions(375, -150, 0);
	upgradeButton.setSizes(250, 100, 1);
	upgradeButton.setImages(data.GetID(IMG_BUTTONNORMAL), data.GetID(IMG_BUTTONHOVER), data.GetID(IMG_BTN_TOOLTIP), data.GetID(IMG_BUTTONNORMAL));
	upgradeButton.setEventsStack(&events);
	upgradeButton.setID(25);
}