#include "Rectangle.h"
#include <iostream>
#include <fstream>

using namespace std;

Rectangle::Rectangle(){
	
	Pos_x=0;
	Pos_y=0;
	
	Width=0;
	Height=0;
}
Rectangle::Rectangle(double width,double height,double pos_x,double pos_y){
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	Width=width;
	Height=height;
	
}
void Rectangle::draw(ofstream &outputfile)const{

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<Pos_x<<"\" y=\""<<Pos_y;
	outputfile<<"\" width=\""<<Width<<"\" height=\""<<Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
}

