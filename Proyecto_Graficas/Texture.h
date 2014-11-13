#pragma once

#pragma comment(lib,"corona")

#include "Globals.h"
#include <iostream>
#include "corona.h"

class Texture
{
private:
	GLuint tex_id;
	double x;
	double y;
	double z;
	double height;
	double width;
	double volume;
	double angleOfRotation;
	int rotX;
	int rotY;
	int rotZ;
	bool loaded;

	GLvoid *pixels;
	int imgW;
	int imgH;
	bool mipmap;
	int wraps;
	int wrapt;
	int type;
	int minf;
	int magf;
	int components;

public:
	Texture();

	bool load(std::string filename, int type = GL_RGBA, int wraps = GL_REPEAT, int wrapt = GL_REPEAT,
		int magf = GL_NEAREST, int minf = GL_NEAREST, bool mipmap = false); // this loads the image
	void draw();


	void setPositions(double x, double y, double z);
	void setSizes(double width, double height, double volume);
	void setRotation(double angleOfRotation, int X, int Y, int Z);
};

