#include "composedShape.cpp"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int Rectangle::objectCount=0;
int Circle::objectCount=0;
int Triangle::objectCount=0;

int main(){
	
	ofstream outputfile;
	
//	outputfile.open("outputfile.svg");
	
	
	Circle circles[4];
	Rectangle rectangles[4];
	Triangle triangles[4];
	
	composedShape united_shapes[9];
	
	int k=1;
	double temporary_radius_for_circle_container;
	cout<<"Please enter radius for circle container"<<endl;
	cin>>temporary_radius_for_circle_container;
	circles[k-1].setter_radius(temporary_radius_for_circle_container);
		
	for(int i=0;i<3;++i){
		
		if(i==0){
			double temporary_radius_for_circle_inner;
			cout<<"Please enter radius for circle inner"<<endl;
			cin>>temporary_radius_for_circle_inner;
			circles[k].setter_radius(temporary_radius_for_circle_inner);
			
			united_shapes[0].setter_container_circle(circles[k-1]);
			united_shapes[0].setter_inner_circle(circles[k]);
			
			united_shapes[0].setter_container_shape('C');
			united_shapes[0].setter_inner_shape('C');
			
			united_shapes[0].optimalFit();
			united_shapes[0].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[0].getter_circles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[0].calculate_remain_area()<<endl;
			united_shapes[0].getter_circles_vector()[0].setter_objectCount(0);
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner;
			double temporary_height_for_rectangle_inner;
			
			cout<<"Please enter width for rectangle inner"<<endl;
			cin>>temporary_width_for_rectangle_inner;
			cout<<"Please enter height for rectangle inner"<<endl;
			cin>>temporary_height_for_rectangle_inner;
			
			rectangles[k-1].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k-1].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[1].setter_container_circle(circles[k-1]);
			united_shapes[1].setter_inner_rectangle(rectangles[k-1]);
			
			united_shapes[1].setter_container_shape('C');
			united_shapes[1].setter_inner_shape('R');
			
			united_shapes[1].optimalFit();
			united_shapes[1].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[1].getter_rectangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[1].calculate_remain_area()<<endl;
			united_shapes[1].getter_rectangles_vector()[0].setter_objectCount(0);
		}
		else if(i==2){
			
			double temporary_lenght_for_triangle_inner;
			
			cout<<"Please enter lenght of triangle inner"<<endl;
			cin>>temporary_lenght_for_triangle_inner;
			
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[2].setter_container_circle(circles[k-1]);
			united_shapes[2].setter_inner_triangle(triangles[k-1]);
			
			united_shapes[2].setter_container_shape('C');
			united_shapes[2].setter_inner_shape('T');
			
			united_shapes[2].optimalFit();
			united_shapes[2].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[2].getter_triangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[2].calculate_remain_area()<<endl;
			united_shapes[2].getter_triangles_vector()[0].setter_objectCount(0);
		}
		
	}
	k+=1;
	double temporary_width_for_rectangle_container;
	double temporary_height_for_rectangle_container;
			
	cout<<"Please enter width for rectangle container"<<endl;
	cin>>temporary_width_for_rectangle_container;
	cout<<"Please enter height for rectangle container"<<endl;
	cin>>temporary_height_for_rectangle_container;
			
	rectangles[k-1].setter_width(temporary_width_for_rectangle_container);
	rectangles[k-1].setter_height(temporary_height_for_rectangle_container);
	
	for(int i=0;i<3;++i){
		
		
		if(i==0){
			double temporary_radius_for_circle_inner;
			cout<<"Please enter radius for circle inner"<<endl;
			cin>>temporary_radius_for_circle_inner;
			circles[k].setter_radius(temporary_radius_for_circle_inner);
			
			united_shapes[3].setter_container_rectangle(rectangles[k-1]);
			united_shapes[3].setter_inner_circle(circles[k]);
			
			united_shapes[3].setter_container_shape('R');
			united_shapes[3].setter_inner_shape('C');
			
			united_shapes[3].optimalFit();
			united_shapes[3].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[3].getter_circles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[3].calculate_remain_area()<<endl;
			united_shapes[3].getter_circles_vector()[0].setter_objectCount(0);
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner;
			double temporary_height_for_rectangle_inner;
			
			cout<<"Please enter width for rectangle inner"<<endl;
			cin>>temporary_width_for_rectangle_inner;
			cout<<"Please enter height for rectangle inner"<<endl;
			cin>>temporary_height_for_rectangle_inner;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[4].setter_container_rectangle(rectangles[k-1]);
			united_shapes[4].setter_inner_rectangle(rectangles[k]);
			
			united_shapes[4].setter_container_shape('R');
			united_shapes[4].setter_inner_shape('R');
			
			united_shapes[4].optimalFit();
			united_shapes[4].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[4].getter_rectangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[4].calculate_remain_area()<<endl;
			united_shapes[4].getter_rectangles_vector()[0].setter_objectCount(0);
		}
		else if(i==2){
			double temporary_lenght_for_triangle_inner;
			
			cout<<"Please enter lenght of triangle inner"<<endl;
			cin>>temporary_lenght_for_triangle_inner;
			
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[5].setter_container_rectangle(rectangles[k-1]);
			united_shapes[5].setter_inner_triangle(triangles[k-1]);
			
			united_shapes[5].setter_container_shape('R');
			united_shapes[5].setter_inner_shape('T');
			
			united_shapes[5].optimalFit();
			united_shapes[5].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[5].getter_triangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[5].calculate_remain_area()<<endl;
			united_shapes[5].getter_triangles_vector()[0].setter_objectCount(0);
		}
		
	}	
	k+=1;
	double temporary_lenght_for_triangle_container;
	cout<<"Please enter lenght of triangle container"<<endl;
	cin>>temporary_lenght_for_triangle_container;
	triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_container);
	
	for(int i=0;i<3;++i){
		
		
		if(i==0){
			double temporary_radius_for_circle_inner;
			cout<<"Please enter radius for circle inner"<<endl;
			cin>>temporary_radius_for_circle_inner;
			circles[k].setter_radius(temporary_radius_for_circle_inner);
			
			united_shapes[6].setter_container_triangle(triangles[k-1]);
			united_shapes[6].setter_inner_circle(circles[k]);
			
			united_shapes[6].setter_container_shape('T');
			united_shapes[6].setter_inner_shape('C');
			
			united_shapes[6].optimalFit();
			united_shapes[6].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[6].getter_circles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[6].calculate_remain_area()<<endl;
			united_shapes[6].getter_circles_vector()[0].setter_objectCount(0);
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner;
			double temporary_height_for_rectangle_inner;
			
			cout<<"Please enter width for rectangle inner"<<endl;
			cin>>temporary_width_for_rectangle_inner;
			cout<<"Please enter height for rectangle inner"<<endl;
			cin>>temporary_height_for_rectangle_inner;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[7].setter_container_triangle(triangles[k-1]);
			united_shapes[7].setter_inner_rectangle(rectangles[k]);
			
			united_shapes[7].setter_container_shape('T');
			united_shapes[7].setter_inner_shape('R');
			
			united_shapes[7].optimalFit();
			united_shapes[7].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[7].getter_rectangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[7].calculate_remain_area()<<endl;
			united_shapes[7].getter_rectangles_vector()[0].setter_objectCount(0);
		}
		else if(i==2){
			double temporary_lenght_for_triangle_inner;
			
			cout<<"Please enter lenght of triangle inner"<<endl;
			cin>>temporary_lenght_for_triangle_inner;
			
			triangles[k].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[8].setter_container_triangle(triangles[k-1]);
			united_shapes[8].setter_inner_triangle(triangles[k]);
			
			united_shapes[8].setter_container_shape('T');
			united_shapes[8].setter_inner_shape('T');
			
			united_shapes[8].optimalFit();
			united_shapes[8].draw(outputfile);
			
			cout<<"I can fit at most "<<united_shapes[8].getter_triangles_vector()[0].getter_objectCount()<<" small shapes into main container. The empty area(green) in container ";
			cout<<"is "<<united_shapes[8].calculate_remain_area()<<endl;
			united_shapes[8].getter_triangles_vector()[0].setter_objectCount(0);
		}
		
	}
	
/*	Circle container_shape(200,0,0);
	Rectangle inner_shape(13,17,100,50);
	
	composedShape mix_shape(container_shape,inner_shape);
	
	mix_shape.optimalFit();
	mix_shape.draw(outputfile);
	cout<<inner_shape.getter_objectCount();*/
	
	
	return 0;
}
