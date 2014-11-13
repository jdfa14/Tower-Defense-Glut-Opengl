#include "GameManager.h"
#include <fstream>
#include "json\json.h"

void GameManager::init(){
	//for this, we need the ortho already with all his values
	double width = win.getOrthoWidth();
	double height = win.getOrthoHeight();
	const int cant = 4;

	test3 = new Button("asdasdasd");
	test3->setPositions(0, 200, 0);

	//we load players info from jsons
	std::cout << "Loading players \n";
	for (int i = 1; i < 4; i++){
		Player aux("Player " + std::to_string(i));
		aux.loadPlayer();
		std::cout << "Player " << i << " loaded\n";
		players.push_back(aux);
	}

	//we load all posible screens
	std::cout << "Loading screens \n";
	for (int i = MAIN; i < NUMBER_OF_SCREENS; i = i + 1){
		Screen newScreen;
		newScreen.loadLevel(i,&events);
		newScreen.getBGImage()->setPositions(0, 0, -99);
		newScreen.getBGImage()->setSizes(width, height, 1);
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

	// we initialize the navigation path mat
	std::cout << "Just a few more thinghs... \n";
	int mat[NUMBER_OF_SCREENS][cant] = {
		//Back			fwrd1			fwrd1 //fwrd1
		{ ERRORNAV,		PLAYERSELECT,	INSTRUCTIONS, CREDITS }, // Main
		{ MAIN,			LEVELSELECT, ERRORNAV, ERRORNAV }, // Player select
		{ MAIN,			ERRORNAV,		ERRORNAV, ERRORNAV }, // Instructions
		{ MAIN,			ERRORNAV,		ERRORNAV, ERRORNAV }, // Credits
		{ PLAYERSELECT, ERRORNAV,		ERRORNAV, ERRORNAV }, // Level Select
		{ LEVELSELECT,	ERRORNAV,		ERRORNAV, ERRORNAV }  // Playing level
	};

	hereYouAre = new int*[NUMBER_OF_SCREENS];
	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		hereYouAre[i] = new int[cant]; // since the +1 one is the back
	}

	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		for (int j = 0; j < cant; j++)
			hereYouAre[i][j] = mat[i][j];
	}

	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		for (int j = 0; j < cant; j++)
			std::cout << hereYouAre[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << "Starting \n";
	loadScreen(screenState);
}

bool GameManager::loadScreen(int i){
	std::cout << "Showing screen: " << i << std::endl;
	if (i >= NUMBER_OF_SCREENS)
		return false;
	bgImage = screens[i].getBGImage();
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
	std::cout << "Loading Images \n";
	data.Load();

}