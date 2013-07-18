#pragma once
class GObject{
    
protected: 
	int x,y;
public:
 GObject(int ix=1, int iy=1);
 ~GObject();
 virtual void show();
 int getx();
 int gety();
 void setx(int ix);
 void sety(int iy);
 void shift(int ix,int iy);
 virtual void rotate(int x, int y);
};

