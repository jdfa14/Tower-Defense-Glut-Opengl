#pragma once
//#include <vector>
//#include <map>
#include "Image.h"
//#include "GlutWindow.h"
//#include "Tower.h"
//#include "BadAgent.h"
//#include "Button.h"
//#include "structs.h"



using namespace std;
class GameManager
{
public:
	GameManager(){
		isPlaying = false;
		level = 0;

		//images
		//bgInitMenu.setPath("C:/Users/JesusDavid/Documents/GitHub/Tower-Defense-Glut-Opengl/Proyecto_Graficas/Imagenes/background.bmp");
		
	}
	//~GameManager();

	void loadLevel(int x){

	}

	void prepareList(){}
	void prepareLevel(){}
	void prepareMaps(string levelname){

	}
	void showGrid(bool wannaShow){}
	void changeActiveWindow(int toWindow){}
	void buttonAction(int thisButton){}
	GlutWindow *getWin(){ return &win; }

	//void(*draw)(unsigned int time);// pointer to the draw function 
	

private:
	
	bool isPlaying;// true if playing a level false if not
	int level;// level that will be played
	//void(*button)(void); //pointer to a function


	GlutWindow win;

	//Image bgInitMenu;


	//map<char, string> sprites_map;//
	//map<string, GLuint> images;


	//vector<Location> path;
	//vector<GLuint> spritesBackground; //sprites to draw as bg
	//vector<Tower> towers;
	//vector<BadAgent> enemies;
	//vector<Button> buttons;

	void drawInitMenu(unsigned int time){

	}
};

