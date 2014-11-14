#include "Mobile.h"

Mobile::Mobile() : PlaceableObject(){
	accelerating = false;
	turning = false;
	setMaxSpeed(1);
	setInitialSpeeds(0, 0);
	setAccelerations(0, 0);
	actualSpeed = 0;
	timeSinceLastTime = 0;
	direction = 0;
}

void Mobile::draw(int tex_id){
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glPushMatrix();
			glTranslated(x, y, z);
			glRotated(direction + 90, 0, 0, 1);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);	glVertex3i(- width / 2.0,   height / 2.0, -1);
				glTexCoord2f(1, 0);	glVertex3i(  width / 2.0,   height / 2.0, -1);
				glTexCoord2f(1, 1);	glVertex3i(  width / 2.0, - height / 2.0, -1);
				glTexCoord2f(0, 1);	glVertex3i(- width / 2.0, - height / 2.0, -1);
			glEnd();
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Mobile::setInitialSpeeds(double speedX, double speedY){
	this->speedX = speedX;
	this->speedY = speedY;
	actualSpeed = speedX * speedX + speedY * speedY;
}

void Mobile::setAccelerations(double accX, double accY){
	this->accX = accX;
	this->accY = accY;
	acc = accX * accX + accY * accY;
	accelerating = true;
}


void Mobile::setMaxSpeed(double maxSpeed){
	this->maxSpeed = maxSpeed * maxSpeed;
}

void Mobile::update(double timeInMiliSec){
	if (timeSinceLastTime == 0){
		timeSinceLastTime = timeInMiliSec;
	}
	double t = (timeInMiliSec - timeSinceLastTime) / 100.0;
	double xAux;
	double yAux;
	double ratio;
	double angleAux;

	speedX += accX * t; // vf = vo + a * t
	speedY += accY * t;

	xAux = speedX * speedX;
	yAux = speedY * speedY;

	actualSpeed = xAux + yAux;

	if (actualSpeed > maxSpeed){
		//accelerating = false;
		ratio = sqrt(maxSpeed / actualSpeed);
		speedX *= ratio;
		speedY *= ratio;
		actualSpeed = maxSpeed;
	}

	direction = speedX >= 0 ? asin(speedY / sqrt(actualSpeed)) * RAD_DEG : 180 + asin(speedY / sqrt(actualSpeed)) * RAD_DEG;

	x += speedX * t;
	y += speedY * t;
	timeSinceLastTime = timeInMiliSec;
}