
#ifndef RECTANGLE_H

#define RECTANGLE_H

// Rectangle.h
#include "Shape.h"

using namespace std;
using namespace Shape_base;
namespace name_rectangle{

class Rectangle : public Shape {
	
	public:
		
		void setter_position(double pos_x,double pos_y);
		void setter_width(double width);
		void setter_height(double height);
		static void setter_objectCount(int new_value);
		static void setter_total_area(double new_value);
		static void setter_total_perimeter(double new_value);
		
		void draw(ofstream& outputfile)const;
		
		static void plus_rectangles(); //increase 1 objectCount

		Rectangle& operator ++(int) override;
		Rectangle& operator ++() override;

		Rectangle& operator --(int) override;
		Rectangle& operator --() override;


		const Rectangle operator +(double adding_size)const;
		friend const Rectangle operator +(double adding_size,const Rectangle& shape);
		const Rectangle operator -(double adding_size)const;
		friend const Rectangle operator -(double adding_size,const Rectangle& shape);

		ofstream& print_shape(ofstream& outputfile)const override;  //virtual function from basesed
		friend ostream& operator <<(ostream& outputStream,const Rectangle& shape);

		
		double getter_pos_x()const;
		double getter_pos_y()const;
		double getter_width()const;
		double getter_height()const;
		static int getter_objectCount();
		static double getter_total_area();
		static double getter_total_perimeter();

		double area()const;
		double perimeter()const;
		
		Rectangle();
		Rectangle(double width,double height);
		Rectangle(double width,double height,double pos_x,double pos_y);
		
	private:
		
		double Pos_x;
		double Pos_y;
		
		double Width;
		double Height;

		static int objectCount;
		static double total_area;
		static double total_perimeter;
};
//below inline functions implementations are performed here because if implementations are performed rectangle.cpp file ,there is errors that undefined reference these functions
inline void Rectangle::plus_rectangles(){
	objectCount+=1;
}
inline void Rectangle::setter_position(double pos_x,double pos_y){
	
	Pos_x=pos_x;
	Pos_y=pos_y;
}
inline void Rectangle::setter_width(double width){
	Width=width;
}
inline void Rectangle::setter_height(double height){
	Height=height;
}
inline void Rectangle::setter_objectCount(int new_value){
	objectCount=new_value;
}
inline double Rectangle::getter_pos_x()const{
	return Pos_x;
}
inline double Rectangle::getter_pos_y()const{
	return Pos_y;
}
inline double Rectangle::getter_width()const{
	return Width;
}
inline double Rectangle::getter_height()const{
	return Height;
}
inline int Rectangle::getter_objectCount(){
	return objectCount;
}
}
#endif
