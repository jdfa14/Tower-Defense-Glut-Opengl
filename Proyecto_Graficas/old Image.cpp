//#include "Image.h"
//
//bool Image::load(int type, int wraps, int wrapt, int magf, int minf, bool mipmap){
//	corona::Image* img;
//	int components;
//
//	img = corona::OpenImage(path.c_str());
//	if (!img){
//		std::cout << "Unable to load the image \n";
//	}
//
//	if (type == GL_RGB)
//	{
//		//img = corona::OpenImage(filename,corona::PF_R8G8B8);
//		components = 3;
//	}
//	else if (type == GL_RGBA)
//	{
//		//img = corona::OpenImage(filename,corona::PF_R8G8B8A8);
//		components = 4;
//	}
//	else return false;
//
//	if (img == NULL) return false;
//
//	int width = img->getWidth();
//	int height = img->getHeight();
//
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapt);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magf);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minf);
//
//	if (!mipmap)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, components, width, height, 0, type,
//			GL_UNSIGNED_BYTE, img->getPixels());
//	}
//	else
//	{
//		gluBuild2DMipmaps(GL_TEXTURE_2D, components, width, height, type,
//			GL_UNSIGNED_BYTE, img->getPixels());
//	}
//	loadList();//after a succeded load of texture, a loadList should be called
//	return true;
//}
//
//void Image::loadList(){
//	glList = glGenLists(1);
//	glNewList(glList, GL_COMPILE);
//		glTranslatef(x, y, z - volume / 2.0); // so x y and z will be the center
//		glRotated(angleOfRotation, rotX, rotY, rotZ);
//		glScalef(width, height, volume);
//		glBegin(GL_QUADS);
//		glVertex3f(-0.5f, -0.5f, 0.0f);
//		glVertex3f(0.5f, -0.5f, 0.0f);
//		glVertex3f(0.5f, 0.5f, 0.0f);
//		glVertex3f(-0.5f, 0.5f, 0.0f);
//		glEnd();
//	glEndList();
//	isLoaded = true;
//}
//
//void Image::draw()
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	glPushMatrix();
//	glTranslatef(x, y, z - volume / 2.0); // so x y and z will be the center
//	glRotated(angleOfRotation, rotX, rotY, rotZ);
//	glScalef(width, height, volume);
//	glBegin(GL_QUADS);
//	glVertex3f(-0.5f, -0.5f, 0.0f);
//	glTexCoord3f(0.0f, 0.0f, 0.0f);
//	glVertex3f(0.5f, -0.5f, 0.0f);
//	glTexCoord3f(1.0f, 0.0f, 0.0f);
//	glVertex3f(0.5f, 0.5f, 0.0f);
//	glTexCoord3f(1.0f, 1.0f, 0.0f);
//	glVertex3f(-0.5f, 0.5f, 0.0f);
//	glTexCoord3f(0.0f, 1.0f, 0.0f);
//	glEnd();
//	glPopMatrix();
//
//	glDisable(GL_TEXTURE_2D);
//}
//
