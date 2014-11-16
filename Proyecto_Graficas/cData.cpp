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
	std::cout << "Loading images -> 00%";
	double i = 0;

	std::string path = "Images/";
	//loading buttons
	LoadImage(IMG_BUTTONNORMAL, path + "buttonNormal.png"); i++;
	LoadImage(IMG_BUTTONHOVER, path + "buttonHover.png"); i++;
	LoadImage(IMG_BUTTONPRESSED, path + "buttonPressed.png"); i++;

	std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	//loading backgrounds
	path = "Images/backgrounds/";
	LoadImage(IMG_BGMAIN, path + "menu.png"); i++;
	LoadImage(IMG_BGCREDITS, path + "credits.png"); i++;
	LoadImage(IMG_BGPLAY, path + "play.png"); i++;
	LoadImage(IMG_GRIDGREEN, path + "greenGrid.png"); i++;
	LoadImage(IMG_GRIDRED, path + "redGrid.png"); i++;
	LoadImage(IMG_GRIDSELECTED, path + "selectedGrid.png"); i++;
	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	// loading towers
	path = "Images/towers/";
	// Pills
	LoadImage(IMG_TOWER1NORMAL, path + "tower1Normal.png"); i++;
	LoadImage(IMG_TOWER1UPGRADED, path + "tower1Upgraded.png"); i++;
	LoadImage(IMG_TOWER1SUPER, path + "tower1Super.png"); i++;
	// White cell
	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER2NORMAL, path + "tower2Normal.png"); i++;
	LoadImage(IMG_TOWER2UPGRADED, path + "tower2Upgraded.png"); i++;
	LoadImage(IMG_TOWER2SUPER, path + "tower2Super.png"); i++;
	// Yellow cell
	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER3NORMAL, path + "tower3Normal.png"); i++;
	LoadImage(IMG_TOWER3UPGRADED, path + "tower3Upgraded.png"); i++;
	LoadImage(IMG_TOWER3SUPER, path + "tower3Super.png"); i++;
	//toplace
	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER_1_TOPLACE, path + "tower1ToPlace.png"); i++;
	LoadImage(IMG_TOWER_2_TOPLACE, path + "tower2ToPlace.png"); i++;
	LoadImage(IMG_TOWER_3_TOPLACE, path + "tower3ToPlace.png"); i++;
	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	//lading tiles
	path = "Images/tiles/tile_";
	LoadImage(IMG_TILE_A, path + "a.png"); i++;
	LoadImage(IMG_TILE_B, path + "b.png"); i++;
	LoadImage(IMG_TILE_C, path + "c.png"); i++;
	LoadImage(IMG_TILE_D, path + "d.png"); i++;
	LoadImage(IMG_TILE_E, path + "e.png"); i++;
	LoadImage(IMG_TILE_F, path + "f.png"); i++;
	LoadImage(IMG_TILE_G, path + "g.png"); i++;
	LoadImage(IMG_TILE_H, path + "h.png"); i++;
	LoadImage(IMG_TILE_I, path + "i.png"); i++;
	LoadImage(IMG_TILE_J, path + "j.png"); i++;
	LoadImage(IMG_TILE_K, path + "k.png"); i++;
	LoadImage(IMG_TILE_L, path + "l.png"); i++;
	/*LoadImage(IMG_TILE_M, path + "m.png"); i++;
	LoadImage(IMG_TILE_N, path + "n.png"); i++;
	LoadImage(IMG_TILE_O, path + "o.png"); i++;
	LoadImage(IMG_TILE_P, path + "p.png"); i++;
	LoadImage(IMG_TILE_Q, path + "q.png"); i++;*/
	LoadImage(IMG_TILE_X, path + "x.png"); i++;

	path = "Images/enemies/badAgent_";
	LoadImage(IMG_BADAGENT1_1, path + "1_1.png");

	std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	std::cout << "\n";
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