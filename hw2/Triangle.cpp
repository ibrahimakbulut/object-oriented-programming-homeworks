//Triangle.cpp
#include "Triangle.h"
#include <iostream>
#include <fstream>

using namespace std;

Triangle::Triangle(){
	
	point1_pos_x=0;
	point1_pos_y=0;
		
	point2_pos_x=0;
	point2_pos_y=0;
		
	point3_pos_x=0;
	point3_pos_y=0;
		
	lenght_of_Triangle=0;
		
}
Triangle::Triangle(double lenght_of_triangle,double pos1_x,double pos1_y,double pos2_x,double pos2_y,double pos3_x,double pos3_y){
	
	point1_pos_x=pos1_x;
	point1_pos_y=pos1_y;
		
	point2_pos_x=pos2_x;
	point2_pos_y=pos2_y;
		
	point3_pos_x=pos3_x;
	point3_pos_y=pos3_y;
		
	lenght_of_Triangle=lenght_of_triangle;
	
	
}
void Triangle::draw(ofstream &outputfile)const{
	
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<point1_pos_x<<","<<point1_pos_y;
	outputfile<<" "<<point2_pos_x<<" ,"<<point2_pos_y;
	outputfile<<" "<<point3_pos_x<<" ,"<<point3_pos_y<<"\"";
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
}

