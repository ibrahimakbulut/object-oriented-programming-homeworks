// Triangle.h
#include <fstream>
#include <iostream>

using namespace std;
class Triangle {
	
	public:
		
		void setter_point1(double pos_x,double pos_y);
		void setter_point2(double pos_x,double pos_y);
		void setter_point3(double pos_x,double pos_y);
		static void setter_objectCount(int new_value);
		
		void setter_lenght_of_triangle(double lenght_of_triangle);
		void draw(ofstream& outputfile)const;
		
		double getter_point1_x()const;
		double getter_point1_y()const;
		double getter_point2_x()const;
		double getter_point2_y()const;
		double getter_point3_x()const;
		double getter_point3_y()const;
		
		static int getter_objectCount();
		
		double getter_lenght_of_triangle()const;
		static void plus_triangles();
		
		Triangle();
		Triangle(double lenght_of_triangle,double pos1_x,double pos1_y,double pos2_x,double pos2_y,double pos3_x,double pos3_y);
		
		
	private:
		
		static int objectCount;
		
		double point1_pos_x;
		double point1_pos_y;
		
		double point2_pos_x;
		double point2_pos_y;
		
		double point3_pos_x;
		double point3_pos_y;
		
		double lenght_of_Triangle;
		
};

inline void Triangle::plus_triangles(){
	objectCount+=1;
}
void Triangle::setter_lenght_of_triangle(double lenght_of_triangle){
	
	lenght_of_Triangle=lenght_of_triangle;   //Triangle_lenght is actual lenght ,triangle_lenght is user input
	
}
inline void Triangle::setter_point1(double pos_x,double pos_y){
	point1_pos_x=pos_x;
	point1_pos_y=pos_y;
}

inline void Triangle::setter_point2(double pos_x,double pos_y){
	point2_pos_x=pos_x;
	point2_pos_y=pos_y;
}
inline void Triangle::setter_point3(double pos_x,double pos_y){
	point3_pos_x=pos_x;
	point3_pos_y=pos_y;
}
inline void Triangle::setter_objectCount(int new_value){
	objectCount=new_value;
}
inline double Triangle::getter_point1_x()const{
	return point1_pos_x;
}
inline double Triangle::getter_point1_y()const{
	return point1_pos_y;
}
inline double Triangle::getter_point2_x()const{
	return point2_pos_x;
}
inline double Triangle::getter_point2_y()const{
	return point2_pos_y;
}
inline double Triangle::getter_point3_x()const{
	return point3_pos_x;
}
inline double Triangle::getter_point3_y()const{
	return point3_pos_y;
}
inline double Triangle::getter_lenght_of_triangle()const{
	return lenght_of_Triangle;
}
inline int Triangle::getter_objectCount(){
	return objectCount;
}
