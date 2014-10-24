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
		
	}

	void setPath(std::string path){
		this->path = path;
		reLoadImage();
	}

private:
	std::string path;
	int width;
	int height;
	bool isLoaded;
	GLuint imagen;

	void loadImage(){
		imagen = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
		isLoaded = (imagen != 0);
	}

	void reLoadImage(){
		imagen = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, imagen, SOIL_FLAG_DDS_LOAD_DIRECT);
		isLoaded = (imagen != 0);
	}
};

