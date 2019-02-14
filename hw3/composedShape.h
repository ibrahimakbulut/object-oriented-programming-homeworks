//Composed_shape.h
#include "Triangle.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include <vector>
#include <fstream>

using namespace std;

enum class Shapes{
	rectangle,
	triangle,
	circle
};
class composedShape {
	

	public:
		
		class shapeElem{

			public:

				double getter_area_of_shape()const;
				double getter_perimeter_lenght_of_shape()const;

				shapeElem();
				shapeElem(void *shape,Shapes inner_type);
				void * getter_shape_point()const;
				void setter_shape_point(void* new_pointing);
				Shapes getter_shape_type()const;
				void setter_shape_type(Shapes a);

				friend ofstream& operator <<(ofstream& outputfile,const composedShape::shapeElem& shape);
				friend ostream& operator <<(ostream& outputfile,const composedShape::shapeElem& shape);


			private:
				void *shapes;
				Shapes shape_type;


		};
		//~composedShape();//descructor
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
		
		friend ofstream& operator <<(ofstream& outputfile,const composedShape& main_shape); 
		friend ostream& operator <<(ostream& outStream,const composedShape& main_shape); 

		void optimalFit();

		double calculate_remain_area()const; //this function calculate container remain area
		

		vector<shapeElem> getter_inner_shapes_vector();

		shapeElem getter_container_shape()const;
		void setter_container_shape(shapeElem container_shape);

		shapeElem getter_inner_shape()const;
		void setter_inner_shape(shapeElem inner_shape);

		composedShape& operator +=(shapeElem shape);
		const shapeElem& operator [](unsigned int index)const;

	private:

	shapeElem container_shapes;  //these variables are for container shape,one of them will be used

	shapeElem inner_shapez;//bunu değiştirecen tüm fonksiyonlarda shape olarak
	
	vector<shapeElem> inner_shapes_vector;//these vectors are for inner shapes that inner shapes fit into container shape
		
};
//below inline functions implementations are performed here because if implementations are performed composedShape.cpp file ,there is errors that undefined reference these functions

inline composedShape::shapeElem composedShape::getter_container_shape()const{
	return container_shapes;
}
inline composedShape::shapeElem composedShape::getter_inner_shape()const{
	return inner_shapez;
}
inline void composedShape::setter_container_shape(composedShape::shapeElem container_shape){
	container_shapes=container_shape;
}
inline void composedShape::setter_inner_shape(composedShape::shapeElem inner_shape){
	inner_shapez=inner_shape;
}
inline vector<composedShape::shapeElem> composedShape::getter_inner_shapes_vector(){
	return inner_shapes_vector;
}


