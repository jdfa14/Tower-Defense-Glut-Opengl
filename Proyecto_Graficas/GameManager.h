#pragma once
#include "addGlut.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#include "Image.h"
#include "GlutWindow.h"
#include "Tower.h"
#include "BadAgent.h"
#include "Button.h"
#include "structs.h"
#include "json\json.h"


class GameManager
{
public:
	const std::string MENU = "Menu";
	const std::string LEVEL = "Level";


	GameManager(){
		isPlaying = false;
		level = 0;
		loadLevel(level);
	}
	
	void init(){

		double width = win.getOrthoWidth();
		double height = win.getOrthoHeight();
		//images
		bgInitMenu.setPositions(0, 0, -99);
		bgInitMenu.setSizes(width,height, 1);
	}

	~GameManager(){

	}

	//gets
	GlutWindow *getWin(){ return &win; }

	//Mouse And keyboard
	void pasiveMouse(int x, int y)
	{
		for (int i = 0; i < buttons.size(); i++){
			buttons[i].mouseState(x, y, false);
		}
	}

	void rigthClick(int x, int y, int state)// state up or down
	{
		if (state == GLUT_DOWN)
		{
			
		}
		else
		{

		}
	}

	void leftClick(int x, int y, int state)
	{
		if (state == GLUT_DOWN){
			for (int i = 0; i < buttons.size(); i++){
				buttons[i].mouseState(x, y, true);
			}
		}
		else {

		}
	}

	void middleClick(int x, int y, int state){
		if (state == GLUT_DOWN){

		}
		else {

		}
	}

	bool loadLevel(int levelNum){
		Button *btnPtr;
		std::string path;
		std::string json_string;
		std::string type;
		std::ifstream json_file;
		std::string line;
		json::Value my_json;
		json::Object root;
		json::Object data;
		json::Object auxObj;
		json::Array auxArr;

		buttons.clear();// erase all current buttons

		path = "levels/level" + std::to_string(levelNum) + ".json";
		json_file.open(path);
		
		if (!json_file.is_open()){
			std::cout << "Error: could not load the json file at " << path << std::endl;
			return false;
		}
		
		while (!json_file.eof())
		{
			json_file >> line;
			json_string += line;
		}
		json_file.close();
		
		my_json = json::Deserialize(json_string);

		if (my_json.GetType() == json::NULLVal){
			std::cout << "Error: Not json file: " << json_string << std::endl;
			return false;
		}

		root = my_json.ToObject();// has to be an object

		type = (std::string)root["type"];
		data = root["data"];

		if (type == MENU){// here we will load a menu
			json::Array positions;
			json::Array sizes;
			path = "Images/" + (std::string)data["background"];
			bgInitMenu.setPath(path);

			auxArr = data["buttons"];
			for (unsigned int i = 0; i < auxArr.size(); i++){
				auxObj = auxArr[i];

				btnPtr = new Button((std::string)auxObj["text"]);
				if (auxObj["positions"].GetType() != json::NULLVal){
					positions = auxObj["positions"];
					btnPtr->setPositions(positions[0], positions[1], positions[2]);
				}
				if (auxObj["sizes"].GetType() != json::NULLVal){
					sizes = auxObj["sizes"];
					btnPtr->setSizes(sizes[0], sizes[1], sizes[2]);
				}

				buttons.push_back(*btnPtr);
				free(btnPtr);// this is no longer needed
			}
		}
		else if (type == LEVEL){
			//construct map and things
		}

		return true;
	}

	void prepareList(){}
	void prepareLevel(){}
	void prepareMaps(std::string levelname){

	}
	void showGrid(bool wannaShow){}
	void changeActiveWindow(int toWindow){}
	void buttonAction(int thisButton){}

	void draw(double time){	
		switch (level)
		{
			//menuses
		case 0:
			bgInitMenu.draw2D();
			for each (Button var in buttons)
			{
				var.draw();
			}
			break;
		default:
			break;
		}
	}
	Image bgInitMenu;
private:

	bool isPlaying;// true if playing a level false if not
	int level;// level that will be played
	
	
	GlutWindow win;

	std::map<char, std::string> sprites_map;//
	std::map<std::string, GLuint> images;


	std::vector<Location> path;

	std::vector<Tower> towers;
	std::vector<BadAgent> enemies;

	std::vector<Button> buttons;
};

