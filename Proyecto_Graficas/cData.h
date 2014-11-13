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



//Image array size
#define NUM_TEX				18


class cData
{
public:
	cData(void);
	~cData(void);

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();

private:
	cTexture textures[NUM_TEX];
	bool LoadImage(int img, std::string filename, int type = GL_RGBA);
};
