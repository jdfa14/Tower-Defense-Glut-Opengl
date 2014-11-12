#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Button.h"
#include "Image.h"
#include "BadAgent.h"
#include "Tower.h"
#include "json\json.h"

class Screen
{
private:
	std::string screenName;
	std::string type;
	Image background;
	std::vector<Image> images;
	std::vector<Button> buttons;
	std::vector<Tower> towers;
	//std::vector<BadAgent> enemies;
	bool loaded;

public:
	Screen();

	//gets
	std::vector<Button>* getButtons();
	std::vector<Image>* getImages();
	std::vector<Tower>* getTowers();
	//std::vector<std::vector<BadAgent>> getEnemies(); pending... i need to know if i will use a class or a struct
	std::string getScreenName();
	std::string getType();
	Image * getBGImage();
	bool isLoaded();

	//sets
	void setName(std::string screenName);
	
	//editions
	bool loadLevel(int level, std::stack<int> *events);
	void draw();
};

