#include "StdAfx.h"
#include "TImage.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

TImage::TImage()
{
    w=0;
    h=0;
    grayscale=0;
    image=0;
}


TImage::~TImage()
{

}

void TImage::load(char *file){
    string vers;
	string comm;
    int i=0;
    ifstream inFile;
    inFile.open(file);
	getline(inFile, vers);
    cout << vers << endl;
    getline(inFile, comm);
    cout << comm << endl;
	inFile >> w;
    inFile >> h;
    cout << w <<endl; 
	cout<< h << endl;
    int res=w*h;
    image = new int[res];
    inFile >> grayscale;
    while((inFile >> image[i]) && (i<res)){
	        i++;
	};
    inFile.close();  
	
	/*
	i=0;
	while(i<res){
		for (int j=0;j<w;j++){
			cout << image[i] << " ";
			i++;
		}
		printf("\n");
	}
	*/

	//for(i=0;i<res;i++)
	//	cout<<image[i] << endl;
}

void TImage::setPoint(int px, int py, int color){
    int p=w*(py-1)+px-1;
    image[p]=color;
}

int TImage::getPoint(int px, int py){
    if(px<1)
        px=1;
    if(py<1)
        py=1;
    if(px>w)
        px=w;
    if(py>h)
        py=h;
    int p=w*(py-1)+px-1;
    //cout << p << endl;
    return image[p];
}

void TImage::save(char *file){
    int i=0;
    int res=w*h;
	string comm="Comment";
    ofstream outFile;
    outFile.open(file);
    outFile << "Vers\n" << comm << "\n" << w << " " << h << "\n" << grayscale << "\n";
    while(i<res){
		for (int j=0;j<w;j++){
			outFile << image[i] << " ";
			i++;
		}
		outFile<<endl;
        
    }
    outFile.close();
}

void TImage::filterSobel(){
    int n[3][3];
    int Gx;
    int Gy;
    int G;
	int Wx[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	int Wy[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	int *buff;
	buff=new int[(w*h)];
	for(int y=1;y<=h;y++)
	{
		for(int x=1;x<=w;x++)
		{
			n[0][0]=getPoint(x-1,y-1);
			n[0][1]=getPoint(x,y-1);
			n[0][2]=getPoint(x+1,y-1);
			n[1][0]=getPoint(x-1,y);
			n[1][1]=getPoint(x,y);
			n[1][2]=getPoint(x+1,y);
			n[2][0]=getPoint(x-1,y+1);
			n[2][1]=getPoint(x,y+1);
			n[2][2]=getPoint(x+1,y+1);
			Gx=0;
			Gy=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
				{
					Gx+=Wx[i][j]*n[i][j];
					Gy+=Wy[i][j]*n[i][j];
				}
			G=sqrt(double((Gx*Gx)+(Gy*Gy)));
			if(G>grayscale)
                G=grayscale;
			buff[(y-1)*w+x-1]=G;
		}
	}
	for(int y=1;y<=h;y++)
		for(int x=1;x<=w;x++)
			image[(y-1)*w+x-1]=buff[(y-1)*w+x-1];
}

void TImage::copy(TImage *p)
{
	p->w=w;
	p->h=h;
	p->image = new int[(w*h)];
	for(int i=0;i<w*h;i++)
		p->image[i]=image[i];
	p->grayscale=grayscale;
}

bool operator==(const TImage& left, const TImage &right){
    bool flag;
	if(left.w!=right.w || left.h!=right.h){
        return 0;
    }else{
        for(int i=0;i<(left.w*left.h);i++){
            if(left.image[i]!=right.image[i]){
                return 0;
				flag=true;
            };
        };
		if (flag=false)
			return 1;
        
    };
}

TImage& TImage::operator=(TImage& y)
{
	w=y.w;
	h=y.h;
	image = new int[(w*h)];
	for(int i=0;i<w*h;i++)
		image[i]=y.image[i];
	grayscale=y.grayscale;
	return *this;
}

