#pragma once
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "json\json.h"
#include "level.h"

class Player
{
private:
	std::string name;
	std::string fileName;
	std::vector<Level> levels;
	bool newPlayer;


public:
	Player(std::string fileName);
	Player();

	//gets
	std::string getName();
	std::string getFileName();
	std::vector<Level> getAllLevels();
	Level getLevel(int i);
	bool isNewPlayer();

	//sets
	void setName(std::string name);
	void setFileName(std::string fileName);
	void setNewPlayer(bool newby);

	//Edit
	void addLevel(Level level);
	void addLevel(bool comp, unsigned int score, bool locked);
	void resetLevels();

	//files
	bool savePlayer();
	bool loadPlayer();
};

