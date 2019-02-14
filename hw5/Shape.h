
#ifndef SHAPE_H

#define SHAPE_H

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

namespace Shape_base{

class Shape{

	public:

		//virtual ~Shape()=default; 

		virtual double area()const=0;
		virtual double perimeter()const=0;
		virtual ofstream& print_shape(ofstream& outputfile)const=0; 

		friend ofstream& operator<<(ofstream& outputfile,const Shape& other);

		virtual  Shape& operator ++(int)=0;
		virtual  Shape& operator ++()=0;

		virtual  Shape& operator --(int)=0;
		virtual  Shape& operator --()=0;
		
		bool operator==(const Shape& other)const;
		bool operator!=(const Shape& other)const;
		bool operator <(const Shape& other)const;
		bool operator >(const Shape& other)const;
		bool operator >=(const Shape& other)const;
		bool operator <=(const Shape& other)const;


};

}

#endif
