#include "Rectangle.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace name_rectangle{

Rectangle::Rectangle(){ //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	Width=0;
	Height=0;
	total_area+=getter_area();  //this calculation 0 because it has no size all size are 0.
	total_perimeter+=getter_perimeter_lenght();
}
Rectangle::Rectangle(double width,double height){

	Width=width;
	Height=height;

	Pos_x=0;
	Pos_y=0;
	total_area+=getter_area();
	total_perimeter+=getter_perimeter_lenght();
}
Rectangle::Rectangle(double width,double height,double pos_x,double pos_y){ //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	Width=width;
	Height=height;
	total_area+=getter_area();
	total_perimeter+=getter_perimeter_lenght();	
}
Rectangle Rectangle::operator ++(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	return Rectangle(Width,Height,temp_pos_x,temp_pos_y);
}
Rectangle Rectangle::operator ++(){
	Pos_x+=1.0;
	Pos_y+=1.0;

	return Rectangle(Width,Height,Pos_x,Pos_y);
}
Rectangle Rectangle::operator --(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	return Rectangle(Width,Height,temp_pos_x,temp_pos_y);
}
Rectangle Rectangle::operator --(){
	Pos_x-=1.0;
	Pos_y-=1.0;

	return Rectangle(Width,Height,Pos_x,Pos_y);
}
double Rectangle::getter_area()const{
	if(Width<0 && Height>0){
		return -Width*Height;
	}
	else if(Width>0 && Height<0){
		return Width*-Height;
	}
	return Width*Height;
}
double Rectangle::getter_perimeter_lenght()const{
	if(Width<0 && Height<0){
		return -2*(Width+Height);
	}
	else if(Width<0 && Height>0){
		return 2*(-Width+Height);
	}
	else if(Width>0 && Height<0){
		return 2*(Width+-Height);
	}
	return 2*(Width+Height);
}
bool Rectangle::operator ==(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a==b);
}
bool Rectangle::operator !=(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a!=b);
}
bool Rectangle::operator <=(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<=b);
}
bool Rectangle::operator >=(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>=b);
}
bool Rectangle::operator <(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a<b);
}
bool Rectangle::operator >(const Rectangle& other)const{
	double a=getter_area();
	double b=other.getter_area();
	return (a>b);
}
const Rectangle Rectangle::operator +(double adding_size)const{
	return Rectangle(Width+adding_size,Height+adding_size);
}
const Rectangle operator +(double adding_size,const Rectangle& shape){
	return Rectangle(shape.Width+adding_size,shape.Height+adding_size);
}
const Rectangle Rectangle::operator -(double adding_size)const{
	return Rectangle(Width-adding_size,Height-adding_size);
}
const Rectangle operator -(double adding_size,const Rectangle& shape){
	return Rectangle(adding_size-shape.Width,adding_size-shape.Height);
}
ofstream& operator <<(ofstream& outputfile,const Rectangle& shape){
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<shape.Pos_x<<"\" y=\""<<shape.Pos_y;
	outputfile<<"\" width=\""<<shape.Width<<"\" height=\""<<shape.Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const Rectangle& shape){
	cout<<"pozition x: "<<shape.Pos_x<<" , "<<"pozition y "<<shape.Pos_y<<endl;
	cout<<"area of this rectangle is "<<shape.getter_area()<<endl;
	cout<<"perimeter lenght of this rectangle is "<<shape.getter_perimeter_lenght()<<endl;
	return outputStream;
}
void Rectangle::draw(ofstream &outputfile)const{ //This function can print a rectangle with rectangle properties

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<Pos_x<<"\" y=\""<<Pos_y;
	outputfile<<"\" width=\""<<Width<<"\" height=\""<<Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
}
double Rectangle::getter_total_area(){
	return total_area;
}
double Rectangle::getter_total_perimeter(){
	return total_perimeter;
}
void Rectangle::setter_total_area(double new_value){
	total_area=new_value;
}
void Rectangle::setter_total_perimeter(double new_value){
	total_perimeter=new_value;
}
}
