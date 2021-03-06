class PolygonDyn
!!!136842.cpp!!!	PolygonDyn()
	polygon_points=nullptr;
	size_of_points=0;
!!!136970.cpp!!!	PolygonDyn(inout shape_triangle : Triangle)
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
!!!137098.cpp!!!	PolygonDyn(inout shape_rectangle : Rectangle)


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
!!!137226.cpp!!!	PolygonDyn(inout shape_circle : Circle)

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
		polygon_points[i].setter_pos_x(shape_circle.getter_pos_x()+radius*sin((2*PI/100)*i));
		polygon_points[i].setter_pos_y(shape_circle.getter_pos_y()+radius*cos((2*PI/100)*i));
	}
	size_of_points=100;
!!!137482.cpp!!!	PolygonDyn(in points : vector<Point2D>)
	polygon_points=new Point2D[points.size()];

	for(int i=0;i<points.size();++i){
		polygon_points[i].setter_pos_x(points[i].getter_pos_x());
		polygon_points[i].setter_pos_y(points[i].getter_pos_y());
	}
	size_of_points=points.size();
!!!137610.cpp!!!	PolygonDyn(in copy_Polygondyn : PolygonDyn)
	if(polygon_points!=nullptr)
		delete [] polygon_points;
	polygon_points=new Point2D[copy_Polygondyn.size_of_points];
	for(int i=0;i<size_of_points;++i){
		polygon_points[i]=copy_Polygondyn.polygon_points[i];
	}
!!!136714.cpp!!!	~PolygonDyn()
	if (polygon_points!=nullptr)
	delete [] polygon_points;
!!!139658.cpp!!!	getter_polygon_points() : Point2D
	return polygon_points;
!!!139914.cpp!!!	get_size() : int
	return size_of_points;
!!!140042.cpp!!!	set_size(in new_size : int) : void
	size_of_points=new_size;
!!!138890.cpp!!!	difference_mostAndleast_x() : double
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
!!!139018.cpp!!!	difference_mostAndleast_y() : double
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
!!!139146.cpp!!!	most_x() : double
	double most_right_x;

	most_right_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
	}
	return most_right_x;
!!!139274.cpp!!!	most_y() : double
	double most_down_y;

	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}
	return most_down_y;	
!!!139402.cpp!!!	area() : double
	if(size_of_points==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.area();
	}
	else if(size_of_points==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.area();
	}
	else if(size_of_points==3){
		Triangle a(difference_mostAndleast_x());
		return a.area();
	}
	else
		return -1;
!!!139530.cpp!!!	perimeter() : double
	if(size_of_points==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.perimeter();
	}
	else if(size_of_points==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.perimeter();
	}
	else if(size_of_points==3){
		Triangle a(difference_mostAndleast_x());
		return a.perimeter();
	}
	else
		return -1;	
!!!140170.cpp!!!	getter_pos_x() : double
	if(size_of_points==4 || size_of_points==3)
	return  most_x()-difference_mostAndleast_x();
	else 
		return most_x()-difference_mostAndleast_x()/2;
!!!140298.cpp!!!	getter_pos_y() : double
	if(size_of_points==4)
		return  most_y()-difference_mostAndleast_y();
	else if(size_of_points==3)
		return most_y(); 
	else 
		return most_y()-difference_mostAndleast_y()/2;
!!!138250.cpp!!!	operator =(in rtSide : PolygonDyn) : PolygonDyn
	if(this==&rtSide)
		return *this;
	else{
		size_of_points=rtSide.size_of_points;
		delete [] polygon_points;
		polygon_points=new Point2D[rtSide.size_of_points];
		for(int i=0;i<rtSide.size_of_points;++i){
			polygon_points[i]=rtSide.polygon_points[i];
		}
		return *this;
	}
!!!138378.cpp!!!	operator [](in index : uint) : Point2D
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
!!!138506.cpp!!!	operator [](in index : uint) : Point2D
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
!!!138634.cpp!!!	operator +(in other : PolygonDyn) : PolygonDyn
	vector<Point2D> temp;
	for(int i=0;i<size_of_points;++i){
		temp.push_back(polygon_points[i]);
	}
	for(int i=0;i<other.size_of_points;++i){
		temp.push_back(other.polygon_points[i]);
	}
	PolygonDyn a(temp);
	return a;

!!!137738.cpp!!!	operator ++(in  : int) : PolygonDyn


	PolygonDyn *a=new PolygonDyn(*this);
	for(int i=0;i<size_of_points;++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()+1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()+1);
	}
	return *a; 


!!!137866.cpp!!!	operator ++() : PolygonDyn

	for(int i=0;i<size_of_points;++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()+1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()+1);
	}

	return *this;
!!!137994.cpp!!!	operator --(in  : int) : PolygonDyn

	PolygonDyn *a=new PolygonDyn(*this);
	for(int i=0;i<size_of_points;++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()-1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()-1);
	}
	return *a;
!!!138122.cpp!!!	operator --() : PolygonDyn

	for(int i=0;i<size_of_points;++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()-1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()-1);
	}
	return *this;	
!!!138762.cpp!!!	print_shape(inout outputfile : ofstream) : ofstream

	double most_right_x,most_down_y;
	most_right_x=polygon_points[0].getter_pos_x();
	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<size_of_points;++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<most_right_x<<"\" height=\""<<most_down_y<<"\" "<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\"";

	for(int i=0;i<size_of_points;++i){
		outputfile<<" "<<polygon_points[i].getter_pos_x();
		outputfile<<","<<polygon_points[i].getter_pos_y();
		if(i<size_of_points-1)
			outputfile<<" ";
	}
	outputfile<<"\""<<endl;
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
