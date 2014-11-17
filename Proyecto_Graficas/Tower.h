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

class Tower : public StaticObject
{
    private:
		LinkedList *enemies;//array where it will check
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
		Tower(cData &data, LinkedList &enemies, double x = 0, double y = 0, double z = 0,int type = WHITE_TOWER);
		~Tower();
		//editions
		

		//sets
		void setTimeToShot(double timeInSeconds);
		void setRange(double range);

		//Display
		void update(double elapsedTimeMiliSec); //time to shot, update every Bullet
		void draw();//draw all images
		void shot(BadAgent *toChase);
};

