#pragma once
#include "cTexture.h"

//Image identifiers

#define IMG_BGMAIN			0 // Done
#define IMG_BGPLAYERSELECT	1 // Done
#define IMG_BGINSTRUCTIONS	2 // NOT
#define IMG_BGCREDITS		3 // Done
#define IMG_BGLEVELSELECT	4 // NOT
#define IMG_BGPLAY			5 // NOT

#define IMG_BUTTONNORMAL	6 // Done
#define IMG_BUTTONHOVER		7 // Done
#define IMG_BUTTONPRESSED	8 // Not Needed

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

#define IMG_BTN_LEVELNORMAL	47
#define IMG_BTN_LEVELHOVER	48

#define IMG_BTN_LEVEL_LOCK_NORMAL	49
#define IMG_BTN_LEVEL_LOCK_HOVER	50 // not needed 

#define IMG_BTN_PLAYER_NORMAL		51
#define IMG_BTN_PLAYER_HOVER		52

#define IMG_BTN_PLAYER_NEW_NORMAL	53
#define IMG_BTN_PLAYER_NEW_HOVER	54

#define IMG_BTN_TOWER1_NORMAL	55
#define IMG_BTN_TOWER1_HOVER	56

#define IMG_BTN_TOWER1U_NORMAL	57
#define IMG_BTN_TOWER1U_HOVER	58

#define IMG_BTN_TOWER1S_NORMAL	59
#define IMG_BTN_TOWER1S_HOVER	60

#define IMG_BTN_TOWER2_NORMAL	61
#define IMG_BTN_TOWER2_HOVER	62

#define IMG_BTN_TOWER2U_NORMAL	63
#define IMG_BTN_TOWER2U_HOVER	64

#define IMG_BTN_TOWER2S_NORMAL	65
#define IMG_BTN_TOWER2S_HOVER	66

#define IMG_BTN_TOWER3_NORMAL	67
#define IMG_BTN_TOWER3_HOVER	68

#define IMG_BTN_TOWER3U_NORMAL	69
#define IMG_BTN_TOWER3U_HOVER	70

#define IMG_BTN_TOWER3S_NORMAL	71
#define IMG_BTN_TOWER3S_HOVER	72

#define IMG_BTN_TOWER_LOCKED	73

#define IMG_BTN_SELL_NORMAL		74
#define IMG_BTN_SELL_HOVER		75

#define IMG_BTN_TOOLTIP		76

//Image array size
#define NUM_TEX				77


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
