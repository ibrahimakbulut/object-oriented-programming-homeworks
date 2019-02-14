class Triangle
!!!153482.cpp!!!	plus_triangles() : void
	objectCount+=1;
!!!150794.cpp!!!	setter_lenght_of_triangle(in lenght_of_triangle : double) : void
	
	lenght_of_Triangle=lenght_of_triangle;   //Triangle_lenght is actual lenght ,triangle_lenght is user input
!!!150026.cpp!!!	setter_point1(in pos_x : double, in pos_y : double) : void
	point1_pos_x=pos_x;
	point1_pos_y=pos_y;
!!!150154.cpp!!!	setter_point2(in pos_x : double, in pos_y : double) : void
	point2_pos_x=pos_x;
	point2_pos_y=pos_y;
!!!150282.cpp!!!	setter_point3(in pos_x : double, in pos_y : double) : void
	point3_pos_x=pos_x;
	point3_pos_y=pos_y;
!!!150410.cpp!!!	setter_objectCount(in new_value : int) : void
	objectCount=new_value;
!!!150922.cpp!!!	getter_point1_x() : double
	return point1_pos_x;
!!!151050.cpp!!!	getter_point1_y() : double
	return point1_pos_y;
!!!151178.cpp!!!	getter_point2_x() : double
	return point2_pos_x;
!!!151306.cpp!!!	getter_point2_y() : double
	return point2_pos_y;
!!!151434.cpp!!!	getter_point3_x() : double
	return point3_pos_x;
!!!151562.cpp!!!	getter_point3_y() : double
	return point3_pos_y;
!!!153354.cpp!!!	getter_lenght_of_triangle() : double
	return lenght_of_Triangle;
!!!152970.cpp!!!	getter_objectCount() : int
	return objectCount;
!!!153610.cpp!!!	Triangle()
 //No parameter constructor
	
	point1_pos_x=0;
	point1_pos_y=0;
		
	point2_pos_x=0;
	point2_pos_y=0;
		
	point3_pos_x=0;
	point3_pos_y=0;
		
	lenght_of_Triangle=0;
	total_area+=area();  //this calculation 0 because it has no size all size are 0.
	total_perimeter+=perimeter();
!!!153738.cpp!!!	Triangle(in lenght_of_triangle : double)
	lenght_of_Triangle=lenght_of_triangle;

	point1_pos_x=lenght_of_Triangle/2;
	point1_pos_y=0;
		
	point2_pos_x=0;
	point2_pos_y=lenght_of_Triangle*sqrt(3.0)/2;
		
	point3_pos_x=lenght_of_Triangle;
	point3_pos_y=lenght_of_Triangle*sqrt(3.0)/2;
	total_area+=area();
	total_perimeter+=perimeter();

!!!153866.cpp!!!	Triangle(in lenght_of_triangle : double, in pos1_x : double, in pos1_y : double, in pos2_x : double, in pos2_y : double, in pos3_x : double, in pos3_y : double)
	
	point1_pos_x=pos1_x;
	point1_pos_y=pos1_y;
		
	point2_pos_x=pos2_x;
	point2_pos_y=pos2_y;
		
	point3_pos_x=pos3_x;
	point3_pos_y=pos3_y;
		
	lenght_of_Triangle=lenght_of_triangle;
	total_area+=area();	
	total_perimeter+=perimeter();
!!!151690.cpp!!!	operator ++(in  : int) : Triangle
	double temp_point1_pos_x=point1_pos_x;
	double temp_point1_pos_y=point1_pos_y;

	double temp_point2_pos_x=point2_pos_x;
	double temp_point2_pos_y=point2_pos_y;

	double temp_point3_pos_x=point3_pos_x;
	double temp_point3_pos_y=point3_pos_y;

	point1_pos_x+=1.0;
	point1_pos_y+=1.0;

	point2_pos_x+=1.0;
	point2_pos_y+=1.0;

	point3_pos_x+=1.0;
	point3_pos_y+=1.0;

	Triangle *temp=new Triangle(lenght_of_Triangle,temp_point1_pos_x,temp_point1_pos_y,temp_point2_pos_x,temp_point2_pos_y,temp_point3_pos_x,temp_point3_pos_y);
	return *temp;
!!!151818.cpp!!!	operator ++() : Triangle
	point1_pos_x+=1.0;
	point1_pos_y+=1.0;

	point2_pos_x+=1.0;
	point2_pos_y+=1.0;

	point3_pos_x+=1.0;
	point3_pos_y+=1.0;

	return *this;
!!!151946.cpp!!!	operator --(in  : int) : Triangle
	double temp_point1_pos_x=point1_pos_x;
	double temp_point1_pos_y=point1_pos_y;

	double temp_point2_pos_x=point2_pos_x;
	double temp_point2_pos_y=point2_pos_y;

	double temp_point3_pos_x=point3_pos_x;
	double temp_point3_pos_y=point3_pos_y;

	point1_pos_x-=1.0;
	point1_pos_y-=1.0;

	point2_pos_x-=1.0;
	point2_pos_y-=1.0;

	point3_pos_x-=1.0;
	point3_pos_y-=1.0;

	Triangle *temp=new Triangle(lenght_of_Triangle,temp_point1_pos_x,temp_point1_pos_y,temp_point2_pos_x,temp_point2_pos_y,temp_point3_pos_x,temp_point3_pos_y);
	return *temp;
!!!152074.cpp!!!	operator --() : Triangle
	point1_pos_x-=1.0;
	point1_pos_y-=1.0;

	point2_pos_x-=1.0;
	point2_pos_y-=1.0;

	point3_pos_x-=1.0;
	point3_pos_y-=1.0;

	return *this;
!!!149642.cpp!!!	area() : double
	return ((pow(lenght_of_Triangle,2.0)*sqrt(3.0))/4.0);
!!!149770.cpp!!!	perimeter() : double
	if(lenght_of_Triangle<0){
		return -3*lenght_of_Triangle;
	}
	return 3*lenght_of_Triangle;
!!!152202.cpp!!!	operator +(in adding_size : double) : Triangle
	return Triangle(lenght_of_Triangle+adding_size);
!!!152330.cpp!!!	operator +(in adding_size : double, in shape : Triangle) : Triangle
 	return Triangle(shape.lenght_of_Triangle+adding_size);
!!!152458.cpp!!!	operator -(in adding_size : double) : Triangle
	return Triangle(lenght_of_Triangle-adding_size);
!!!152586.cpp!!!	operator -(in adding_size : double, in shape : Triangle) : Triangle
	return Triangle(adding_size-shape.lenght_of_Triangle);
!!!152714.cpp!!!	print_shape(inout outputfile : ofstream) : ofstream
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<point1_pos_x<<","<<point1_pos_y;
	outputfile<<" "<<point2_pos_x<<" ,"<<point2_pos_y;
	outputfile<<" "<<point3_pos_x<<" ,"<<point3_pos_y<<"\"";
	outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	outputfile<<"</svg>";
	return outputfile;
!!!153098.cpp!!!	getter_total_area() : double
	return total_area;
!!!153226.cpp!!!	getter_total_perimeter() : double
	return total_perimeter;
!!!150538.cpp!!!	setter_total_area(in new_value : double) : void
	total_area=new_value;
!!!150666.cpp!!!	setter_total_perimeter(in new_value : double) : void
	total_perimeter=new_value;
