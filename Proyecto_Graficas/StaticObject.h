#pragma once
#include "Texture.h"
#include "PlaceableObject.h"
class StaticObject :
	public PlaceableObject
{
public:

	StaticObject() : PlaceableObject()
	{
	}

	void setImagePath(std::string imagePath){
	}

	void setPositions(double x, double y, double z){
		PlaceableObject::setPositions(x, y, z);
	}

	void setSizes(double width, double height, double volume){
		PlaceableObject::setSizes(width, height, volume);
	}

	void drawText(int tex_id){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);	glVertex3i(x - width / 2.0, y + height / 2.0, -1);
			glTexCoord2f(1, 0);	glVertex3i(x + width / 2.0, y + height / 2.0, -1);
			glTexCoord2f(1, 1);	glVertex3i(x + width / 2.0, y - height / 2.0, -1);
			glTexCoord2f(0, 1);	glVertex3i(x - width / 2.0, y - height / 2.0, -1);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}
protected:
};

