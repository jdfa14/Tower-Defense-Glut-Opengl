#pragma once
#define GRD_STATE_PLACEABLE 0
#define GRD_STATE_NOTPLACEABLE 1
#define GRD_STATE_SELECTED 2

typedef struct Grid{
	double x;
	double y;
	double width;
	double heith;
	bool placeable;
	int state; //0 green, 1 red, 2 selected
	int img;
	char tileType;
}Grid;