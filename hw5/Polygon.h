

#ifndef POLYGON_H

#define POLYGON_H

#include "Shape.h"
using namespace std;
using namespace Shape_base;

namespace name_polygon{
class Polygon: public Shape{

public:

	class Point2D{

	public:

		Point2D();
		Point2D(double initialize_pos_x,double initialize_pos_y);

		void setter_pos_x(double new_pos_x);
		void setter_pos_y(double new_pos_y);

		double getter_pos_x()const;
		double getter_pos_y()const;

	private:
		double pos_x;
		double pos_y;
	};


	double area()const{};
	double perimeter()const{};
	ofstream& print_shape(ofstream& outputfile)const{}; 

	virtual const Point2D& operator [](unsigned int index)const=0;
	virtual Point2D& operator [](unsigned int index)=0;

};
}
#endif