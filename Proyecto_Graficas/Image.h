#pragma once
#include "addGlut.h"
#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include "auto_array.h"
//#include <SFML/Graphics.hpp>

//using namespace sf;

class Image :
	public PlaceableObject
{
public:

	Image(std::string path) : PlaceableObject()
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
		loadImage();
	}

	void draw(){
		glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, texture);
		glTranslatef(x, y, z - width / 2.0);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(8.0f, 0.0f, 0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(8.0f, 8.0f, 0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.0f, 8.0f, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}

private:
	std::string path;
	bool isLoaded;
	int width;
	int height;
	unsigned char *imagen;
	GLuint texture;

	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes)
	{
		return (int)(((unsigned char)bytes[3] << 24) |
			((unsigned char)bytes[2] << 16) |
			((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Converts a two-character array to a short, using little-endian form
	short toShort(const char* bytes)
	{
		return (short)(((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Reads the next four bytes as an integer, using little-endian form
	int readInt(ifstream &input)
	{
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	//Reads the next two bytes as a short, using little-endian form
	short readShort(ifstream &input)
	{
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}

	void loadImage(){
		if (isLoaded){
			free(imagen);
			isLoaded = false;
		}
		ifstream input;
		input.open(path.c_str(), ifstream::binary);

		assert(!input.fail() || !"Could not find file");
		char buffer[2];
		input.read(buffer, 2);
		assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
		input.ignore(8);
		int dataOffset = readInt(input);

		//Read the header
		int headerSize = readInt(input);
		switch (headerSize)
		{
		case 40:
			//V3
			width = readInt(input);
			height = readInt(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			width = readShort(input);
			height = readShort(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			break;
		case 64:
			//OS/2 V2
			assert(!"Can't load OS/2 V2 bitmaps");
			break;
		case 108:
			//Windows V4
			assert(!"Can't load Windows V4 bitmaps");
			break;
		case 124:
			//Windows V5
			assert(!"Can't load Windows V5 bitmaps");
			break;
		default:
			assert(!"Unknown bitmap format");
		}

		//Read the data
		int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
		int size = bytesPerRow * height;
		auto_array<char> pixels(new char[size]);
		input.seekg(dataOffset, ios_base::beg);
		input.read(pixels.get(), size);

		//Get the data into the right format
		auto_array<char> pixels2(new char[width * height * 3]);
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					pixels2[3 * (width * y + x) + c] =
						pixels[bytesPerRow * y + 3 * x + (2 - c)];
				}
			}
		}
		input.close();

		imagen = (unsigned char*)(pixels2.release());
		if (imagen != NULL){
			isLoaded = true;
		}
	}
	
	void loadTexture(){
		glBindTexture(GL_TEXTURE_2D, texture); //Tell OpenGL which texture to edit
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//Map the image to the texture
		glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
			0,                            //0 for now
			GL_RGB,                       //Format OpenGL uses for image
			width, height,  //Width and height
			0,                            //The border of the image
			GL_RGB, //GL_RGB, because pixels are stored in RGB format
			GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
			//as unsigned numbers
			imagen);               //The actual pixel data
	}
};

