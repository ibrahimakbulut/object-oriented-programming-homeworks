class Circle
!!!131082.cpp!!!	plus_circles() : void
 
	objectCount+=1;
!!!128138.cpp!!!	setter_position_x(in pos_x : double) : void
	Pos_x=pos_x;
!!!128266.cpp!!!	setter_position_y(in pos_y : double) : void
	Pos_y=pos_y;
!!!128010.cpp!!!	setter_radius(in radius : double) : void
	
	radius_of_circle=radius;
!!!128394.cpp!!!	setter_objectCount(in new_value : int) : void
	objectCount=new_value;
!!!128778.cpp!!!	getter_pos_x() : double
	if(Pos_x==0 && radius_of_circle!=0){
		return radius_of_circle;
	}
	return Pos_x;
!!!128906.cpp!!!	getter_pos_y() : double
	if(Pos_y==0 && radius_of_circle!=0){
		return radius_of_circle;
	}
	return Pos_y;
!!!129034.cpp!!!	getter_radius() : double
	return radius_of_circle;
!!!129162.cpp!!!	getter_objectCount() : int

	return objectCount;
!!!131210.cpp!!!	Circle()
  //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	radius_of_circle=0;
	total_area+=area();//this calculation 0 because it has no size all size are 0.
	total_perimeter+=perimeter();
!!!131338.cpp!!!	Circle(in radius : double)
	radius_of_circle=radius;
	Pos_x=radius_of_circle;
	Pos_y=radius_of_circle;
	total_area+=area();
	total_perimeter+=perimeter();
!!!131466.cpp!!!	Circle(in radius : double, in pos_x : double, in pos_y : double)
 //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	radius_of_circle=radius;
	total_area+=area();
	total_perimeter+=perimeter();
!!!129546.cpp!!!	operator ++(in  : int) : Circle
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	Circle *temp=new Circle(radius_of_circle,temp_pos_x,temp_pos_y);
	return *temp;
!!!129674.cpp!!!	operator ++() : Circle
	Pos_x+=1.0;
	Pos_y+=1.0;

	return *this;
!!!129802.cpp!!!	operator --(in  : int) : Circle
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	Circle *temp=new Circle(radius_of_circle,temp_pos_x,temp_pos_y);
	return *temp;
!!!129930.cpp!!!	operator --() : Circle
	Pos_x-=1.0;
	Pos_y-=1.0;

	return *this;
!!!130826.cpp!!!	area() : double
	return PI*pow(radius_of_circle,2.0);
!!!130954.cpp!!!	perimeter() : double
	if(radius_of_circle<0){
		return -2*PI*radius_of_circle;
	}
	return 2*PI*radius_of_circle;
!!!130058.cpp!!!	operator +(in adding_size : double) : Circle
	return Circle(radius_of_circle+adding_size);
!!!130186.cpp!!!	operator +(in adding_size : double, in shape : Circle) : Circle
	return Circle(shape.radius_of_circle+adding_size);
!!!130314.cpp!!!	operator -(in adding_size : double) : Circle
	return Circle(radius_of_circle-adding_size);
!!!130442.cpp!!!	operator -(in adding_size : double, in shape : Circle) : Circle
	return Circle(adding_size-shape.radius_of_circle);
!!!130570.cpp!!!	print_shape(inout outputfile : ofstream) : ofstream
	if(Pos_x>2*radius_of_circle)
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" width=\""<<Pos_x+radius_of_circle<<"\" height=\""<<Pos_y+radius_of_circle<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	else
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<Pos_x<<"\" ";
	outputfile<<"cy=\""<<Pos_y<<"\""<<" r=\""<<radius_of_circle<<"\" ";
	outputfile<<" fill=\"red\"/>"<<endl;
	outputfile<<"</svg>";
	return outputfile;
!!!130698.cpp!!!	operator <<(inout outputStream : ostream, in shape : Circle) : ostream
	cout<<"pozition x of this circle: "<<shape.Pos_x<<" , "<<"pozition y of this circle: "<<shape.Pos_y<<endl;
	cout<<"area of this circle is "<<shape.area()<<endl;
	cout<<"perimeter of this circle is "<<shape.perimeter()<<endl;
	return outputStream;
!!!129290.cpp!!!	getter_total_area() : double
	return total_area;
!!!129418.cpp!!!	getter_total_perimeter() : double
	return total_perimeter;
!!!128522.cpp!!!	setter_total_area(in new_value : double) : void
	total_area=new_value;
!!!128650.cpp!!!	setter_total_perimeter(in new_value : double) : void
	total_perimeter=new_value;
