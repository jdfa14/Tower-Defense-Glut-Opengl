#pragma once

#pragma comment(lib,"corona")

#include "Globals.h"
#include <iostream>
#include "corona.h"

class cTexture
{
public:
	cTexture(void);
	~cTexture(void);

	bool Load(std::string filename, int type = GL_RGBA, int wraps = GL_REPEAT, int wrapt = GL_REPEAT,
		int magf = GL_NEAREST, int minf = GL_NEAREST, bool mipmap = false);
	int  GetID();
	void GetSize(int *w, int *h);

private:
	GLuint id;
	int width, height;
};