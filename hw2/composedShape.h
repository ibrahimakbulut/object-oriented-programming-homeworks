//Composed_shape.h
#include "Triangle.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include <vector>
#include <fstream>

using namespace std;

class composedShape {
	

	public:
		
		composedShape(Rectangle container_shape,Rectangle inner_small_shape);
		composedShape(Rectangle container_shape,Triangle inner_small_shape);
		composedShape(Rectangle container_shape,Circle inner_small_shape);
		
		composedShape(Triangle container_shape,Rectangle inner_small_shape);
		composedShape(Triangle container_shape,Triangle inner_small_shape);
		composedShape(Triangle container_shape,Circle inner_small_shape);
		
		composedShape(Circle container_shape,Rectangle inner_small_shape);
		composedShape(Circle container_shape,Triangle inner_small_shape);
		composedShape(Circle container_shape,Circle inner_small_shape);
		
		composedShape();
		
		void draw(ofstream& outputfile)const;
		void optimalFit();
		double calculate_remain_area()const;
		
		void setter_inner_circle(Circle circle);
		void setter_inner_triangle(Triangle triangle);
		void setter_inner_rectangle(Rectangle rectangle);
		
		void setter_container_circle(Circle circle);
		void setter_container_triangle(Triangle triangle);
		void setter_container_rectangle(Rectangle rectangle);
		
		vector<Circle> getter_circles_vector();
		vector<Rectangle> getter_rectangles_vector();
		vector<Triangle> getter_triangles_vector();
		
		Circle getter_inner_circle();
		Triangle getter_inner_triangle();
		Rectangle getter_inner_rectangle();
		
		Circle getter_container_circle();
		Triangle getter_container_triangle();
		Rectangle getter_container_rectangle();
		
		void setter_container_shape(char shape_letter);
		void setter_inner_shape(char shape_letter);
		
		char getter_container_shape();
		char getter_inner_shape();
	
	private:
		
	char container_shape;
	char inner_shape;	
	
		
	Rectangle container_rectangle;
	Triangle container_triangle;
	Circle container_circle;
	
	Rectangle inner_rectangle;
	Triangle inner_triangle;
	Circle inner_circle;
	
	vector<Rectangle> inner_rectangle_shapes;
	vector<Triangle> inner_triangle_shapes;
	vector<Circle> inner_circle_shapes;
		
};
inline void composedShape::setter_inner_circle(Circle circle){
	inner_circle=circle;
}
inline void composedShape::setter_inner_triangle(Triangle triangle){
	inner_triangle=triangle;
}
inline void composedShape::setter_inner_rectangle(Rectangle rectangle){
	inner_rectangle=rectangle;
}		
inline void composedShape::setter_container_circle(Circle circle){
	container_circle=circle;
}
inline void composedShape::setter_container_triangle(Triangle triangle){
	container_triangle=triangle;
}
inline void composedShape::setter_container_rectangle(Rectangle rectangle){
	container_rectangle=rectangle;
}
inline Circle composedShape::getter_inner_circle(){
	return inner_circle;
}
inline Triangle composedShape::getter_inner_triangle(){
	return inner_triangle;
}
inline Rectangle composedShape::getter_inner_rectangle(){
	return inner_rectangle;
}
inline Circle composedShape::getter_container_circle(){
	return container_circle;
}
inline Triangle composedShape::getter_container_triangle(){
	return container_triangle;
}
inline Rectangle composedShape::getter_container_rectangle(){
	return container_rectangle;
}
inline vector<Circle> composedShape::getter_circles_vector(){
	return inner_circle_shapes;
}
inline vector<Rectangle> composedShape::getter_rectangles_vector(){
	return inner_rectangle_shapes;
}
inline vector<Triangle> composedShape::getter_triangles_vector(){
	return inner_triangle_shapes;
}
inline void composedShape::setter_container_shape(char shape_letter){
	container_shape=shape_letter;
}
inline void composedShape::setter_inner_shape(char shape_letter){
	inner_shape=shape_letter;
}
inline char composedShape::getter_container_shape(){
	return container_shape;
}
inline char composedShape::getter_inner_shape(){
	return inner_shape;
}
