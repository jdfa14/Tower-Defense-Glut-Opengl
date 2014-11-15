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

//Image array size
#define NUM_TEX				25


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
