#pragma once
#include "Globals.h"
#include "StaticObject.h"
#include "Bullet.h"
#include "BadAgent.h"
#include "cData.h"
#include <time.h>
#include <stdlib.h>

#include "LinkedList.h"

#define WHITE_TOWER 0
#define YELLOW_TOWER 1
#define PILL_TOWER 2


#define PRICE_TOWER_TYPE_1			100
#define PRICE_TO_UPGRADE_TYPE_1		150
#define PRICE_TO_SUPPER_TYPE_1		300

#define PRICE_TOWER_TYPE_2			150
#define PRICE_TO_UPGRADE_TYPE_2		200
#define PRICE_TO_SUPPER_TYPE_2		300

#define PRICE_TOWER_TYPE_3			200
#define PRICE_TO_UPGRADE_TYPE_3		300
#define PRICE_TO_SUPPER_TYPE_3		400

class Tower : public StaticObject
{
    private:
		LinkedList<BadAgent> *enemies;//array where it will check
		std::vector<Bullet> bullets; // my array of bullets
		double dmgAntiViral;
		double dmgAntiBacterial;
		double range; //range from origin to shot must be positive
		double timeBetweenShots; 
		double timeToShot;//need to be 0 to be able to shot
		int type;// 1 normal, 2 desintegrators, 3 booster
		int level;// 1 normal, 2 upgraded, 3 super
		cData *data;
		void setType(int type);

		//shot
		void goTo(double x, double y);//change 

    public:
		Tower(cData &data, LinkedList<BadAgent> &enemies, double x = 0, double y = 0, double z = 0,int type = WHITE_TOWER);
		~Tower();
		//editions
		bool didHeJustClickedMe(double x, double y); // return true if x and y are inside him

		//sets
		void setTimeToShot(double timeInSeconds);
		void setRange(double range);

		//Display
		void update(double elapsedTimeMiliSec); //time to shot, update every Bullet
		void draw();//draw all images
		void shot(BadAgent *toChase);
};

