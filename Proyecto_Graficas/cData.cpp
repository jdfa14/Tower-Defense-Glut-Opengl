#include "cData.h"

cData::cData(void) {}
cData::~cData(void){}

int cData::GetID(int img)
{
	return textures[img].GetID();
}

void cData::GetSize(int img, int *w, int *h)
{
	textures[img].GetSize(w, h);
}

bool cData::LoadImage(int img, std::string filename, int type)
{
	int res;
	res = textures[img].Load(filename, type);
	if (!res) return false;

	return true;
}
bool cData::Load()
{
	int res;
	std::string path = "Images/";
	//loading buttons
	res = LoadImage(IMG_BUTTONNORMAL, path + "buttonNormal.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_BUTTONHOVER, path + "buttonHover.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_BUTTONPRESSED, path + "buttonPressed.png", GL_RGBA); if (!res) return false;

	//loading backgrounds
	path = "Images/backgrounds/";
	res = LoadImage(IMG_BGMAIN, path + "menu.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_BGCREDITS, path + "credits.png", GL_RGBA); if (!res) return false;

	return true;
}