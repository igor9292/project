// ProjectOne.cpp: определяет точку входа для консольного приложения.
//
#include "StdAfx.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "GObject.h"
#include "TVector.h"
#include "TPoint.h"
#include "TRect.h"
#include "TLine.h"
#include "TImage.h"
#include <GL/glut.h>
#include <Windows.h>
//TVector recsq(100);
TVector figures(100);

  int lcount=0;
  int rcount=0;
TVector linesq(100);

float color[3] = {0, 0, 1};
float color1[3] = {1, 0, 0};
  TVector lin(100);
  TVector rec(100);
using namespace std;
void myshow(GObject* p){
   p->show();
} 

bool isEqPoint(TPoint &p1, TPoint &p2)
{
	if((p2.getx()==p1.getx()) && (p2.gety()==p1.gety()))
		return true;
	else
		return false;
}

bool isEqLines(TLine &l1, TLine &l2)
{
	if((   (l1.getp1()->getx()==l2.getp1()->getx()) && (l1.getp1()->gety()==l2.getp1()->gety()) && (l1.getp2()->getx()==l2.getp2()->getx()) && (l1.getp2()->gety()==l2.getp2()->gety())) 
		|| (l1.getp1()->getx()==l2.getp2()->getx()) && (l1.getp1()->gety()==l2.getp2()->gety()) && (l1.getp2()->getx()==l2.getp1()->getx()) && (l1.getp2()->gety()==l2.getp1()->gety())		)
		return true;
	else
		return false;
}

bool isEqQuad(TRect &r1, TRect &r2)
{
	if(   (isEqLines(*r1.getl1(),*r2.getl1()) && isEqLines(*r1.getl2(),*r2.getl2()) && isEqLines(*r1.getl3(),*r2.getl3()) && isEqLines(*r1.getl4(),*r2.getl4()))
		||(isEqLines(*r1.getl1(),*r2.getl2()) && isEqLines(*r1.getl2(),*r2.getl3()) && isEqLines(*r1.getl3(),*r2.getl4()) && isEqLines(*r1.getl4(),*r2.getl1()))
		||(isEqLines(*r1.getl1(),*r2.getl3()) && isEqLines(*r1.getl2(),*r2.getl4()) && isEqLines(*r1.getl3(),*r2.getl1()) && isEqLines(*r1.getl4(),*r2.getl2()))
		||(isEqLines(*r1.getl1(),*r2.getl4()) && isEqLines(*r1.getl2(),*r2.getl1()) && isEqLines(*r1.getl3(),*r2.getl2()) && isEqLines(*r1.getl4(),*r2.getl3()))
		||(isEqLines(*r1.getl1(),*r2.getl1()) && isEqLines(*r1.getl2(),*r2.getl4()) && isEqLines(*r1.getl3(),*r2.getl3()) && isEqLines(*r1.getl4(),*r2.getl2()))
		||(isEqLines(*r1.getl1(),*r2.getl3()) && isEqLines(*r1.getl2(),*r2.getl2()) && isEqLines(*r1.getl3(),*r2.getl1()) && isEqLines(*r1.getl4(),*r2.getl4())))
		return true;
	else
		return false;
}

void readLines(TVector *l, char *fileName, int *cnt)
{
	FILE *f;
	f = fopen(fileName,"r");

	int i=0;
	int k=0;
	int n[4];

	while(fscanf(f, "%d", &n[i]) != EOF){
		i++;
		if(i==4){
			i=0;
			(*l).setat(new TLine(n[0],n[1],n[2],n[3]),*cnt);
			(*cnt)++;
		}
		
	}

	fclose(f);
}

void initLines(TVector *p, int *icnt)
{
	*icnt = 0;
	readLines(p,"lines.txt",icnt);
}

void showLines(TVector *p, int lineCnt)
{
	for(int i=0; i<lineCnt; i++)
	{
		printf("Line %d: ", i+1);
		((TLine*)(p->getObject(i)))->showLine();

		printf("\n");
	}	
	
}

void showRect(TVector *p, int rCnt)
{
	for(int i=0; i<rCnt; i++)
	{
		printf("Rect %d: ", i+1);
		((TRect*)(p->getObject(i)))->showRect();

		printf("\n");
	}	
	
}

int isNormal (TLine *l1,TLine *l2)
{
 int i;
 int j;
 float k1;
 float k2;
 if (((*l1).getp2()->getx()==(*l1).getp1()->getx())||((*l2).getp2()->getx()==(*l2).getp1()->getx()))
 {
  if (((*l1).getp2()->getx()==(*l1).getp1()->getx())&&((*l2).getp2()->getx()==(*l2).getp1()->getx()))
  {
   return 0;
  }
  else if ((*l1).getp2()->getx()==(*l1).getp1()->getx())
  {
   k2= (((*l2).getp2()->gety()-(*l2).getp1()->gety())/((*l2).getp2()->getx()-(*l2).getp1()->getx()));
   if (k2==0)
   {
    return 1;
   }
   else 
    return 0;
  }
  else
  {
   k1= (((*l1).getp2()->gety()-(*l1).getp1()->gety())/((*l1).getp2()->getx()-(*l1).getp1()->getx()));
   if (k1==0)
   {
    return 1;
   }
   else
    return 0;
  }
 }
 else
 {
  k1= (((*l1).getp2()->gety()-(*l1).getp1()->gety())/((*l1).getp2()->getx()-(*l1).getp1()->getx()));
  k2= (((*l2).getp2()->gety()-(*l2).getp1()->gety())/((*l2).getp2()->getx()-(*l2).getp1()->getx()));
  if ((k1*k2)==-1)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
};

void addQuad(TLine *l1, TLine *l2,TLine *l3, TLine *l4, TVector *res, int *rcnt)
{
	if (isNormal(l1,l2) && isNormal(l2,l3) && isNormal (l3, l4)&& isNormal(l4,l1)){
		bool error=false;
		TRect *rect;
		rect=new TRect(l1,l2,l3,l4);
		for (int i=0;i<*rcnt;i++){
			if ((res->getObject(i))!=NULL)
			if (isEqQuad(*((TRect*)(res->getObject(i))),*rect)){
				error=true;
			}
		}
		if (error==false){

			res[*rcnt].setat(rect,*rcnt);
			(*rcnt)++;
		}
	}	
};

void calcRect(TVector *l, int lcnt, TVector *rect, int* rcnt){
	int i;
	int j;
	int n;
	int m;
	*rcnt=0;

	 for (int i=0;i<lcnt;i++){
		for (int j=0;j<lcnt;j++){
			if (isEqPoint(*(((TLine*)(l->getObject(i)) )->getp2()),*(((TLine*)(l->getObject(j)) )->getp1()))){
				for (int n=0;n<lcnt;n++){
					if (isEqPoint(*(((TLine*)(l->getObject(j)) )->getp2()),*(((TLine*)(l->getObject(n)) )->getp1()))){
						for (int m=0;m<lcnt;m++){
							if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp2()),*(((TLine*)(l->getObject(m)) )->getp1()))){
								if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp2()),*(((TLine*)(l->getObject(i)) )->getp1()))){
									addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
								}
							}
							else{
								if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp2()),*(((TLine*)(l->getObject(m)) )->getp2()))){
									if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp1()),*(((TLine*)(l->getObject(i)) )->getp1()))){
										addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
									}
								}
							}
						}
					}
					else{
						if (isEqPoint(*(((TLine*)(l->getObject(j)) )->getp2()),*(((TLine*)(l->getObject(n)) )->getp2()))){
							for (int m=0;m<lcnt;m++){
								if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp1()),*(((TLine*)(l->getObject(m)) )->getp1()))){
									if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp1()),*(((TLine*)(l->getObject(i)) )->getp1()))){
										addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
									}
								}
								else{
									if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp1()),*(((TLine*)(l->getObject(m)) )->getp2()))){
										if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp1()),*(((TLine*)(l->getObject(i)) )->getp1()))){
											addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
										}
									}
								}
							}
						}
					}
				}
			}
			else{
				if (isEqPoint(*(((TLine*)(l->getObject(i)) )->getp2()),*(((TLine*)(l->getObject(j)) )->getp2()))){
						for (int n=0;n<lcnt;n++){
							if (isEqPoint(*(((TLine*)(l->getObject(j)) )->getp1()),*(((TLine*)(l->getObject(n)) )->getp1()))){
								for (int m=0;m<lcnt;m++){
									if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp2()),*(((TLine*)(l->getObject(m)) )->getp1()))){
										if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp2()),*(((TLine*)(l->getObject(i)) )->getp1()))){
											 addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
										}
									}
									else{
										if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp2()),*(((TLine*)(l->getObject(m)) )->getp2()))){
											if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp1()),*(((TLine*)(l->getObject(i)) )->getp1()))){
												addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
											}
										}
									}
								}
							}
							else{
								if (isEqPoint(*(((TLine*)(l->getObject(j)) )->getp1()),*(((TLine*)(l->getObject(n)) )->getp2()))){
									for (int m=0;m<lcnt;m++){
										if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp1()),*(((TLine*)(l->getObject(m)) )->getp1()))){
											if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp2()),*(((TLine*)(l->getObject(i)) )->getp1()))){
												addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
											}
										}
										else{
											if (isEqPoint(*(((TLine*)(l->getObject(n)) )->getp1()),*(((TLine*)(l->getObject(m)) )->getp2()))){
												if (isEqPoint(*(((TLine*)(l->getObject(m)) )->getp1()),*(((TLine*)(l->getObject(i)) )->getp1()))){
													addQuad(((TLine*)(l->getObject(i))),((TLine*)(l->getObject(j)) ),((TLine*)(l->getObject(n)) ),((TLine*)(l->getObject(m)) ),rect, rcnt);
												}
											}
										}
									}
								}
							}
						}
				}
			}
		}
	}
}

void drawRectangle( GLfloat color[3], TVector *v,int rcount ) 
{
	
	for (int i=0; i<rcount; i++)
	{
	glBegin( GL_LINES );
	glColor3fv( color );
	
	glVertex2f( ((TRect*)(v->getObject(i)))->getl1()->getp1()->getx(), ((TRect*)(v->getObject(i)))->getl1()->getp1()->gety());
	glVertex2f( ((TRect*)(v->getObject(i)))->getl1()->getp2()->getx(), ((TRect*)(v->getObject(i)))->getl1()->getp2()->gety() );
	glEnd();
	glBegin( GL_LINES );
	glVertex2f( ((TRect*)(v->getObject(i)))->getl2()->getp1()->getx(), ((TRect*)(v->getObject(i)))->getl2()->getp1()->gety() );
	glVertex2f( ((TRect*)(v->getObject(i)))->getl2()->getp2()->getx(), ((TRect*)(v->getObject(i)))->getl2()->getp2()->gety() );
	glEnd();
	glBegin( GL_LINES );
	glVertex2f( ((TRect*)(v->getObject(i)))->getl3()->getp1()->getx(), ((TRect*)(v->getObject(i)))->getl3()->getp1()->gety() );
	glVertex2f( ((TRect*)(v->getObject(i)))->getl3()->getp2()->getx(), ((TRect*)(v->getObject(i)))->getl3()->getp2()->gety() );
	glEnd();
	glBegin( GL_LINES );
	glVertex2f( ((TRect*)(v->getObject(i)))->getl4()->getp1()->getx(), ((TRect*)(v->getObject(i)))->getl4()->getp1()->gety() );
	glVertex2f(((TRect*)(v->getObject(i)))->getl4()->getp2()->getx(), ((TRect*)(v->getObject(i)))->getl4()->getp2()->gety() );
	glEnd();
	}
}
 int hasLine(TVector * lines, TLine * l){
	for(int i=0; i<(lines->getCount()); i++)
		if(*((TLine*)(lines->getObject(i))) == *l) return 1;
	return 0;
}
void getLinesFromRecs(TVector *lines, TVector *rec){
	bool error=false;
	for(int i = 0; i < rec->getCount(); i++){
		for (int k = 0;k<4;k++){
			for (int l=0;l<lines->getCount();l++){
				if ((((TRect*)(rec->getObject(i)))->getLines(k))==((TLine*)(lines->getObject(l))))
					error=true;
			}
			if (error==false){

				lines->setat(((TRect*)(rec->getObject(i)))->getLines(k),lines->getCount());

			}
		}

	}
}

void recalc()
{	
	for(int i = 0; i < rec.getCount(); i++)
		((TRect*)(rec.getObject(i)))->rotate(10,10);

	linesq.deleteall();
	getLinesFromRecs(&linesq, &rec);
	linesq.mix();
	figures.deleteall();
	calcRect(&linesq,linesq.getCount(), &figures, &rcount);
	
	for(int i = 0; i < figures.getCount(); i++){
		((TRect*)figures.getObject(i))->getl1()->getp1()->shift(10,10);
		((TRect*)figures.getObject(i))->getl1()->getp2()->shift(10,10);
		((TRect*)figures.getObject(i))->getl2()->getp1()->shift(10,10);
		((TRect*)figures.getObject(i))->getl2()->getp2()->shift(10,10);
		((TRect*)figures.getObject(i))->getl3()->getp1()->shift(10,10);
		((TRect*)figures.getObject(i))->getl3()->getp2()->shift(10,10);
		((TRect*)figures.getObject(i))->getl4()->getp1()->shift(10,10);
		((TRect*)figures.getObject(i))->getl4()->getp2()->shift(10,10);

	}
	
}
void  display(void) 
 { 
 
 for(int i = 0; i < rec.getCount(); i++)
		((TRect*)(rec.getObject(i)))->rotate(0,0);
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (0.0, 0.0, 0.0); 
 drawRectangle(color,&rec ,rec.getCount());
 drawRectangle(color1,&figures ,figures.getCount());

	//float col2[3] = {1, 1, 1};
	//float col[3] = {0, 0.7, 1};
	/*
	for(int i = 0; i < recsq.getCount(); i++)
		drawRectangle((TRect*)(recsq.getObject(i)), col);
	
	for(int i = 0; i < figures.getCount(); i++)
		drawRectangle((TRect*)(figures.getCount()), col2);
		
	
	*/
 
 
 glutSwapBuffers();


 Sleep(300);
 recalc();
 glutPostRedisplay();
 
  glFinish (); 
  glutSwapBuffers();
 } 

//GLint viewport[4];
 void init () 
 {  
 glClearColor (1.0, 1.0, 1.0, 0.0); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 gluOrtho2D(-400,400,-400,400);
 //glLoadIdentity();
 //glGetIntegerv(GL_VIEWPORT,viewport);
 
 } 

 

int main(int argc, char** argv, GLfloat* color){

  //GObject c;
  //myshow(&c);
  //GObject *d;
  //d=new GObject(5,1);
  //myshow(d);
  //GObject *dead;
  //dead=new GObject(335,1);
  //delete d;
  //delete dead;
  

  initLines(&lin, &lcount);
  showLines(&lin, lcount);
  calcRect(&lin,lcount,&rec,&rcount);
  showRect(&rec, rcount);
  cout<<rec.getCount()<<endl;
   cout<<rec.getSize()<<endl;
  
  
  glutInit(&argc, argv); 
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Rectangle"); 
  glutDisplayFunc( display); 
  init (); 
  glutMainLoop(); 
  return 0;
  



  //v.setat(dead,2);
  //v.setat(d,3);
  //v.deleteall();
  //v.show(1);
  //v.showAll();
  
  /*
  while(1){
	  TVector p;
  }*/

/*
  TImage img;
  img.load("3.pgm");
  img.save("save.pgm");
  
  */
  getchar();
}
