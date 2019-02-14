
#include "Triangle.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include <vector>
#include <fstream>
using namespace name_triangle;
using namespace name_circle;
using namespace name_rectangle;

namespace name_polygon{
class Polygon{

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

	~Polygon();
	Polygon();
	Polygon(Triangle& shape_triangle);
	Polygon(Rectangle& shape_rectangle);
	Polygon (Circle& shape_circle);

	Polygon(const Point2D point);
	Polygon(const vector<Point2D> points);
	Polygon(const Polygon& copy_Polygon);

	bool operator ==(const Polygon& other)const;
	bool operator !=(const Polygon& other)const;

	Polygon& operator =(const Polygon& rtSide);
	const Point2D& operator [](unsigned int index)const;
	Point2D& operator [](unsigned int index);

	const Polygon operator +(const Polygon& other)const;

	friend ofstream& operator <<(ofstream& outputfile,const Polygon& shape);

	double difference_mostAndleast_x()const;

	double difference_mostAndleast_y()const;

	double most_x()const;
	double most_y()const;

	double getter_area_of_shape()const;
	double getter_perimeter_of_shape()const;


	Point2D* getter_polygon_points()const;
	void setter_polygon_points(Point2D* new_polygon_points);

	int get_size()const;
	void set_size(int new_size);

private:

	Point2D* polygon_points;

	int size_of_points;

};
}