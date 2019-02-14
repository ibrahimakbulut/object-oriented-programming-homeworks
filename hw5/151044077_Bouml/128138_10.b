class Shape
!!!148234.cpp!!!	operator <<(inout outputfile : ofstream, in shape : Shape) : ofstream
	return shape.print_shape(outputfile);
!!!148874.cpp!!!	operator ==(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a==b);
!!!149002.cpp!!!	operator !=(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a!=b);
!!!149130.cpp!!!	operator <(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a<b);
!!!149258.cpp!!!	operator >(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a>b);
!!!149386.cpp!!!	operator >=(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a>=b);
!!!149514.cpp!!!	operator <=(in other : Shape) : bool
	double a=area();
	double b=other.area();
	return (a<=b);
