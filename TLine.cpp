#include "StdAfx.h"
#include "TLine.h"
#include "TPoint.h"
#include <iostream> 


TLine::TLine(int ix1, int iy1, int ix2, int iy2)
{
	p1.setPoint(ix1, iy1);
	p2.setPoint(ix2, iy2);
}

TLine::~TLine(void)
{
}


void TLine::setp1(int ix, int iy)
{
	p1.setPoint(ix, iy);
}

void TLine::setp2(int ix, int iy)
{
	p2.setPoint(ix, iy);
}

TPoint* TLine::getp1(void){
	return &p1;
}

TPoint* TLine::getp2(void){
	return &p2;
}

void TLine::showLine()
{
	printf("( (%d,%d);(%d,%d) )\n",p1.getx(),p1.gety(),p2.getx(),p2.gety());
}
bool operator==(const TLine& left, const TLine& right) {

	int lx1 = ((TPoint*)((TLine)left).getp1())->getx();
	int ly1 = ((TPoint*)((TLine)left).getp1())->gety();
	int lx2 = ((TPoint*)((TLine)left).getp2())->getx();
	int ly2 = ((TPoint*)((TLine)left).getp2())->gety();
	int rx1 = ((TPoint*)((TLine)right).getp1())->getx();
	int ry1 = ((TPoint*)((TLine)right).getp1())->gety();
	int rx2 = ((TPoint*)((TLine)right).getp2())->getx();
	int ry2 = ((TPoint*)((TLine)right).getp2())->gety();

	//printf("(%d %d %d %d) - (%d %d %d %d)\n",lx1,ly1,lx2,ly2,rx1,ry1,rx2,ry2);

	if( (lx1==rx1) && (ly1==ry1) && (lx2==rx2) && (ly2==ry2))
		return 1;
	else
		return 0;
}