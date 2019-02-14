
#include "Polygon.h"
#include <vector>

namespace name_polygon{
Polygon::Point2D::Point2D(){
	pos_x=0;pos_y=0;
}
Polygon::Point2D::Point2D(double initialize_pos_x,double initialize_pos_y){
	pos_x=initialize_pos_x;
	pos_y=initialize_pos_y;
}
void Polygon::Point2D::setter_pos_x(double new_pos_x){
	pos_x=new_pos_x;
}
void Polygon::Point2D::setter_pos_y(double new_pos_y){
	pos_y=new_pos_y;
}
double Polygon::Point2D::getter_pos_x()const{
	return pos_x;
}
double Polygon::Point2D::getter_pos_y()const{
	return pos_y;
}

Polygon::Polygon(){
	polygon_points=nullptr;
	size_of_points=0;
}
Polygon::Polygon( Triangle& shape_triangle){
	if(shape_triangle.getter_point1_x()<0 || shape_triangle.getter_point1_y()<0 || shape_triangle.getter_point2_x()<0 || shape_triangle.getter_point2_y()<0
		|| shape_triangle.getter_point3_x()<0 || shape_triangle.getter_point3_y()<0){
		double new_1x=shape_triangle.getter_point1_x();
		double new_1y=shape_triangle.getter_point1_y();
		double new_2x=shape_triangle.getter_point2_x();
		double new_2y=shape_triangle.getter_point2_y();
		double new_3x=shape_triangle.getter_point3_x();
		double new_3y=shape_triangle.getter_point3_y();

		if(shape_triangle.getter_point1_x()<0){
		cout<<"Point 1 x coordinate is wrong enter again"<<endl;
		cin>>new_1x;}
		else if(shape_triangle.getter_point1_y()<0){
		cout<<"Point 1 y coordinate is wrong enter again"<<endl;
		cin>>new_1y;}
		else if(shape_triangle.getter_point2_x()<0){
		cout<<"Point 2 x coordinate is wrong enter again"<<endl;
		cin>>new_2x;}
		else if(shape_triangle.getter_point2_y()<0){
		cout<<"Point 2 y coordinate is wrong enter again"<<endl;
		cin>>new_2y;}
		else if(shape_triangle.getter_point3_x()<0){
		cout<<"Point 3 x coordinate is wrong enter again"<<endl;
		cin>>new_3x;}
		else if(shape_triangle.getter_point2_y()<0){
		cout<<"Point 3 y coordinate is wrong enter again"<<endl;
		cin>>new_3y;}

		while(new_1x<0 || new_1y<0 || new_2x<0 || new_2y<0 || new_3x<0 || new_3y<0){
		if(new_1x<0){
		cout<<"Point 1 x coordinate is wrong enter again"<<endl;
		cin>>new_1x;}
		else if(new_1y<0){
		cout<<"Point 1 y coordinate is wrong enter again"<<endl;
		cin>>new_1y;}
		else if(new_2x<0){
		cout<<"Point 2 x coordinate is wrong enter again"<<endl;
		cin>>new_2x;}
		else if(new_2y<0){
		cout<<"Point 2 y coordinate is wrong enter again"<<endl;
		cin>>new_2y;}
		else if(new_3x<0){
		cout<<"Point 3 x coordinate is wrong enter again"<<endl;
		cin>>new_3x;}
		else if(new_3y<0){
		cout<<"Point 3 y coordinate is wrong enter again"<<endl;
		cin>>new_3y;}
		}
		shape_triangle.setter_point1(new_1x,new_1y);
		shape_triangle.setter_point2(new_2x,new_2y);
		shape_triangle.setter_point3(new_3x,new_3y);
	}
	polygon_points=new Point2D[3];

	if(!(shape_triangle.getter_point1_y()==0 && shape_triangle.getter_point2_x()==0 )){
	polygon_points[0].setter_pos_x(shape_triangle.getter_point1_x());
	polygon_points[0].setter_pos_y(shape_triangle.getter_point1_y());

	polygon_points[1].setter_pos_x(shape_triangle.getter_point2_x());
	polygon_points[1].setter_pos_y(shape_triangle.getter_point2_y());

	polygon_points[2].setter_pos_x(shape_triangle.getter_point3_x());
	polygon_points[2].setter_pos_y(shape_triangle.getter_point3_y());
	}
	else{
	polygon_points[0].setter_pos_x(shape_triangle.getter_lenght_of_triangle()/2);
	polygon_points[0].setter_pos_y(0);

	polygon_points[1].setter_pos_x(shape_triangle.getter_lenght_of_triangle());
	polygon_points[1].setter_pos_y(shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);

	polygon_points[2].setter_pos_x(0);
	polygon_points[2].setter_pos_y(shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);}
	size_of_points=3;
}
Polygon::Polygon(Rectangle& shape_rectangle){


	if(shape_rectangle.getter_pos_x()<0 || shape_rectangle.getter_pos_y()<0){

		double new_x=shape_rectangle.getter_pos_x();
		double new_y=shape_rectangle.getter_pos_y();
		if(shape_rectangle.getter_pos_x()<0){
			cout<<"Rectangle coordinate x is wrong ,enter again"<<endl;
			cin>>new_x;
		}
		else if(shape_rectangle.getter_pos_y()<0){
			cout<<"Rectangle coordinate y is wrong ,enter again"<<endl;  //error check if coordinates are negative
			cin>>new_y;
		}
		while(new_x<0 || new_y<0){
			if(new_x<0){
				cout<<"Rectangle coordinate x is wrong, enter again"<<endl;
				cin>>new_x;
			}
			else if(new_y<0){
				cout<<"Rectangle coordinate y is wrong, enter again"<<endl;
				cin>>new_y;
			}
		}
		shape_rectangle.setter_position(new_x,new_y);
	}

	polygon_points=new Point2D[4];

	double rectangle_pos_x=shape_rectangle.getter_pos_x();
	double rectangle_pos_y=shape_rectangle.getter_pos_y();

	polygon_points[0].setter_pos_x(rectangle_pos_x);
	polygon_points[0].setter_pos_y(rectangle_pos_y);

	polygon_points[1].setter_pos_x(rectangle_pos_x+shape_rectangle.getter_width());
	polygon_points[1].setter_pos_y(rectangle_pos_y);

	polygon_points[2].setter_pos_x(rectangle_pos_x+shape_rectangle.getter_width());
	polygon_points[2].setter_pos_y(rectangle_pos_y+shape_rectangle.getter_height());

	polygon_points[3].setter_pos_x(rectangle_pos_x);
	polygon_points[3].setter_pos_y(rectangle_pos_y+shape_rectangle.getter_height());
	size_of_points=4;
}
Polygon::Polygon(Circle& shape_circle){

	if(shape_circle.getter_pos_x()<0 || shape_circle.getter_pos_y()<0){
		double new_x=shape_circle.getter_pos_x();
		double new_y=shape_circle.getter_pos_y();
		if(shape_circle.getter_pos_x()<0){
			cout<<"Circle coordinate x is wrong,enter again"<<endl;
			cin>>new_x;
		}
		else if(shape_circle.getter_pos_y()<0){
			cout<<"Circle coordinate y is wrong, enter again"<<endl;
			cin>>new_y;
		}
		while(new_x<0 || new_y<0){
			if(new_x<0){
			cout<<"Circle coordinate x is wrong,enter again"<<endl;
			cin>>new_x;				
			}
			else if(new_y<0){
			cout<<"Circle coordinate y is wrong,enter again"<<endl;
			cin>>new_y;
			}
		}
		shape_circle.setter_position_x(new_x);
		shape_circle.setter_position_y(new_y);
	}
	polygon_points=new Point2D[100];

	double radius=shape_circle.getter_radius();
	for(int i=0;i<100;++i){
		polygon_points[i].setter_pos_x(shape_circle.getter_pos_x()+radius+radius*sin((2*PI/100)*i));
		polygon_points[i].setter_pos_y(shape_circle.getter_pos_y()+radius+radius*cos((2*PI/100)*i));
	}
	size_of_points=100;
}
Polygon::Polygon(const Polygon::Point2D point){
	polygon_points=new Point2D;

	polygon_points->setter_pos_x(point.getter_pos_x());
	polygon_points->setter_pos_y(point.getter_pos_y());
	size_of_points=1;
}
Polygon::Polygon(const vector<Point2D> points){
	polygon_points=new Point2D[points.size()];

	for(int i=0;i<points.size();++i){
		polygon_points[i].setter_pos_x(points[i].getter_pos_x());
		polygon_points[i].setter_pos_y(points[i].getter_pos_y());
	}
	size_of_points=points.size();
}
Polygon::Polygon(const Polygon& copy_Polygon)
	:size_of_points(copy_Polygon.size_of_points)
{
	polygon_points=new Point2D[size_of_points];
	for(int i=0;i<size_of_points;++i){
		polygon_points[i]=copy_Polygon.polygon_points[i];
	}
}

Polygon::~Polygon(){
	delete [] polygon_points;
}
Polygon::Point2D* Polygon::getter_polygon_points()const{
	return polygon_points;
}
void Polygon::setter_polygon_points(Polygon::Point2D* new_polygon_points){
	delete [] polygon_points;
	polygon_points=new_polygon_points;
}
int Polygon::get_size()const{
	return size_of_points;
}
void Polygon::set_size(int new_size){
	size_of_points=new_size;
}
double Polygon::difference_mostAndleast_x()const{
	double most_right_x;

	most_right_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
	}

	double most_left_x;

	most_left_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_x()<most_left_x)
			most_left_x=polygon_points[i].getter_pos_x();
	}	

	return (most_right_x-most_left_x);
}
double Polygon::difference_mostAndleast_y()const{
	double most_down_y;

	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}

	double most_up_y;

	most_up_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_y()<most_up_y)
			most_up_y=polygon_points[i].getter_pos_y();
	}	

	return (most_down_y-most_up_y);
}
double Polygon::most_x()const{
	double most_right_x;

	most_right_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
	}
	return most_right_x;
}
double Polygon::most_y()const{
	double most_down_y;

	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}
	return most_down_y;	
}
double Polygon::getter_area_of_shape()const{
	if(size_of_points==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.getter_area();
	}
	else if(size_of_points==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.getter_area();
	}
	else if(size_of_points==3){
		Triangle a(difference_mostAndleast_x());
		return a.getter_area();
	}
	else
		return -1;
}
double Polygon::getter_perimeter_of_shape()const{
	if(size_of_points==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.getter_perimeter_lenght();
	}
	else if(size_of_points==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.getter_perimeter_lenght();
	}
	else if(size_of_points==3){
		Triangle a(difference_mostAndleast_x());
		return a.getter_perimeter_lenght();
	}
	else
		return -1;	
}
bool Polygon::operator ==(const Polygon& other)const{
	if(getter_area_of_shape()!=other.getter_area_of_shape())
		return false;
	else if(size_of_points!=other.size_of_points)
		return false;
	else
		return true;
}
bool Polygon::operator !=(const Polygon& other)const{
	if(getter_area_of_shape()!=other.getter_area_of_shape())
		return true;
	else if(size_of_points!=other.size_of_points)
		return true;
	else
		return false;
}

Polygon& Polygon::operator =(const Polygon& rtSide){
	if(this==&rtSide)
		return *this;
	else{
		size_of_points=rtSide.size_of_points;
		delete [] polygon_points;
		polygon_points=new Point2D[size_of_points];
		for(int i=0;i<size_of_points;++i){
			polygon_points[i]=rtSide.polygon_points[i];
		}
		return *this;
	}
}
const Polygon::Point2D& Polygon::operator [](unsigned int index)const{
	if(size_of_points==0){
		cout<<"Points array is empty ,can not be reached an element of it"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else if(index<0 || index>=size_of_points){
		cout<<"index is out of range"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else
		return polygon_points[index];
}
 Polygon::Point2D& Polygon::operator [](unsigned int index){
	if(size_of_points==0){
		cout<<"Points array is empty ,can not be reached an element of it"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else if(index<0 || index>=size_of_points){
		cout<<"index is out of range"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else
		return polygon_points[index];
}
const Polygon Polygon::operator +(const Polygon& other)const{
	vector<Point2D> temp;
	for(int i=0;i<size_of_points;++i){
		temp.push_back(polygon_points[i]);
	}
	for(int i=0;i<other.size_of_points;++i){
		temp.push_back(other.polygon_points[i]);
	}
	Polygon a(temp);
	return a;

}
ofstream& operator <<(ofstream& outputfile,const Polygon& shape){

	double most_right_x,most_down_y;
	most_right_x=shape.polygon_points[0].getter_pos_x();
	most_down_y=shape.polygon_points[0].getter_pos_y();
	for(int i=1;i<shape.size_of_points;++i){
		if(shape.polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=shape.polygon_points[i].getter_pos_x();
		if(shape.polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=shape.polygon_points[i].getter_pos_y();
	}
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<most_right_x<<"\" height=\""<<most_down_y<<"\" "<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\"";

	for(int i=0;i<shape.size_of_points;++i){
		outputfile<<" "<<shape.polygon_points[i].getter_pos_x();
		outputfile<<","<<shape.polygon_points[i].getter_pos_y();
		if(i<shape.size_of_points-1)
			outputfile<<" ";
	}
	outputfile<<"\""<<endl;
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
}
}
