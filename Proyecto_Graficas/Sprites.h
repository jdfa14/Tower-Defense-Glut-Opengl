#include "imageloader.h"
class Sprites {
	Vector<Images> vectorImagenes;
	double tiempoTransicion;
	int cantSprites;
	static GLuint texName[90];
	
	public:
	Sprites();
	void setPositions(double, double, double);
	void setSizes(double, double, double);
	bool addSprites(string, int);
	bool deleteSprites();
	void draw(double);
};
Sprites::Sprites() {

}
void Sprites::setPositions(double x, double y, double z) {

}
void Sprites::setSizes(double x, double y, double y) {
}
bool Sprites::addSprites(string path, int i) {

   glBindTexture(GL_TEXTURE_2D, texName[k]); //Tell OpenGL which texture to edit
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,                 //Always GL_TEXTURE_2D
                 0,                             //0 for now
                 GL_RGB,                        //Format OpenGL uses for image
                 image->width, image->height,   //Width and height
                 0,                             //The border of the image
                 GL_RGB,                        //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE,              //GL_UNSIGNED_BYTE, because pixels are stored
                                                //as unsigned numbers
                 image->pixels);                //The actual pixel data
	
	
	
	
	return true;
}
bool Sprites::deleteSprites() {
	
	return true;
}
void Sprites::draw(double tiempoTranscurrido) {

}