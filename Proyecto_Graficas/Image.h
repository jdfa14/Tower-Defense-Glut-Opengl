#pragma once
#include "addGlut.h"
#include <iostream>
#include <string>
class Image
{
public:

	Image(std::string path)
	{
		imagen = SOIL_load	
	}

	~Image()
	{
		free(imagen);
	}
private:
	std::string path;
	int width;
	int height;
	unsigned char* imagen;
};

