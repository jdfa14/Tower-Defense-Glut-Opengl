#include "Screen.h"


Screen::Screen()
{
	screenName = "No Name";
	type = "";
	loaded = false;
}

std::vector<Button>* Screen::getButtons(){
	return &buttons;
}

std::vector<Image>* Screen::getImages(){
	return &images;
}

std::vector<Tower>* Screen::getTowers(){
	return &towers;
}

//std::vector<BadAgent> Screen::getEnemies(){
//	return enemies;
//}

std::string Screen::getScreenName(){
	return screenName;
}

std::string Screen::getType(){
	return type;
}

Image* Screen::getBGImage(){
	return &background;
}

void Screen::setName(std::string screenName){
	this->screenName = screenName;
}

bool Screen::isLoaded(){
	return loaded;
}

bool Screen::loadLevel(int num, std::stack<int> *events){
	json::Object json;
	json::Object data;
	json::Array buttons;
	json::Array images;
	json::Array towers;
	json::Array enemies;


	std::string path = "screens/Screen " + std::to_string(num) + ".json";
	int errorHandler;
	
	json = json::loadJson(path, errorHandler).ToObject();

	if (errorHandler > 0){
		std::cout << "Error loading screen: " << errorHandler << std::endl;
		return false;
	}

	type = (std::string)json["type"];
	data = json["data"];
	background.setPath("Images/backgrounds/" + (std::string)data["background"]);

	//load buttons
	if (data["buttons"].GetType() != json::NULLVal){
		buttons = data["buttons"];
		for (unsigned int i = 0; i < buttons.size(); i++){
			json::Object jsonBut = buttons[i];
			std::string name = (std::string)jsonBut["text"];
			Button newButton(name);
			newButton.setID(jsonBut["ID"]);
			newButton.setEventsStack(events);

			if (jsonBut["positions"].GetType() != json::NULLVal){
				json::Array arr;
				arr = jsonBut["positions"];
				newButton.setPositions(arr[0], arr[1], arr[2]);
			}

			if (jsonBut["sizes"].GetType() != json::NULLVal){
				json::Array arr;
				arr = jsonBut["sizes"];
				newButton.setSizes(arr[0], arr[1], arr[2]);
			}

			this->buttons.push_back(newButton);
		}

		//pending
	}
	return true;
}

void Screen::draw(){
	for (unsigned int i = 0; i < buttons.size(); i++)
		buttons[i].draw();
	for (unsigned int i = 0; i < images.size(); i++)
		images[i].draw2D();
	for (unsigned int i = 0; i < towers.size(); i++)
		towers[i].draw();
}