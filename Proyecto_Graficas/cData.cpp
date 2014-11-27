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
	std::cout << "Loading images... 00%";
	double i = 0;

	std::string path = "Images/";
	//loading buttons
	LoadImage(IMG_LIFEBAR, path + "lifeBar.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_TOOLTIP, path + "tooltip.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	path = "Images/buttons/";
	LoadImage(IMG_BUTTONNORMAL, path + "buttonNormal.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BUTTONHOVER, path + "buttonHover.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_LEVELNORMAL, path + "levelNormal.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_LEVELHOVER, path + "levelHover.png"); i++; std::cout << "\b\b\b0" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_LEVEL_LOCK_NORMAL, path + "levelLocked.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	
	LoadImage(IMG_BTN_PLAYER1_NORMAL, path + "player1Progress.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER1_HOVER, path + "player1ProgressHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER1_NEW_NORMAL, path + "player1NewGame.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER1_NEW_HOVER, path + "player1NewGameHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	LoadImage(IMG_BTN_PLAYER2_NORMAL, path + "player2Progress.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER2_HOVER, path + "player2ProgressHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER2_NEW_NORMAL, path + "player2NewGame.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER2_NEW_HOVER, path + "player2NewGameHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	LoadImage(IMG_BTN_PLAYER3_NORMAL, path + "player3Progress.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER3_HOVER, path + "player3ProgressHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER3_NEW_NORMAL, path + "player3NewGame.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BTN_PLAYER3_NEW_HOVER, path + "player3NewGameHover.png");  i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";


	//loading backgrounds
	path = "Images/backgrounds/";
	LoadImage(IMG_BGMAIN, path + "menu.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BGCREDITS, path + "credits.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BGPLAY, path + "play.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BGPLAYERSELECT, path + "playerBackground.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BGLEVELSELECT, path + "levelSelect.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BG_HISTORY, path + "history.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_GRIDGREEN, path + "greenGrid.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_GRIDRED, path + "redGrid.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_GRIDSELECTED, path + "selectedGrid.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

	
	// loading towers
	path = "Images/towers/";
	// Pills
	LoadImage(IMG_TOWER1NORMAL, path + "tower1Normal.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER1UPGRADED, path + "tower1Upgraded.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER1SUPER, path + "tower1Super.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	// White cell
	LoadImage(IMG_TOWER2NORMAL, path + "tower2Normal.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER2UPGRADED, path + "tower2Upgraded.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER2SUPER, path + "tower2Super.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	// Yellow cell
	LoadImage(IMG_TOWER3NORMAL, path + "tower3Normal.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER3UPGRADED, path + "tower3Upgraded.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER3SUPER, path + "tower3Super.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	//toplace
	LoadImage(IMG_TOWER_1_TOPLACE, path + "tower1ToPlace.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER_2_TOPLACE, path + "tower2ToPlace.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_TOWER_3_TOPLACE, path + "tower3ToPlace.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";

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

	path = "Images/enemies/";
	LoadImage(IMG_VIRUS, path + "bad.png"); std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	LoadImage(IMG_BACTERIA, path + "bad.png"); std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";


	// Agrega virus inicio
	path = "Images/enemies/";
	LoadImage(IMG_VIRUS, path + "bad.png"); i++; std::cout << "\b\b\b" << (int)(i / (double)NUM_TEX * 100.0) << "%";
	// Agrega virus fin

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