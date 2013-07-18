#pragma once
#include "GObject.h"
#include "TLine.h"

class TRect: public GObject {
protected: TLine l1,l2,l3,l4;
public:
    TRect(TLine *ln1=NULL,TLine *ln2=NULL,TLine* ln3=NULL,TLine* ln4=NULL);
	~TRect();
	TLine* TRect::getLines(int num);
	TLine* TRect::getl1(void);
	TLine* TRect::getl2(void);
	TLine* TRect::getl3(void);
	TLine* TRect::getl4(void);
    void showRect();
	virtual void rotate(int x, int y);
};


