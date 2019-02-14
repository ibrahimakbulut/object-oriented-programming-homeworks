//Circle.h
#include <fstream>

using namespace std;
class Circle {
	
	public:
		
		void setter_radius(double radius);
		void setter_position_x(double pos_x);
		void setter_position_y(double pos_y);
		static void setter_objectCount(int new_value);
		
		void draw(ofstream& outputfile)const;
		
		double getter_pos_x()const;
		double getter_pos_y()const;
		double getter_radius()const;
		static int getter_objectCount();
		
		static void plus_circles();
		
		Circle();
		Circle(double radius,double pos_x,double pos_y);
		
	private:
		
		static int objectCount;
		double radius_of_circle;
		
		double Pos_x;
		double Pos_y;
};
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
