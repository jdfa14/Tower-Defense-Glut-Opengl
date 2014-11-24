#include "Player.h"

Player::Player(std::string fileName, cData &data):Player(data) {
	this->fileName = fileName;
}

Player::Player(cData &data){
	this->data = &data;
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

std::vector<Level>* Player::getAllLevels(){
	return &levels;
}

std::vector<Button>* Player::getLevelButtons(){
	return &levelButtons;
}

Level Player::getLevel(int i){
	return levels[i];
}

bool Player::isNewPlayer(){
	return newPlayer;
}

void Player::setName(std::string name){
	this->name = name;
}

void Player::setFileName(std::string fileName){
	this->fileName = fileName;
}

void Player::setNewPlayer(bool newby){
	this->newPlayer = newby;
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
	double spaceX = 50;
	double spaceY = 50;
	double width = (1000 - 200) / 5.0 - spaceX;
	double height = (1000 - 200) / 2.0 - spaceY;
	double xP = -500 + 100 + width / 2.0 + spaceX / 2.0;
	double yP = 500 - 100 - height / 2.0 - spaceY / 2.0;
	
	levels.clear();
	levelButtons.clear();

	Level aux;
	aux.completed = false;
	aux.score = 0;
	aux.locked = false;
	levels.push_back(aux);

	for (int i = 1; i < 5; i++){
		Level toLoad;
		toLoad.completed = false;
		toLoad.score = 0;
		toLoad.locked = true;
		levels.push_back(toLoad);
	}

	addButton(0, -360,-140);
	addButton(1, -230, 100);
	addButton(2,    0, 270);
	addButton(3,  230, 100);
	addButton(4,  360,-140);

}

void Player::addButton(int level, int x, int y){
	Button newOne(std::to_string(level));
	newOne.setID(level + 9);
	newOne.setSizes(220, 220, 1);
	newOne.setPositions(x, y,1);
	newOne.setEnable(!levels[level].locked);
	newOne.setImages(data->GetID(IMG_BTN_LEVELNORMAL), data->GetID(IMG_BTN_LEVELHOVER), data->GetID(IMG_BTN_TOOLTIP), data->GetID(IMG_BTN_LEVEL_LOCK_NORMAL));
	levelButtons.push_back(newOne);
}

bool Player::loadPlayer(std::stack<int> &events){
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
			return loadPlayer(events);// after this, you should no see the error
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

		for (unsigned int i = 0; i < levels.size(); i++){
			levelButtons[i].setEnable(!levels[i].locked);
			levelButtons[i].setEventsStack(&events);
		}

	}
	else{
		name = "New Player";
		resetLevels();// fill the 5 posible levels
		for (unsigned int i = 0; i < levels.size(); i++){
			levelButtons[i].setEventsStack(&events);
		}
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

	std::cout << "Player Saved \n";
	return true;
}

void Player::unlock(int levelPos){
	levels[levelPos].locked = false;
	levelButtons[levelPos].setEnable(true);
}

void Player::setNewLevelScore(int levelPos, Level newLevel){
	levels[levelPos] = newLevel;
}