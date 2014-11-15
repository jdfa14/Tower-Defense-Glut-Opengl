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
	std::string path = "Images/";

	//loading buttons
	LoadImage(IMG_BUTTONNORMAL, path + "buttonNormal.png"); 
	LoadImage(IMG_BUTTONHOVER, path + "buttonHover.png"); 
	LoadImage(IMG_BUTTONPRESSED, path + "buttonPressed.png"); 

	//loading backgrounds
	path = "Images/backgrounds/";
	LoadImage(IMG_BGMAIN, path + "menu.png"); 
	LoadImage(IMG_BGCREDITS, path + "credits.png"); 
	LoadImage(IMG_BGPLAY, path + "play.png"); 
	LoadImage(IMG_GRIDGREEN, path + "greenGrid.png");
	LoadImage(IMG_GRIDRED, path + "redGrid.png");
	LoadImage(IMG_GRIDSELECTED, path + "selectedGrid.png");

	// loading towers
	path = "Images/towers/";
	// Pills
	LoadImage(IMG_TOWER1NORMAL, path + "tower1Normal.png");
	LoadImage(IMG_TOWER1UPGRADED, path + "tower1Upgraded.png");
	LoadImage(IMG_TOWER1SUPER, path + "tower1Super.png");
	// White cell
    LoadImage(IMG_TOWER2NORMAL, path + "tower2Normal.png");
	LoadImage(IMG_TOWER2UPGRADED, path + "tower2Upgraded.png");
	LoadImage(IMG_TOWER2SUPER, path + "tower2Super.png");
	// Yellow cell
    LoadImage(IMG_TOWER3NORMAL, path + "tower3Normal.png");
	LoadImage(IMG_TOWER3UPGRADED, path + "tower3Upgraded.png");
	LoadImage(IMG_TOWER3SUPER, path + "tower3Super.png");
	//toplace
	LoadImage(IMG_TOWER_1_TOPLACE, path + "tower1ToPlace.png");
	LoadImage(IMG_TOWER_2_TOPLACE, path + "tower2ToPlace.png");
	LoadImage(IMG_TOWER_3_TOPLACE, path + "tower3ToPlace.png");
	return true;
}

void cData::Draw(int img, double x, double y, double z, double width, double height){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[img].GetID());
	glPushMatrix();
	glTranslated(x, y, z);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3i(-width / 2.0, height / 2.0, -1);
	glTexCoord2f(1, 0);	glVertex3i(width / 2.0, height / 2.0, -1);
	glTexCoord2f(1, 1);	glVertex3i(width / 2.0, -height / 2.0, -1);
	glTexCoord2f(0, 1);	glVertex3i(-width / 2.0, -height / 2.0, -1);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}