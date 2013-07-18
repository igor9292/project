#pragma once
#include "GObject.h"

class TVector: public GObject{
private:  
	int size;
	GObject **arr;
public:
	TVector(int sz);
	~TVector();
	GObject &operator [] (int i);
	//TVector &operator = (const TVector& a);
	void Resize(int delta);
	void Add(GObject& e);
	void setat(GObject* p, int pos);
	GObject *getObject(int pos);
	void show(int pos);
	void showAll();
	void deleteall();
	int getSize(void);
	int getCount(void);
   void mix(void);
private:
	void Plus(int delta);
	void Minus(int delta);

	
};


