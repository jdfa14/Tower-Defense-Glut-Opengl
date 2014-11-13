#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Button.h"
#include "Texture.h"
#include "BadAgent.h"
#include "Tower.h"
#include "json\json.h"

class Screen
{
private:
	std::string screenName;
	std::string type;
	Texture background;
	std::vector<Texture> images;
	std::vector<Button> buttons;
	std::vector<Tower> towers;
	//std::vector<BadAgent> enemies;
	bool loaded;

public:
	Screen();

	//gets
	std::vector<Button>* getButtons();
	std::vector<Texture>* getImages();
	std::vector<Tower>* getTowers();
	//std::vector<std::vector<BadAgent>> getEnemies(); pending... i need to know if i will use a class or a struct
	std::string getScreenName();
	std::string getType();
	Texture* getBGImage();
	bool isLoaded();

	//sets
	void setName(std::string screenName);
	
	//editions
	bool loadLevel(int level, std::stack<int> *events);
};

