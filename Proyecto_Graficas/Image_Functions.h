#pragma once
#include <GL\glut.h>
#include <fstream>

GLuint LoadTexture(const char * filename, int width, int height)
{
	FILE * file;
	GLuint texture;
	unsigned char * byte;//byte

	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	byte = (unsigned char *)malloc(width * height * 3);
	fread(byte, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = byte[index];
		R = byte[index + 2];

		byte[index] = R;
		byte[index + 2] = B;

	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, byte);
	free(byte);
	return texture;
}