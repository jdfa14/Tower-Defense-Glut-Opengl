#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include "addGlut.h"
class Window
{
public:

	Window()
	{
		xMin = 0;
		xMax = 0;
		yMin = 0;
		yMax = 0;

		leftOrtho = 0;
		rigthOrtho = 0;
		bottomOrtho = 0;
		topOrtho = 0;

		winName = "No Name";
	}

	~Window()
	{
	}

	void setWindowSize(int xMin, int xMax, int yMin, int yMax){
		this->xMin = xMin;
		this->xMax = xMax;
		this->yMin = yMin;
		this->yMax = yMax;
	}

	void setOrthoSize(int left, int rigth, int bottom, int top){
		leftOrtho = left;
		rigthOrtho = rigth;
		bottomOrtho = bottom;
		topOrtho = top;
	}

	void setOrho(int nearOrtho, int farOrtho){
		glOrtho(leftOrtho, rigthOrtho, bottomOrtho, topOrtho, nearOrtho, farOrtho);
	}

	void setName(std::string name){
		winName = name;
	}
	//windows info
	int getWindowWidth(){ return abs(xMax - xMin); }
	int getOrthoWidth(){ return abs(rigthOrtho - leftOrtho);}
	int getWindowsHeight(){ return abs(yMax - yMin); }
	int getOrthoHeigth() { return abs(topOrtho - bottomOrtho); }
	std::string getName(){ return winName; }

	//ortho
	int getLeft(){ return leftOrtho; }
	int getRigth() { return rigthOrtho; }
	int getTop(){ return topOrtho; }
	int getBottom(){ return bottomOrtho; }

	//map
	double getXMapped(double x){
		double ratio = (double)getWindowWidth() / getOrthoWidth();
		return (double)leftOrtho + x / ratio;
	}

	double getYMapped(double y){
		double ratio = (double)getWindowsHeight() / getOrthoHeigth();
		return (double)bottomOrtho + (topOrtho - y / ratio);
	}

private:
	std::string winName;
	//windows size
	int xMin;
	int xMax;
	int yMin;
	int yMax;
	//ortho size
	int leftOrtho;
	int rigthOrtho;
	int bottomOrtho;
	int topOrtho;


};

