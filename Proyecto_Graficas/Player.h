#pragma once
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "json\json.h"
#include "level.h"
#include "Button.h"
#include "cData.h"

class Player
{
private:
	cData *data;
	std::string name;
	std::string fileName;
	std::vector<Level> levels;
	std::vector<Button> levelButtons;
	bool newPlayer;
	void addButton(int level, int x, int y);

public:
	Player(std::string fileName, cData &data);
	Player(cData &data);

	//gets
	std::string getName();
	std::string getFileName();
	std::vector<Level>* getAllLevels();
	std::vector<Button>* getLevelButtons();
	Level getLevel(int i);
	bool isNewPlayer();

	//sets
	void setName(std::string name);
	void setFileName(std::string fileName);
	void setNewPlayer(bool newby);
	void setNewLevelScore(int levelPos, Level);
	void unlock(int levelPos);

	//Edit
	void addLevel(Level level);
	void addLevel(bool comp, unsigned int score, bool locked);
	void resetLevels();

	//files
	bool savePlayer();
	bool loadPlayer(std::stack<int> &events);
};

