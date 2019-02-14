//Triangle.cpp
#include "Triangle.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Triangle::Triangle(){ //No parameter constructor
	
	point1_pos_x=0;
	point1_pos_y=0;
		
	point2_pos_x=0;
	point2_pos_y=0;
		
	point3_pos_x=0;
	point3_pos_y=0;
		
	lenght_of_Triangle=0;
	total_area+=getter_area();  //this calculation 0 because it has no size all size are 0.
	total_perimeter+=getter_perimeter_lenght();
}
//constructor with parameters
Triangle::Triangle(double lenght_of_triangle){
	lenght_of_Triangle=lenght_of_triangle;

	point1_pos_x=lenght_of_Triangle/2;
	point1_pos_y=0;
		
	point2_pos_x=0;
	point2_pos_y=lenght_of_Triangle*sqrt(3.0)/2;
		
	point3_pos_x=lenght_of_Triangle;
	point3_pos_y=lenght_of_Triangle*sqrt(3.0)/2;
	total_area+=getter_area();
	total_perimeter+=getter_perimeter_lenght();

}
Triangle::Triangle(double lenght_of_triangle,double pos1_x,double pos1_y,double pos2_x,double pos2_y,double pos3_x,double pos3_y){
	
	point1_pos_x=pos1_x;
	point1_pos_y=pos1_y;
		
	point2_pos_x=pos2_x;
	point2_pos_y=pos2_y;
		
	point3_pos_x=pos3_x;
	point3_pos_y=pos3_y;
		
	lenght_of_Triangle=lenght_of_triangle;
	total_area+=getter_area();	
	total_perimeter+=getter_perimeter_lenght();
}
Triangle Triangle::operator ++(int){
	double temp_point1_pos_x=point1_pos_x;
	double temp_point1_pos_y=point1_pos_y;

	double temp_point2_pos_x=point2_pos_x;
	double temp_point2_pos_y=point2_pos_y;

	double temp_point3_pos_x=point3_pos_x;
	double temp_point3_pos_y=point3_pos_y;

	point1_pos_x+=1.0;
	point1_pos_y+=1.0;

	point2_pos_x+=1.0;
	point2_pos_y+=1.0;

	point3_pos_x+=1.0;
	point3_pos_y+=1.0;

	return Triangle(lenght_of_Triangle,temp_point1_pos_x,temp_point1_pos_y,temp_point2_pos_x,temp_point2_pos_y,temp_point3_pos_x,temp_point3_pos_y);
}
Triangle Triangle::operator ++(){
	point1_pos_x+=1.0;
	point1_pos_y+=1.0;

	point2_pos_x+=1.0;
	point2_pos_y+=1.0;

	point3_pos_x+=1.0;
	point3_pos_y+=1.0;
	return Triangle(lenght_of_Triangle,point1_pos_x,point1_pos_y,point2_pos_x,point2_pos_y,point3_pos_x,point3_pos_y);
}
Triangle Triangle::operator --(int){
	double temp_point1_pos_x=point1_pos_x;
	double temp_point1_pos_y=point1_pos_y;

	double temp_point2_pos_x=point2_pos_x;
	double temp_point2_pos_y=point2_pos_y;

	double temp_point3_pos_x=point3_pos_x;
	double temp_point3_pos_y=point3_pos_y;

	point1_pos_x-=1.0;
	point1_pos_y-=1.0;

	point2_pos_x-=1.0;
	point2_pos_y-=1.0;

	point3_pos_x-=1.0;
	point3_pos_y-=1.0;

	return Triangle(lenght_of_Triangle,temp_point1_pos_x,temp_point1_pos_y,temp_point2_pos_x,temp_point2_pos_y,temp_point3_pos_x,temp_point3_pos_y);
}
Triangle Triangle::operator --(){
	point1_pos_x-=1.0;
	point1_pos_y-=1.0;

	point2_pos_x-=1.0;
	point2_pos_y-=1.0;

	point3_pos_x-=1.0;
	point3_pos_y-=1.0;
	return Triangle(lenght_of_Triangle,point1_pos_x,point1_pos_y,point2_pos_x,point2_pos_y,point3_pos_x,point3_pos_y);
}

double Triangle::getter_area()const{
	return ((pow(lenght_of_Triangle,2.0)*sqrt(3.0))/4.0);
}
double Triangle::getter_perimeter_lenght()const{
	if(lenght_of_Triangle<0){
		return -3*lenght_of_Triangle;
	}
	return 3*lenght_of_Triangle;
}
bool Triangle::operator ==(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a==b);
}
bool Triangle::operator !=(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a!=b);
}
bool Triangle::operator <(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<b);
}
bool Triangle::operator >(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>b);
}
bool Triangle::operator >=(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>=b);
}
bool Triangle::operator <=(const Triangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<=b);
}
 const Triangle Triangle::operator +(double adding_size)const{
	return Triangle(lenght_of_Triangle+adding_size);
}
 const Triangle operator +(double adding_size,const Triangle& shape){
 	return Triangle(shape.lenght_of_Triangle+adding_size);
 }
 const Triangle Triangle::operator -(double adding_size)const{
	return Triangle(lenght_of_Triangle-adding_size);
}
const Triangle operator -(double adding_size,const Triangle& shape){
	return Triangle(adding_size-shape.lenght_of_Triangle);
}
ofstream& operator <<(ofstream& outputfile,const Triangle& shape){
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<shape.point1_pos_x<<","<<shape.point1_pos_y;
	outputfile<<" "<<shape.point2_pos_x<<" ,"<<shape.point2_pos_y;
	outputfile<<" "<<shape.point3_pos_x<<" ,"<<shape.point3_pos_y<<"\"";
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const Triangle& shape){
	cout<<"point1: "<<shape.point1_pos_x<<" , "<<shape.point1_pos_y<<"   ";
	cout<<"point2: "<<shape.point2_pos_x<<" , "<<shape.point2_pos_y<<"   ";
	cout<<"point3: "<<shape.point3_pos_x<<" , "<<shape.point3_pos_y<<"   "<<endl;
	cout<<"area of this triangle is "<<shape.getter_area()<<"."<<endl;
	cout<<"perimeter lenght of this triangle is "<<shape.getter_perimeter_lenght()<<"."<<endl;

	return outputStream;
}
double Triangle::getter_total_area(){
	return total_area;
}
double Triangle::getter_total_perimeter(){
	return total_perimeter;
}
void Triangle::setter_total_area(double new_value){
	total_area=new_value;
}
void Triangle::setter_total_perimeter(double new_value){
	total_perimeter=new_value;
}

