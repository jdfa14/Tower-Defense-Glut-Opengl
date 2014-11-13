#include "Texture.h"

Texture::Texture()
{
	setSizes(200, 200, 1);
	setPositions(0, 0, 0);
}

bool Texture::load(std::string filename, int type, int wraps, int wrapt, int magf, int minf, bool mipmap)
{
	loaded = false;
	tex_id = 0;

	corona::Image* img;

	img = corona::OpenImage(filename.c_str());
	if (!img){
		std::cout << "Unable to load image at path " << filename << std::endl;
		return false;
	}

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

	if (img == NULL) return false;

	imgW = img->getWidth();
	imgH = img->getHeight();
	pixels = img->getPixels();
	this->mipmap = mipmap;
	this->wraps = wraps;
	this->wrapt = wrapt;
	this->type = type;
	this->minf = minf;
	this->magf = magf;
	

	//glGenTextures(1, &tex_id);
	/*glBindTexture(GL_TEXTURE_2D, tex_id);

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
	}*/

	loaded = true;

	return true;
}

void Texture::draw(){
	if (loaded){
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapt);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magf);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minf);

		if (!mipmap)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, components, imgW, imgH, 0, type, GL_UNSIGNED_BYTE,pixels);
		}
		else
		{
			gluBuild2DMipmaps(GL_TEXTURE_2D, components, imgH, imgH, type, GL_UNSIGNED_BYTE, pixels);
		}

		glPushMatrix();
		glTranslatef(x, y, z - volume / 2.0); // so x y and z will be the center
		glRotated(angleOfRotation, rotX, rotY, rotZ);
		glScalef(width, height, volume);

		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);	glVertex3f(-0.5f, -0.5f, 0.0f);
		glTexCoord2f(1, 0);	glVertex3f(0.5f, -0.5f, 0.0f);
		glTexCoord2f(1, 1);	glVertex3f(0.5f, 0.5f, 0.0f);
		glTexCoord2f(0, 1);	glVertex3f(-0.5f, 0.5f, 0.0f);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

	}
}

void Texture::setPositions(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Texture::setSizes(double width, double height, double volume){
	this->height = height;
	this->width = width;
	this->volume = volume;
}

void Texture::setRotation(double angleOfRotation, int X, int Y, int Z){
	this->angleOfRotation = angleOfRotation;
	rotX = X;
	rotY = Y;
	rotZ = Z;
}