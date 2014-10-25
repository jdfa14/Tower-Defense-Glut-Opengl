#pragma once
#include "addGlut.h"
#include <vector>
#include <map>
#include "Image.h"
#include "GlutWindow.h"
#include "Tower.h"
#include "BadAgent.h"
#include "Button.h"
#include "structs.h"


class GameManager
{
public:
	GameManager(){
		isPlaying = false;
		level = initMenu;
		
	}
	
	void init(){

		double width = win.getOrthoWidth();
		double height = win.getOrthoHeight();
		//images
		bgInitMenu.setPath("Imagenes/background.bmp");
		bgInitMenu.setPositions(0, 0, -99);
		bgInitMenu.setSizes(width,height, 1);
	}

	~GameManager(){

	}

	void loadLevel(int x){

	}

	void prepareList(){}
	void prepareLevel(){}
	void prepareMaps(std::string levelname){

	}
	void showGrid(bool wannaShow){}
	void changeActiveWindow(int toWindow){}
	void buttonAction(int thisButton){}
	GlutWindow *getWin(){ return &win; }

	void draw(double time){
		bgInitMenu.draw();
		
		switch (level)
		{
		case initMenu:
			
			break;
		default:
			break;
		}
	}
	Image bgInitMenu;
private:
	
	enum levels
	{
		initMenu,selectUser,choseLevel,level1,level2,level3,level4
	};

	bool isPlaying;// true if playing a level false if not
	int level;// level that will be played
	
	
	
	GlutWindow win;
	


	std::map<char, std::string> sprites_map;//
	std::map<std::string, GLuint> images;


	std::vector<Location> path;
	std::vector<GLuint> spritesBackground; //sprites to draw as bg
	std::vector<Tower> towers;
	std::vector<BadAgent> enemies;
	std::vector<Button> buttons;

};

