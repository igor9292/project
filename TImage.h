#pragma once
#include <fstream>
#include <string>
#include <math.h>

class TImage
{
    int w;
    int h;
    int grayscale;
    int *image;
    public:
        TImage();
		virtual ~TImage();
        void setPoint(int px, int py, int color);
        int getPoint(int px, int py);
        void load(char *file);
        void save(char *file);
        void filterSobel();
        void copy(TImage *p);
        friend bool operator==(const TImage& left, const TImage &right);
        TImage& operator=(TImage& i);
};

