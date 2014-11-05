/* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
/* File for "Textures" lesson of the OpenGL tutorial on
* www.videotutorialsrock.com
*/
/* Modified by Jesus De La Fuente Amaya on 10/25/2014
*  All rights are reserved
*/

#pragma once
#include "addGlut.h"
#include <fstream>
#include <string>
#include <assert.h>
#include "PlaceableObject.h"

//Just like auto_ptr, but for arrays
template<class T>
class auto_array
{
private:
	T* array;
	mutable bool isReleased;
public:
	explicit auto_array(T* array_ = NULL) :
		array(array_), isReleased(false)
	{
	}

	auto_array(const auto_array<T> &aarray)
	{
		array = aarray.array;
		isReleased = aarray.isReleased;
		aarray.isReleased = true;
	}

	~auto_array()
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
	}

	T* get() const
	{
		return array;
	}

	T &operator*() const
	{
		return *array;
	}

	void operator=(const auto_array<T> &aarray)
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
		array = aarray.array;
		isReleased = aarray.isReleased;
		aarray.isReleased = true;
	}

	T* operator->() const
	{
		return array;
	}

	T* release()
	{
		isReleased = true;
		return array;
	}

	void reset(T* array_ = NULL)
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
		array = array_;
	}

	T* operator+(int i)
	{
		return array + i;
	}

	T &operator[](int i)
	{
		return array[i];
	}
};

class Image 
{
public:

	Image(std::string path) : Image()
	{
		this->path = path;
		loadImage();
	}
	Image(){
		setPositions(0, 0, 0);
		setSizes(1, 1, 1);
		setRotation(0, 0, 0, 1);
		wrap = GL_REPEAT;
		filter = GL_LINEAR;
		isLoaded = false;
	}

	~Image()
	{
		free(imagen);
	}

	void setPath(std::string path){
		this->path = path;
		loadImage();
	}

	void setPositions(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void setSizes(double width, double height, double volume){
		this->height = height;
		this->width = width;
		this->volume = volume;
	}

	//image sets
	void setFilter(GLint filter){ this->filter = filter; }
	void setWrap(GLint wrap){ this->wrap = wrap; }
	void setRotation(double angleOfRotation, int X, int Y, int Z){
		this->angleOfRotation = angleOfRotation;
		rotX = X;
		rotY = Y;
		rotZ = Z;
	}

	void draw2D(){
		if (isLoaded){
			//glEnable(GL_NORMALIZE);
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, texture);//texture to apply next changes
			//S T U = X Y Z
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);// rellenar vacios
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);// rellenar vacios

			glTexImage2D(GL_TEXTURE_2D,     //Always GL_TEXTURE_2D
				0,                          //0 for now
				GL_RGB,                     //Format OpenGL uses for image
				widthImg, heightImg,		//Width and height
				0,                          //The border of the image
				GL_RGB,						//GL_RGB, because pixels are stored in RGB format
				GL_UNSIGNED_BYTE,			//GL_UNSIGNED_BYTE, because pixels are stored
				//as unsigned numbers
				imagen);

			glPushMatrix();
			glTranslatef(x, y, z - volume / 2.0); // so x y and z will be the center
			glRotated(angleOfRotation, rotX, rotY, rotZ);
			glScalef(width , height , volume);
			glBegin(GL_QUADS);
			//0 0
			//X 0
			glTexCoord3f(0.0f, 0.0f,0.0f);
			glVertex3f(-0.5f, -0.5f, 0.0f);
			
			//0 0
			//0 X
			glTexCoord3f(1.0f, 0.0f,0.0f);
			glVertex3f(0.5f, -0.5f, 0.0f);
			
			//0 X
			//0 0
			glTexCoord3f(1.0f, 1.0f,0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			
			//X 0
			//0 0
			glTexCoord3f(0.0f, 1.0f,0.0f);
			glVertex3f(-0.5f, 0.5f, 0.0f);
			glEnd();
			
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		}
	}

private:
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

	std::string path;
	bool isLoaded;
	int widthImg;
	int heightImg;
	unsigned char *imagen;

	GLuint texture;
	GLint wrap;
	GLint filter;

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
	int readInt(std::ifstream &input)
	{
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	//Reads the next two bytes as a short, using little-endian form
	short readShort(std::ifstream &input)
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

		std::ifstream input;
		input.open(path.c_str(), std::ifstream::binary);
		//assert(!input.fail() || !"Could not find file");
		if (input.fail())
		{
			std::cout << "Could not load the file: \n" << path << std::endl;
			return;
		}

		char buffer[2];
		input.read(buffer, 2);
		//assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
		if (!(buffer[0] == 'B' && buffer[1] == 'M'))
		{
			std::cout << "The file at \n:" << path << "\nis not a bitmap file " << std::endl;
			return;
		}
		
		input.ignore(8);
		int dataOffset = readInt(input);

		//Read the header
		int headerSize = readInt(input);
		switch (headerSize)
		{
		case 40:
			//V3
			widthImg = readInt(input);
			heightImg = readInt(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			widthImg = readShort(input);
			heightImg = readShort(input);
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
		int bytesPerRow = ((widthImg * 3 + 3) / 4) * 4 - (widthImg * 3 % 4);
		int size = bytesPerRow * heightImg;
		auto_array<char> pixels(new char[size]);
		input.seekg(dataOffset, std::ios_base::beg);
		input.read(pixels.get(), size);

		//Get the data into the right format
		auto_array<char> pixels2(new char[widthImg * heightImg * 3]);
		for (int y = 0; y < heightImg; y++)
		{
			for (int x = 0; x < widthImg; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					pixels2[3 * (widthImg * y + x) + c] =
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
};