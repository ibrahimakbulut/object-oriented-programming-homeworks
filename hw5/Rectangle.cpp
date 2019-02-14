#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>

namespace name_rectangle{

Rectangle::Rectangle(){ //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	Width=0;
	Height=0;
	total_area+=area();  //this calculation 0 because it has no size all size are 0.
	total_perimeter+=perimeter();
}
Rectangle::Rectangle(double width,double height){

	Width=width;
	Height=height;

	Pos_x=0;
	Pos_y=0;
	total_area+=area();
	total_perimeter+=perimeter();
}
Rectangle::Rectangle(double width,double height,double pos_x,double pos_y){ //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	Width=width;
	Height=height;
	total_area+=area();
	total_perimeter+=perimeter();	
}
Rectangle& Rectangle::operator ++(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	Rectangle *temp =new Rectangle(Width,Height,temp_pos_x,temp_pos_y);
	return *temp;
}
Rectangle& Rectangle::operator ++(){
	Pos_x+=1.0;
	Pos_y+=1.0;

	return *this;
}
Rectangle& Rectangle::operator --(int){
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	Rectangle *temp=new Rectangle(Width,Height,temp_pos_x,temp_pos_y);
	return *temp;
}
Rectangle& Rectangle::operator --(){
	Pos_x-=1.0;
	Pos_y-=1.0;

	return *this;
}
double Rectangle::area()const{
	if(Width<0 && Height>0){
		return -Width*Height;
	}
	else if(Width>0 && Height<0){
		return Width*-Height;
	}
	return Width*Height;
}
double Rectangle::perimeter()const{
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
ofstream& Rectangle::print_shape(ofstream& outputfile)const{
	if(Pos_x>Width)
			outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<"width=\""<<Pos_x+Width<<"\" height=\""<<Pos_y+Height<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	else
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<Pos_x<<"\" y=\""<<Pos_y;
	outputfile<<"\" width=\""<<Width<<"\" height=\""<<Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const Rectangle& shape){

	cout<<"pozition x: "<<shape.Pos_x<<" , "<<"pozition y "<<shape.Pos_y<<endl;
	cout<<"area of this rectangle is "<<shape.area()<<endl;
	cout<<"perimeter lenght of this rectangle is "<<shape.perimeter()<<endl;
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
