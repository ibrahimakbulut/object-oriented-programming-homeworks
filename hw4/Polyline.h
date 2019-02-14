#include "Polygon.cpp"

using namespace name_polygon;

namespace name_polyline{
class Polyline{

public:

	Polyline();
	Polyline(const Triangle& shape_triangle);
	Polyline(const Rectangle& shape_rectangle);
	Polyline (const Circle& shape_circle);

	Polyline(const Polygon::Point2D point);
	Polyline(const vector<Polygon::Point2D> points);
	Polyline(const Polygon copy_Polygon);

	bool operator ==(const Polyline& other)const;
	bool operator !=(const Polyline& other)const;

	Polyline& operator =(const Polyline& rtSide);
	const Polygon::Point2D& operator [](unsigned int index)const;
	Polygon::Point2D& operator [](unsigned int index);

	const Polyline operator +(const Polyline other)const;


	friend ofstream& operator <<(ofstream& outputfile,const Polyline& shape);

	double difference_mostAndleast_x()const;

	double difference_mostAndleast_y()const;

	double most_x()const;
	double most_y()const;

	double getter_perimeter_of_shape()const;


	Polygon::Point2D* getter_polyline_points()const;
	void setter_polyline_points(Polygon::Point2D* new_polyline_points);

	int get_size()const;
	void set_size(int new_size);


private:

	Polygon shape;
};
}