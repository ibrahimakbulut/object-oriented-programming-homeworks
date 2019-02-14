#include "composedShape.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>

#define PI 3.141592

using namespace std;

composedShape::composedShape(Rectangle Container_shape,Rectangle inner_small_shape){
	
	container_rectangle.setter_position(0,0);
	container_rectangle.setter_height(Container_shape.getter_height());
	container_rectangle.setter_width(Container_shape.getter_width());
	
	inner_rectangle.setter_position(0,0);
	inner_rectangle.setter_height(inner_small_shape.getter_height());
	inner_rectangle.setter_width(inner_small_shape.getter_width());
	
	container_shape='R';
	inner_shape='R';
	
}
composedShape::composedShape(Rectangle Container_shape,Triangle inner_small_shape){

	container_rectangle.setter_position(0,0);
	container_rectangle.setter_height(Container_shape.getter_height());
	container_rectangle.setter_width(Container_shape.getter_width());
	
	inner_triangle.setter_point1(0,0);
	inner_triangle.setter_point2(0,0);
	inner_triangle.setter_point3(0,0);
	inner_triangle.setter_lenght_of_triangle(inner_small_shape.getter_lenght_of_triangle());
	
	container_shape='R';
	inner_shape='T';
}
composedShape::composedShape(Rectangle Container_shape,Circle inner_small_shape){
	
	container_rectangle.setter_position(0,0);
	container_rectangle.setter_height(Container_shape.getter_height());
	container_rectangle.setter_width(Container_shape.getter_width());
	
	inner_circle.setter_position_x(0);
	inner_circle.setter_position_y(0);
	inner_circle.setter_radius(inner_small_shape.getter_radius());
	
	container_shape='R';
	inner_shape='C';
}
composedShape::composedShape(Triangle Container_shape,Rectangle inner_small_shape){
	
	container_triangle.setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	container_triangle.setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	container_triangle.setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	
	inner_rectangle.setter_position(0,0);
	inner_rectangle.setter_height(inner_small_shape.getter_height());
	inner_rectangle.setter_width(inner_small_shape.getter_width());
	
	container_shape='T';
	inner_shape='R';
}
composedShape::composedShape(Triangle Container_shape,Triangle inner_small_shape){
	
	container_triangle.setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	container_triangle.setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	container_triangle.setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	
	inner_triangle.setter_point1(0,0);
	inner_triangle.setter_point2(0,0);
	inner_triangle.setter_point3(0,0);
	inner_triangle.setter_lenght_of_triangle(inner_small_shape.getter_lenght_of_triangle());
	
	container_shape='T';
	inner_shape='T';
}
composedShape::composedShape(Triangle Container_shape,Circle inner_small_shape){
	
	container_triangle.setter_point1(Container_shape.getter_lenght_of_triangle()/2,0);
	container_triangle.setter_point2(0,(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	container_triangle.setter_point3(Container_shape.getter_lenght_of_triangle(),(Container_shape.getter_lenght_of_triangle()*sqrt(3.0))/2);
	
	inner_circle.setter_position_x(0);
	inner_circle.setter_position_y(0);
	inner_circle.setter_radius(inner_small_shape.getter_radius());
	
	container_shape='T';
	inner_shape='C';
}
composedShape::composedShape(Circle Container_shape,Rectangle inner_small_shape){
	
	container_circle.setter_position_x(Container_shape.getter_radius());
	container_circle.setter_position_y(Container_shape.getter_radius());
	container_circle.setter_radius(Container_shape.getter_radius());
	
	inner_rectangle.setter_position(0,0);
	inner_rectangle.setter_width(inner_small_shape.getter_width());
	inner_rectangle.setter_height(inner_small_shape.getter_height());
	
	container_shape='C';
	inner_shape='R';
}
composedShape::composedShape(Circle Container_shape,Triangle inner_small_shape){
	
	container_circle.setter_position_x(Container_shape.getter_radius());
	container_circle.setter_position_y(Container_shape.getter_radius());
	container_circle.setter_radius(Container_shape.getter_radius());
	
	inner_triangle.setter_point1(0,0);
	inner_triangle.setter_point2(0,0);
	inner_triangle.setter_point3(0,0);
	inner_triangle.setter_lenght_of_triangle(inner_small_shape.getter_lenght_of_triangle());
	
	container_shape='C';
	inner_shape='T';
	
}
composedShape::composedShape(Circle Container_shape,Circle inner_small_shape){
	
	container_circle.setter_position_x(Container_shape.getter_radius());
	container_circle.setter_position_y(Container_shape.getter_radius());
	container_circle.setter_radius(Container_shape.getter_radius());
	
	inner_circle.setter_position_x(0);
	inner_circle.setter_position_y(0);
	inner_circle.setter_radius(inner_small_shape.getter_radius());
	
	container_shape='C';
	inner_shape='C';
}
composedShape::composedShape(){
	
	container_shape='N';  //container and inner shapes are not yet clear
	inner_shape='N';
}
	
void composedShape::draw(ofstream& outputfile)const{
	
	if(container_shape=='C' && inner_shape=='C'){
	
	outputfile.open("circles_into_circle.svg");
		
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_circle.getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<container_circle.getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<container_circle.getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<container_circle.getter_pos_y()<<"\""<<" r=\""<<container_circle.getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_circle_shapes.size();++i){
		
		inner_circle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='C' && inner_shape=='R'){
		
	outputfile.open("rectangles_into_circle.svg");
	
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_circle.getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<container_circle.getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<container_circle.getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<container_circle.getter_pos_y()<<"\""<<" r=\""<<container_circle.getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_rectangle_shapes.size();++i){
		
		inner_rectangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='C' && inner_shape=='T'){
		
	outputfile.open("triangles_into_circle.svg");	
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_circle.getter_radius()*2<<"\""<<" ";
	outputfile<<"height=\""<<container_circle.getter_radius()*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<container_circle.getter_pos_x()<<"\" ";
	outputfile<<"cy=\""<<container_circle.getter_pos_y()<<"\""<<" r=\""<<container_circle.getter_radius()<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_triangle_shapes.size();++i){
		
		inner_triangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();	
	}
	else if(container_shape=='T' && inner_shape=='C'){
		
	outputfile.open("circles_into_triangles.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_triangle.getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<container_triangle.getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<container_triangle.getter_lenght_of_triangle()<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_circle_shapes.size();++i){
		
		inner_circle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='T' && inner_shape=='T'){
		
	outputfile.open("triangles_into_triangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_triangle.getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<container_triangle.getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<container_triangle.getter_lenght_of_triangle()<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_triangle_shapes.size();++i){
		
		inner_triangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='T' && inner_shape=='R'){
		
	outputfile.open("rectangles_into_triangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_triangle.getter_lenght_of_triangle()<<"\""<<" ";
	outputfile<<"height=\""<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<container_triangle.getter_lenght_of_triangle()/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2;
	outputfile<<" "<<container_triangle.getter_lenght_of_triangle()<<" ,"<<container_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;
	
	for(int i=0;i<inner_rectangle_shapes.size();++i){
		
		inner_rectangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='R' && inner_shape=='C'){
		
	outputfile.open("circles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_rectangle.getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<container_rectangle.getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;
	
	for(int i=0;i<inner_circle_shapes.size();++i){
		
		inner_circle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='R' && inner_shape=='T'){
		
	outputfile.open("triangles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_rectangle.getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<container_rectangle.getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;
	
	for(int i=0;i<inner_triangle_shapes.size();++i){
		
		inner_triangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
	else if(container_shape=='R' && inner_shape=='R'){
		
	outputfile.open("rectangles_into_rectangle.svg");
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_rectangle.getter_width()<<"\""<<" ";
	outputfile<<"height=\""<<container_rectangle.getter_height()<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;
	
	for(int i=0;i<inner_rectangle_shapes.size();++i){
		
		inner_rectangle_shapes[i].draw(outputfile);
	}
	outputfile<<"</svg>";
	outputfile.close();
	}
}
double composedShape::calculate_remain_area()const{

	if(container_shape=='C' && inner_shape=='C'){
		double container_area=PI*pow(container_circle.getter_radius(),2.0);
		double inner_shape_area=PI*pow(inner_circle.getter_radius(),2.0);
		
		return (container_area-(inner_circle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='C' && inner_shape=='R'){
		
		double container_area=PI*pow(container_circle.getter_radius(),2.0);
		double inner_shape_area=inner_rectangle.getter_height()*inner_rectangle.getter_width();
		
		return (container_area-(inner_rectangle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='C' && inner_shape=='T'){
		
		double container_area=PI*pow(container_circle.getter_radius(),2.0);
		double inner_shape_area=pow(inner_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		
		return (container_area-(inner_triangle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='T' && inner_shape=='C'){
		
		double container_area=pow(container_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		double inner_shape_area=PI*pow(inner_circle.getter_radius(),2.0);
		
		return (container_area-(inner_circle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='T' && inner_shape=='T'){
		
		double container_area=pow(container_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		double  inner_shape_area=pow(inner_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		
		return (container_area-(inner_triangle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='T' && inner_shape=='R'){
		double container_area=pow(container_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		double inner_shape_area=inner_rectangle.getter_height()*inner_rectangle.getter_width();
		
		return (container_area-(inner_rectangle.getter_objectCount()*inner_shape_area));
		
	}
	else if(container_shape=='R' && inner_shape=='C'){
		
		double  container_area=container_rectangle.getter_height()*container_rectangle.getter_width();
		double  inner_shape_area=PI*pow(inner_circle.getter_radius(),2.0);
		
		return (container_area-(inner_circle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='R' && inner_shape=='T'){
		
		double  container_area=container_rectangle.getter_height()*container_rectangle.getter_width();
		double inner_shape_area=pow(inner_triangle.getter_lenght_of_triangle(),2.0)*sqrt(3.0)/4;
		return (container_area-(inner_triangle.getter_objectCount()*inner_shape_area));
	}
	else if(container_shape=='R' && inner_shape=='R'){
		
		double container_area=container_rectangle.getter_height()*container_rectangle.getter_width();
		double  inner_shape_area=inner_rectangle.getter_height()*inner_rectangle.getter_width();
		return (container_area-(inner_rectangle.getter_objectCount()*inner_shape_area));
	}
	else
		return 0;
}
void composedShape::optimalFit(){
	
	if(container_shape=='R' && inner_shape=='C'){
		
	double width=container_rectangle.getter_width();
	double height=container_rectangle.getter_height();
	double radius=inner_circle.getter_radius();	
		
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
	int i=height_counter;

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
					
					current_shape.setter_position_x(j*radius*2);
					current_shape.setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
					current_shape.setter_radius(radius);}
				}
				else{
					
					current_shape.setter_position_x(j*radius+(j-1)*radius);
					current_shape.setter_position_y(radius+(i-1)*(radius*pow(3,(1/2.0))));
					current_shape.setter_radius(radius);
				}
				
			inner_circle_shapes.push_back(current_shape);
		}

		height_counter=i;
	}
	

	int i=height_counter;

	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j){
				
			Circle current_shape;
			current_shape.plus_circles();
				
			if((height_counter-1)%2==0){
			if((j*radius*2)<width){
				current_shape.setter_position_x(j*radius*2);
			}
			
			current_shape.setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape.setter_radius(radius);
			}
			else{
			current_shape.setter_position_x(j*radius+(j-1)*radius);
			current_shape.setter_position_y(radius+(height_counter)*(radius*pow(3,(1/2.0))));
			current_shape.setter_radius(radius);

			}
			inner_circle_shapes.push_back(current_shape);
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
			
			inner_circle_shapes.push_back(current_shape);
		}
	}
	}
	}
	
	else if(container_shape=='R' && inner_shape=='T'){
		
	double width=container_rectangle.getter_width();
	double height=container_rectangle.getter_height();
	double lenght_of_triangle_edge=inner_triangle.getter_lenght_of_triangle();
	
	if((height<lenght_of_triangle_edge*sqrt(3.0)/2) && width>=lenght_of_triangle_edge){
		width=container_rectangle.getter_height();
		height=container_rectangle.getter_width();
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
			
			inner_triangle_shapes.push_back(current_shape);
			}
		}	
		else{
		for(int j=1;(j*lenght_of_triangle_edge)<=width;++j){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1((2*j-1)*lenght_of_triangle_edge/2,(i-k)*triangle_lenght);
			current_shape.setter_point2((2*j-2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);
			current_shape.setter_point3((j*2)*lenght_of_triangle_edge/2,(i-1-k)*triangle_lenght);

			inner_triangle_shapes.push_back(current_shape);
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

		inner_triangle_shapes.push_back(current_shape);
	}
	}
	else if(container_shape=='R' && inner_shape=='R'){
		
	double container_width=container_rectangle.getter_width();
	double container_height=container_rectangle.getter_height();
	double shape_width=inner_rectangle.getter_width();
	double shape_height=inner_rectangle.getter_height();
	
	/*if there is a solution that is fully divided on both sides then call it */
if( (static_cast <int>(container_width/shape_height)*shape_height==container_width) && (static_cast <int>(container_height/shape_width)*shape_width==container_height) ){
	
	shape_width=inner_rectangle.getter_height();
	shape_height=inner_rectangle.getter_width();
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
			
			inner_rectangle_shapes.push_back(current_shape);
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
			
			inner_rectangle_shapes.push_back(current_shape);
				
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
			
			inner_rectangle_shapes.push_back(current_shape);
		}
	}	
	}	
	}
	else if(container_shape=='T' && inner_shape=='C'){
		
		container_triangle.setter_point1(container_triangle.getter_lenght_of_triangle()/2,0);
		container_triangle.setter_point2(0,(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		container_triangle.setter_point3(container_triangle.getter_lenght_of_triangle(),(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		
		double lenght_of_triangle=container_triangle.getter_lenght_of_triangle();
		double radius_of_circle=inner_circle.getter_radius();
		
		for(int i=1;i*radius_of_circle*sqrt(3.0)+radius_of_circle<=lenght_of_triangle*sqrt(3.0)/2;++i){
		for(int j=1;(j*2)*radius_of_circle+(radius_of_circle*sqrt(3.0)-radius_of_circle)<=lenght_of_triangle-(radius_of_circle*sqrt(3.0)-radius_of_circle)-(i-1)*2*radius_of_circle;++j){
			
			Circle current_shape;
			current_shape.plus_circles();
			
			current_shape.setter_position_x((i-1)*radius_of_circle+radius_of_circle*sqrt(3.0)+(j*2-2)*radius_of_circle);
			current_shape.setter_position_y(lenght_of_triangle*sqrt(3.0)/2-(radius_of_circle+(i-1)*radius_of_circle*sqrt(3.0)));
			current_shape.setter_radius(radius_of_circle);

			inner_circle_shapes.push_back(current_shape);
		}
	}	
	}
	else if(container_shape=='T' && inner_shape=='T'){
		
		container_triangle.setter_point1(container_triangle.getter_lenght_of_triangle()/2,0);
		container_triangle.setter_point2(0,(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		container_triangle.setter_point3(container_triangle.getter_lenght_of_triangle(),(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		
		double lenght_of_container_triangle=container_triangle.getter_lenght_of_triangle();
		double lenght_of_small_triangle=inner_triangle.getter_lenght_of_triangle();
		
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

			inner_triangle_shapes.push_back(current_shape);

		}
		/*this loop fit triangles in other way(dont use the rotate property)*/
		for(int k=1;k<j-1;++k){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1((i-1)*lenght_of_small_triangle/2+k*lenght_of_small_triangle,lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2((2*k+1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3((2*k-1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2,lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2));

			inner_triangle_shapes.push_back(current_shape);
		}

	}
	}
	else if(container_shape=='T' && inner_shape=='R'){
		
		container_triangle.setter_point1(container_triangle.getter_lenght_of_triangle()/2,0);
		container_triangle.setter_point2(0,(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		container_triangle.setter_point3(container_triangle.getter_lenght_of_triangle(),(container_triangle.getter_lenght_of_triangle()*sqrt(3.0))/2);
		
		double lenght_of_triangle=container_triangle.getter_lenght_of_triangle();
		double rectangle_width=inner_rectangle.getter_width();
		double rectangle_height=inner_rectangle.getter_height();
		
		
		if(rectangle_height>rectangle_width){
			rectangle_width=inner_rectangle.getter_height();
			rectangle_height=inner_rectangle.getter_width();
		}
		
		for(int i=1;i*rectangle_height<=lenght_of_triangle*sqrt(3.0)/2;++i){ /*The total height should be up to the length of the triangle*/
		
	/* the total width of the rectangles in the line + lenght_of_triangle*sqrt(3.0)/2 should be equall lenght of triangle*/
		for(int j=1;j*rectangle_width<=lenght_of_triangle-((i*rectangle_height*2)/sqrt(3.0));++j){

			Rectangle current_shape;
			current_shape.plus_rectangles(); /*the number of rectangles that fit to triangle is constantly updated */
			
			current_shape.setter_position((j-1)*rectangle_width+i*rectangle_height/sqrt(3.0),(lenght_of_triangle*sqrt(3.0)/2-(i)*rectangle_height));
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			inner_rectangle_shapes.push_back(current_shape);
		}
	}
	}
	else if(container_shape=='C' && inner_shape=='C'){
	
	container_circle.setter_position_x(container_circle.getter_radius());
	container_circle.setter_position_y(container_circle.getter_radius());
	double radius_of_container_circle=container_circle.getter_radius();
	double radius_of_small_circle=inner_circle.getter_radius();
	
	int height_counter;

	int total_circles=0;

	/*first for loop is to find out how many circles can fit verticaly*/
	for(int i=1;i*2*radius_of_small_circle<=radius_of_container_circle;++i){
		
		Circle current_shape;
		current_shape.plus_circles();
		
		current_shape.setter_position_x(radius_of_container_circle);
		current_shape.setter_position_y((2*i-1)*radius_of_small_circle);
		current_shape.setter_radius(radius_of_small_circle);
		
		inner_circle_shapes.push_back(current_shape);
	
		/*this for is to find out how many circles fits into the beam(the length of the beam varies depending on where it cuts the circle.) */
		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*i*radius_of_small_circle)-pow(2*i*radius_of_small_circle,2.0))) && (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*((2*i-1)*radius_of_small_circle)-pow((2*i-1)*radius_of_small_circle,2.0))));++j){
			
			Circle current_shapee;
			current_shapee.plus_circles(); /*increases the total number of circles*/
			
			current_shapee.setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle);
			current_shapee.setter_position_y((i*2)*radius_of_small_circle);
			current_shapee.setter_radius(radius_of_small_circle);
			
			inner_circle_shapes.push_back(current_shapee);
	
			Circle current_shapee2;
			current_shapee2.plus_circles();
			
			current_shapee2.setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2.setter_position_y(i*2*radius_of_small_circle);
			current_shapee2.setter_radius(radius_of_small_circle);
			
			inner_circle_shapes.push_back(current_shapee2);
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
		
		inner_circle_shapes.push_back(current_shape);

		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-2*height_counter*radius_of_small_circle)-pow(2*radius_of_container_circle-2*height_counter*radius_of_small_circle,2.0))) &&  (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle)-pow(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle,2.0))));++j){
			
			Circle current_shapee;
			current_shapee.plus_circles();
			
			current_shapee.setter_position_x(radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle);
			current_shapee.setter_position_y((height_counter*2)*radius_of_small_circle);
			current_shapee.setter_radius(radius_of_small_circle);
			
			inner_circle_shapes.push_back(current_shapee);

			Circle current_shapee2;
			current_shapee2.plus_circles();
			
			current_shapee2.setter_position_x(radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle));
			current_shapee2.setter_position_y(height_counter*2*radius_of_small_circle);
			current_shapee2.setter_radius(radius_of_small_circle);
			
			inner_circle_shapes.push_back(current_shapee2);

		}
	}
	}
	else if(container_shape=='C' && inner_shape=='T'){
		
		container_circle.setter_position_x(container_circle.getter_radius());
		container_circle.setter_position_y(container_circle.getter_radius());
		double radius_of_circle=container_circle.getter_radius();
		double lenght_of_triangle=inner_triangle.getter_lenght_of_triangle();
		
		/*to put one triangle the top of circle if the beam is enough long */
		if(2*pow(2*radius_of_circle*(2*radius_of_circle-lenght_of_triangle)-pow(2*radius_of_circle-lenght_of_triangle,2.0),1/2.0)>=lenght_of_triangle){
			
		Triangle current_shape;
		current_shape.plus_triangles();
		
		current_shape.setter_point1(radius_of_circle,0);
		current_shape.setter_point2(radius_of_circle+lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		current_shape.setter_point3(radius_of_circle-lenght_of_triangle/2,1*(lenght_of_triangle*pow(3,(1/2.0))/2));
		
		inner_triangle_shapes.push_back(current_shape);
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
		
			inner_triangle_shapes.push_back(current_shape);	
			}
		int k=0;
		if((pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*(i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){

			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			k=1;
			inner_triangle_shapes.push_back(current_shape);
		}
		/*these two for loop are used to fill one beam that in the middle of circle width triangle*/
		for(int j=2;((j-1+k)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*k*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,i*(lenght_of_triangle*pow(3,(1/2.0))/2));
			
			inner_triangle_shapes.push_back(current_shape);
			}
		copy_i=i;
		}
		
		for(int j=1 ;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			
			inner_triangle_shapes.push_back(current_shape);
			
			Triangle current_shapee;
			current_shapee.plus_triangles();
		
			current_shapee.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle,copy_i*(lenght_of_triangle*pow(3,1/2.0)/2));
			current_shapee.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j+1)*lenght_of_triangle/2,(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2));
			
			inner_triangle_shapes.push_back(current_shapee);
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
			inner_triangle_shapes.push_back(current_shape);
			}
		
		int z=0;
		if((pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));

			inner_triangle_shapes.push_back(current_shape);
			z=1;
		}
		/*and the last for loop is used to fill beam(if there is enough long) that in bottom of circle */
		for(int j=2;((j-1+z)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*z*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
			
			Triangle current_shape;
			current_shape.plus_triangles();
			
			current_shape.setter_point1(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle,(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2));
			current_shape.setter_point2(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			current_shape.setter_point3(radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2,(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2));
			
			inner_triangle_shapes.push_back(current_shape);
		}
	}
	}
	else if(container_shape=='C' && inner_shape=='R'){
		
		container_circle.setter_position_x(container_circle.getter_radius());
		container_circle.setter_position_y(container_circle.getter_radius());
		double radius_of_circle=container_circle.getter_radius();
		double rectangle_width=inner_rectangle.getter_width();
		double rectangle_height=inner_rectangle.getter_height();
		
		if(rectangle_height>rectangle_width){
			rectangle_width=inner_rectangle.getter_height();
			rectangle_height=inner_rectangle.getter_width();
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
			
			inner_rectangle_shapes.push_back(current_shape);
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
			
			inner_rectangle_shapes.push_back(current_shape);
		}
	}
	
	if(inner_rectangle.getter_objectCount()==0){

		if(sqrt(pow(rectangle_width/2,2.0)+pow(rectangle_height/2,2.0))<=radius_of_circle){
			
			Rectangle current_shape;
			current_shape.plus_rectangles();
			
			current_shape.setter_position(radius_of_circle-rectangle_width/2,radius_of_circle-rectangle_height/2);
			current_shape.setter_width(rectangle_width);
			current_shape.setter_height(rectangle_height);
			
			inner_rectangle_shapes.push_back(current_shape);
		}
	}
	}	
}

