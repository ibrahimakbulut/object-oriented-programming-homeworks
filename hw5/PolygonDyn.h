#ifndef POLYGONDYNA_H

#define POLYGONDYNA_H

#include "Shape.h"
using namespace Shape_base;

#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"

using namespace name_triangle;
using namespace name_circle;
using namespace name_rectangle;
using namespace name_polygon;

namespace name_polygonDyn{
class PolygonDyn: public Polygon{

public:


/*	double area()=0;
	double perimeter()=0;

	const Polygon operator ++(int);
	const Polygon operator ++();
										//these are inherited functions from base class Shape
	const Polygon operator --(int);
	const Polygon operator --();

//---------------------------------------- */

	~PolygonDyn();
	PolygonDyn();
	PolygonDyn(Triangle& shape_triangle);
	PolygonDyn(Rectangle& shape_rectangle);
	PolygonDyn(Circle& shape_circle);

	PolygonDyn(const Point2D& point);
	PolygonDyn(const vector<Point2D>& points);
	PolygonDyn(const PolygonDyn& copy_Polygondyn);


	PolygonDyn& operator ++(int) override;
	PolygonDyn& operator ++() override;

	PolygonDyn& operator --(int) override;
	PolygonDyn& operator --() override;




	PolygonDyn& operator =(const PolygonDyn& rtSide);
	const Point2D& operator [](unsigned int index)const override;
	Point2D& operator [](unsigned int index) override;

	const PolygonDyn operator +(const PolygonDyn& other)const;

	ofstream& print_shape(ofstream& outputfile)const;

	double difference_mostAndleast_x()const;

	double difference_mostAndleast_y()const;

	double most_x()const;
	double most_y()const;

	double area()const;
	double perimeter()const;


	Point2D* getter_polygon_points()const;
	void setter_polygon_points(Point2D* new_polygon_points);

	int get_size()const;
	void set_size(int new_size);

	double getter_pos_x();
	double getter_pos_y();

private:

	Point2D* polygon_points;

	int size_of_points;

};
}
#endif