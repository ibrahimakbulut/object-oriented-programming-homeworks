class Rectangle
!!!144906.cpp!!!	plus_rectangles() : void
	objectCount+=1;
!!!144010.cpp!!!	setter_position(in pos_x : double, in pos_y : double) : void
	
	Pos_x=pos_x;
	Pos_y=pos_y;
!!!144138.cpp!!!	setter_width(in width : double) : void
	Width=width;
!!!144266.cpp!!!	setter_height(in height : double) : void
	Height=height;
!!!144394.cpp!!!	setter_objectCount(in new_value : int) : void
	objectCount=new_value;
!!!146314.cpp!!!	getter_pos_x() : double
	return Pos_x;
!!!146442.cpp!!!	getter_pos_y() : double
	return Pos_y;
!!!146570.cpp!!!	getter_width() : double
	return Width;
!!!146698.cpp!!!	getter_height() : double
	return Height;
!!!146826.cpp!!!	getter_objectCount() : int
	return objectCount;
!!!147466.cpp!!!	Rectangle()
 //No parameter constructor
	
	Pos_x=0;
	Pos_y=0;
	
	Width=0;
	Height=0;
	total_area+=area();  //this calculation 0 because it has no size all size are 0.
	total_perimeter+=perimeter();
!!!147594.cpp!!!	Rectangle(in width : double, in height : double)

	Width=width;
	Height=height;

	Pos_x=0;
	Pos_y=0;
	total_area+=area();
	total_perimeter+=perimeter();
!!!147722.cpp!!!	Rectangle(in width : double, in height : double, in pos_x : double, in pos_y : double)
 //constructor with parameters
	
	Pos_x=pos_x;
	Pos_y=pos_y;
	
	Width=width;
	Height=height;
	total_area+=area();
	total_perimeter+=perimeter();	
!!!145034.cpp!!!	operator ++(in  : int) : Rectangle
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x+=1.0;
	Pos_y+=1.0;

	Rectangle *temp =new Rectangle(Width,Height,temp_pos_x,temp_pos_y);
	return *temp;
!!!145162.cpp!!!	operator ++() : Rectangle
	Pos_x+=1.0;
	Pos_y+=1.0;

	return *this;
!!!145290.cpp!!!	operator --(in  : int) : Rectangle
	double temp_pos_x=Pos_x;
	double temp_pos_y=Pos_y;

	Pos_x-=1.0;
	Pos_y-=1.0;

	Rectangle *temp=new Rectangle(Width,Height,temp_pos_x,temp_pos_y);
	return *temp;
!!!145418.cpp!!!	operator --() : Rectangle
	Pos_x-=1.0;
	Pos_y-=1.0;

	return *this;
!!!147210.cpp!!!	area() : double
	if(Width<0 && Height>0){
		return -Width*Height;
	}
	else if(Width>0 && Height<0){
		return Width*-Height;
	}
	return Width*Height;
!!!147338.cpp!!!	perimeter() : double
	if(Width<0 && Height<0){
		return -2*(Width+Height);
	}
	else if(Width<0 && Height>0){
		return 2*(-Width+Height);
	}
	else if(Width>0 && Height<0){
		return 2*(Width+-Height);
	}
	return 2*(Width+Height);
!!!145546.cpp!!!	operator +(in adding_size : double) : Rectangle
	return Rectangle(Width+adding_size,Height+adding_size);
!!!145674.cpp!!!	operator +(in adding_size : double, in shape : Rectangle) : Rectangle
	return Rectangle(shape.Width+adding_size,shape.Height+adding_size);
!!!145802.cpp!!!	operator -(in adding_size : double) : Rectangle
	return Rectangle(Width-adding_size,Height-adding_size);
!!!145930.cpp!!!	operator -(in adding_size : double, in shape : Rectangle) : Rectangle
	return Rectangle(adding_size-shape.Width,adding_size-shape.Height);
!!!146058.cpp!!!	print_shape(inout outputfile : ofstream) : ofstream
	if(Pos_x>Width)
			outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<"width=\""<<Pos_x+Width<<"\" height=\""<<Pos_y+Height<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	else
		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<Pos_x<<"\" y=\""<<Pos_y;
	outputfile<<"\" width=\""<<Width<<"\" height=\""<<Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
!!!146186.cpp!!!	operator <<(inout outputStream : ostream, in shape : Rectangle) : ostream

	cout<<"pozition x: "<<shape.Pos_x<<" , "<<"pozition y "<<shape.Pos_y<<endl;
	cout<<"area of this rectangle is "<<shape.area()<<endl;
	cout<<"perimeter lenght of this rectangle is "<<shape.perimeter()<<endl;
	return outputStream;
!!!144778.cpp!!!	draw(inout outputfile : ofstream) : void
 //This function can print a rectangle with rectangle properties

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect x=\""<<Pos_x<<"\" y=\""<<Pos_y;
	outputfile<<"\" width=\""<<Width<<"\" height=\""<<Height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
	outputfile<<"</svg>";
!!!146954.cpp!!!	getter_total_area() : double
	return total_area;
!!!147082.cpp!!!	getter_total_perimeter() : double
	return total_perimeter;
!!!144522.cpp!!!	setter_total_area(in new_value : double) : void
	total_area=new_value;
!!!144650.cpp!!!	setter_total_perimeter(in new_value : double) : void
	total_perimeter=new_value;
