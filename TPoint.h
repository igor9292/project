#pragma once
#include "GObject.h"

class TPoint: public GObject {
	public:
		
		TPoint(int ix=0,int iy=0);
		~TPoint();
		void setPoint(int ix, int iy);
	friend bool operator==(const TPoint& left, const TPoint& right){ 
		if((left.x==right.x) && (left.y==right.y))   
			return true;
		else
			return false;
	}
	TPoint &operator=(const TPoint& a){ 
		x=a.x;
		y=a.y;
		return *this;
	}

};

