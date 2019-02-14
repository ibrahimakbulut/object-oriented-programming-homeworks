//Composed_shape.h
#include "Polyline.cpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace name_polyline;

namespace {
	enum class Shapes{
	rectangle,
	triangle,
	circle
};
}
class composedShape {
	

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
		
		composedShape();
		
		friend ofstream& operator <<(ofstream& outputfile,const composedShape& main_shape); //print functions
		friend ostream& operator <<(ostream& outStream,const composedShape& main_shape); 

		void optimalFit();//fitting shape into container

		vector<Polygon> getter_inner_shapes_vector(); //reach inner shapes vektor data

		Polygon getter_container_shape()const; //reach container shape polygon
		void setter_container_shape(Polygon Container_shape); //set " " "

		Polygon getter_inner_shape()const;  //reach inner shape polygon
		void setter_inner_shape(Polygon innerr_shape); //set " " "

		composedShape& operator +=(Polygon shape);
		const Polygon& operator [](unsigned int index)const;  //only reach element of inner shapes vektor.can't  change it.

	public:

	Polygon container_shape;

	Polygon inner_shape;
	
	vector<Polygon> inner_shapes_vector;//these vectors are for inner shapes that inner shapes fit into container shape
		
};
//below inline functions implementations are performed here because if implementations are performed composedShape.cpp file ,there is errors that undefined reference these functions

inline Polygon composedShape::getter_container_shape()const{
	return container_shape;
}
inline Polygon composedShape::getter_inner_shape()const{
	return inner_shape;
}
inline void composedShape::setter_container_shape(Polygon Container_shape){
	container_shape=Container_shape;
}
inline void composedShape::setter_inner_shape(Polygon innerr_shape){
	inner_shape=innerr_shape;
}
inline vector<Polygon> composedShape::getter_inner_shapes_vector(){
	return inner_shapes_vector;
}


