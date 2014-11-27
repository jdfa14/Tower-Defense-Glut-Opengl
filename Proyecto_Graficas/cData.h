#pragma once
#include "cTexture.h"

//Image identifiers

#define IMG_BGMAIN			0 // Done
#define IMG_BGPLAYERSELECT	1 // Done
#define IMG_BGINSTRUCTIONS	2 // NOT
#define IMG_BGCREDITS		3 // Done
#define IMG_BGLEVELSELECT	4 // NOT
#define IMG_BGPLAY			5 // NOT
#define IMG_BG_HISTORY		6

#define IMG_BUTTONNORMAL	7 // Done
#define IMG_BUTTONHOVER		8 // Done

#define IMG_TOWER1NORMAL	9 // Done
#define	IMG_TOWER1UPGRADED  10 // Done
#define IMG_TOWER1SUPER		11 // Done
#define IMG_TOWER2NORMAL	12 // Done
#define IMG_TOWER2UPGRADED	13 // Done
#define IMG_TOWER2SUPER		14 // Done
#define IMG_TOWER3NORMAL	15 // Done
#define IMG_TOWER3UPGRADED	16 // Done
#define IMG_TOWER3SUPER		17 // Done

#define IMG_TOWER_1_TOPLACE	19 // Done
#define IMG_TOWER_2_TOPLACE	20 // Done
#define IMG_TOWER_3_TOPLACE	21 // Done

#define IMG_GRIDGREEN		22 // Done
#define IMG_GRIDRED			23 // Done
#define IMG_GRIDSELECTED	24 // Done

//grid tiles
#define IMG_TILE_A			25 // All of those need to get a visual update
#define IMG_TILE_B			26
#define IMG_TILE_C			27
#define IMG_TILE_D			28
#define IMG_TILE_E			29
#define IMG_TILE_F			30
#define IMG_TILE_G			31
#define IMG_TILE_H			32
#define IMG_TILE_I			33
#define IMG_TILE_J			34
#define IMG_TILE_K			35
#define IMG_TILE_L			36
#define IMG_TILE_M			37
#define IMG_TILE_N			38
#define IMG_TILE_O			39
#define IMG_TILE_P			40
#define IMG_TILE_Q			41
#define IMG_TILE_X			42

#define IMG_VIRUS			43 // Done
#define IMG_BACTERIA		44 // Done

#define IMG_LIFEBAR			45 // Done

#define IMG_BTN_LEVELNORMAL	47// Done
#define IMG_BTN_LEVELHOVER	48// Done

#define IMG_BTN_LEVEL_LOCK_NORMAL	49// Done

#define IMG_BTN_PLAYER1_NORMAL		50
#define IMG_BTN_PLAYER1_HOVER		51

#define IMG_BTN_PLAYER1_NEW_NORMAL	52
#define IMG_BTN_PLAYER1_NEW_HOVER	53

#define IMG_BTN_PLAYER2_NORMAL		54
#define IMG_BTN_PLAYER2_HOVER		55

#define IMG_BTN_PLAYER2_NEW_NORMAL	56
#define IMG_BTN_PLAYER2_NEW_HOVER	57

#define IMG_BTN_PLAYER3_NORMAL		58
#define IMG_BTN_PLAYER3_HOVER		59

#define IMG_BTN_PLAYER3_NEW_NORMAL	60
#define IMG_BTN_PLAYER3_NEW_HOVER	61

#define IMG_BTN_TOWER_LOCKED	62

#define IMG_BTN_TOOLTIP		63 // Done

//Image array size
#define NUM_TEX				64


class cData
{
public:
	cData(void);
	~cData(void);

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();
	void Draw(int img, double x = 0, double y = 0, double z = 0, double width = 100, double height = 100);

private:
	cTexture textures[NUM_TEX];
	bool LoadImage(int img, std::string filename, int type = GL_RGBA);
};
