#include "StdAfx.h"
#include "TPoint.h"
#include "GObject.h"


TPoint::TPoint(int ix,int iy){
	x=ix;
    y=iy;
};


TPoint::~TPoint(void)
{
}

void TPoint::setPoint(int ix, int iy){
	x=ix;
	y=iy;
}

