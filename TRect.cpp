#include "StdAfx.h"
#include "TRect.h"
#include "TLine.h"


TRect::TRect(TLine *ln1,TLine *ln2,TLine* ln3,TLine* ln4){ 
	l1=*ln1;
	l2=*ln2;
	l3=*ln3;
	l4=*ln4;

}
void TRect::rotate(int x, int y)
{
	/*
	if(center)
	{
		x = (l1.getp1()->getx()+l1.getp2()->getx()+l3.getp1()->getx()+l3.getp2()->getx())/4;
		y = (l1.getp1()->gety()+l1.getp2()->gety()+l3.getp1()->gety()+l3.getp2()->gety())/4;
	}
	*/
	
	l1.getp1()->rotate(x, y);
	l1.getp2()->rotate(x, y);
	l2.getp1()->rotate(x, y);
	l2.getp2()->rotate(x, y);
	l3.getp1()->rotate(x, y);
	l3.getp2()->rotate(x, y);
	l4.getp1()->rotate(x, y);
	l4.getp2()->rotate(x, y);
	
}

TRect::~TRect(void){ 

}

TLine* TRect::getLines(int num){
	switch(num) {
	case 0:
		return &l1;
	case 1:
		return &l2;
	case 2:
		return &l3;
	case 3:	
		return &l4;
}
}
	TLine* TRect::getl1(void)
	{
	return &l1;
}

TLine* TRect::getl2(void){
	return &l2;
}

TLine* TRect::getl3(void){
	return &l3;
}

TLine* TRect::getl4(void){
	return &l4;
}

void TRect::showRect() {
		printf("   Rectangle: \n");
		l1.showLine();
		l2.showLine();
		l3.showLine();
		l4.showLine();

}
