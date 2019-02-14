#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

#include "Polygon.h"

using namespace name_polygon;
#include "PolygonVect.h"
#include "PolygonDyn.h"
using namespace name_polygonDyn;
using namespace name_polygonVect;
#include "composedShape.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>
#include <memory>

using namespace std;
using namespace name_circle;
using namespace name_triangle;
using namespace name_rectangle;
using namespace name_polygon;
using namespace name_polygonVect;
using namespace name_polygonDyn;

int Rectangle::objectCount=0;
int Circle::objectCount=0;
int Triangle::objectCount=0;

double Circle::total_area=0;
double Triangle::total_area=10;
double Rectangle::total_area=0;

double Circle::total_perimeter=0;
double Triangle::total_perimeter=10;
double Rectangle::total_perimeter=0;


namespace {

void printAll(vector<Shape*>& shapes){

composedShape *temp;
ofstream print_all;
print_all.open("printAll.svg");

int count=0;

print_all<<"<svg version=\"1.1\" baseProfile=\"full\" width=\"%100\" height=\"%100\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"purple\" />";

for(int i=0;i<shapes.size();++i){
	temp=dynamic_cast<composedShape*>(shapes[i]);
	if(temp!=nullptr){
		count=1;
	}
	(shapes[i])->print_shape(print_all);
}
print_all<<"</svg>";

if(count==0)
	print_all.close();
}

void printPoly(vector<Shape*>& shapes){

Polygon *temp;
ofstream print_poly;
print_poly.open("printPoly.svg");

print_poly<<"<svg version=\"1.1\" baseProfile=\"full\" width=\"%100\" height=\"%100\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"purple\" />";

for(int i=0;i<shapes.size();++i){
	temp=dynamic_cast<Polygon*>(shapes[i]);
	if(temp!=nullptr){
		(shapes[i])->print_shape(print_poly);
	}
}
print_poly<<"</svg>";

print_poly.close();
}

vector<Shape*> convertsAll(vector<Shape*>& shapes){

	Circle *object3;
	Rectangle *object4;
	Triangle *object5;
	Polygon *object6;

	vector<Shape*> new_polygon_shape;

	for(int i=0;i<shapes.size();++i){

		object6=dynamic_cast<Polygon*>(shapes[i]);
		if(object6!=nullptr){
			new_polygon_shape.push_back(shapes[i]);
			continue;
		}

		object3=dynamic_cast<Circle*>(shapes[i]);
		if(object3!=nullptr){
			Circle *temp=new Circle(*(static_cast<Circle*>(shapes[i])));
			new_polygon_shape.push_back(temp);
			continue;
		}
		object4=dynamic_cast<Rectangle*>(shapes[i]);
		if(object4!=nullptr){
			Rectangle *temp=new Rectangle(*(static_cast<Rectangle*>(shapes[i])));
			new_polygon_shape.push_back(temp);
			continue;
		}
		object5=dynamic_cast<Triangle*>(shapes[i]);
		if(object5!=nullptr){
			Triangle *temp=new Triangle(*(static_cast<Triangle*>(shapes[i])));
			new_polygon_shape.push_back(temp);
			continue;
		}


	}
	return new_polygon_shape;
}

void sortShapes(vector<Shape*>& shapes){

	for(int i=0; i<shapes.size(); i++)
	{
		for(int j=i+1; j<shapes.size(); j++)
		{
			if((shapes[i])->area()>(shapes[j])->area())
			{
				Shape* temp=shapes[i];
				shapes[i]=shapes[j];
				shapes[j]=temp;
			}
		}
	}
}
		
}

int main(){  

ofstream outputfile;

	Circle circles[4];
	Rectangle rectangles[4];
	Triangle triangles[4];
	
	composedShape united_shapes[9];

	Shape* shapes[9];
	
	//whether the input is valid or not is not checked.So please enter only real number for size of shapes.
	int k=1;
	double temporary_radius_for_circle_container=300;
			
	circles[k-1].setter_radius(temporary_radius_for_circle_container); //The radius of container circle is assigned with the setter function
	for(int i=0;i<3;++i){
		
		if(i==0){
			double temporary_radius_for_circle_inner=8;
			circles[k].setter_radius(temporary_radius_for_circle_inner);//The radius of inner circle is assigned with the setter
			united_shapes[0].setter_container_shape(PolygonDyn(circles[k-1]));

		//container circle and inner circle are send to composedShape element with setter function
			united_shapes[0].setter_inner_shape(PolygonDyn(circles[k]));       			
			//for the shape elements inside composedshape(no parameter objects) ,we must inrease total area and total perimeter manually because, 
			//the container shape element and inner shape element are created by no parameter constructor so ,this are have no size information.*/
		united_shapes[0].optimalFit(); //call functions of composedShape element
		shapes[0]= &united_shapes[0];
			outputfile<<*(shapes[0]);

		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=17;
			double temporary_height_for_rectangle_inner=25;
		//same statements that above are aplied here with one differ that inner shape is rectangle here	
	
			rectangles[k-1].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k-1].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[1].setter_container_shape(PolygonDyn(circles[k-1]));
			united_shapes[1].setter_inner_shape(PolygonDyn(rectangles[k-1]));
			
			united_shapes[1].optimalFit();
			shapes[1]= &united_shapes[1];
			outputfile<<*(shapes[1]);
			outputfile<<united_shapes[1];
		}
		else if(i==2){

			double temporary_lenght_for_triangle_inner=30;
			
		//same statements that above are aplied here with one differ that inner shape is triangle here	
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[2].setter_container_shape(PolygonDyn(circles[k-1]));
			united_shapes[2].setter_inner_shape(PolygonDyn(triangles[k-1]));
			
			united_shapes[2].optimalFit();
			shapes[2]= &united_shapes[2];
			outputfile<<*(shapes[2]);
		}
	}

	k+=1;
	double temporary_width_for_rectangle_container=280;
	double temporary_height_for_rectangle_container=270;
	//container shape changed. it is rectangle now. 		
	
	rectangles[k-1].setter_width(temporary_width_for_rectangle_container);
	rectangles[k-1].setter_height(temporary_height_for_rectangle_container);
	
	for(int i=0;i<3;++i){
		
		//for the inner shapes same as above
		if(i==0){
			double temporary_radius_for_circle_inner=9;
			circles[k].setter_radius(temporary_radius_for_circle_inner);
			
			united_shapes[3].setter_container_shape(PolygonDyn(rectangles[k-1]));
			united_shapes[3].setter_inner_shape(PolygonDyn(circles[k]));
			
			united_shapes[3].optimalFit();
			shapes[3]= &united_shapes[3];
			outputfile<<*(shapes[3]);
			
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=18;
			double temporary_height_for_rectangle_inner=25;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[4].setter_container_shape(PolygonDyn(rectangles[k-1]));
			united_shapes[4].setter_inner_shape(PolygonDyn(rectangles[k]));

			united_shapes[4].optimalFit();
			shapes[4]= &united_shapes[4];
			outputfile<<*(shapes[4]);

		}
		else if(i==2){
			double temporary_lenght_for_triangle_inner=15;
			
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[5].setter_container_shape(PolygonDyn(rectangles[k-1]));
			united_shapes[5].setter_inner_shape(PolygonDyn(triangles[k-1]));

			united_shapes[5].optimalFit();
			shapes[5]= &united_shapes[5];
			outputfile<<*(shapes[5]);
		}
	}	
	k+=1;
	double temporary_lenght_for_triangle_container=270;
	triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_container);
	//container shape changed. it is triangle now. 
	for(int i=0;i<3;++i){
		
		//for the inner shapes same as above
		if(i==0){
			double temporary_radius_for_circle_inner=7;
			circles[k].setter_radius(temporary_radius_for_circle_inner);
			
			united_shapes[6].setter_container_shape(PolygonDyn(triangles[k-1]));
			united_shapes[6].setter_inner_shape(PolygonDyn(circles[k]));
			
			united_shapes[6].optimalFit();
			shapes[6]= &united_shapes[6];
			outputfile<<*(shapes[6]);
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=17;
			double temporary_height_for_rectangle_inner=11;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[7].setter_container_shape(PolygonDyn(triangles[k-1]));
			united_shapes[7].setter_inner_shape(PolygonDyn(rectangles[k]));
			
			united_shapes[7].optimalFit();
			shapes[7]= &united_shapes[7];
			outputfile<<*(shapes[7]);
		}
		 else if(i==2){
			double temporary_lenght_for_triangle_inner=26.99;
			
			triangles[k].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[8].setter_container_shape(PolygonDyn(triangles[k-1]));
			united_shapes[8].setter_inner_shape(PolygonDyn(triangles[k]));
			
			united_shapes[8].optimalFit();
			shapes[8]= &united_shapes[8];
			outputfile<<*(shapes[8]);
		}
		
	}

Shape *s2;
Shape *s3;

Polygon *p2;


Rectangle a(15,21);
Triangle b(200);
Circle c(150);

PolygonVect v(b);


outputfile.open("yeni.svg");


Rectangle d(90,80);
Triangle x(14);
Circle s(4);

PolygonDyn g(d);

Shape *s1;


composedShape f(b,s);

f.optimalFit();

vector<Shape*> temp;
temp.push_back(&b);
temp.push_back(&x);
temp.push_back(&d);
temp.push_back(&c);
temp.push_back(&f);
temp.push_back(&a);
temp.push_back(&g);

printPoly(temp); //this only print polygons shapes

printAll(temp); //this print all shapes 

//printPoly(convertsAll(temp));  after convertAll printAll functions print all shapes because all of them converted to polygons.

sortShapes(temp);

for(int i=0;i<temp.size();++i){
	cout<<(temp[i])->area()<<endl;
}

outputfile<<*((convertsAll(temp))[4]);
 Shape *y;
y=&f;




cout<<(++x).getter_point2_x()<<endl;

cout<<(++(++x)).getter_point2_x()<<endl;

try{cout<<v[5].getter_pos_x();}
catch(int n){
	if(n==0){
		cout<<"Points array is empty ,can not be reached an element of it"<<endl;
	}
	else
		cout<<"index is out of range"<<endl;
}


ofstream l1;
l1.open("deneme1_polygon.svg");

p2=&g;

l1<<*p2;

ofstream l2;

l2.open("deneme2_polygonvect.svg");

Shape* s4;

PolygonVect polyvect(c);

s4=&polyvect;

l2<<*s4;


PolygonDyn h(c);
s2=&h;
s3=&c;


cout<<(*s4==*s3)<<endl;


return 0;
}

