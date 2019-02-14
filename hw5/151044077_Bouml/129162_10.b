class PolygonVect
!!!140682.cpp!!!	PolygonVect(inout shape_triangle : Triangle)
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


	if(!(shape_triangle.getter_point1_y()==0 && shape_triangle.getter_point2_x()==0 )){
	Point2D polygon_points_1(shape_triangle.getter_point1_x(),shape_triangle.getter_point1_y());

	Point2D polygon_points_2(shape_triangle.getter_point2_x(),shape_triangle.getter_point2_y());

	Point2D polygon_points_3(shape_triangle.getter_point3_x(),shape_triangle.getter_point3_y());

	polygon_points.push_back(polygon_points_1);
	polygon_points.push_back(polygon_points_2);
	polygon_points.push_back(polygon_points_3);
	}
	else{
	Point2D polygon_points_1(shape_triangle.getter_lenght_of_triangle()/2,0);

	Point2D polygon_points_2(shape_triangle.getter_lenght_of_triangle(),shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);

	Point2D polygon_points_3(0,shape_triangle.getter_lenght_of_triangle()*sqrt(3.0)/2);
	polygon_points.push_back(polygon_points_1);
	polygon_points.push_back(polygon_points_2);
	polygon_points.push_back(polygon_points_3);
	}

!!!140810.cpp!!!	PolygonVect(inout shape_rectangle : Rectangle)


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


	double rectangle_pos_x=shape_rectangle.getter_pos_x();
	double rectangle_pos_y=shape_rectangle.getter_pos_y();

	Point2D polygon_points_1(rectangle_pos_x,rectangle_pos_y);

	Point2D polygon_points_2(rectangle_pos_x+shape_rectangle.getter_width(),rectangle_pos_y);

	Point2D polygon_points_3(rectangle_pos_x+shape_rectangle.getter_width(),rectangle_pos_y+shape_rectangle.getter_height());

	Point2D polygon_points_4(rectangle_pos_x,rectangle_pos_y+shape_rectangle.getter_height());

	polygon_points.push_back(polygon_points_1);
	polygon_points.push_back(polygon_points_2);
	polygon_points.push_back(polygon_points_3);  //push points into vector polygon_points in the polygonvect class
	polygon_points.push_back(polygon_points_4);
!!!140938.cpp!!!	PolygonVect(inout shape_circle : Circle)

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

	double radius=shape_circle.getter_radius();
	for(int i=0;i<100;++i){
		Point2D polygon_points_of_circle(shape_circle.getter_pos_x()+radius*sin((2*PI/100)*i),shape_circle.getter_pos_y()+radius*cos((2*PI/100)*i));
		polygon_points.push_back(polygon_points_of_circle);
	}
!!!141194.cpp!!!	PolygonVect(in points : vector<Point2D>)

	for(int i=0;i<points.size();++i){
		Point2D polygon_point(points[i].getter_pos_x(),points[i].getter_pos_y());
		polygon_points.push_back(polygon_point);
	}
!!!141322.cpp!!!	PolygonVect(in copy_Polygonvect : PolygonVect)
	polygon_points.resize(0);
	for(int i=0;i<copy_Polygonvect.polygon_points.size();++i){
		polygon_points.push_back(copy_Polygonvect.polygon_points[i]);
	}
!!!143626.cpp!!!	getter_polygon_points() : vector<Point2D>
	return polygon_points;
!!!143754.cpp!!!	setter_polygon_points(in new_polygon_points : vector<Point2D>) : void

	polygon_points.resize(0);
	for(int i=0;i<new_polygon_points.size();++i){
		Point2D polygon_point(new_polygon_points[i].getter_pos_x(),new_polygon_points[i].getter_pos_y());
		polygon_points.push_back(polygon_point);
	}
!!!143882.cpp!!!	get_size() : int
	return polygon_points.size();
!!!142602.cpp!!!	difference_mostAndleast_x() : double
	double most_right_x;

	most_right_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
	}

	double most_left_x;

	most_left_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_x()<most_left_x)
			most_left_x=polygon_points[i].getter_pos_x();
	}	

	return (most_right_x-most_left_x);
!!!142730.cpp!!!	difference_mostAndleast_y() : double
	double most_down_y;

	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}

	double most_up_y;

	most_up_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_y()<most_up_y)
			most_up_y=polygon_points[i].getter_pos_y();
	}	

	return (most_down_y-most_up_y);
!!!142858.cpp!!!	most_x() : double
	double most_right_x;

	most_right_x=polygon_points[0].getter_pos_x();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
	}
	return most_right_x;
!!!142986.cpp!!!	most_y() : double
	double most_down_y;

	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}
	return most_down_y;	
!!!143114.cpp!!!	area() : double
	if(polygon_points.size()==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.area();
	}
	else if(polygon_points.size()==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.area();
	}
	else if(polygon_points.size()==3){
		Triangle a(difference_mostAndleast_x());
		return a.area();
	}
	else
		return -1;
!!!143242.cpp!!!	perimeter() : double
	if(polygon_points.size()==100){
		Circle a(difference_mostAndleast_x()/2);
		return a.perimeter();
	}
	else if(polygon_points.size()==4){
		Rectangle a(difference_mostAndleast_x(),difference_mostAndleast_y());
		return a.perimeter();
	}
	else if(polygon_points.size()==3){
		Triangle a(difference_mostAndleast_x());
		return a.perimeter();
	}
	else
		return -1;	
!!!141962.cpp!!!	operator =(in rtSide : PolygonVect) : PolygonVect
	if(this==&rtSide)
		return *this;
	else{
		polygon_points.resize(0);
		for(int i=0;i<rtSide.polygon_points.size();++i){
			polygon_points.push_back(rtSide.polygon_points[i]);
		}
		return *this;
	}
!!!142090.cpp!!!	operator [](in index : uint) : Point2D
	if(polygon_points.size()==0){

		cout<<"Points array is empty ,can not be reached an element of it"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else if(index<0 || index>=polygon_points.size()){

		cout<<"index is out of range"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else
		return polygon_points[index];
!!!142218.cpp!!!	operator [](in index : uint) : Point2D
	if(polygon_points.size()==0){
		cout<<"Points array is empty ,can not be reached an element of it"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else if(index<0 || index>=polygon_points.size()){
		cout<<"index is out of range"<<endl;
		Point2D a;
		Point2D& b=a;
		return b;
	}
	else
		return polygon_points[index];
!!!142346.cpp!!!	operator +(in other : PolygonVect) : PolygonVect
	vector<Point2D> temp;
	for(int i=0;i<polygon_points.size();++i){
		temp.push_back(polygon_points[i]);
	}
	for(int i=0;i<other.polygon_points.size();++i){
		temp.push_back(other.polygon_points[i]);
	}
	PolygonVect a(temp);
	return a;

!!!143370.cpp!!!	getter_pos_x() : double
	if(polygon_points.size()==4 || polygon_points.size()==3) //posx of rectangle left-top corner. pos_x of circle middle of circle.pos _x triangle left-down corner
		return  most_x()-difference_mostAndleast_x();
	else 
		return most_x()-(difference_mostAndleast_x()/2);
!!!143498.cpp!!!	getter_pos_y() : double
	if(polygon_points.size()==4)
		return  most_y()-difference_mostAndleast_y(); //pos_y of rectangle left-top corner.pos_y of circle middle of circle.pos_y of triangle left-down corner.
	else if(polygon_points.size()==3)
		return most_y(); 
	else 
		return most_y()-difference_mostAndleast_y()/2;
!!!141450.cpp!!!	operator ++(in  : int) : PolygonVect

PolygonVect *temp=new PolygonVect(polygon_points);

	for(int i=0;i<polygon_points.size();++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()+1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()+1);
	}
	return *temp;

!!!141578.cpp!!!	operator ++() : PolygonVect

	for(int i=0;i<polygon_points.size();++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()+1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()+1);
	}
	return *this;
!!!141706.cpp!!!	operator --(in  : int) : PolygonVect
	PolygonVect *temp=new PolygonVect(polygon_points);

	for(int i=0;i<polygon_points.size();++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()-1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()-1);
	}
	return *temp;
!!!141834.cpp!!!	operator --() : PolygonVect
	for(int i=0;i<polygon_points.size();++i){
		polygon_points[i].setter_pos_x(polygon_points[i].getter_pos_x()-1);
		polygon_points[i].setter_pos_y(polygon_points[i].getter_pos_y()-1);
	}
	return *this;
!!!142474.cpp!!!	print_shape(inout outputfile : ofstream) : ofstream

	double most_right_x,most_down_y;
	most_right_x=polygon_points[0].getter_pos_x();
	most_down_y=polygon_points[0].getter_pos_y();
	for(int i=1;i<polygon_points.size();++i){
		if(polygon_points[i].getter_pos_x()>most_right_x)
			most_right_x=polygon_points[i].getter_pos_x();
		if(polygon_points[i].getter_pos_y()>most_down_y)
			most_down_y=polygon_points[i].getter_pos_y();
	}
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<most_right_x<<"\" height=\""<<most_down_y<<"\" "<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\"";

	for(int i=0;i<polygon_points.size();++i){
		outputfile<<" "<<polygon_points[i].getter_pos_x();
		outputfile<<","<<polygon_points[i].getter_pos_y();
		if(i<polygon_points.size()-1)
			outputfile<<" ";
	}
	outputfile<<"\""<<endl;
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
