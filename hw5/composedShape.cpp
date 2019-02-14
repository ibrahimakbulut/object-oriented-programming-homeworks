	
#include "composedShape.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace name_polygonVect;
using namespace name_polygonDyn;
#define PI 3.141592


composedShape::~composedShape(){  //polygondyn objects were not created as dynamic so dont need to delete manuel;

	for(int i=0;i<inner_shapes_vector.size();++i){
		delete inner_shapes_vector[i];
	}
}
composedShape::composedShape(const composedShape& copy_composed){
	container_shape=copy_composed.container_shape;
	inner_shape=copy_composed.inner_shape;

	if(copy_composed.inner_shapes_vector.size()!=0){

	inner_shapes_vector.resize(0);

	for(int i=0;i<copy_composed.inner_shapes_vector.size();++i){

		Shape* temp= new PolygonDyn(*(static_cast<PolygonDyn*>(copy_composed.inner_shapes_vector[i]))); //inner shapes vektor's shape * points to PolygonDyn objects
		inner_shapes_vector.push_back(temp);
	}
	}
}
composedShape& composedShape::operator =(const composedShape& rtSide){
	if(this==&rtSide)
		return *this;

	else{
		container_shape=rtSide.container_shape;
		inner_shape=rtSide.inner_shape;
		if(rtSide.inner_shapes_vector.size()!=0){


		inner_shapes_vector.resize(0);
		for(int i=0;i<rtSide.inner_shapes_vector.size();++i){

			Shape* temp= new PolygonDyn(*(static_cast<PolygonDyn*>(rtSide.inner_shapes_vector[i]))); //inner shapes vektor's shape * points to PolygonDyn objects
			inner_shapes_vector.push_back(temp);
		}
		}
		return *this;
	}
}
composedShape::composedShape(Rectangle Container_shape,Rectangle inner_small_shape){ //constructor with rectangle parameters

PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
	
}
composedShape::composedShape(Rectangle Container_shape,Triangle inner_small_shape){ //constructor with rectangle and triangle parameter

PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Rectangle Container_shape,Circle inner_small_shape){ //constructor with rectangle and circle parameter
	
PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Triangle Container_shape,Rectangle inner_small_shape){ //constructor with triangle and rectangle parameters 
	
PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Triangle Container_shape,Triangle inner_small_shape){ //constructors with triangles parameters
	
PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Triangle Container_shape,Circle inner_small_shape){ //constructor with triangle container and circle inner parameter
	
PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Circle Container_shape,Rectangle inner_small_shape){//constructor with circle container and rectangle inner parameter
	
PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Circle Container_shape,Triangle inner_small_shape){//constructor with circle container and triangle inner parameter

PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(Circle Container_shape,Circle inner_small_shape){//constructor with circle container and circle inner parameter 

PolygonDyn temp_Object(Container_shape);
PolygonDyn temp_Object1(inner_small_shape);
container_shape=temp_Object;
inner_shape=temp_Object1;
}
composedShape::composedShape(){ //otomatically PolygonDyn objects created by their no parameter constructor and inside PolygonDyn objects
								//polygon_points point to nullptr ,size_of_polygon points equal 0.
	
}
composedShape& composedShape::operator +=(Shape& shape){ //this operator overload adds a shape as Polygon to composedShape object.
	inner_shapes_vector.push_back(&shape);
	return *this;
}
const Shape*  composedShape::operator [](unsigned int index)const{ //with this operator an element of vector is only accessable, not changeable
	if(inner_shapes_vector.size()==0){
		cout<<"vector is empty, can not be reached an element of it"<<endl;
		Shape* b=nullptr; //if vector is empty then return a shape element that has null as void pointer variable.
		return b;
	}
	if(index<0 || index>inner_shapes_vector.size()){
		cout<<"vector  index out of range."<<endl;
		Shape* b=nullptr; //if index is wrong then return the first element of vector.
		return b;
	}

	return inner_shapes_vector[index];
}
Shape*  composedShape::operator [](unsigned int index){ //with this operator an element of vector is  accessable and  changeable
	if(inner_shapes_vector.size()==0){
		cout<<"vector is empty, can not be reached an element of it"<<endl;
		Shape* b=nullptr; //if vector is empty then return a shape element that has null as void pointer variable.
		return b;
	}
	if(index<0 || index>inner_shapes_vector.size()){
		cout<<"vector  index out of range."<<endl;
		Shape* b=nullptr; //if index is wrong then return the first element of vector.
		return b;
	}

	return inner_shapes_vector[index];
}
ofstream& composedShape::print_shape(ofstream& outputfile)const{ //for writing a composedshape 

	if( (container_shape.get_size()==3 || container_shape.get_size()==4 || container_shape.get_size()==100) && 
		(inner_shape.get_size()==3 || inner_shape.get_size()==4 || inner_shape.get_size()==100) ){

	double most_right_x,most_down_y;
	most_right_x=container_shape.most_x();
	most_down_y=container_shape.most_y();

	int open=1;
	if(!(outputfile.is_open())){
		open=0;
	if(container_shape.get_size()==100 && inner_shape.get_size()==100)
		outputfile.open("circles_into_circle.svg");
	else if(container_shape.get_size()==100 && inner_shape.get_size()==3)
		outputfile.open("triangles_into_circle.svg");
	else if(container_shape.get_size()==100 && inner_shape.get_size()==4)
		outputfile.open("rectangle_into_circle.svg");
	else if(container_shape.get_size()==4 && inner_shape.get_size()==100)
		outputfile.open("circles_into_rectangle.svg");
	else if(container_shape.get_size()==4 && inner_shape.get_size()==3)
		outputfile.open("triangles_into_rectangle.svg");
	else if(container_shape.get_size()==4 && inner_shape.get_size()==4)
		outputfile.open("rectangles_into_rectangle.svg");
	else if(container_shape.get_size()==3 && inner_shape.get_size()==3)
		outputfile.open("triangles_into_triangle.svg");
	else if(container_shape.get_size()==3 && inner_shape.get_size()==100)
		outputfile.open("circles_into_triangle.svg");
	else 
		outputfile.open("rectangles_into_triangle.svg");  
	}

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<most_right_x<<"\""<<" ";
	outputfile<<"height=\""<<most_down_y<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\"";

	for(auto i=0;i<container_shape.get_size();++i){
		outputfile<<" "<<((container_shape.getter_polygon_points())[i].getter_pos_x())<<","<<((container_shape.getter_polygon_points())[i].getter_pos_y());
		if(i<container_shape.get_size()-1)
			outputfile<<" ";
	}
	outputfile<<"\""<<endl;
	outputfile<<" fill=\"green\" />"<<endl;

	for(unsigned int i=0;i<inner_shapes_vector.size();++i){
		(*((*this)[i])).print_shape(outputfile); 
		//inner shape vector's every element is a inner_shape so this prints every inner_shape
	}
	outputfile<<"</svg>";
	if(!open)
		outputfile.close();
	return outputfile;
	}
	else
		return outputfile;
}
	double composedShape::area()const{
		return (container_shape.area()+inner_shape.area());
	}
	double composedShape::perimeter()const{
		return (container_shape.perimeter()+inner_shape.perimeter());
	}
	
/*ostream& operator <<(ostream& outputStream,const composedShape& main_shape){

	if( main_shape.container_shape.get_size()==100 && main_shape.inner_shape.get_size()==100){

		cout<<"area of container circle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner circle  shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if(main_shape.container_shape.get_size()==100 && main_shape.inner_shape.get_size()==4){

		cout<<"area of container circle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner rectangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;		

	}
	else if(main_shape.container_shape.get_size()==100 && main_shape.inner_shape.get_size()==3){

		cout<<"area of container circle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner triangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if(main_shape.container_shape.get_size()==3 && main_shape.inner_shape.get_size()==100){

		cout<<"area of container triangle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner circle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shape.get_size()==3 && main_shape.inner_shape.get_size()==3){

		cout<<"area of container triangle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner triangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shape.get_size()==3 && main_shape.inner_shape.get_size()==4){

		cout<<"area of container triangle  shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner rectangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shape.get_size()==4 && main_shape.inner_shape.get_size()==100 ){

		cout<<"area of container rectangle  shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner circle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if(main_shape.container_shape.get_size()==4 && main_shape.inner_shape.get_size()==4){

		cout<<"area of container rectangle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner rectangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;
	}
	else if( main_shape.container_shape.get_size()==4 && main_shape.inner_shape.get_size()==3){
	
		cout<<"area of container rectangle shape is "<<main_shape.container_shape.getter_area_of_shape()<<endl;
		cout<<"area of inner triangle shape is "<<main_shape.inner_shape.getter_area_of_shape()<<endl;
		cout<<"can fitted at most "<<main_shape.inner_shapes_vector.size()<<" inner shape to container shape"<<endl;
		cout<<"remain area is "<<main_shape.container_shape.getter_area_of_shape()-(main_shape.inner_shapes_vector.size()*main_shape.inner_shape.getter_area_of_shape())<<endl;
		return outputStream;

	}
	else
		return outputStream;

}*/
void composedShape::optimalFit(){

	if(container_shape.get_size()==4 && inner_shape.get_size()==100){

		/*if(container_shape.most_x()>container_shape.difference_mostAndleast_x){
			for(int i=0;i<container_shape.size_of_points;++i){
				container_shape.polygon_points[i].setter_pos_x()
			}
		}*/

	decltype(3.5*7) width=container_shape.difference_mostAndleast_x();
	auto height=container_shape.difference_mostAndleast_y();
	decltype(3.8*9) radius=inner_shape.difference_mostAndleast_y()/2;
		
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
			Circle current_shape;
			current_shape.plus_circles();
				
			if(i%2==0){
			if((j*radius*2+radius)<=width){
					
				current_shape.setter_position_x((2*j)*radius);
				current_shape.setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
				current_shape.setter_radius(radius);}
			}
			else{
				
				current_shape.setter_position_x(j*radius+(j-1)*radius);
				current_shape.setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
				current_shape.setter_radius(radius);
			}
		current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
		current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);//type of current_shape is circle.PolygonDyn assigment operator take rtSide polygonDyn type.
													//The PolygonDyn(circle&) constructor convert circle to PolygonDyn.
		*this+=*a; //+= operator is used here.
	}
	height_counter=i;
	}
	
	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j){
				
			Circle current_shape;
			current_shape.plus_circles();
				
			if((height_counter-1)%2==0){
			if((j*radius*2)<width){
				current_shape.setter_position_x((2*j)*radius);
			}
			
			current_shape.setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape.setter_radius(radius);
			}
			else{
			current_shape.setter_position_x(j*radius+(j-1)*radius);
			current_shape.setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape.setter_radius(radius);

			}
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());	
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
		}
		height_counter+=1;
	}
	}
	/*rectangular pattern fitting circles part*/
	else{
	for(int i=1;(i*radius*2)<=(height-height_remaning);i++){
		for(int j=1;(j*radius*2)<=(width-width_remaning);j++){
			Circle current_shape;
			current_shape.plus_circles();

			current_shape.setter_position_x(width_remaning/2+j*(radius)+(j-1)*radius);
			current_shape.setter_position_y(height_remaning/2+i*(radius)+(i-1)*radius);
			current_shape.setter_radius(radius);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
		}
	}
	}
	}
	else if(container_shape.get_size()==4 && inner_shape.get_size()==3){
		
	double width=container_shape.difference_mostAndleast_x();
	double height=container_shape.difference_mostAndleast_y();
	double lenght_of_triangle_edge=inner_shape.difference_mostAndleast_x();
	
	if((height<lenght_of_triangle_edge*sqrt(3.0)/2) && width>=lenght_of_triangle_edge){
		width=container_shape.difference_mostAndleast_y();
		height=container_shape.difference_mostAndleast_x();
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
			
			Triangle current_shape;
			current_shape.plus_triangles();
		
			current_shape.setter_point1(2*j*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape.setter_point2((2*j+1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape.setter_point3((2*j-1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape.setter_lenght_of_triangle(lenght_of_triangle_edge);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
			}
		}	
		else{
		for(int j=1;(j*lenght_of_triangle_edge)<=width;++j){

			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1((2*j-1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape.setter_point2((2*j-2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape.setter_point3((j*2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape.setter_lenght_of_triangle(lenght_of_triangle_edge);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area()); //this statement increase total area of inner shapes.
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
			}			
		}
	line_counter=i;
	}
	for(int j=1;(j*lenght_of_triangle_edge+lenght_of_triangle_edge/2)<=width;++j){
		
		Triangle current_shape;
		current_shape.plus_triangles();
		
		current_shape.setter_point1(2*j*lenght_of_triangle_edge/2,(line_counter-1-k)*triangle_lenght);
		current_shape.setter_point2((2*j+1)*lenght_of_triangle_edge/2,(line_counter-k)*triangle_lenght);
		current_shape.setter_point3((2*j-1)*lenght_of_triangle_edge/2,(line_counter-k)*triangle_lenght);
		current_shape.setter_lenght_of_triangle(lenght_of_triangle_edge);

		current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
		current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
	}
	}
	else if(container_shape.get_size()==4 && inner_shape.get_size()==4){
		
	double container_width=container_shape.difference_mostAndleast_x();
	double container_height=container_shape.difference_mostAndleast_y();
	double shape_width=inner_shape.difference_mostAndleast_x();
	double shape_height=inner_shape.difference_mostAndleast_y();

	
	/*if there is a solution that is fully divided on both sides then call it */
if( (static_cast <int>(container_width/shape_height)*shape_height==container_width) && (static_cast <int>(container_height/shape_width)*shape_width==container_height) ){
	
	shape_width=inner_shape.difference_mostAndleast_y();
	shape_height=inner_shape.difference_mostAndleast_x();
}
	if(!((shape_width>container_width && shape_height>container_height) || (shape_height>container_width && shape_width>container_height) || (shape_width>container_width && shape_width>container_height && shape_height>container_height && shape_height>container_width))){
		
	int height_counter,width_counter;
	
/*likewise continues to lay shapes.*/
	for(int i=1;i*shape_height<=container_height;++i){

		for(int j=1;j*shape_width<=container_width;++j){
			
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position((j-1)*shape_width,(i-1)*shape_height);
			current_shape.setter_width(shape_width);
			current_shape.setter_height(shape_height);
	
			width_counter=j;
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
		height_counter=i;
	}
	/*if there is space left on the right side, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=container_height;++i){

		for(int j=1;j*shape_height<=(container_width-width_counter*shape_width);++j){
		
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position(width_counter*shape_width+(j-1)*shape_height,(i-1)*shape_width);
			current_shape.setter_width(shape_height);
			current_shape.setter_height(shape_width);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}	
	/*if the space is left below, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=(container_height-height_counter*shape_height);++i){

		for(int j=1;j*shape_height<=container_width;++j){
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position((j-1)*shape_height,height_counter*shape_height+(i-1)*shape_height);
			current_shape.setter_width(shape_height);
			current_shape.setter_height(shape_width);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}	
	}	
	}
	else if(container_shape.get_size()==3 && inner_shape.get_size()==100){

		double lenght_of_triangle=container_shape.difference_mostAndleast_x();
		double radius_of_circle=inner_shape.difference_mostAndleast_x();
		
		for(int i=1;i*radius_of_circle*sqrt(3.0)+radius_of_circle<=lenght_of_triangle*sqrt(3.0)/2;++i){
		for(int j=1;(j*2)*radius_of_circle+(radius_of_circle*sqrt(3.0)-radius_of_circle)<=lenght_of_triangle-(radius_of_circle*sqrt(3.0)-radius_of_circle)-(i-1)*2*radius_of_circle;++j){
			
			Circle current_shape;
			current_shape.plus_circles();
			
			current_shape.setter_position_x((i-2)*radius_of_circle+radius_of_circle*sqrt(3.0)+(j*2-1)*radius_of_circle);
			current_shape.setter_position_y(lenght_of_triangle*sqrt(3.0)/2+radius_of_circle-(2*radius_of_circle+(i-1)*radius_of_circle*sqrt(3.0)));
			current_shape.setter_radius(radius_of_circle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}	
	}
	else if(container_shape.get_size()==3 && inner_shape.get_size()==3){
		

		double lenght_of_container_triangle=container_shape.difference_mostAndleast_x();
		double lenght_of_small_triangle=inner_shape.difference_mostAndleast_x();
		
			/*This loop determines the total height*/
	for(int i=1;i*(lenght_of_small_triangle*pow(3,1/2.0)/2)<=lenght_of_container_triangle*pow(3,1/2.0)/2;++i){
		
		/*this loop fit triangles in one way*/
		int j=1;
		for( ;j*lenght_of_small_triangle<=(lenght_of_container_triangle-(i-1)*lenght_of_small_triangle);++j){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1((i-1)*lenght_of_small_triangle/2+(2*j-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2(j*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3((j-1)*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_lenght_of_triangle(lenght_of_small_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;

		}
		/*this loop fit triangles in other way(dont use the rotate property)*/
		for(int k=1;k<j-1;++k){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1((i-1)*lenght_of_small_triangle/2+k*lenght_of_small_triangle,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2((2*k+1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3((2*k-1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_lenght_of_triangle(lenght_of_small_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}

	}
	}
	
	else if(container_shape.get_size()==3 && inner_shape.get_size()==4){
		
		double lenght_of_triangle=container_shape.difference_mostAndleast_x();
		double rectangle_width=inner_shape.difference_mostAndleast_x();
		double rectangle_height=inner_shape.difference_mostAndleast_y();
		
		
		if(rectangle_height>rectangle_width){
			rectangle_width=inner_shape.difference_mostAndleast_y();
			rectangle_height=inner_shape.difference_mostAndleast_x();
		}
		
		for(int i=1;i*rectangle_height<=lenght_of_triangle*sqrt(3.0)/2;++i){ /*The total height should be up to the length of the triangle*/
		
	/* the total width of the rectangles in the line + lenght_of_triangle*sqrt(3.0)/2 should be equall lenght of triangle*/
		for(int j=1;j*rectangle_width<=lenght_of_triangle-((i*rectangle_height*2)/sqrt(3.0));++j){

			Rectangle current_shape;
			current_shape.plus_rectangles(); /*the number of rectangles that fit to triangle is constantly updated */
			
			current_shape.setter_position((j-1)*rectangle_width+i*rectangle_height/sqrt(3.0),(lenght_of_triangle*sqrt(3.0)/2-(i)*rectangle_height));
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}
	}
	else if(container_shape.get_size()==100 && inner_shape.get_size()==100){
	
	double radius_of_container_circle=container_shape.difference_mostAndleast_x()/2;
	double radius_of_small_circle=inner_shape.difference_mostAndleast_x()/2;
	
	int height_counter;

	/*first for loop is to find out how many circles can fit verticaly*/
	for(int i=1;i*2*radius_of_small_circle<=radius_of_container_circle;++i){
		
		Circle current_shape;
		current_shape.plus_circles();
		
		current_shape.setter_position_x(radius_of_container_circle);
		current_shape.setter_position_y((2*i-1)*radius_of_small_circle);
		current_shape.setter_radius(radius_of_small_circle);
		
		current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
		current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
	
		/*this for is to find out how many circles fits into the beam(the length of the beam varies depending on where it cuts the circle.) */
		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*i*radius_of_small_circle)-pow(2*i*radius_of_small_circle,2.0))) && (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*((2*i-1)*radius_of_small_circle)-pow((2*i-1)*radius_of_small_circle,2.0))));++j){
			
			Circle current_shapee;
			current_shapee.plus_circles(); /*increases the total number of circles*/
			
			current_shapee.setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-1)*radius_of_small_circle-1*radius_of_small_circle);
			current_shapee.setter_position_y((i*2)*radius_of_small_circle);
			current_shapee.setter_radius(radius_of_small_circle);
			
			current_shapee.setter_total_area(current_shapee.getter_total_area()+current_shapee.area());
			current_shapee.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *b=new PolygonDyn(current_shapee);
			*this+=*b;
	
			Circle current_shapee2;
			current_shapee2.plus_circles();
			
			current_shapee2.setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2.setter_position_y((i*2)*radius_of_small_circle);
			current_shapee2.setter_radius(radius_of_small_circle);
			
			current_shapee2.setter_total_area(current_shapee2.getter_total_area()+current_shapee2.area());
			current_shapee2.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *c=new PolygonDyn(current_shapee2);
			*this+=*c;
		}
	height_counter=i; /*to know and to use later where we are vertically */

	}
	/* up to here the top of the main circle is filling */
	height_counter+=1;
	 
	/* this part for to filling remaining circle which is under part of circle */
	for( ;height_counter*2*radius_of_small_circle<=2*radius_of_container_circle;++height_counter){
		
		Circle current_shape;
		current_shape.plus_circles();
		
		current_shape.setter_position_x(radius_of_container_circle);
		current_shape.setter_position_y((2*height_counter-1)*radius_of_small_circle);
		current_shape.setter_radius(radius_of_small_circle);
		
		current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
		current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;

		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-2*height_counter*radius_of_small_circle)-pow(2*radius_of_container_circle-2*height_counter*radius_of_small_circle,2.0))) &&  (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle)-pow(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle,2.0))));++j){
			
			Circle current_shapee;
			current_shapee.plus_circles();
			
			current_shapee.setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-1)*radius_of_small_circle-1*radius_of_small_circle);
			current_shapee.setter_position_y((height_counter*2)*radius_of_small_circle);
			current_shapee.setter_radius(radius_of_small_circle);
			
			current_shapee.setter_total_area(current_shapee.getter_total_area()+current_shapee.area());
			current_shapee.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *b=new PolygonDyn(current_shapee);
			*this+=*b;

			Circle current_shapee2;
			current_shapee2.plus_circles();
			
			current_shapee2.setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2.setter_position_y((height_counter*2)*radius_of_small_circle);
			current_shapee2.setter_radius(radius_of_small_circle);
			
			current_shapee2.setter_total_area(current_shapee2.getter_total_area()+current_shapee2.area());
			current_shapee2.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *c=new PolygonDyn(current_shapee2);
			*this+=*c;

		}
	}
	}
	else if(container_shape.get_size()==100 && inner_shape.get_size()==3){
		
		double radius_of_circle=container_shape.difference_mostAndleast_x()/2;
		double lenght_of_triangle=inner_shape.difference_mostAndleast_x();
		
		/*to put one triangle the top of circle if the beam is enough long */
		if(2*pow(2*radius_of_circle*(2*radius_of_circle-lenght_of_triangle)-pow(2*radius_of_circle-lenght_of_triangle,2.0),1/2.0)>=lenght_of_triangle){
		Triangle current_shape;
		current_shape.plus_triangles();
		
		current_shape.setter_point1(radius_of_circle,0);
		current_shape.setter_point2(radius_of_circle+lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		current_shape.setter_point3(radius_of_circle-lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		current_shape.setter_lenght_of_triangle(lenght_of_triangle);

		current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
		current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
		PolygonDyn *a=new PolygonDyn(current_shape);
		*this+=*a;
		}
	int copy_i=0;

	/*these three nested for loop are used to fill above half of circle */
	for(int i=2;(i*(lenght_of_triangle*pow(3,(1/2.0))/2))<=radius_of_circle;++i){
	
		for(int j=1;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
			}
		int k=0;
		if((pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*(i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){

			Triangle current_shape;
			current_shape.plus_triangles();
		
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);
			k=1;
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
		/*these two for loop are used to fill one beam that in the middle of circle width triangle*/
		for(int j=2;(((j-1+k)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*k*lenght_of_triangle/2)))<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			Triangle current_shape;
			current_shape.plus_triangles();

			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
			}
		copy_i=i;
		}
		
		for(int j=1 ;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
			
			Triangle current_shapee;
			current_shapee.plus_triangles();
		
			current_shapee.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j+1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee.setter_lenght_of_triangle(lenght_of_triangle);	

			current_shapee.setter_total_area(current_shapee.getter_total_area()+current_shapee.area());
			current_shapee.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *b=new PolygonDyn(current_shapee);
			*this+=*b;
		}
		copy_i+=2;
		
		/*these three for loop are used to fill below of circle width triangle*/
		for( ;copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)<=2*radius_of_circle;++copy_i){
	
		for(int j=1;(j*lenght_of_triangle)<=2*pow((2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)),2.0)),1/2.0);++j){
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(2*j-1)*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,1/2.0))/2);
			current_shape.setter_point2(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(j-1)*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3(radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
			}
		
		int z=0;
		if((pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
			z=1;
		}
		/*and the last for loop is used to fill beam(if there is enough long) that in bottom of circle */
		for(int j=2;((j-1+z)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*z*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_lenght_of_triangle(lenght_of_triangle);	

			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}
	}
	else if(container_shape.get_size()==100 && inner_shape.get_size()==4){
		
		double radius_of_circle=container_shape.difference_mostAndleast_x()/2;
		double rectangle_width=inner_shape.difference_mostAndleast_x();
		double rectangle_height=inner_shape.difference_mostAndleast_y();
		
		if(rectangle_height>rectangle_width){
			rectangle_width=inner_shape.difference_mostAndleast_y();
			rectangle_height=inner_shape.difference_mostAndleast_x();
		}
	double starter_y=0;
	int height_counter=1;

	do{  /*searches for a length value that can be used to obtain the beam to fit at least one rectangle*/

	starter_y+=0.001;

	}while(sqrt(2*radius_of_circle*starter_y-pow(starter_y,2.0))*2<rectangle_width);

	for(int i=1;starter_y+i*rectangle_height<=radius_of_circle;++i){ /*to progress vertically fit to rectangles until reach diameter */

		/*to reach diameter horizontally */
		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0)));++j){
			
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position(radius_of_circle-sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0))+(j-1)*rectangle_width,starter_y+(i-1)*rectangle_height);
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
		height_counter=i;
	}
		/*to fill the upper part of the two circles we use above, fill the rest with two loops in the bottom */
	for(int i=height_counter+1;starter_y+i*rectangle_height<=2*radius_of_circle;++i){
		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0)));++j){
			
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position(radius_of_circle-sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0))+(j-1)*rectangle_width,starter_y+(i-1)*rectangle_height);
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}
	Rectangle z;
	if(z.getter_objectCount()==0){

		if(sqrt(pow(rectangle_width/2,2.0)+pow(rectangle_height/2,2.0))<=radius_of_circle){
			
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position(radius_of_circle-rectangle_width/2,radius_of_circle-rectangle_height/2);
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			current_shape.setter_total_area(current_shape.getter_total_area()+current_shape.area());
			current_shape.setter_total_perimeter(current_shape.getter_total_perimeter()+current_shape.perimeter());
			PolygonDyn *a=new PolygonDyn(current_shape);
			*this+=*a;
		}
	}
	}	
}
