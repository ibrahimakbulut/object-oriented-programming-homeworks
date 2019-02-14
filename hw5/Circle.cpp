#include "Circle.h"  
#include <iostream>
#include <fstream>
#include <memory>

#define PI 3.141592

using namespace std;
namespace name_circle{

Circle::Circle(){  //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	radius_of_circle=0;
	total_area+=area();//this calculation 0 because it has no size all size are 0.
	total_perimeter+=perimeter();
}
Circle::Circle(double radius){
	radius_of_circle=radius;
	Pos_x=radius_of_circle;
	Pos_y=radius_of_circle;
	total_area+=area();
	total_perimeter+=perimeter();
}
Circle::Circle(double radius,double pos_x,double pos_y){ //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	radius_of_circle=radius;
	total_area+=area();
	total_perimeter+=perimeter();
}

Circle& Circle::operator ++(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	Circle *temp=new Circle(radius_of_circle,temp_pos_x,temp_pos_y);
	return *temp;
}
Circle& Circle::operator ++(){
	Pos_x+=1.0;
	Pos_y+=1.0;

	return *this;
}
Circle& Circle::operator --(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	Circle *temp=new Circle(radius_of_circle,temp_pos_x,temp_pos_y);
	return *temp;
}
Circle& Circle::operator --(){
	Pos_x-=1.0;
	Pos_y-=1.0;

	return *this;
}
double Circle::area()const{
	return PI*pow(radius_of_circle,2.0);
}
double Circle::perimeter()const{
	if(radius_of_circle<0){
		return -2*PI*radius_of_circle;
	}
	return 2*PI*radius_of_circle;
}
const Circle Circle::operator +(double adding_size)const{
	return Circle(radius_of_circle+adding_size);
}
const Circle operator +(double adding_size,const Circle& shape){
	return Circle(shape.radius_of_circle+adding_size);
}
const Circle Circle::operator -(double adding_size)const{
	return Circle(radius_of_circle-adding_size);
}
const Circle operator -(double adding_size,const Circle& shape){
	return Circle(adding_size-shape.radius_of_circle);
}
ofstream& Circle::print_shape(ofstream& outputfile)const{
	if(Pos_x>2*radius_of_circle)
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<Pos_x+radius_of_circle<<"\" height=\""<<Pos_y+radius_of_circle<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	else
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<Pos_x<<"\" ";
	outputfile<<"cy=\""<<Pos_y<<"\""<<" r=\""<<radius_of_circle<<"\" ";
	outputfile<<" fill=\"red\"/>"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const Circle& shape){
	cout<<"pozition x of this circle: "<<shape.Pos_x<<" , "<<"pozition y of this circle: "<<shape.Pos_y<<endl;
	cout<<"area of this circle is "<<shape.area()<<endl;
	cout<<"perimeter of this circle is "<<shape.perimeter()<<endl;
	return outputStream;
}
double Circle::getter_total_area(){
	return total_area;
}
double Circle::getter_total_perimeter(){
	return total_perimeter;
}
void Circle::setter_total_area(double new_value){
	total_area=new_value;
}
void Circle::setter_total_perimeter(double new_value){
	total_perimeter=new_value;
}
}