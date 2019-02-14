//Composed_shape.h
#include "Shape.h"
using namespace Shape_base;
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace name_triangle;
using namespace name_circle;
using namespace name_rectangle;

#include "Polygon.h"

using namespace name_polygon;
#include "PolygonVect.h"
#include "PolygonDyn.h"

using namespace name_polygonVect;
using namespace name_polygonDyn;



#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

namespace {
	enum class Shapes{
	rectangle,
	triangle,
	circle
};
}
class composedShape: public Shape{
	

	public:
		
		composedShape(Rectangle container_shape,Rectangle inner_small_shape); //constructors
		composedShape(Rectangle container_shape,Triangle inner_small_shape);
		composedShape(Rectangle container_shape,Circle inner_small_shape);
		
		composedShape(Triangle container_shape,Rectangle inner_small_shape);
		composedShape(Triangle container_shape,Triangle inner_small_shape);
		composedShape(Triangle container_shape,Circle inner_small_shape);
		
		composedShape(Circle container_shape,Rectangle inner_small_shape);
		composedShape(Circle container_shape,Triangle inner_small_shape);
		composedShape(Circle container_shape,Circle inner_small_shape);

		composedShape(const composedShape& copy_composed); //copy constructor
		composedShape& operator =(const composedShape& rtSide); //assignment operator
		
		composedShape();
		~composedShape();


		composedShape&  operator ++(int){};
		composedShape&  operator ++(){};

		composedShape&  operator --(int){};
		composedShape& operator --(){};

		double area()const;
		double perimeter()const;
		
		ofstream& print_shape(ofstream& outputfile)const override; //print function from base class as virtual

		void optimalFit();//fitting shape into container

		vector<Shape*> getter_inner_shapes_vector(); //reach inner shapes vektor data

		Shape& getter_container_shape(); //reach container shape polygon

		Shape& getter_inner_shape();  //reach inner shape polygon

		void setter_container_shape(PolygonDyn Container_shape);
		void setter_inner_shape(PolygonDyn innerr_shape);

		composedShape& operator +=(Shape& shape);
		const Shape* operator [](unsigned int index)const;  //only reach element of inner shapes vektor.can't  change it.
		Shape* operator [](unsigned int index); //accessable and changable.

	public:

	PolygonDyn container_shape;

	PolygonDyn inner_shape;
	
	vector<Shape*> inner_shapes_vector;//these vectors are for inner shapes that inner shapes fit into container shape as polygonDyn
		
};
//below inline functions implementations are performed here because if implementations are performed composedShape.cpp file ,there is errors that undefined reference these functions

inline Shape& composedShape::getter_container_shape(){
	return container_shape;
}
inline Shape& composedShape::getter_inner_shape(){
	return inner_shape;
}
/*inline void composedShape::setter_container_shape(PolygonDyn Container_shape){
	PolygonDyn *temp=dynamic_cast<PolygonDyn*>(Container_shape);
	if(temp!=nullptr){
		PolygonDyn *object=new PolygonDyn(*temp);
		container_shape=*object;
	}
}*/

inline void composedShape::setter_container_shape(PolygonDyn Container_shape){
		container_shape=Container_shape;
}
inline void composedShape::setter_inner_shape(PolygonDyn innerr_shape){
		inner_shape=innerr_shape;
}
inline vector<Shape*> composedShape::getter_inner_shapes_vector(){
	return inner_shapes_vector;
}


