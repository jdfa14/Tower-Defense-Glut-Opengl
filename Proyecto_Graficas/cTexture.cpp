#include "cTexture.h"

cTexture::cTexture(void)
{
}

cTexture::~cTexture(void)
{
}

bool cTexture::Load(std::string filename, int type, int wraps, int wrapt, int magf, int minf, bool mipmap)
{
	corona::Image* img;
	int components;

	img = corona::OpenImage(filename.c_str());
	if (type == GL_RGB)
	{
		//img = corona::OpenImage(filename,corona::PF_R8G8B8);
		components = 3;
	}
	else if (type == GL_RGBA)
	{
		//img = corona::OpenImage(filename,corona::PF_R8G8B8A8);
		components = 4;
	}
	else return false;

	if (img == NULL){
		std::cout << "Unable to load image: " << filename << std::endl;
		return false;
	}

	width = img->getWidth();
	height = img->getHeight();

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapt);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magf);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minf);

	if (!mipmap)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, components, width, height, 0, type, GL_UNSIGNED_BYTE, img->getPixels());
	}
	else
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, components, width, height, type, GL_UNSIGNED_BYTE, img->getPixels());
	}

	if (id == 0){
		std::cout << glGetError() << "\n\n";
	}

	return true;
}

int cTexture::GetID()
{
	return id;
}
void cTexture::GetSize(int *w, int *h)
{
	*w = width;
	*h = height;
}