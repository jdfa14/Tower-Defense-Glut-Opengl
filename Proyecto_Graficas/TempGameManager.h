#pragma once
#include "addGlut.h"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>

#include "Image.h"
#include "GlutWindow.h"
#include "Tower.h"
#include "BadAgent.h"
#include "Button.h"
#include "json\json.h"
#include "Player.h"


class GameManager2
{
public:
	const std::string MENU = "Menu";
	const std::string LEVEL = "Level";


	GameManager2(){
		player1.setFileName("Player 1");
		player2.setFileName("Player 2");
		player3.setFileName("Player 3");
		
		isPlaying = false;
		loadLevel(0);
	}
	
	void init(){
		// we need to add a loading screen

		double width = win.getOrthoWidth();
		double height = win.getOrthoHeight();
		//images
		bgInitMenu.setPositions(0, 0, -99);
		bgInitMenu.setSizes(width,height, 1);

		//Loading Players
		player1.loadPlayer();
		player2.loadPlayer();
		player3.loadPlayer();
		players.push_back(player1);
		players.push_back(player2);
		players.push_back(player3);

		//loading all posible levels

	}

	//gets
	GlutWindow *getWin(){ return &win; }

	//Mouse And keyboard
	void pasiveMouse(int x, int y)
	{
		for (unsigned int i = 0; i < buttons.size(); i++){
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
			for (unsigned int i = 0; i < buttons.size(); i++){
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
		level = root["level"];
		type = (std::string)root["type"];
		data = root["data"];

		if (type == MENU){// here we will load a menu
			json::Array positions;
			json::Array sizes;
			path = "Images/" + (std::string)data["background"];
			bgInitMenu.setPath(path);

			auxArr = data["buttons"];
			for (unsigned int i = 0; i < auxArr.size(); i++){// ADD BUTTON
				auxObj = auxArr[i];

				btnPtr = new Button((std::string)auxObj["text"]);
				btnPtr->setEventsStack(&events);// sending the address of this event stack

				if (auxObj["ID"].GetType() != json::NULLVal){
					btnPtr->setID(auxObj["ID"]);
				}

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

	void button_listener(int id){
		std::cout << id << std::endl;
		// ids from 0 to 99 are transicion buttons
		// ids 99 - 999 are action functions

		// 0 = NEXT
		// 99 = BACK
		switch (id)
		{
		case 0:
			//NEXT
			loadLevel(level + 1);
			break;
		case 3:
			loadLevel(2);
			break;
		case 99:
			//BACK
			loadLevel(level - 1);
			break;
		default:
			break;
		}
	}


	void prepareList(){}
	void prepareLevel(){}
	void prepareMaps(std::string levelname){

	}
	void showGrid(bool wannaShow){}
	void changeActiveWindow(int toWindow){}

	void draw(double time){

		bgInitMenu.draw2D();

		for (unsigned int i = 0; i < buttons.size(); i++)
			buttons[i].draw();
		for (unsigned int i = 0; i < images.size(); i++)
			images[i].draw2D();
		//also we need to draw all other objects
	}

	void refresh(){
		while (!events.empty())
		{
			button_listener(events.top());
			events.pop();
		}					
	}

	Image bgInitMenu;
private:

	bool isPlaying;// true if playing a level false if not
	int level;// level that will be played
	Player player1;
	Player player2;
	Player player3;

	//PathManager
	//int goTo[10][3] = {
	//	[], [], []
	//};

	GlutWindow win;
	std::stack<int> events;
	std::map<char, std::string> sprites_map;//

	//Objects
	std::vector<Tower> towers;
	std::vector<BadAgent> enemies;//maybe it will be not implemented
	std::vector<Player> players;

	//visual controls
	std::vector<Button> buttons;
	std::vector<Image> images;
};

