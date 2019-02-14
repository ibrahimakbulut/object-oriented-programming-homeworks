#include "Circle.h"  
#include <iostream>
#include <fstream>

#define PI 3.141592

using namespace std;
namespace name_circle{

Circle::Circle(){  //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	radius_of_circle=0;
	total_area+=getter_area();//this calculation 0 because it has no size all size are 0.
	total_perimeter+=getter_perimeter_lenght();
}
Circle::Circle(double radius){
	radius_of_circle=radius;
	Pos_x=radius_of_circle;
	Pos_y=radius_of_circle;
	total_area+=getter_area();
	total_perimeter+=getter_perimeter_lenght();
}
Circle::Circle(double radius,double pos_x,double pos_y){ //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	radius_of_circle=radius;
	total_area+=getter_area();
	total_perimeter+=getter_perimeter_lenght();
}

Circle Circle::operator ++(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	return Circle(radius_of_circle,temp_pos_x,temp_pos_y);
}
Circle Circle::operator ++(){
	Pos_x+=1.0;
	Pos_y+=1.0;

	return Circle(radius_of_circle,Pos_x,Pos_y);
}
Circle Circle::operator --(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	return Circle(radius_of_circle,temp_pos_x,temp_pos_y);
}
Circle Circle::operator --(){
	Pos_x-=1.0;
	Pos_y-=1.0;

	return Circle(radius_of_circle,Pos_x,Pos_y);
}
double Circle::getter_area()const{
	return PI*pow(radius_of_circle,2.0);
}
double Circle::getter_perimeter_lenght()const{
	if(radius_of_circle<0){
		return -2*PI*radius_of_circle;
	}
	return 2*PI*radius_of_circle;
}
bool Circle::operator ==(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a==b);
}
bool Circle::operator !=(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a!=b);
}
bool Circle::operator <(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<b);
}
bool Circle::operator >(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>b);
}
bool Circle::operator >=(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>=b);
}
bool Circle::operator <=(const Circle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<=b);
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
ofstream& operator <<(ofstream& outputfile,const Circle& shape){
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<shape.Pos_x<<"\" ";
	outputfile<<"cy=\""<<shape.Pos_y<<"\""<<" r=\""<<shape.radius_of_circle<<"\" ";
	outputfile<<" fill=\"red\"/>"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const Circle& shape){
	cout<<"pozition x of this circle: "<<shape.Pos_x<<" , "<<"pozition y of this circle: "<<shape.Pos_y<<endl;
	cout<<"area of this circle is "<<shape.getter_area()<<endl;
	cout<<"perimeter of this circle is "<<shape.getter_perimeter_lenght()<<endl;
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