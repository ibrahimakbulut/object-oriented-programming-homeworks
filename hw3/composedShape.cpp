#include "composedShape.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>

#define PI 3.141592

using namespace std;

composedShape::shapeElem::shapeElem(){
	shapes=NULL;  //shape elem has nothing inside
	shape_type=Shapes::triangle; //triangles can replace with circle or rectangle it is not important.
}
composedShape::shapeElem::shapeElem(void *shape,Shapes inner_type){
	shapes=shape;
	shape_type=inner_type;
}
double composedShape::shapeElem::getter_area_of_shape()const{
	if(shapes==NULL)
		return 0;
	if(shape_type==Shapes::circle){
		return (static_cast<Circle*>(shapes))->getter_area();
	}
	else if(shape_type==Shapes::triangle){
		return (static_cast<Triangle*>(shapes))->getter_area();
	}
	else if(shape_type==Shapes::rectangle){
		return (static_cast<Rectangle*>(shapes))->getter_area();
	}
	else
		return 0;
}
double composedShape::shapeElem::getter_perimeter_lenght_of_shape()const{
	if(shapes==NULL)
		return 0;
	if(shape_type==Shapes::circle){
		return (static_cast<Circle*>(shapes))->getter_perimeter_lenght();
	}
	else if(shape_type==Shapes::triangle){
		return (static_cast<Triangle*>(shapes))->getter_perimeter_lenght();
	}
	else if(shape_type==Shapes::rectangle){
		return (static_cast<Rectangle*>(shapes))->getter_perimeter_lenght();
	}
	else
		return 0;
}
void* composedShape::shapeElem::getter_shape_point()const{
	return shapes;
}
void composedShape::shapeElem::setter_shape_point(void* new_pointing){
	shapes=new_pointing;
}
void composedShape::shapeElem::setter_shape_type(Shapes a){
	shape_type=a;
}
Shapes composedShape::shapeElem::getter_shape_type()const{
	return shape_type;
}
ofstream& operator <<(ofstream& outputfile,const composedShape::shapeElem& shape){ //overload for writing a shapeElem(base shapes) to a file as SVG
	if(shape.getter_shape_type()==Shapes::triangle){
		outputfile<<*(static_cast<Triangle*>(shape.getter_shape_point()));
		return outputfile;
	}
	else if(shape.getter_shape_type()==Shapes::circle){
		outputfile<<*(static_cast<Circle*>(shape.getter_shape_point()));
		return outputfile;
	}
	else if(shape.getter_shape_type()==Shapes::rectangle){
		outputfile<<*(static_cast<Rectangle*>(shape.getter_shape_point()));
		return outputfile;
	}
	else
		cout<<"wrong shape parameter"<<endl;
	return outputfile;
}
ostream& operator <<(ostream& outputStream,const composedShape::shapeElem& shape){
	if(shape.getter_shape_type()==Shapes::triangle){
		cout<<*(static_cast<Triangle*>(shape.getter_shape_point()));
		return outputStream;
	}
	else if(shape.getter_shape_type()==Shapes::circle){
		outputStream<<*(static_cast<Circle*>(shape.getter_shape_point()));
		return outputStream;
	}
	else if(shape.getter_shape_type()==Shapes::rectangle){
		outputStream<<*(static_cast<Rectangle*>(shape.getter_shape_point()));
		return outputStream;
	}
	else
		cout<<"Wrong shape parameter"<<endl;
		return outputStream;
}
/*composedShape::~composedShape(){ //Descructor but i am not used that if you use that be very carefull ,if you use ,container_shapes and inner shapes must be created dynamically.
	delete static_cast<Triangle*>(container_shapes.getter_shape_point()); //void pointer can not be deleted so cast this void pointer to any type of Shapes
	delete static_cast<Triangle*>(inner_shapez.getter_shape_point());//void pointer can not be deleted so cast this void pointer to any type of Shapes

	for(unsigned int i=0;i<inner_shapes_vector.size();++i){
		
		delete static_cast<Triangle*>(inner_shapes_vector[i].getter_shape_point());
	}
}*/
composedShape::composedShape(Rectangle Container_shape,Rectangle inner_small_shape){ //constructor with rectangle parameters
	
	Shapes container_shape_type=Shapes::rectangle;
	Shapes inner_shape_type=Shapes::rectangle;

	Rectangle *container_shape=new(Rectangle);
	Rectangle *inner_shape=new(Rectangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Rectangle*>(container_shapes.getter_shape_point())->setter_position(0,0);

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
	
}
composedShape::composedShape(Rectangle Container_shape,Triangle inner_small_shape){ //constructor with rectangle and triangle parameter

	Shapes container_shape_type=Shapes::rectangle;
	Shapes inner_shape_type=Shapes::triangle;

	Rectangle *container_shape=new(Rectangle);
	Triangle *inner_shape=new(Triangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape); //cast is not necessary because this is work to.
	static_cast<Rectangle*>(container_shapes.getter_shape_point())->setter_position(0,0); //cast it needed becuse elements of rectangle are not accessable over void*

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Rectangle Container_shape,Circle inner_small_shape){ //constructor with rectangle and circle parameter
	
	Shapes container_shape_type=Shapes::rectangle;
	Shapes inner_shape_type=Shapes::circle;

	Rectangle *container_shape=new(Rectangle);
	Circle *inner_shape=new(Circle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Rectangle*>(container_shapes.getter_shape_point())->setter_position(0,0);

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Triangle Container_shape,Rectangle inner_small_shape){ //constructor with triangle and rectangle parameters 
	
	Shapes container_shape_type=Shapes::triangle;
	Shapes inner_shape_type=Shapes::rectangle;

	Triangle *container_shape=new(Triangle);
	Rectangle *inner_shape=new(Rectangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Triangle Container_shape,Triangle inner_small_shape){ //constructors with triangles parameters
	
	Shapes container_shape_type=Shapes::triangle;
	Shapes inner_shape_type=Shapes::triangle;

	Triangle *container_shape=new(Triangle);
	Triangle *inner_shape=new(Triangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Triangle Container_shape,Circle inner_small_shape){ //constructor with triangle container and circle inner parameter
	
	Shapes container_shape_type=Shapes::triangle;
	Shapes inner_shape_type=Shapes::circle;

	Triangle *container_shape=new(Triangle);
	Circle *inner_shape=new(Circle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	static_cast<Triangle*>(container_shapes.getter_shape_point())->setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Circle Container_shape,Rectangle inner_small_shape){//constructor with circle container and rectangle inner parameter
	
	Shapes container_shape_type=Shapes::circle;
	Shapes inner_shape_type=Shapes::rectangle;

	Circle *container_shape=new(Circle);
	Rectangle *inner_shape=new(Rectangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_x(Container_shape.getter_radius());
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_y(Container_shape.getter_radius());

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Circle Container_shape,Triangle inner_small_shape){//constructor with circle container and triangle inner parameter

	Shapes container_shape_type=Shapes::circle;
	Shapes inner_shape_type=Shapes::triangle;

	Circle *container_shape=new(Circle);
	Triangle *inner_shape=new(Triangle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_x(Container_shape.getter_radius());
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_y(Container_shape.getter_radius());

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(Circle Container_shape,Circle inner_small_shape){//constructor with circle container and circle inner parameter 

	Shapes container_shape_type=Shapes::circle;
	Shapes inner_shape_type=Shapes::circle;

	Circle *container_shape=new(Circle);
	Circle *inner_shape=new(Circle);
	*container_shape=Container_shape;
	*inner_shape=inner_small_shape;

	container_shapes.setter_shape_point(container_shape);
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_x(Container_shape.getter_radius());
	static_cast<Circle*>(container_shapes.getter_shape_point())->setter_position_y(Container_shape.getter_radius());

	inner_shapez.setter_shape_point(inner_shape);
	
	inner_shapez.setter_shape_type(inner_shape_type);
	container_shapes.setter_shape_type(container_shape_type);
}
composedShape::composedShape(){ //constructor with no parameter
	
	container_shapes.setter_shape_point(NULL);
	inner_shapez.setter_shape_point(NULL);

}
composedShape& composedShape::operator +=(composedShape::shapeElem shape){ //this operator overload adds a shapes as shapeElem to composedShape object.
	inner_shapes_vector.push_back(shape);
	return *this;
}
const composedShape::shapeElem& composedShape::operator [](unsigned int index)const{ //with this operator an element of vector is only accessable, not changeable
	if(inner_shapes_vector.size()==0){
		cout<<"vector is empty, can not be reached an element of it"<<endl;
		shapeElem b(NULL,Shapes::triangle); //if vector is empty then return a shape element that has null as void pointer variable.
		shapeElem& a=b;
		return a;
	}
	if(index<0 || index>inner_shapes_vector.size()){
		cout<<"vector  index out of range."<<endl;
		shapeElem b(NULL,Shapes::triangle); //if index is wrong then return the first element of vector.
		shapeElem& a=b;
		return a;
	}

	return inner_shapes_vector[index];
}
ofstream& operator <<(ofstream& outputfile,const composedShape& main_shape){ //for writing a composedshape 

	if( main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle){

	outputfile.open("circles_into_circle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_y()<<"\""<<" r=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i]; //inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle){

	outputfile.open("rectangles_into_circle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_y()<<"\""<<" r=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){

	outputfile.open("triangles_into_circle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_pos_y()<<"\""<<" r=\""<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle){

	outputfile.open("circles_into_triangles.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){

	outputfile.open("triangles_into_triangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle ){

	outputfile.open("rectangles_into_triangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()<<" ,"<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle ){

	outputfile.open("circles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle){

	outputfile.open("rectangles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){
	
	outputfile.open("triangles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	for(unsigned int i=0;i<main_shape.inner_shapes_vector.size();++i){
		
		outputfile<<main_shape[i];//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	outputfile.close();
	return outputfile;
	}
	else
		return outputfile;
}
ostream& operator <<(ostream& outputStream,const composedShape& main_shape){

	if( main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle){

		cout<<"area of container circle shape is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner circle  shape is "<<(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle){

		cout<<"area of container circle shape is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner rectangle shape is "<<(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;		

	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::circle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){

		cout<<"area of container circle shape is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner triangle shape is "<<(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Circle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if(main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle){

		cout<<"area of container triangle shape is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner circle shape is "<<(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){

		cout<<"area of container triangle shape is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner triangle shape is "<<(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::triangle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle ){

		cout<<"area of container triangle  shape is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner rectangle shape is "<<(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Triangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::circle ){

		cout<<"area of container rectangle  shape is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner circle shape is "<<(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Circle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::rectangle){

		cout<<"area of container rectangle shape is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner rectangle shape is "<<(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Rectangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shapes.getter_shape_type()==Shapes::rectangle && main_shape.inner_shapez.getter_shape_type()==Shapes::triangle){
	
		cout<<"area of container rectangle shape is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()<<endl;
		cout<<"area of inner triangle shape is "<<(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<(static_cast<Rectangle*>(main_shape.container_shapes.getter_shape_point()))->getter_area()-(main_shape.inner_shapes_vector.size()*(static_cast<Triangle*>(main_shape.inner_shapez.getter_shape_point()))->getter_area())<<endl;
		return outputStream;

	}
	else
		return outputStream;

}
double composedShape::calculate_remain_area()const{ 

	if( container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::circle){
		double container_area=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_area();
		double inner_shape_area=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		
		double container_area=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_area();
		double inner_shape_area=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
		double container_area=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_area();
		double inner_shape_area=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-((static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::circle){
		
		auto container_area=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(3*4.7) inner_shape_area=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
		auto container_area=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(7*9.5) inner_shape_area=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		auto container_area=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(1*6.5) inner_shape_area=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
		
	}
	else if( container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::circle){
		
		auto container_area=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(8*2.4) inner_shape_area=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_area();
		
		return (container_area-( (static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
		auto container_area=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(7*5.4) inner_shape_area=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_area();
		return (container_area-( (static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else if( container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		
		auto container_area=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_area();
		decltype(4*7.9) inner_shape_area=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_area();
		return (container_area-( (static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()*inner_shape_area));
	}
	else
		return 0;
}
void composedShape::optimalFit(){

	if(container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::circle){

	double width=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_width();
	double height=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_height();
	double radius=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_radius();	
		
	double width_remaning=width-(static_cast<int>((width/(2*radius)))*radius*2);
	double height_remaning=height-(static_cast<int>((height/(2*radius)))*radius*2);


	int total_circles_first=0;int total_circles_second=0;

	/* this for count the circles in rectangular parttern */
	for(int i=1;(i*radius*2)<=(height-height_remaning);++i){
		for(int j=1;(j*radius*2)<=(width-width_remaning);++j,++total_circles_first){
			
		}
	}
	int height_counter=0;
	/*this for loop and while loop counts circle in triangular pattern */
	for(int i=1;((i*radius*2)+height_remaning)<=height;i++){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+(i%2)*width_remaning)<=width;j++,++total_circles_second){
			}
	height_counter=i;
	}

	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j,++total_circles_second){		
		}
		height_counter+=1;
	}
	/*whic pattern is more efficient then apply that */
	if(total_circles_second>total_circles_first){

	 height_counter=0;
	/*triangular pattern fitting circles part */
	for(int i=1;((i*radius*2)+height_remaning)<=height;i++){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+(i%2)*width_remaning)<=width;++j){
			Circle *current_shape=new(Circle);
			shapeElem current_elem;
			current_shape->plus_circles();
				
			if(i%2==0){
			if((j*radius*2+radius)<=width){
					
				current_shape->setter_position_x(j*radius*2);
				current_shape->setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
				current_shape->setter_radius(radius);}
			}
			else{
				
				current_shape->setter_position_x(j*radius+(j-1)*radius);
				current_shape->setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
				current_shape->setter_radius(radius);
			}
		current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
		current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
		current_elem.setter_shape_point(current_shape);
		current_elem.setter_shape_type(Shapes::circle);	
		*this+=current_elem; //+= operator is used here.
	}
	height_counter=i;
	}
	
	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j){
				
			shapeElem current_elem;
			Circle *current_shape=new(Circle);
			current_shape->plus_circles();
				
			if((height_counter-1)%2==0){
			if((j*radius*2)<width){
				current_shape->setter_position_x(j*radius*2);
			}
			
			current_shape->setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape->setter_radius(radius);
			}
			else{
			current_shape->setter_position_x(j*radius+(j-1)*radius);
			current_shape->setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape->setter_radius(radius);

			}
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::circle);	
			*this+=current_elem;
		}
		height_counter+=1;
	}
	}
	/*rectangular pattern fitting circles part*/
	else{
	for(int i=1;(i*radius*2)<=(height-height_remaning);i++){
		for(int j=1;(j*radius*2)<=(width-width_remaning);j++){
			shapeElem current_elem;
			Circle *current_shape=new(Circle);
			current_shape->plus_circles();

			
			current_shape->setter_position_x(width_remaning/2+j*(radius)+(j-1)*radius);
			current_shape->setter_position_y(height_remaning/2+i*(radius)+(i-1)*radius);
			current_shape->setter_radius(radius);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::circle);	
			*this+=current_elem;
		}
	}
	}
	}
	else if(container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
	double width=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_width();
	double height=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_height();
	double lenght_of_triangle_edge=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_lenght_of_triangle();
	
	if((height<lenght_of_triangle_edge*sqrt(3.0)/2) && width>=lenght_of_triangle_edge){
		width=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_height();
		height=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_width();
	}

	double triangle_lenght;

	triangle_lenght=(lenght_of_triangle_edge*pow(3,(1/2.0)))/2;

	int k=0;
	int line_counter=0;
	for(int i=1;((i-k)*(triangle_lenght))<=height;++i){

		if(i%2==0)
			k+=1;
	/*This condition mechanism is used to place triangles by oppositly*/
		if(i%2==0){
		for(int j=1;(j*lenght_of_triangle_edge+lenght_of_triangle_edge/2)<=width;++j){
			
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
		
			current_shape->setter_point1(2*j*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape->setter_point2((2*j+1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape->setter_point3((2*j-1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape->setter_lenght_of_triangle(lenght_of_triangle_edge);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			}
		}	
		else{
		for(int j=1;(j*lenght_of_triangle_edge)<=width;++j){
			
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1((2*j-1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape->setter_point2((2*j-2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape->setter_point3((j*2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape->setter_lenght_of_triangle(lenght_of_triangle_edge);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area()); //this statement increase total area of inner shapes.
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			}			
		}
	line_counter=i;
	}
	for(int j=1;(j*lenght_of_triangle_edge+lenght_of_triangle_edge/2)<=width;++j){
		
		shapeElem current_elem;
		Triangle *current_shape=new(Triangle);
		current_shape->plus_triangles();
		
		current_shape->setter_point1(2*j*lenght_of_triangle_edge/2,(line_counter-1-k)*triangle_lenght);
		current_shape->setter_point2((2*j+1)*lenght_of_triangle_edge/2,(line_counter-k)*triangle_lenght);
		current_shape->setter_point3((2*j-1)*lenght_of_triangle_edge/2,(line_counter-k)*triangle_lenght);
		current_shape->setter_lenght_of_triangle(lenght_of_triangle_edge);

		current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
		current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
		current_elem.setter_shape_point(current_shape);
		current_elem.setter_shape_type(Shapes::triangle);
		*this+=current_elem;
	}
	}
	else if(container_shapes.getter_shape_type()==Shapes::rectangle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		
	double container_width=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_width();
	double container_height=(static_cast<Rectangle*>(container_shapes.getter_shape_point()))->getter_height();
	double shape_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
	double shape_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();

	
	/*if there is a solution that is fully divided on both sides then call it */
if( (static_cast <int>(container_width/shape_height)*shape_height==container_width) && (static_cast <int>(container_height/shape_width)*shape_width==container_height) ){
	
	shape_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();
	shape_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
}
	if(!((shape_width>container_width && shape_height>container_height) || (shape_height>container_width && shape_width>container_height) || (shape_width>container_width && shape_width>container_height && shape_height>container_height && shape_height>container_width))){
		
	int height_counter,width_counter;
	
/*likewise continues to lay shapes.*/
	for(int i=1;i*shape_height<=container_height;++i){

		for(int j=1;j*shape_width<=container_width;++j){
			
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position((j-1)*shape_width,(i-1)*shape_height);
			current_shape->setter_width(shape_width);
			current_shape->setter_height(shape_height);
	
			width_counter=j;
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
		height_counter=i;
	}
	/*if there is space left on the right side, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=container_height;++i){

		for(int j=1;j*shape_height<=(container_width-width_counter*shape_width);++j){
		
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position(width_counter*shape_width+(j-1)*shape_height,(i-1)*shape_width);
			current_shape->setter_width(shape_height);
			current_shape->setter_height(shape_width);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
	}	
	/*if the space is left below, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=(container_height-height_counter*shape_height);++i){

		for(int j=1;j*shape_height<=container_width;++j){
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position((j-1)*shape_height,height_counter*shape_height+(i-1)*shape_height);
			current_shape->setter_width(shape_height);
			current_shape->setter_height(shape_width);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
	}	
	}	
	}
	else if(container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::circle){
		
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point1((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2,0);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point2(0,((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point3((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle(),((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);

		double lenght_of_triangle=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle();
		double radius_of_circle=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_radius();
		
		for(int i=1;i*radius_of_circle*sqrt(3.0)+radius_of_circle<=lenght_of_triangle*sqrt(3.0)/2;++i){
		for(int j=1;(j*2)*radius_of_circle+(radius_of_circle*sqrt(3.0)-radius_of_circle)<=lenght_of_triangle-(radius_of_circle*sqrt(3.0)-radius_of_circle)-(i-1)*2*radius_of_circle;++j){
			
			shapeElem current_elem;
			Circle *current_shape=new(Circle);
			current_shape->plus_circles();
			
			current_shape->setter_position_x((i-1)*radius_of_circle+radius_of_circle*sqrt(3.0)+(j*2-2)*radius_of_circle);
			current_shape->setter_position_y(lenght_of_triangle*sqrt(3.0)/2-(radius_of_circle+(i-1)*radius_of_circle*sqrt(3.0)));
			current_shape->setter_radius(radius_of_circle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::circle);
			*this+=current_elem;
		}
	}	
	}
	else if(container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point1((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2,0);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point2(0,((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point3((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle(),((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);

		double lenght_of_container_triangle=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle();
		double lenght_of_small_triangle=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_lenght_of_triangle();
		
			/*This loop determines the total height*/
	for(int i=1;i*(lenght_of_small_triangle*pow(3,1/2.0)/2)<=lenght_of_container_triangle*pow(3,1/2.0)/2;++i){
		
		/*this loop fit triangles in one way*/
		int j=1;
		for( ;j*lenght_of_small_triangle<=(lenght_of_container_triangle-(i-1)*lenght_of_small_triangle);++j){
			
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1((i-1)*lenght_of_small_triangle/2+(2*j-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point2(j*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point3((j-1)*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_lenght_of_triangle(lenght_of_small_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;

		}
		/*this loop fit triangles in other way(dont use the rotate property)*/
		for(int k=1;k<j-1;++k){
			
			shapeElem current_elem;
			Triangle*current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1((i-1)*lenght_of_small_triangle/2+k*lenght_of_small_triangle,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point2((2*k+1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point3((2*k-1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape->setter_lenght_of_triangle(lenght_of_small_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
		}

	}
	}
	
	else if(container_shapes.getter_shape_type()==Shapes::triangle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point1((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()/2,0);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point2(0,((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);
		(static_cast<Triangle*>(container_shapes.getter_shape_point()))->setter_point3((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle(),((static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle()*sqrt(3.0))/2);

		double lenght_of_triangle=(static_cast<Triangle*>(container_shapes.getter_shape_point()))->getter_lenght_of_triangle();
		double rectangle_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
		double rectangle_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();
		
		
		if(rectangle_height>rectangle_width){
			rectangle_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();
			rectangle_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
		}
		
		for(int i=1;i*rectangle_height<=lenght_of_triangle*sqrt(3.0)/2;++i){ /*The total height should be up to the length of the triangle*/
		
	/* the total width of the rectangles in the line + lenght_of_triangle*sqrt(3.0)/2 should be equall lenght of triangle*/
		for(int j=1;j*rectangle_width<=lenght_of_triangle-((i*rectangle_height*2)/sqrt(3.0));++j){

			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles(); /*the number of rectangles that fit to triangle is constantly updated */
			
			current_shape->setter_position((j-1)*rectangle_width+i*rectangle_height/sqrt(3.0),(lenght_of_triangle*sqrt(3.0)/2-(i)*rectangle_height));
			current_shape->setter_width(rectangle_width);
			current_shape->setter_height(rectangle_height);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
	}
	}
	else if(container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::circle){
	
	(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_x((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
	(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_y((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
	double radius_of_container_circle=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius();
	double radius_of_small_circle=(static_cast<Circle*>(inner_shapez.getter_shape_point()))->getter_radius();
	
	int height_counter;

	/*first for loop is to find out how many circles can fit verticaly*/
	for(int i=1;i*2*radius_of_small_circle<=radius_of_container_circle;++i){
		
		shapeElem current_elem;
		Circle *current_shape=new(Circle);
		current_shape->plus_circles();
		
		current_shape->setter_position_x(radius_of_container_circle);
		current_shape->setter_position_y((2*i-1)*radius_of_small_circle);
		current_shape->setter_radius(radius_of_small_circle);
		
		current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
		current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
		current_elem.setter_shape_point(current_shape);
		current_elem.setter_shape_type(Shapes::circle);
		*this+=current_elem;
	
		/*this for is to find out how many circles fits into the beam(the length of the beam varies depending on where it cuts the circle.) */
		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*i*radius_of_small_circle)-pow(2*i*radius_of_small_circle,2.0))) && (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*((2*i-1)*radius_of_small_circle)-pow((2*i-1)*radius_of_small_circle,2.0))));++j){
			
			shapeElem current_elemm;
			Circle *current_shapee=new(Circle);
			current_shapee->plus_circles(); /*increases the total number of circles*/
			
			current_shapee->setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle);
			current_shapee->setter_position_y((i*2)*radius_of_small_circle);
			current_shapee->setter_radius(radius_of_small_circle);
			
			current_shapee->setter_total_area(current_shapee->getter_total_area()+current_shapee->getter_area());
			current_shapee->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elemm.setter_shape_point(current_shapee);
			current_elemm.setter_shape_type(Shapes::circle);
			*this+=current_elemm;
	
			shapeElem current_elemm2;
			Circle *current_shapee2=new(Circle);
			current_shapee2->plus_circles();
			
			current_shapee2->setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2->setter_position_y(i*2*radius_of_small_circle);
			current_shapee2->setter_radius(radius_of_small_circle);
			
			current_shapee2->setter_total_area(current_shapee2->getter_total_area()+current_shapee2->getter_area());
			current_shapee2->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elemm2.setter_shape_point(current_shapee2);
			current_elemm2.setter_shape_type(Shapes::circle);
			*this+=current_elemm2;
		}
	height_counter=i; /*to know and to use later where we are vertically */

	}
	/* up to here the top of the main circle is filling */
	height_counter+=1;
	 
	/* this part for to filling remaining circle which is under part of circle */
	for( ;height_counter*2*radius_of_small_circle<=2*radius_of_container_circle;++height_counter){
		
		shapeElem current_elem;
		Circle *current_shape=new(Circle);
		current_shape->plus_circles();
		
		current_shape->setter_position_x(radius_of_container_circle);
		current_shape->setter_position_y((2*height_counter-1)*radius_of_small_circle);
		current_shape->setter_radius(radius_of_small_circle);
		
		current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
		current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
		current_elem.setter_shape_point(current_shape);
		current_elem.setter_shape_type(Shapes::circle);
		*this+=current_elem;

		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-2*height_counter*radius_of_small_circle)-pow(2*radius_of_container_circle-2*height_counter*radius_of_small_circle,2.0))) &&  (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle)-pow(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle,2.0))));++j){
			
			shapeElem current_elemm;
			Circle *current_shapee=new(Circle);
			current_shapee->plus_circles();
			
			current_shapee->setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle);
			current_shapee->setter_position_y((height_counter*2)*radius_of_small_circle);
			current_shapee->setter_radius(radius_of_small_circle);
			
			current_shapee->setter_total_area(current_shapee->getter_total_area()+current_shapee->getter_area());
			current_shapee->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elemm.setter_shape_point(current_shapee);
			current_elemm.setter_shape_type(Shapes::circle);
			*this+=current_elemm;

			shapeElem current_elemm2;
			Circle *current_shapee2=new(Circle);
			current_shapee2->plus_circles();
			
			current_shapee2->setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2->setter_position_y(height_counter*2*radius_of_small_circle);
			current_shapee2->setter_radius(radius_of_small_circle);
			
			current_shapee2->setter_total_area(current_shapee2->getter_total_area()+current_shapee2->getter_area());
			current_shapee2->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elemm2.setter_shape_point(current_shapee2);
			current_elemm2.setter_shape_type(Shapes::circle);
			*this+=current_elemm2;

		}
	}
	}
	else if(container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::triangle){
		
		(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_x((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
		(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_y((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
		double radius_of_circle=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius();
		double lenght_of_triangle=(static_cast<Triangle*>(inner_shapez.getter_shape_point()))->getter_lenght_of_triangle();
		
		/*to put one triangle the top of circle if the beam is enough long */
		if(2*pow(2*radius_of_circle*(2*radius_of_circle-lenght_of_triangle)-pow(2*radius_of_circle-lenght_of_triangle,2.0),1/2.0)>=lenght_of_triangle){
			
		shapeElem current_elem;
		Triangle *current_shape=new(Triangle);
		current_shape->plus_triangles();
		
		current_shape->setter_point1(radius_of_circle,0);
		current_shape->setter_point2(radius_of_circle+lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		current_shape->setter_point3(radius_of_circle-lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		current_shape->setter_lenght_of_triangle(lenght_of_triangle);

		current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
		current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
		current_elem.setter_shape_point(current_shape);
		current_elem.setter_shape_type(Shapes::triangle);
		*this+=current_elem;
		}
	int copy_i=0;

	/*these three nested for loop are used to fill above half of circle */
	for(int i=2;(i*(lenght_of_triangle*pow(3,(1/2.0))/2))<=radius_of_circle;++i){

		for(int j=1;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
			
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			}
		int k=0;
		if((pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*(i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){

			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);
			k=1;
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
		}
		/*these two for loop are used to fill one beam that in the middle of circle width triangle*/
		for(int j=2;((j-1+k)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*k*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			}
		copy_i=i;
		}
		
		for(int j=1 ;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			
			shapeElem current_elemm;
			Triangle *current_shapee=new(Triangle);
			current_shapee->plus_triangles();
		
			current_shapee->setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee->setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee->setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j+1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee->setter_lenght_of_triangle(lenght_of_triangle);	

			current_shapee->setter_total_area(current_shapee->getter_total_area()+current_shapee->getter_area());
			current_shapee->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elemm.setter_shape_point(current_shapee);
			current_elemm.setter_shape_type(Shapes::triangle);
			*this+=current_elemm;
		}
		copy_i+=2;
		
		/*these three for loop are used to fill below of circle width triangle*/
		for( ;copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)<=2*radius_of_circle;++copy_i){
	
		for(int j=1;(j*lenght_of_triangle)<=2*pow((2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)),2.0)),1/2.0);++j){
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(2*j-1)*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,1/2.0))/2);
			current_shape->setter_point2(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(j-1)*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_point3(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			}
		
		int z=0;
		if((pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
			z=1;
		}
		/*and the last for loop is used to fill beam(if there is enough long) that in bottom of circle */
		for(int j=2;((j-1+z)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*z*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
			
			shapeElem current_elem;
			Triangle *current_shape=new(Triangle);
			current_shape->plus_triangles();
			
			current_shape->setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape->setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape->setter_lenght_of_triangle(lenght_of_triangle);	

			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::triangle);
			*this+=current_elem;
		}
	}
	}
	else if(container_shapes.getter_shape_type()==Shapes::circle && inner_shapez.getter_shape_type()==Shapes::rectangle){
		
		(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_x((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
		(static_cast<Circle*>(container_shapes.getter_shape_point()))->setter_position_y((static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius());
		double radius_of_circle=(static_cast<Circle*>(container_shapes.getter_shape_point()))->getter_radius();
		double rectangle_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
		double rectangle_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();
		
		if(rectangle_height>rectangle_width){
			rectangle_width=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_height();
			rectangle_height=(static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_width();
		}
	double starter_y=0;
	int height_counter=1;

	do{  /*searches for a length value that can be used to obtain the beam to fit at least one rectangle*/

	starter_y+=0.001;

	}while(sqrt(2*radius_of_circle*starter_y-pow(starter_y,2.0))*2<rectangle_width);

	for(int i=1;starter_y+i*rectangle_height<=radius_of_circle;++i){ /*to progress vertically fit to rectangles until reach diameter */

		/*to reach diameter horizontally */
		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0)));++j){
			
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position(radius_of_circle-sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0))+(j-1)*rectangle_width,starter_y+(i-1)*rectangle_height);
			current_shape->setter_width(rectangle_width);
			current_shape->setter_height(rectangle_height);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
		height_counter=i;
	}
		/*to fill the upper part of the two circles we use above, fill the rest with two loops in the bottom */
	for(int i=height_counter+1;starter_y+i*rectangle_height<=2*radius_of_circle;++i){
		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0)));++j){
			
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position(radius_of_circle-sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0))+(j-1)*rectangle_width,starter_y+(i-1)*rectangle_height);
			current_shape->setter_width(rectangle_width);
			current_shape->setter_height(rectangle_height);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
	}
	
	if((static_cast<Rectangle*>(inner_shapez.getter_shape_point()))->getter_objectCount()==0){

		if(sqrt(pow(rectangle_width/2,2.0)+pow(rectangle_height/2,2.0))<=radius_of_circle){
			
			shapeElem current_elem;
			Rectangle *current_shape=new(Rectangle);
			current_shape->plus_rectangles();
			
			current_shape->setter_position(radius_of_circle-rectangle_width/2,radius_of_circle-rectangle_height/2);
			current_shape->setter_width(rectangle_width);
			current_shape->setter_height(rectangle_height);
			
			current_shape->setter_total_area(current_shape->getter_total_area()+current_shape->getter_area());
			current_shape->setter_total_perimeter(current_shape->getter_total_perimeter()+current_shape->getter_perimeter_lenght());
			current_elem.setter_shape_point(current_shape);
			current_elem.setter_shape_type(Shapes::rectangle);
			*this+=current_elem;
		}
	}
	}	
}
