//Circle.h
#include <fstream>

using namespace std;
class Circle {
	
	public:
		
		void setter_radius(double radius);
		void setter_position_x(double pos_x);
		void setter_position_y(double pos_y);
		static void setter_objectCount(int new_value); //change the objectCount
		static void setter_total_area(double new_value);
		static void setter_total_perimeter(double new_value);
		
		double getter_pos_x()const;
		double getter_pos_y()const;
		double getter_radius()const;

		static int getter_objectCount();
		static double getter_total_area();
		static double getter_total_perimeter();

		Circle operator ++(int);
		Circle operator ++();

		Circle operator --(int);
		Circle operator --();

		bool operator ==(const Circle& other)const;
		bool operator !=(const Circle& other)const;
		bool operator <(const Circle& other)const;
		bool operator >(const Circle& other)const;
		bool operator >=(const Circle& other)const;
		bool operator <=(const Circle& other)const;

		const Circle operator +(double adding_size)const; 
		friend const Circle operator +(double adding_size,const Circle& shape);
		const Circle operator -(double adding_size)const;
		friend const Circle operator -(double adding_size,const Circle& shape);

		friend ofstream& operator <<(ofstream& outputfile,const Circle& shape);
		friend ostream& operator <<(ostream& outputStream,const Circle& shape);

		double getter_area()const;
		double getter_perimeter_lenght()const;
		
		static void plus_circles();  //increase 1 objectCount
		
		Circle();
		Circle(double radius);
		Circle(double radius,double pos_x,double pos_y);
		
	private:
		
		static int objectCount;  //how many circle created for inner shape.
		static double total_area;
		static double total_perimeter;
		double radius_of_circle;
		
		double Pos_x;
		double Pos_y;
};
//below inline functions implementations are performed here because if implementations are performed circle.cpp file ,there is errors that undefined reference these functions
inline void  Circle::plus_circles(){ 
	objectCount+=1;
}

inline void Circle::setter_position_x(double pos_x){
	Pos_x=pos_x;
}
inline void Circle::setter_position_y(double pos_y){
	Pos_y=pos_y;
}
inline void Circle::setter_radius(double radius){
	
	radius_of_circle=radius;
}
inline void Circle::setter_objectCount(int new_value){
	objectCount=new_value;
}
inline double Circle::getter_pos_x()const{
	return Pos_x;
}
inline double Circle::getter_pos_y()const{
	return Pos_y;
}
inline double Circle::getter_radius()const{
	return radius_of_circle;
}
inline int Circle::getter_objectCount(){
	return objectCount;
}
