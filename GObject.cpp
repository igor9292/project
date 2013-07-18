#include "StdAfx.h"
#include "GObject.h"
#include <cmath>

const float PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664;
const float alfa =PI/12;
GObject::GObject(int ix, int iy){
   x=ix;
   y=iy;
 }

GObject::~GObject(void)
{
	printf("GObject deleted\n");
}

void GObject::show() {
   printf("GObject: (%d;%d)",x,y);
   printf("\n");
 }

int GObject::getx() {
   return x;
 }

int GObject::gety() {
   return y;
 }

void GObject::setx(int ix) {
   x=ix;
 }

void GObject::sety(int iy) {
   y=iy;
 }

void GObject::rotate(int ix, int iy)
{
	/*
	float oldAngle, newAngle, r;
	printf("( ix = %d, iy = %d )\n",ix,iy);
	r = sqrt(pow(double(y-iy),2)+pow(double(x-ix),2));
	if(x!=ix)
	{
		oldAngle = atan((float)(y-iy)/(float)(x-ix)); 
		if(oldAngle<0) oldAngle+=PI;
		if(y<iy) oldAngle+=PI;
		if(y==iy && x<ix) oldAngle+=PI;
	}
	else
	{
		if(y>iy) oldAngle = PI/2;
		else oldAngle = (3*PI)/2;
	}
	newAngle = oldAngle + angle;
	*/
	//float alfa;
	float TCos;
	float TSin;
	TCos= cos(alfa);
	TSin= sin(alfa);
	printf("( x = %d, y = %d )\n",x,y);
	float x1;
	float y1;

	x1=x*TCos-y*TSin+ix;
	y1=x*TSin+y*TCos+iy;
	x=x1;
	y=y1;
	printf("( x = %d, y = %d )\n",x,y);
	//printf("oldAngle = %f, newAngle = %f \n",oldAngle*57.295779513, newAngle*57.295779513);
	//printf("%d \n",(int)(floor(r*cos(newAngle))));
	//printf("%d \n",(int)(floor(r*sin(newAngle))));
	//x = ix+(int)(floor(r*cos(newAngle)));
	//y = iy+(int)(floor(r*sin(newAngle)));
	
		
	
}
void GObject::shift(int ix,int iy){
	x=x+ix;
	y=y+iy;

}