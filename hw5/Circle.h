
#ifndef CIRCLE_H

#define CIRCLE_H

//Circle.h
#include <fstream>
#include <cmath>
#include <iostream>
#include "Shape.h"

using namespace std;
using namespace Shape_base;
namespace name_circle{
class Circle: public Shape {
	
	public:
		
		void setter_radius(double radius);
		void setter_position_x(double pos_x);
		void setter_position_y(double pos_y);
		static void setter_objectCount(int new_value); //change the objectCount
		static void setter_total_area(double new_value);
		static void setter_total_perimeter(double new_value);
		
		double getter_pos_x()const;
		double getter_pos_y()const;
		double getter_radius()const;

		static int getter_objectCount();
		static double getter_total_area();
		static double getter_total_perimeter();

		Circle& operator ++(int) override;
		Circle& operator ++() override;

		Circle& operator --(int) override;
		Circle& operator --() override;


		const Circle operator +(double adding_size)const; 
		friend const Circle operator +(double adding_size,const Circle& shape);
		const Circle operator -(double adding_size)const;
		friend const Circle operator -(double adding_size,const Circle& shape);

		ofstream& print_shape(ofstream& outputfile)const override;
		friend ostream& operator <<(ostream& outputStream,const Circle& shape);

		double area()const override;
		double perimeter()const override;
		
		static void plus_circles();  //increase 1 objectCount
		
		Circle();
		Circle(double radius);
		Circle(double radius,double pos_x,double pos_y);
		
	private:
		
		static int objectCount;  //how many circle created for inner shape.
		static double total_area;
		static double total_perimeter;
		double radius_of_circle;
		
		double Pos_x;
		double Pos_y;
};
//below inline functions implementations are performed here because if implementations are performed circle.cpp file ,there is errors that undefined reference these functions
inline void  Circle::plus_circles(){ 
	objectCount+=1;
}

inline void Circle::setter_position_x(double pos_x){
	Pos_x=pos_x;
}
inline void Circle::setter_position_y(double pos_y){
	Pos_y=pos_y;
}
inline void Circle::setter_radius(double radius){
	
	radius_of_circle=radius;
}
inline void Circle::setter_objectCount(int new_value){
	objectCount=new_value;
}
inline double Circle::getter_pos_x()const{
	if(Pos_x==0 && radius_of_circle!=0){
		return radius_of_circle;
	}
	return Pos_x;
}
inline double Circle::getter_pos_y()const{
	if(Pos_y==0 && radius_of_circle!=0){
		return radius_of_circle;
	}
	return Pos_y;
}
inline double Circle::getter_radius()const{
	return radius_of_circle;
}
inline int Circle::getter_objectCount(){

	return objectCount;
}	
}
#endif
