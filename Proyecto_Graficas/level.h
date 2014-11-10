#pragma once

typedef struct Level{
	bool completed;// if the game has been completed
	int score;// the higer score reached
	bool locked;// if the game is able to be played
}Level;