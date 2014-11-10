#include "Player.h"

Player::Player(std::string fileName) : Player()
{
	setFileName(fileName);
}

Player::Player(){
	name = "No name";
	newPlayer = true;
	resetLevels();
}

std::string Player::getName(){
	return name;
}

std::string Player::getFileName(){
	return fileName;
}

std::vector<Level> Player::getAllLevels(){
	return levels;
}

Level Player::getLevel(int i){
	return levels[i];
}

void Player::setName(std::string name){
	this->name = name;
}

void Player::setFileName(std::string fileName){
	this->fileName = fileName;
}

void Player::addLevel(Level level){
	levels.push_back(level);
}

void Player::addLevel(bool c, unsigned int s, bool l){
	Level aux;
	aux.completed = c;
	aux.score = s;
	aux.locked = l;
	levels.push_back(aux);
}

void Player::resetLevels(){
	levels.clear();

	Level aux;
	aux.completed = false;
	aux.score = 0;
	aux.locked = false;
	levels.push_back(aux);

	for (int i = 1; i < 10; i++){
		Level toLoad;
		toLoad.completed = false;
		toLoad.score = 0;
		toLoad.locked = true;
		levels.push_back(toLoad);
	}
}

bool Player::loadPlayer(){
	std::string path = "players/" + fileName + ".json";
	std::string line;
	std::string json_string;
	std::ifstream json_file;
	json::Value json_value;
	json::Object json;
	json::Object saved_lvl;
	json::Array saved_levels;

	json_file.open(path);

	if (!json_file.is_open()){
		
		// If no file, we have to save one and then invoque this same method
		if (savePlayer()){
			return loadPlayer();// after this, you should no see the error
		}
		else{
			std::cout << "Error: could not load the json file at " << path << std::endl;
			std::cout << "And unable to create one with that name" << std::endl;
			return false;
		}
	}

	while (!json_file.eof())
	{
		json_file >> line;
		json_string += line;
	}
	json_file.close();

	json_value = json::Deserialize(json_string);

	if (json_value.GetType() == json::NULLVal){
		std::cout << "Error: Not json file: " << json_string << std::endl;
		return false;
	}

	json = json_value.ToObject();

	levels.clear();
	newPlayer = json["newPlayer"];

	if (!newPlayer){
		name = json["name"];
		saved_levels = json["levels"];
		
		for (unsigned int i = 0; i < saved_levels.size(); i++){
			Level toLoad;
			saved_lvl = saved_levels[i];
			toLoad.completed = saved_lvl["completed"];
			toLoad.score = saved_lvl["score"];
			toLoad.locked = saved_lvl["locked"];

			levels.push_back(toLoad);
		}
	}
	else{
		name = "New Player";
		resetLevels();// fill the then posible levels
	}
	return true;
}

bool Player::savePlayer(){
	if (fileName == "")// if no filename we will not be able to save the file
		return false;

	json::Object playerObject;
	json::Array playerLevels;
	std::string json_string;
	std::string path;
	std::ofstream output;

	playerObject["type"] = "Player";
	playerObject["name"] = name;
	playerObject["newPlayer"] = newPlayer;

	for each (Level var in levels)
	{
		json::Object playerLevel;
		playerLevel["completed"] = var.completed;
		playerLevel["score"] = var.score;
		playerLevel["locked"] = var.locked;

		playerLevels.push_back(playerLevel);
	}

	playerObject["levels"] = playerLevels;

	json_string = json::Serialize(playerObject);
	// we have the json string, now we have to save it

	path = "players/" + fileName + ".json";

	output.open(path); // filename validation required
	output << json_string;
	output.close();
	//json saved
	return true;
}
