#pragma once

#pragma comment(lib,"corona")

#include "Globals.h"
#include "corona.h"

class Texture
{
public:
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


	Texture();

	bool load(char *filename, int type = GL_RGBA, int wraps = GL_REPEAT, int wrapt = GL_REPEAT,
		int magf = GL_NEAREST, int minf = GL_NEAREST, bool mipmap = false); // this loads the image
	void draw();

	void setPositions(double x, double y, double z);
	void setSizes(double width, double height, double volume);
	void setRotation(double angleOfRotation, int X, int Y, int Z);
};