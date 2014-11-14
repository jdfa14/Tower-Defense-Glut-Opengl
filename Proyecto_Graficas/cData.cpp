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
	res = LoadImage(IMG_BGPLAY, path + "play.png", GL_RGBA); if (!res) return false;

	// loading towers
	path = "Images/towersPNG/";
	// Pills
	res = LoadImage(IMG_TOWER1NORMAL, path + "tower1Normal.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER1UPGRADED, path + "tower1Upgraded.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER1SUPER, path + "tower1Super.png", GL_RGBA); if (!res) return false;
	// White cell
    res = LoadImage(IMG_TOWER2NORMAL, path + "tower2Normal.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER2UPGRADED, path + "tower2Upgraded.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER2SUPER, path + "tower2Super.png", GL_RGBA); if (!res) return false;
	// Yellow cell
    res = LoadImage(IMG_TOWER3NORMAL, path + "tower3Normal.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER3UPGRADED, path + "tower3Upgraded.png", GL_RGBA); if (!res) return false;
	res = LoadImage(IMG_TOWER3SUPER, path + "tower3Super.png", GL_RGBA); if (!res) return false;


	return true;
}
