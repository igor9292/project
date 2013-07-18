#pragma once
#include "gobject.h"
#include "TPoint.h"

class TLine :
	public GObject
{
protected: TPoint p1,p2;
public:
	TLine(int ix1=0, int iy1=0, int ix2=0, int iy2=0);
	~TLine(void);
	void setp1(int ix, int iy);
	void setp2(int ix, int iy);
	TPoint * TLine::getp1(void);
	TPoint * TLine::getp2(void);
	void showLine();
	friend bool operator ==(const TLine& left, const TLine& right);
};

