
#include "Polygon.h"
#include <iostream>

namespace name_polygon{
Polygon::Point2D::Point2D(){
	pos_x=0;pos_y=0;
}
Polygon::Point2D::Point2D(double initialize_pos_x,double initialize_pos_y){
	pos_x=initialize_pos_x;
	pos_y=initialize_pos_y;
}
void Polygon::Point2D::setter_pos_x(double new_pos_x){
	pos_x=new_pos_x;
}
void Polygon::Point2D::setter_pos_y(double new_pos_y){
	pos_y=new_pos_y;
}
double Polygon::Point2D::getter_pos_x()const{
	return pos_x;
}
double Polygon::Point2D::getter_pos_y()const{
	return pos_y;
}

}
