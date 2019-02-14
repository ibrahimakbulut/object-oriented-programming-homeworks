#include "Circle.h"
#include <iostream>
#include <fstream>

using namespace std;

Circle::Circle(){
	
	Pos_x=0;
	Pos_y=0;
	
	radius_of_circle=0;
}
Circle::Circle(double radius,double pos_x,double pos_y){
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	radius_of_circle=radius;
}

void Circle::draw(ofstream &outputfile)const{
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<Pos_x<<"\" ";
	outputfile<<"cy=\""<<Pos_y<<"\""<<" r=\""<<radius_of_circle<<"\" ";
	outputfile<<" fill=\"red\"/>"<<endl;
	outputfile<<"</svg>";
}
