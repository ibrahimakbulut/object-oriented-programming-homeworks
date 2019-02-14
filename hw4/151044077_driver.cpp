#include "composedShape.cpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>

using namespace std;

int Rectangle::objectCount=0;
int Circle::objectCount=0;
int Triangle::objectCount=0;

double Circle::total_area=0;
double Triangle::total_area=10;
double Rectangle::total_area=0;

double Circle::total_perimeter=0;
double Triangle::total_perimeter=10;
double Rectangle::total_perimeter=0;

int main(){  

/*
	ofstream outputfile;

	Circle container_shape(8);    // Example: these three objects were declared with constructors.
	Triangle inner_shape(12);
	Rectangle a(200,400);

	Polyline temp(container_shape);
	Polyline z(inner_shape);
	Polyline c;
	c=z;

	ofstream yeni;

	yeni.open("yepyeni.svg");

	yeni<<temp;
	
	composedShape mix_shape(a,container_shape); 
	
	mix_shape.optimalFit();

	outputfile<<mix_shape;
	cout<<mix_shape;
	cout<<mix_shape.container_shape.get_size();
	cout<<mix_shape.inner_shape.get_size();*/
	
	
	//if you wish ,you can create the shape you want same as the example     
	

	ofstream outputfile;
	
	Circle circles[4];
	Rectangle rectangles[4];
	Triangle triangles[4];
	
	composedShape united_shapes[9];
	
	//whether the input is valid or not is not checked.So please enter only real number for size of shapes.
	int k=1;
	double temporary_radius_for_circle_container=300;

	circles[k-1].setter_radius(temporary_radius_for_circle_container); //The radius of container circle is assigned with the setter function
		
	for(int i=0;i<3;++i){
		
		if(i==0){
			double temporary_radius_for_circle_inner=8;
			circles[k].setter_radius(temporary_radius_for_circle_inner);//The radius of inner circle is assigned with the setter
			
			united_shapes[0].setter_container_shape(Polygon(circles[k-1]));
		//container circle and inner circle are send to composedShape element with setter function
			united_shapes[0].setter_inner_shape(Polygon(circles[k]));
			//for the shape elements inside composedshape(no parameter objects) ,we must inrease total area and total perimeter manually because, 
			//the container shape element and inner shape element are created by no parameter constructor so ,this are have no size information.*/
			
		united_shapes[0].optimalFit(); //call functions of composedShape element
			outputfile<<united_shapes[0];
			cout<<united_shapes[0]<<endl<<endl;
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=17;
			double temporary_height_for_rectangle_inner=25;
		//same statements that above are aplied here with one differ that inner shape is rectangle here	
	
			rectangles[k-1].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k-1].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[1].setter_container_shape(Polygon(circles[k-1]));
			united_shapes[1].setter_inner_shape(Polygon(rectangles[k-1]));
			
			united_shapes[1].optimalFit();
			outputfile<<united_shapes[1];
			cout<<united_shapes[1]<<endl<<endl;
		}
		else if(i==2){
			
			double temporary_lenght_for_triangle_inner=30;
			
		//same statements that above are aplied here with one differ that inner shape is triangle here	
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[2].setter_container_shape(Polygon(circles[k-1]));
			united_shapes[2].setter_inner_shape(Polygon(triangles[k-1]));
			
			united_shapes[2].optimalFit();
			outputfile<<united_shapes[2];
			cout<<united_shapes[2]<<endl<<endl;
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
			
			united_shapes[3].setter_container_shape(Polygon(rectangles[k-1]));
			united_shapes[3].setter_inner_shape(Polygon(circles[k]));
			
			united_shapes[3].optimalFit();
			outputfile<<united_shapes[3];
			cout<<united_shapes[3]<<endl<<endl;
			
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=18;
			double temporary_height_for_rectangle_inner=25;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[4].setter_container_shape(Polygon(rectangles[k-1]));
			united_shapes[4].setter_inner_shape(Polygon(rectangles[k]));

			united_shapes[4].optimalFit();
			outputfile<<united_shapes[4];
			cout<<united_shapes[4]<<endl<<endl;

		}
		else if(i==2){
			double temporary_lenght_for_triangle_inner=15;
			
			triangles[k-1].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[5].setter_container_shape(Polygon(rectangles[k-1]));
			united_shapes[5].setter_inner_shape(Polygon(triangles[k-1]));

			united_shapes[5].optimalFit();
			outputfile<<united_shapes[5];
			cout<<united_shapes[5]<<endl<<endl;
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
			
			united_shapes[6].setter_container_shape(Polygon(triangles[k-1]));
			united_shapes[6].setter_inner_shape(Polygon(circles[k]));
			
			united_shapes[6].optimalFit();
			outputfile<<united_shapes[6];
			cout<<united_shapes[6]<<endl<<endl;
		}
		else if(i==1){
			double temporary_width_for_rectangle_inner=17;
			double temporary_height_for_rectangle_inner=11;
			
			rectangles[k].setter_width(temporary_width_for_rectangle_inner);
			rectangles[k].setter_height(temporary_height_for_rectangle_inner);
			
			united_shapes[7].setter_container_shape(Polygon(triangles[k-1]));
			united_shapes[7].setter_inner_shape(Polygon(rectangles[k]));
			
			united_shapes[7].optimalFit();
			outputfile<<united_shapes[7];
			cout<<united_shapes[7]<<endl<<endl;
		}
		 else if(i==2){
			double temporary_lenght_for_triangle_inner=26.99;
			
			triangles[k].setter_lenght_of_triangle(temporary_lenght_for_triangle_inner);
			
			united_shapes[8].setter_container_shape(Polygon(triangles[k-1]));
			united_shapes[8].setter_inner_shape(Polygon(triangles[k]));
			
			united_shapes[8].optimalFit();
			outputfile<<united_shapes[8];
			cout<<united_shapes[8]<<endl<<endl;
		}
		
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"from here what i did they are only to show member functions of classses are workly fine.Above part is designed for creating 9 svg file."<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
//from here what i did they are only to show member functions of classses are workly fine.Above part is designed for creating 9 svg file.


	Circle container_c(300);
	Triangle container_t(190);
	Rectangle container_r(250,140);

	Circle inner_c(9,70,100);
	Triangle inner_t(13,4,9,30,9,24,40);
	Rectangle inner_r(13,15,0,0);



	cout<<container_c+9<<endl<<19+container_c<<endl<<endl;  //+ operator overlaod for 3 main shapes(triangle,circle,rectangle)
	cout<<container_t+27<<endl<<43+container_t<<endl<<endl; //+ operator work fine shapeObject+double and double+shapeObject
	cout<<inner_r+100<<endl<<1+inner_r<<endl<<endl;


	cout<<inner_c-30<<endl<<40-inner_c<<endl<<endl;				//- operator overlaod for 3 main shapes(triangle,circle,rectangle)
	cout<<container_t-200<<endl<<500-container_t<<endl<<endl;  //- operator work fine shapeObject-double and double-shapeObject
	cout<<inner_t-100<<endl<<75-inner_t<<endl<<endl;

	ofstream alone_triangle;
	alone_triangle.open("alone_triangle.svg");

	alone_triangle<<100-inner_t;

	ofstream alone_rectangle;
	alone_rectangle.open("alone_rectangle.svg");

	alone_rectangle<<200+inner_r;

	ofstream alone_circle;
	alone_circle.open("alone_circle.svg");
	alone_circle<<400+container_c+70;

	container_t--;--container_t;
	container_t++;++container_t;

	cout<<inner_c--<<endl<<inner_c++<<endl<<endl;
	cout<<--inner_c<<endl<<++inner_c<<endl<<endl<<endl<<endl;  //++ -- operator both prefix and post fix overload and work fine.

	cout<<container_r--<<endl<<container_r++<<endl;
	cout<<--container_r<<endl<<++container_r<<endl<<endl<<endl;


	if(container_c>inner_c){
		cout<<container_c.getter_area()<<" > "<<inner_c.getter_area()<<endl<<endl;
	}
	else if(container_c==inner_c){
		cout<<container_c.getter_area()<<" == "<<inner_c.getter_area()<<endl<<endl;
	}
	else if(container_c<inner_c){
		cout<<container_c.getter_area()<<" < "<<inner_c.getter_area()<<endl<<endl;
	}



	if(inner_t<=container_t){
			if(inner_t==container_t){
				cout<<inner_t.getter_area()<<" == "<<container_t.getter_area()<<endl<<endl;      
			}
			else if(inner_t!=container_t){
				if(inner_t<container_t){
					cout<<inner_t.getter_area()<<" < "<<container_t.getter_area()<<endl<<endl;
				}
			}

	}
	else if(inner_t>=container_t){
			if(inner_t==container_t){
				cout<<inner_t.getter_area()<<" == "<<container_t.getter_area()<<endl<<endl;
			}
			else if(inner_t!=container_t){
				if(inner_t>container_t){
					cout<<inner_t.getter_area()<<" > "<<container_t.getter_area()<<endl<<endl;
				}
			}
	}

	//== , != , < , > , <= , >= operator are all overload for all main shapes(rectangle,triangle,circle).so you can check by
	//changing value of inner and container shape's sizes.																

	if(inner_r<=container_r){
			if(inner_r==container_r){
				cout<<inner_r.getter_area()<<" == "<<container_r.getter_area()<<endl<<endl;
			}
			else if(inner_r!=container_r){
				if(inner_r<container_r){
					cout<<inner_r.getter_area()<<" < "<<container_r.getter_area()<<endl<<endl;
				}
			}

	}
	else if(inner_r>=container_r){
			if(inner_r==container_r){
				cout<<inner_t.getter_area()<<" == "<<container_t.getter_area()<<endl<<endl;
			}
			else if(inner_r!=container_r){
				if(inner_r>container_r){
					cout<<inner_r.getter_area()<<" > "<<container_r.getter_area()<<endl<<endl;
				}
			}
	}

//asagidaki fonksiyonlar onceden olusan dosyalarin ustune yazilabilir bu yuzden 9 SVG dosyasini klasore attim.
	composedShape mix_shape(container_r,inner_r);

	mix_shape.optimalFit();

	ofstream  testfile;

	testfile<<mix_shape;
	cout<<mix_shape;

	ofstream  testfile2;

	ofstream testfile3;
	testfile3.open("test.svg");   //this is for writing one ShapeElem as svg to a file.please open that file with browser other may not be represented.

	composedShape mix_shape2(container_t,inner_c);
	Polygon shapeObject(inner_c); //in here mix shape2 has no inner shape because we dont call optimaFit function.
	mix_shape2+=shapeObject;										//we add a shape to it here with += operator and it work fine.

	shapeObject=Polygon(inner_r);//we add shapes it randomly without looking 
	mix_shape2+=shapeObject;										//if shape setting pozition is empty or not.

	shapeObject=Polygon(inner_t);
	mix_shape2+=shapeObject;

	testfile3<<mix_shape2[0];   //shape that we add it to composedShape manually we can acces that with [] operator and 
	//printf it alone with << overloaded operator for shapeElem.

	//testfile2<<mix_shape2;	//printf mix_shape2 with << overloaded operator for composedShape.


	Triangle d(24);
	Polyline temp1(d);
					     //for polyline constructors

	ofstream triangle_polyline;

	triangle_polyline.open("triangle_polyline.svg");


triangle_polyline<<temp1;

	Rectangle l(240,70);
	Polyline temp2(l);
	ofstream rectangle_polyline;
	rectangle_polyline.open("rectangle_polyline.svg");
rectangle_polyline<<temp2;

	Circle m(128);
	Polyline temp3(m);
	ofstream circle_polyline;
	circle_polyline.open("circle_polyline.svg");

circle_polyline<<temp3;







	Polygon tests[5]; 

	Circle a1(158);

	Polygon shape1(a1);

	vector<Polygon::Point2D> points_vector0;
	for(int i=0;i<shape1.get_size();++i){

		points_vector0.push_back(shape1[i]);
	}

	tests[0]=Polygon(points_vector0);

	ofstream polygon1;
	polygon1.open("polygon1.svg");
	polygon1<<tests[0];

 
	Triangle a2(158,19,0,7,0,20,5);  //if you want to see error checks enter negative number to a2 position parameters.
										//dont enter all y positions 0 if you do that the svg file dont work because height is 0 then.

	Polygon shape2(a2);

	vector<Polygon::Point2D> points_vector1;
	for(int i=0;i<shape2.get_size();++i){

		points_vector1.push_back(shape2[i]);
	}

	tests[1]=Polygon(points_vector1);

	ofstream polygon2;
	polygon2.open("polygon2.svg");
	polygon2<<tests[1];


	Triangle a3(158);

	Polygon shape3(a3);

	vector<Polygon::Point2D> points_vector2;
	for(int i=0;i<shape3.get_size();++i){

		points_vector2.push_back(shape3[i]);
	}

	tests[2]=Polygon(points_vector2);

	ofstream polygon3;
	polygon3.open("polygon3.svg");
	polygon3<<tests[2];


	Rectangle a4(7,40);

	Polygon shape4(a4);

	vector<Polygon::Point2D> points_vector3;
	for(int i=0;i<shape4.get_size();++i){

		points_vector3.push_back(shape4[i]);
	}

	tests[3]=Polygon(points_vector3);

	ofstream polygon4;
	polygon4.open("polygon4.svg");
	polygon4<<tests[3];


	Circle a5(200,12,13);  //if you want to see error checks Cİrcle a5(200,-8,-5)

	Polygon shape5(a5);

	vector<Polygon::Point2D> points_vector4;
	for(int i=0;i<shape5.get_size();++i){

		points_vector4.push_back(shape5[i]);
	}

	tests[4]=Polygon(points_vector4);

	ofstream polygon5;
	polygon5.open("polygon5.svg");
	polygon5<<tests[4];


	
	return 0;
}
