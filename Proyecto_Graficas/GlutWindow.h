#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include "Globals.h"
class GlutWindow
{
public:

	GlutWindow()
	{
		setWindowSize(0, 0, 0, 0);
		setOrthoSize(0, 0, 0, 0,0,0);
		setCamera(0, 0, 1, 0, 0, 0, 0, 0, 1);
		setName("No name");
	}

	~GlutWindow()
	{
	}

	void setWindowSize(double xMin, double xMax, double yMin, double yMax){
		this->xMin = xMin;
		this->xMax = xMax;
		this->yMin = yMin;
		this->yMax = yMax;
	}

	void setOrthoSize(double left, double rigth, double bottom, double top, double nearO, double farO){
		leftOrtho = left;
		rigthOrtho = rigth;
		bottomOrtho = bottom;
		topOrtho = top;
		nearOrtho = nearO;
		farOrtho = farO;
	}

	void setCamera(double eyeX, double eyeY, double eyeZ, double origX, double origY, double origZ, int xCam, int yCam, int zCam){
		this->eyeX = eyeX;
		this->eyeY = eyeY;
		this->eyeZ = eyeZ;
		this->origX = origX;
		this->origY = origY;
		this->origZ = origZ;
		this->xCam = xCam;
		this->yCam = yCam;
		this->zCam = zCam;
	}

	void setOrho(){
		glOrtho(leftOrtho, rigthOrtho, bottomOrtho, topOrtho, nearOrtho, farOrtho);
	}

	void setName(std::string name){
		winName = name;
	}
	//windows info
	double getWindowWidth(){ return abs(xMax - xMin); }
	double getOrthoWidth(){ return abs(rigthOrtho - leftOrtho); }
	double getWindowsHeight(){ return abs(yMax - yMin); }
	double getOrthoHeight() { return abs(topOrtho - bottomOrtho); }
	double getOrthoVolum(){ return abs(farOrtho - nearOrtho); }
	std::string getName(){ return winName; }

	//ortho
	double getLeft(){ return leftOrtho; }
	double getRigth() { return rigthOrtho; }
	double getTop(){ return topOrtho; }
	double getBottom(){ return bottomOrtho; }
	double getNear() { return nearOrtho; }
	double getFar() { return farOrtho; }

	//camera
	double getEyeX(){ return eyeX; }
	double getEyeY(){ return eyeY; }
	double getEyeZ(){ return eyeZ; }
	double getOrigX(){ return origX; }
	double getOrigY(){ return origY; }
	double getOrigZ(){ return origZ; }
	double getCamX(){ return xCam; }
	double getCamY(){ return yCam; }
	double getCamZ(){ return zCam; }

	//map
	double getXMapped(double x){
		double ratio = getWindowWidth() / getOrthoWidth();
		return leftOrtho + x / ratio;
	}

	double getYMapped(double y){
		double ratio = getWindowsHeight() / getOrthoHeight();
		return topOrtho - y / ratio;
	}



private:
	std::string winName;
	//windows size
	double xMin;
	double xMax;
	double yMin;
	double yMax;
	//ortho size
	double leftOrtho;
	double rigthOrtho;
	double bottomOrtho;
	double topOrtho;
	double nearOrtho;
	double farOrtho;

	//camera
	double eyeX;
	double eyeY;
	double eyeZ;
	double origX;
	double origY;
	double origZ;
	int xCam;
	int yCam;
	int zCam;
};

