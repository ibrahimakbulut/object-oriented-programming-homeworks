#include "Polyline.h"

namespace name_polyline{
Polyline::Polyline(){
}
Polyline::Polyline(const Triangle& shape_triangle){
	Polygon::Point2D* polyline_points=shape.getter_polygon_points();
	polyline_points=new Polygon::Point2D[3];

	if(!(shape_triangle.getter_point1_y()==0 && shape_triangle.getter_point2_x()==0 )){
	polyline_points[0].setter_pos_x(shape_triangle.getter_point1_x());
	polyline_points[0].setter_pos_y(shape_triangle.getter_point1_y());

	polyline_points[1].setter_pos_x(shape_triangle.getter_point2_x());
	polyline_points[1].setter_pos_y(shape_triangle.getter_point2_y());

	polyline_points[2].setter_pos_x(shape_triangle.getter_point3_x());
	polyline_points[2].setter_pos_y(shape_triangle.getter_point3_y());
	}
	else{
	polyline_points[0].setter_pos_x(shape_triangle.getter_lenght_of_triangle()/2);
	polyline_points[0].setter_pos_y(0);

	polyline_points[1].setter_pos_x(shape_triangle.getter_lenght_of_triangle());
	polyline_points[1].setter_pos_y(shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);

	polyline_points[2].setter_pos_x(0);
	polyline_points[2].setter_pos_y(shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);}
	shape.setter_polygon_points(polyline_points);
	shape.set_size(3);
}
Polyline::Polyline(const Rectangle& shape_rectangle){

	Polygon::Point2D* polyline_points=shape.getter_polygon_points();
	polyline_points=new Polygon::Point2D[4];

	double rectangle_pos_x=shape_rectangle.getter_pos_x();
	double rectangle_pos_y=shape_rectangle.getter_pos_y();

	polyline_points[0].setter_pos_x(rectangle_pos_x);
	polyline_points[0].setter_pos_y(rectangle_pos_y);

	polyline_points[1].setter_pos_x(rectangle_pos_x+shape_rectangle.getter_width());
	polyline_points[1].setter_pos_y(rectangle_pos_y);

	polyline_points[2].setter_pos_x(rectangle_pos_x+shape_rectangle.getter_width());
	polyline_points[2].setter_pos_y(rectangle_pos_y+shape_rectangle.getter_height());

	polyline_points[3].setter_pos_x(rectangle_pos_x);
	polyline_points[3].setter_pos_y(rectangle_pos_y+shape_rectangle.getter_height());
	shape.setter_polygon_points(polyline_points);
	shape.set_size(4);
}
Polyline::Polyline(const Circle& shape_circle){
	Polygon::Point2D* polyline_points=shape.getter_polygon_points();
	polyline_points=new Polygon::Point2D[100];

	double radius=shape_circle.getter_radius();
	for(int i=0;i<100;++i){
		polyline_points[i].setter_pos_x(shape_circle.getter_pos_x()+radius+radius*sin((2*PI/100)*i));
		polyline_points[i].setter_pos_y(shape_circle.getter_pos_y()+radius+radius*cos((2*PI/100)*i));
	}
	shape.setter_polygon_points(polyline_points);
	shape.set_size(100);
}
Polyline::Polyline(const Polygon::Point2D point){
	Polygon::Point2D* polyline_points=shape.getter_polygon_points();
	polyline_points=new Polygon::Point2D;

	polyline_points->setter_pos_x(point.getter_pos_x());
	shape.setter_polygon_points(polyline_points);
	shape.set_size(1);
}
Polyline::Polyline(const vector<Polygon::Point2D> points){
	Polygon::Point2D* polyline_points=shape.getter_polygon_points();
	polyline_points=new Polygon::Point2D[points.size()];

	for(int i=0;i<points.size();++i){
		polyline_points[i].setter_pos_x(points[i].getter_pos_x());
		polyline_points[i].setter_pos_y(points[i].getter_pos_y());
	}
	shape.setter_polygon_points(polyline_points);
	shape.set_size(points.size());
}
Polyline::Polyline(const Polygon copy_Polygon){
	shape.setter_polygon_points(copy_Polygon.getter_polygon_points());
}

double Polyline::getter_perimeter_of_shape()const{
	if(shape.get_size()==100){
		return (shape.getter_perimeter_of_shape()/100.0)*99; //polyline has always perimeter lenght than same polygon.
	}
	else if(shape.get_size()==4){
		return (shape.getter_perimeter_of_shape());
	}
	else if(shape.get_size()==3){
		Triangle a(shape.difference_mostAndleast_x());
		return (shape.getter_perimeter_of_shape()/3.0)*2;
	}
	else
		return -1;	
}
bool Polyline::operator ==(const Polyline& other)const{
	return shape==other.shape;
}
bool Polyline::operator !=(const Polyline& other)const{
	return shape!=other.shape;
}
ofstream& operator <<(ofstream& outputfile,const Polyline& shape_line){

	double most_right_x,most_down_y;
	most_right_x=shape_line.shape.getter_polygon_points()[0].getter_pos_x();
	most_down_y=shape_line.shape.getter_polygon_points()[0].getter_pos_y();
	for(int i=1;i<shape_line.shape.get_size();++i){
		if(shape_line.shape.getter_polygon_points()[i].getter_pos_x()>most_right_x)
			most_right_x=shape_line.shape.getter_polygon_points()[i].getter_pos_x();
		if(shape_line.shape.getter_polygon_points()[i].getter_pos_y()>most_down_y)
			most_down_y=shape_line.shape.getter_polygon_points()[i].getter_pos_y();
	}
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<most_right_x<<"\" height=\""<<most_down_y<<"\" "<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polyline points=\"";

	for(int i=0;i<shape_line.shape.get_size();++i){
		outputfile<<" "<<shape_line.shape.getter_polygon_points()[i].getter_pos_x();
		outputfile<<","<<shape_line.shape.getter_polygon_points()[i].getter_pos_y();
		if(i<shape_line.shape.get_size()-1)
			outputfile<<" ";
	}
	outputfile<<"\""<<endl;
	outputfile<<" style=\"fill:none;stroke:purple;stroke-width:1.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
Polygon::Point2D* Polyline::getter_polyline_points()const{
	return shape.getter_polygon_points();
}
void Polyline::setter_polyline_points(Polygon::Point2D* new_polyline_points){
	shape.setter_polygon_points(new_polyline_points);
}
int Polyline::get_size()const{
	return shape.get_size();
}
void Polyline::set_size(int new_size){
	shape.set_size(new_size);
}
double Polyline::difference_mostAndleast_x()const{
return shape.difference_mostAndleast_x();
}
double Polyline::difference_mostAndleast_y()const{
return shape.difference_mostAndleast_y();
}
double Polyline::most_x()const{
return shape.most_x();
}
double Polyline::most_y()const{
return shape.most_y();
}
Polyline& Polyline::operator =(const Polyline& rtSide){
	shape=rtSide.shape;
	return *this;
}
const Polygon::Point2D& Polyline::operator [](unsigned int index)const{
	return shape[index]; 
}
 Polygon::Point2D& Polyline::operator [](unsigned int index){
	return shape[index];
}
const Polyline Polyline::operator +(const Polyline other)const{
return Polyline(shape+other.shape);
}
}