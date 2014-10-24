#pragma once
#include "addGlut.h"
#include <iostream>
#include <string>
#include "SoilSrc\SOIL.h"
class Image
{
public:

	Image(std::string path)
	{
		this->path = path;
		loadImage();
	}

	~Image()
	{
		free(imagen);
	}

	void setPath(std::string path){
		this->path = path;
		reLoadImage();
	}

private:
	std::string path;
	int width;
	int height;
	int channels;
	bool isLoaded;
	unsigned char *imagen;

	void loadImage(){
		imagen = SOIL_load_image(path.c_str(), &width, &height, &channels)
		isLoaded = (imagen != NULL);
	}

	void reLoadImage(){
		imagen = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, imagen, SOIL_FLAG_DDS_LOAD_DIRECT);
		isLoaded = (imagen != 0);
	}
};

