// Rectangle.h
#include <fstream>

using namespace std;

class Rectangle {
	
	public:
		
		void setter_position(double pos_x,double pos_y);
		void setter_width(double width);
		void setter_height(double height);
		static void setter_objectCount(int new_value);
		
		void draw(ofstream& outputfile)const;
		
		static void plus_rectangles();
		
		double getter_pos_x()const;
		double getter_pos_y()const;
		double getter_width()const;
		double getter_height()const;
		static int getter_objectCount();
		
		Rectangle();
		Rectangle(double width,double height,double pos_x,double pos_y);
		
	private:
		
		double Pos_x;
		double Pos_y;
		
		double Width;
		double Height;
		
		static int objectCount;
};
inline void Rectangle::plus_rectangles(){
	objectCount+=1;
}
inline void Rectangle::setter_position(double pos_x,double pos_y){
	
	Pos_x=pos_x;
	Pos_y=pos_y;
}
inline void Rectangle::setter_width(double width){
	Width=width;
}
inline void Rectangle::setter_height(double height){
	Height=height;
}
inline void Rectangle::setter_objectCount(int new_value){
	objectCount=new_value;
}
inline double Rectangle::getter_pos_x()const{
	return Pos_x;
}
inline double Rectangle::getter_pos_y()const{
	return Pos_y;
}
inline double Rectangle::getter_width()const{
	return Width;
}
inline double Rectangle::getter_height()const{
	return Height;
}
inline int Rectangle::getter_objectCount(){
	return objectCount;
}
