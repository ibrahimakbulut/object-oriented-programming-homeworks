#ifndef POLYGONVECT_H

#define POLYGONVECT_H

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

namespace name_polygonVect{
class PolygonVect: public Polygon{

public:

	~PolygonVect()=default;
	PolygonVect();
	PolygonVect(Triangle& shape_triangle);
	PolygonVect(Rectangle& shape_rectangle);
	PolygonVect (Circle& shape_circle);

	PolygonVect(const Point2D& point);
	PolygonVect(const vector<Point2D>& points);
	PolygonVect(const PolygonVect& copy_Polygonvect);


	PolygonVect& operator ++(int) override;
	PolygonVect& operator ++() override;

	PolygonVect& operator --(int) override;
	PolygonVect& operator --() override;

	PolygonVect& operator =(const PolygonVect& rtSide);
	const Point2D& operator [](unsigned int index)const override;
	Point2D& operator [](unsigned int index) override;

	const PolygonVect operator +(const PolygonVect& other)const;

	ofstream& print_shape(ofstream& outputfile)const;

	double difference_mostAndleast_x()const;

	double difference_mostAndleast_y()const;

	double most_x()const;
	double most_y()const;

	double area()const override;
	double perimeter()const override;

	double getter_pos_x();
	double getter_pos_y();

	vector<Point2D> getter_polygon_points()const;
	void setter_polygon_points(vector<Point2D> new_polygon_points);

	int get_size()const;

private:

	vector<Point2D> polygon_points;

};
}
#endif