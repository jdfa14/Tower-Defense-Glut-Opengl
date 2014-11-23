#pragma once
#include "cTexture.h"

//Image identifiers

#define IMG_BGMAIN			0
#define IMG_BGPLAYERSELECT	1
#define IMG_BGINSTRUCTIONS	2
#define IMG_BGCREDITS		3
#define IMG_BGLEVELSELECT	4
#define IMG_BGPLAY			5

#define IMG_BUTTONNORMAL	6
#define IMG_BUTTONHOVER		7
#define IMG_BUTTONPRESSED	8

#define IMG_TOWER1NORMAL	9
#define	IMG_TOWER1UPGRADED  10
#define IMG_TOWER1SUPER		11
#define IMG_TOWER2NORMAL	12
#define IMG_TOWER2UPGRADED	13
#define IMG_TOWER2SUPER		14
#define IMG_TOWER3NORMAL	15
#define IMG_TOWER3UPGRADED	16
#define IMG_TOWER3SUPER		17

#define IMG_TOWER_1_TOPLACE	19
#define IMG_TOWER_2_TOPLACE	20
#define IMG_TOWER_3_TOPLACE	21

#define IMG_GRIDGREEN		22
#define IMG_GRIDRED			23
#define IMG_GRIDSELECTED	24

//grid tiles
#define IMG_TILE_A			25
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

#define IMG_VIRUS			43
#define IMG_BACTERIA		44

#define IMG_LIFEBAR			45

#define IMG_BTN_LEVELNORMAL	47
#define IMG_BTN_LEVELHOVER	48

#define IMG_BTN_LEVEL_LOCK_NORMAL	49
#define IMG_BTN_LEVEL_LOCK_HOVER	50

#define IMG_BTN_PLAYER_NORMAL		51
#define IMG_BTN_PLAYER_HOVER		52

#define IMG_BTN_PLAYER_NEW_NORMAL	53
#define IMG_BTN_PLAYER_NEW_HOVER	54

//Image array size
#define NUM_TEX				55


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
