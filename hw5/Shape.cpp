#include "Shape.h"

using namespace std;

namespace Shape_base{

ofstream& operator<<(ofstream& outputfile,const Shape& shape){
	return shape.print_shape(outputfile);
}
bool Shape::operator==(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a==b);
}
bool Shape::operator!=(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a!=b);
}
bool Shape::operator <(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a<b);
}
bool Shape::operator >(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a>b);
}
bool Shape::operator >=(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a>=b);
}
bool Shape::operator <=(const Shape& other)const{
	double a=area();
	double b=other.area();
	return (a<=b);
}
}
