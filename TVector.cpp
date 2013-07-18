#include "StdAfx.h"
#include <iostream>
#include "TVector.h"
#include "GObject.h"

TVector::TVector(int sz){
	size=sz;

	//if (size<0){
	//	throw "TVector constructor: Negative arr size";
	//}
	arr = (GObject**)malloc(sizeof(GObject*)*size);
	//GObject **arr=new GObject*[size];
	for (int i=0;i<size; i++){
		arr[i]=NULL;
	}
}

TVector::~TVector(){
	deleteall();
}

GObject &TVector::operator[](int i){
	if (i<0||i>=size){
		throw "operator []: Arr index is out of range";
	}
	return *arr[i];
}

/*TVector& TVector::operator=(const TVector&a){
	Resize(a.size-size);
	for (int i=0;i<size;i++)
		arr[i]=a.arr[i];
	return *this;
}*/

void TVector::Resize(int delta){
	if (delta>0)
		Plus(delta);
	else if (delta<0)
		Minus(-delta);
}

void TVector::Add(GObject&e){
	Resize(1);
	*arr[size-1]=e;
}

void TVector::Plus(int delta){
		//GObject **newArr=new GObject*[size+delta];
		GObject **newArr;
		//size=100;
		newArr = (GObject**)malloc(sizeof(GObject*)*size);
		for (int i=0;i<size;i++){
			newArr[i]=arr[i];
		}
		size+=delta;
		arr=newArr;
	}

void TVector::Minus(int delta){
	size=(delta>size?0:size-delta);

}


void TVector::setat(GObject* p, int pos){
	if (pos<size){
		arr[pos]=p;
	}
	else{
		Plus(pos-size+1);
		arr[pos]=p;
	}
  }

GObject* TVector::getObject(int pos){
    return arr[pos];
 }

void TVector::show(int pos)
{
	if(arr[pos]!=NULL) {
		printf("[%d] ",pos);
		arr[pos]->show();
		//(*object).setx(arr[pos]->getx());
		//(*object).sety(arr[pos]->gety());
		//GObject::show(object);
        printf("\n");
      }
	else 
		printf("[%d] is empty\n",pos);
}

void TVector::showAll() {
    for (int i=0;i<size;i++) {
      if(arr[i]!=NULL) {
		printf("[%d] ",i);
        arr[i]->show();
        printf("\n");
      }
      else {
        printf("[%d] is empty\n",i);
      }
    }
}

void TVector::deleteall(){
	//delete[] arr;
	//printf("Vector deleted\n");
	for(int i=0; i<size; i++)
		if(arr[i]!=NULL) {
			arr[i] = NULL;
		}
	//size = 0;

}

int TVector::getSize(void){
	return size;
}

int TVector::getCount(void){
	int count=0;
	for (int i=0;i<size;i++) {
      if(arr[i]!=NULL) 
		count++;
      }
	return count;
}
void TVector::mix(void){
		int count=0;
			for (int i=0;i<size;i++) {
			if(arr[i]!=NULL) 
			count++;
			}
	
		for (size_t i = 0; i < size; i ++) 
		{
			if (arr[i]!=NULL)
		std::swap(arr[i], arr[rand() % count]);
	}
		/*
		bool error=false;
		int *massCifr;
		massCifr=(int*)malloc(sizeof(int)*100);
		GObject **newArr;
		newArr = (GObject**)malloc(sizeof(GObject*)*size);
		for (int i=0;i<size;i++){
			num=rand() % (size);
			for (int j=0;j<i;j++){
				if (massCifr[j]==num) error=true;
			}
			if (error=false){
				newArr[i]=arr[num];
				massCifr[i]=num;
			}
		}
		arr=newArr;
		*/
}
