#include <iostream>
#include <fstream>
#include <math.h>
#include<limits> /*just for take an valid input that integer used*/

using namespace std;

enum class Shapes{
	rectangle,
	triangle,
	circle
	};

#define PI 3.1415929

int circles_into_rectangle(const double& width,const double& height,const double& radius);
int rectangles_into_rectangle(const double& container_width,const double& container_height,const double& shape_width ,const double& shape_height);
int triangles_into_rectangle(const double& width,const double& height,const double& lenght_of_triangle_edge);

int triangles_into_triangle(const double& lenght_of_container_triangle,const double& lenght_of_small_triangle);
int rectangles_into_triangle(const double& lenght_of_triangle,const double& rectangle_width,const double& rectangle_height);
int circles_into_triangle(const double& lenght_of_triangle,const double& radius_of_circle);

int circles_into_circle(const double& radius_of_container_circle,const double& radius_of_small_circle);
int rectangles_into_circle(const double& radius_of_circle,const double& rectangle_width,const double& rectangle_height);
int triangles_into_circle(double& radius_of_circle,double& lenght_of_triangle);

int main(void){

double  rectangle_width,rectangle_height,radius_of_circle,lenght_of_triangle;
int shape_valid=0;
char shape;
Shapes container_shape;


rectangle_width=0,rectangle_height=0,radius_of_circle=0,lenght_of_triangle=0;
	
	do{
	cout<<"please enter the main  shape(R,T,C)"<<endl;
	
	cin>>shape;

	if (shape=='R' || shape=='r')
		container_shape=Shapes::rectangle;
	else if(shape=='T' || shape=='t')
		container_shape=Shapes::triangle;
	else if(shape=='C' || shape=='c')
		 container_shape=Shapes::circle;

	
	if(container_shape==Shapes::rectangle){
		shape_valid=1;
		
		cout<<"please enter the width"<<endl;

    		while(!(cin >> rectangle_width)){    /*continius until user enter integer */
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		cout<<"please enter the height"<<endl;

    		while(!(cin >> rectangle_height)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		do{

			if(rectangle_height*rectangle_width<1){
			cout<<"container rectangle is too smal.please enter sizes again."<<endl;

				cout<<"please enter the width"<<endl;

    				while(!(cin >> rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				cout<<"please enter the height"<<endl;

    				while(!(cin >> rectangle_height)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(rectangle_height*rectangle_width<1); /*check the validity of user input that is too small */


	double  small_rectangle_width,small_rectangle_height,small_radius_of_circle,small_lenght_of_triangle;
	small_rectangle_width=0,small_rectangle_height=0,small_radius_of_circle=0,small_lenght_of_triangle=0;
	int shape_valid_in=0;
	char shape_in;
	Shapes small_shape;
		
	do{
	cout<<"enter the small shape (R,T,C)"<<endl;
	
	cin>>shape_in;

	if (shape_in=='R' || shape_in=='r')
		small_shape=Shapes::rectangle;
	else if(shape_in=='T' || shape_in=='t')
		small_shape=Shapes::triangle;
	else if(shape_in=='C' || shape_in=='c')
		small_shape=Shapes::circle;


	
	
	if(small_shape==Shapes::rectangle){
		shape_valid_in=1;
		
		cout<<"please enter the width"<<endl;

    		while(!(cin >> small_rectangle_width)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		cout<<"please enter the height"<<endl;

    		while(!(cin >> small_rectangle_height)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		do{

			if(small_rectangle_height*small_rectangle_width<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the width"<<endl;

    				while(!(cin >> small_rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				cout<<"please enter the height"<<endl;

    				while(!(cin >> small_rectangle_height)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(small_rectangle_height*small_rectangle_width<0);/*chech the user input valid that is negative*/
		
		
		double container_area=rectangle_width*rectangle_height;
		double small_shape_area=small_rectangle_width*small_rectangle_height;
		
		int rectangle_number_fitted=rectangles_into_rectangle(rectangle_width,rectangle_height,small_rectangle_width,small_rectangle_height);

		double remain_area=container_area-(small_shape_area*rectangle_number_fitted);

		cout<<"I can fit at most "<<rectangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;
		

		}


	if(small_shape==Shapes::triangle){

		shape_valid_in=1;
		
		cout<<"please enter the edge lenght of triangle"<<endl;

    		while(!(cin >> small_lenght_of_triangle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_lenght_of_triangle<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the edge lenght_of_triangle"<<endl;

    				while(!(cin >> small_lenght_of_triangle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_lenght_of_triangle<0);	/*chech the user input valid that is negative*/

		double container_area=rectangle_width*rectangle_height;
		double small_shape_area=pow(small_lenght_of_triangle,2.0)*sqrt(3.0)/4;
		
		int triangle_number_fitted=triangles_into_rectangle(rectangle_width,rectangle_height,small_lenght_of_triangle);

		double remain_area=container_area-(small_shape_area*triangle_number_fitted);

		cout<<"I can fit at most "<<triangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;

		}

	if(small_shape==Shapes::circle){

		shape_valid_in=1;
		
		cout<<"please enter the radius of circle"<<endl;

    		while(!(cin >> small_radius_of_circle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_radius_of_circle<0){
			cout<<"invalid input for small shape enter again"<<endl;

				cout<<"please enter the radius of circle"<<endl;

    				while(!(cin >> small_radius_of_circle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_radius_of_circle<0);	/*chech the user input valid that is negative*/

		double container_area=rectangle_width*rectangle_height;
		double small_shape_area=PI*pow(small_radius_of_circle,2.0);
		
		int circle_number_fitted=circles_into_rectangle(rectangle_width,rectangle_height,small_radius_of_circle);

		double remain_area=container_area-(small_shape_area*circle_number_fitted);

		cout<<"I can fit at most "<<circle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;

		}

	     }while(shape_valid_in<1);
	}


	if(container_shape==Shapes::triangle){
		shape_valid=1;
		
		cout<<"please enter the edge lenght of triangle"<<endl;

    		while(!(cin >> lenght_of_triangle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		
		do{

			if(lenght_of_triangle<1){
			cout<<"container triangle is too smal.please enter sizes again."<<endl;

				cout<<"please enter lenght of triangle "<<endl;

    				while(!(cin >> rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(lenght_of_triangle<1);    /*check the validity of input that is too small */

	double  small_rectangle_width,small_rectangle_height,small_radius_of_circle,small_lenght_of_triangle;
	small_rectangle_width=0,small_rectangle_height=0,small_radius_of_circle=0,small_lenght_of_triangle=0;
	int shape_valid_in=0;
	char shape_in;
	Shapes small_shape;
		
	do{
	cout<<"enter the small shape (R,T,C)"<<endl;
	
	cin>>shape_in;

	if (shape_in=='R' || shape_in=='r')
		small_shape=Shapes::rectangle;
	else if(shape_in=='T' || shape_in=='t')
		 small_shape=Shapes::triangle;
	else if(shape_in=='C' || shape_in=='c')
		small_shape=Shapes::circle;

	if( small_shape==Shapes::rectangle){


		shape_valid_in=1;
		
		cout<<"please enter the width"<<endl;

    		while(!(cin >> small_rectangle_width)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		cout<<"please enter the height"<<endl;

    		while(!(cin >> small_rectangle_height)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		do{

			if(small_rectangle_height*small_rectangle_width<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the width"<<endl;

    				while(!(cin >> small_rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				cout<<"please enter the height"<<endl;

    				while(!(cin >> small_rectangle_height)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(small_rectangle_height*small_rectangle_width<0);   /*chech the user input valid that is negative*/
		
		
		double container_area=pow(lenght_of_triangle,2.0)*sqrt(3.0)/4;
		double small_shape_area=small_rectangle_width*small_rectangle_height;
		
		int rectangle_number_fitted=rectangles_into_triangle(lenght_of_triangle,small_rectangle_width,small_rectangle_height);

		double remain_area=container_area-(small_shape_area*rectangle_number_fitted);

		cout<<"I can fit at most "<<rectangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;
		}


	if(small_shape==Shapes::triangle){

		shape_valid_in=1;
		
		cout<<"please enter the edge lenght of triangle"<<endl;

    		while(!(cin >> small_lenght_of_triangle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_lenght_of_triangle<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the edge lenght_of_triangle"<<endl;

    				while(!(cin >> small_lenght_of_triangle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_lenght_of_triangle<0);	/*chech the user input valid that is negative*/

		double container_area=pow(lenght_of_triangle,2.0)*sqrt(3.0)/4;
		double small_shape_area=pow(small_lenght_of_triangle,2.0)*sqrt(3.0)/4;
		
		int triangle_number_fitted=triangles_into_triangle(lenght_of_triangle,small_lenght_of_triangle);

		double remain_area=container_area-(small_shape_area*triangle_number_fitted);

		cout<<"I can fit at most "<<triangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;
	
		}

	if(small_shape==Shapes::circle){

		shape_valid_in=1;
		
		cout<<"please enter the radius of circle"<<endl;

    		while(!(cin >> small_radius_of_circle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_radius_of_circle<0){
			cout<<"invalid input for small shape enter again"<<endl;

				cout<<"please enter the radius of circle"<<endl;

    				while(!(cin >> small_radius_of_circle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_radius_of_circle<0);	/*chech the user input valid that is negative*/

		double container_area=pow(lenght_of_triangle,2.0)*sqrt(3.0)/4;
		double small_shape_area=PI*pow(small_radius_of_circle,2.0);
		
		int circle_number_fitted=circles_into_triangle(lenght_of_triangle,small_radius_of_circle);

		double remain_area=container_area-(small_shape_area*circle_number_fitted);

		cout<<"I can fit at most "<<circle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;

		}
		}while(shape_valid_in<1);
	    }




	if(container_shape==Shapes::circle){
		shape_valid=1;
		
		cout<<"please enter the radius of circle"<<endl;

    		while(!(cin >> radius_of_circle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		
		do{

			if(radius_of_circle<1){
			cout<<"container circle is too smal.please enter sizes again."<<endl;

				cout<<"please enter lenght of triangle "<<endl;

    				while(!(cin >> rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(radius_of_circle<1); /*check the container size that is too small */

	double  small_rectangle_width,small_rectangle_height,small_radius_of_circle,small_lenght_of_triangle;
	small_rectangle_width=0,small_rectangle_height=0,small_radius_of_circle=0,small_lenght_of_triangle=0;
	int shape_valid_in=0;
	char shape_in;
	Shapes small_shape;
		
	do{
	cout<<"enter the small shape (R,T,C)"<<endl;
	
	cin>>shape_in;

	if (shape_in=='R' || shape_in=='r')
		small_shape=Shapes::rectangle;
	else if(shape_in=='T' || shape_in=='t')
		small_shape=Shapes::triangle;
	else if(shape_in=='C' || shape_in=='c')
		small_shape=Shapes::circle;

	
	if(small_shape==Shapes::rectangle){


		shape_valid_in=1;
		
		cout<<"please enter the width"<<endl;

    		while(!(cin >> small_rectangle_width)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		cout<<"please enter the height"<<endl;

    		while(!(cin >> small_rectangle_height)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}
		
		do{

			if(small_rectangle_height*small_rectangle_width<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the width"<<endl;

    				while(!(cin >> small_rectangle_width)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				cout<<"please enter the height"<<endl;

    				while(!(cin >> small_rectangle_height)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}

				
			}
		
		}while(small_rectangle_height*small_rectangle_width<0);/*chech the user input valid that is negative*/
		
		
		double container_area=PI*pow(radius_of_circle,2.0);
		double small_shape_area=small_rectangle_width*small_rectangle_height;
		
		int rectangle_number_fitted=rectangles_into_circle(radius_of_circle,small_rectangle_width,small_rectangle_height);

		double remain_area=container_area-(small_shape_area*rectangle_number_fitted);

		cout<<"I can fit at most "<<rectangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;
		}

	if(small_shape==Shapes::triangle){

		shape_valid_in=1;
		
		cout<<"please enter the edge lenght of triangle"<<endl;

    		while(!(cin >> small_lenght_of_triangle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_lenght_of_triangle<0){
			cout<<"invalid inputs for small shape enter again"<<endl;

				cout<<"please enter the edge lenght_of_triangle"<<endl;

    				while(!(cin >> small_lenght_of_triangle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_lenght_of_triangle<0);	/*chech the user input valid that is negative*/

		double container_area=PI*pow(radius_of_circle,2.0);
		double small_shape_area=pow(small_lenght_of_triangle,2.0)*sqrt(3.0)/4;
		
		int triangle_number_fitted=triangles_into_circle(radius_of_circle,small_lenght_of_triangle);

		double remain_area=container_area-(small_shape_area*triangle_number_fitted);

		cout<<"I can fit at most "<<triangle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;
	
		}

	if(small_shape==Shapes::circle){

		shape_valid_in=1;
		
		cout<<"please enter the radius of circle"<<endl;

    		while(!(cin >> small_radius_of_circle)){
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        		cout << "Please enter a valid size"<<endl;
    		}

		do{

			if(small_radius_of_circle<0){
			cout<<"invalid input for small shape enter again"<<endl;

				cout<<"please enter the radius of circle"<<endl;

    				while(!(cin >> small_radius_of_circle)){
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(),'\n');
        				cout << "Please enter a valid size"<<endl;
    				}
				
			}
		
		}while(small_radius_of_circle<0);	/*chech the user input valid that is negative*/

		double container_area=PI*pow(radius_of_circle,2.0);
		double small_shape_area=PI*pow(small_radius_of_circle,2.0);
		
		int circle_number_fitted=circles_into_circle(radius_of_circle,small_radius_of_circle);

		double remain_area=container_area-(small_shape_area*circle_number_fitted);

		cout<<"I can fit at most "<<circle_number_fitted<<" small shapes into main container. The empty area(green) in container ";
		cout<<"is "<<remain_area<<endl;

	}
	}while(shape_valid_in<1);

	}
	}while(shape_valid<1);

	return 0;
}
int circles_into_rectangle(const double& width,const double& height,const double& radius){

ofstream outputfile;

outputfile.open("output.svg");
	
double width_remaning=width-(static_cast<int>((width/(2*radius)))*radius*2);
double height_remaning=height-(static_cast<int>((height/(2*radius)))*radius*2);

int total_circles_first=0;int total_circles_second=0;


	/* this for count the circles in rectangular parttern */
	for(int i=1;(i*radius*2)<=(height-height_remaning);++i){
		for(int j=1;(j*radius*2)<=(width-width_remaning);++j,++total_circles_first){
			
		}
	}
	int height_counter=0;
	/*this for loop and while loop counts circle in triangular pattern */
	for(int i=1;((i*radius*2)+height_remaning)<=height;i++){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+(i%2)*width_remaning)<=width;j++,++total_circles_second){
			}
	height_counter=i;
	}
	int i=height_counter;

	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j,++total_circles_second){		
		}
		height_counter+=1;
	}

		outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<width<<"\""<<" ";
		outputfile<<"height=\""<<height<<"\""<<endl;
		outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
		outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	/*whic pattern is more efficient then apply that */
	if(total_circles_second>total_circles_first){

	 height_counter=0;
	/*triangular pattern fitting circles part */
	for(int i=1;((i*radius*2)+height_remaning)<=height;i++){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+(i%2)*width_remaning)<=width;++j){
				
				if(i%2==0){
				if((j*radius*2+radius)<=width){
					outputfile<<"<circle cx=\""<<j*radius*2<<"\" ";
				
				outputfile<<"cy=\""<<radius+(i-1)*(radius*pow(3,(1/2.0)))<<"\""<<" r=\""<<radius<<"\" ";
				/*outputfile<<"stroke=\"black\" stroke-width=\"2\"  ";*/
				outputfile<<"fill=\"red\"/>"<<endl;}
				}
				else{
				outputfile<<"<circle cx=\""<<j*radius+(j-1)*radius<<"\" ";
				outputfile<<"cy=\""<<radius+(i-1)*(radius*pow(3,(1/2.0)))<<"\""<<" r=\""<<radius<<"\" ";
				/*outputfile<<"stroke=\"black\" stroke-width=\"2\"  ";*/
				outputfile<<"fill=\"red\"/>"<<endl;
				}
		}
	height_counter=i;
	
	}
	int i=height_counter;

	while((2*radius+(height_counter)*radius*pow(3,(1/2.0)))<=height){
		for(int j=1;((j*radius*2)+(height_counter%2)*radius+((height_counter+1)%2)*width_remaning)<=width;++j){
				
			if((height_counter-1)%2==0){
			if((j*radius*2)<width){
				outputfile<<"<circle cx=\""<<j*radius*2<<"\" ";}
			
			outputfile<<"cy=\""<<radius+(height_counter)*(radius*pow(3,(1/2.0)))<<"\""<<" r=\""<<radius<<"\" ";
			/*outputfile<<"stroke=\"black\" stroke-width=\"2\"  ";*/
			outputfile<<"fill=\"red\"/>"<<endl;
			}
			else{
			outputfile<<"<circle cx=\""<<j*radius+(j-1)*radius<<"\" ";
			outputfile<<"cy=\""<<radius+(height_counter)*(radius*pow(3,(1/2.0)))<<"\""<<" r=\""<<radius<<"\" ";
			/*outputfile<<"stroke=\"black\" stroke-width=\"2\"  ";*/
			outputfile<<"fill=\"red\"/>"<<endl;
			}
		}
		height_counter+=1;
	}
		
	outputfile<<"</svg>"<<endl;
	outputfile.close();
	return total_circles_second;
	}

	/*rectangular pattern fitting circles part*/
	else{

	for(int i=1;(i*radius*2)<=(height-height_remaning);i++){
		for(int j=1;(j*radius*2)<=(width-width_remaning);j++){
			outputfile<<"<circle cx=\""<<width_remaning/2+j*(radius)+(j-1)*radius<<"\" ";
			outputfile<<"cy=\""<<height_remaning/2+i*(radius)+(i-1)*radius<<"\""<<" r=\""<<radius<<"\" ";
			outputfile<<"fill=\"red\"/>"<<endl;
		}
	}
	outputfile<<"</svg>"<<endl;
	outputfile.close();
	return total_circles_first;
	}
}

int rectangles_into_rectangle(const double& container_width,const double& container_height,const double& shape_width ,const double& shape_height){


/*if there is a solution that is fully divided on both sides then call it */
if( (static_cast <int>(container_width/shape_height)*shape_height==container_width) && (static_cast <int>(container_height/shape_width)*shape_width==container_height) ){

	return rectangles_into_rectangle(container_width,container_height,shape_height,shape_width);

}
if(shape_width>container_width && shape_height>container_height)
	return 0;
if(shape_height>container_width && shape_width>container_height)
	return 0;
if(shape_width>container_width && shape_width>container_height && shape_height>container_height && shape_height>container_width)
	return 0;
	ofstream outputfile;

	outputfile.open("output.svg");

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<container_width<<"\""<<" ";
	outputfile<<"height=\""<<container_height<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	int height_counter,width_counter;

	int total_rectangles=0;

/*likewise continues to lay shapes.*/
	for(int i=1;i*shape_height<=container_height;++i){

		for(int j=1;j*shape_width<=container_width;++j){

			outputfile<<"<rect x=\""<<(j-1)*shape_width<<"\" y=\""<<(i-1)*shape_height;
			outputfile<<"\" width=\""<<shape_width<<"\" height=\""<<shape_height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
		
			width_counter=j;
			total_rectangles+=1;
		}
		
		height_counter=i;
	}

	/*if there is space left on the right side, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=container_height;++i){

		for(int j=1;j*shape_height<=(container_width-width_counter*shape_width);++j){

			outputfile<<"<rect x=\""<<width_counter*shape_width+(j-1)*shape_height<<"\" y=\""<<(i-1)*shape_width;
			outputfile<<"\" width=\""<<shape_height<<"\" height=\""<<shape_width<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;	
		}
	}	
	/*if the space is left below, it tries to rotate and fit*/
	for(int i=1;i*shape_width<=(container_height-height_counter*shape_height);++i){

		for(int j=1;j*shape_height<=container_width;++j){
			outputfile<<"<rect x=\""<<(j-1)*shape_height<<"\" y=\""<<height_counter*shape_height+(i-1)*shape_height;
			outputfile<<"\" width=\""<<shape_height<<"\" height=\""<<shape_width<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;	
		}
	}	
			
	outputfile<<"</svg>";
	outputfile.close();

return total_rectangles;

}

int rectangles_into_triangle(const double& lenght_of_triangle,const double& rectangle_width,const double& rectangle_height){

/* long edge is considered then function call*/
if(rectangle_height>rectangle_width){
	return rectangles_into_triangle(lenght_of_triangle,rectangle_height,rectangle_width);
}

	int total_rectangles=0;	

	ofstream outputfile;

	outputfile.open("output.svg");

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<lenght_of_triangle<<"\""<<" ";
	outputfile<<"height=\""<<lenght_of_triangle*sqrt(3.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<lenght_of_triangle/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<lenght_of_triangle*sqrt(3.0)/2;
	outputfile<<" "<<lenght_of_triangle<<" ,"<<lenght_of_triangle*sqrt(3.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;

	for(int i=1;i*rectangle_height<=lenght_of_triangle*sqrt(3.0)/2;++i){ /*The total height should be up to the length of the triangle*/

	/* the total width of the rectangles in the line + lenght_of_triangle*sqrt(3.0)/2 should be equall lenght of triangle*/
		for(int j=1;j*rectangle_width<=lenght_of_triangle-((i*rectangle_height*2)/sqrt(3.0));++j){

				
			outputfile<<"<rect x=\""<<(j-1)*rectangle_width+i*rectangle_height/sqrt(3.0)<<"\" y=\""<<(lenght_of_triangle*sqrt(3.0)/2-(i)*rectangle_height);
			outputfile<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
			total_rectangles+=1; /*the number of rectangles that fit to triangle is constantly updated */
		}
	}
	outputfile<<"</svg>";
	outputfile.close();

	return total_rectangles;
}
int rectangles_into_circle(const double& radius_of_circle,const double& rectangle_width,const double& rectangle_height){

	
	if(rectangle_height>rectangle_width){   /* to process long edge as width */
	return rectangles_into_circle(radius_of_circle,rectangle_height,rectangle_width);
	}


	ofstream outputfile;
	outputfile.open("output.svg");

	double starter_y=0;
	int height_counter=1;
	int total_rectangles=0;

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<2*radius_of_circle<<"\""<<" ";
	outputfile<<"height=\""<<2*radius_of_circle<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<radius_of_circle<<"\" ";
	outputfile<<"cy=\""<<radius_of_circle<<"\""<<" r=\""<<radius_of_circle<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;

	do{  /*searches for a length value that can be used to obtain the beam to fit at least one rectangle*/

	starter_y+=0.001;

	}while(sqrt(2*radius_of_circle*starter_y-pow(starter_y,2.0))*2<rectangle_width);


	for(int i=1;starter_y+i*rectangle_height<=radius_of_circle;++i){ /*to progress vertically fit to rectangles until reach diameter */

		/*to reach diameter horizontally */
		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0)));++j){

			outputfile<<"<rect x=\""<<radius_of_circle-sqrt(2*radius_of_circle*(starter_y+(i-1)*rectangle_height)-pow((starter_y+(i-1)*rectangle_height),2.0))+(j-1)*rectangle_width<<"\" y=\""<<starter_y+(i-1)*rectangle_height;
			outputfile<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;	
		
			total_rectangles+=1;
		}
		height_counter=i;
	}

	/*to fill the upper part of the two circles we use above, fill the rest with two loops in the bottom */
	for(int i=height_counter+1;starter_y+i*rectangle_height<=2*radius_of_circle;++i){

		for(int j=1;j*rectangle_width<=(2*sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0)));++j){

			outputfile<<"<rect x=\""<<radius_of_circle-sqrt(2*radius_of_circle*(2*radius_of_circle-(starter_y+(i)*rectangle_height))-pow((2*radius_of_circle-(starter_y+(i)*rectangle_height)),2.0))+(j-1)*rectangle_width<<"\" y=\""<<starter_y+(i-1)*rectangle_height;
			outputfile<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;	
		
			total_rectangles+=1;
		}
	}

	if(total_rectangles==0){

		if(sqrt(pow(rectangle_width/2,2.0)+pow(rectangle_height/2,2.0))<=radius_of_circle){

			outputfile<<"<rect x=\""<<radius_of_circle-rectangle_width/2<<"\" y=\""<<radius_of_circle-rectangle_height/2;
			outputfile<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\" fill=\"red\" stroke=\"purple\" stroke-width=\"0.2\" />"<<endl;
			total_rectangles+=1;
		}
	}
			
	outputfile<<"</svg>";

	outputfile.close();

	return total_rectangles;
}
int triangles_into_rectangle(const double& width,const double& height,const double& lenght_of_triangle_edge){


if((height<lenght_of_triangle_edge*sqrt(3.0)/2) && width>=lenght_of_triangle_edge){

	return triangles_into_rectangle(height,width,lenght_of_triangle_edge);
	}


	ofstream outputfile;

	outputfile.open("output.svg");

	double triangle_lenght;

		
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<width<<"\""<<" ";
	outputfile<<"height=\""<<height<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<rect width=\"100%\" height=\"100%\" fill=\"green\" />"<<endl;

	triangle_lenght=(lenght_of_triangle_edge*pow(3,(1/2.0)))/2;

	int k=0;
	int line_counter=0;
	int triangle_counter=0;
	for(int i=1;((i-k)*(triangle_lenght))<=height;++i){

		if(i%2==0)
			k+=1;
		
	/*This condition mechanism is used to place triangles by oppositly*/
		if(i%2==0){
		for(int j=1;(j*lenght_of_triangle_edge+lenght_of_triangle_edge/2)<=width;++j){
		
			
			outputfile<<"<polygon points=\""<<2*j*lenght_of_triangle_edge/2<<","<<(i-1-k)*triangle_lenght;
			outputfile<<" "<<(2*j+1)*lenght_of_triangle_edge/2<<" ,"<<(i-k)*triangle_lenght;
			outputfile<<" "<<(2*j-1)*lenght_of_triangle_edge/2<<" ,"<<(i-k)*triangle_lenght<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:1\" />"<<endl;
			triangle_counter+=1;
			
			}
		}
				
		else{
		for(int j=1;(j*lenght_of_triangle_edge)<=width;++j){
			outputfile<<"<polygon points=\""<<(2*j-1)*lenght_of_triangle_edge/2<<","<<(i-k)*triangle_lenght;
			outputfile<<" "<<(2*j-2)*lenght_of_triangle_edge/2<<" ,"<<(i-1-k)*triangle_lenght;
			outputfile<<" "<<(j*2)*lenght_of_triangle_edge/2<<" ,"<<(i-1-k)*triangle_lenght<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:1\" />"<<endl;
		triangle_counter+=1;
			}			
		}
		
	line_counter=i;

	}
	
	for(int j=1;(j*lenght_of_triangle_edge+lenght_of_triangle_edge/2)<=width;++j){
		outputfile<<"<polygon points=\""<<2*j*lenght_of_triangle_edge/2<<","<<(line_counter-1-k)*triangle_lenght;
		outputfile<<" "<<(2*j+1)*lenght_of_triangle_edge/2<<" ,"<<(line_counter-k)*triangle_lenght;
		outputfile<<" "<<(2*j-1)*lenght_of_triangle_edge/2<<" ,"<<(line_counter-k)*triangle_lenght<<"\"";
		outputfile<<" style=\"fill:red;stroke:purple;stroke-width:1\" />"<<endl;
		triangle_counter+=1;
	}
	outputfile<<"</svg>";
			 
	outputfile.close();
		
	return triangle_counter;
}
int triangles_into_circle(double& radius_of_circle,double& lenght_of_triangle){

	ofstream outputfile;

	outputfile.open("output.svg");

	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<radius_of_circle*2<<"\""<<" ";
	outputfile<<"height=\""<<radius_of_circle*2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<radius_of_circle<<"\" ";
	outputfile<<"cy=\""<<radius_of_circle<<"\""<<" r=\""<<radius_of_circle<<"\" ";
	outputfile<<"fill=\"green\"/>"<<endl;

		/*to put one triangle the top of circle if the beam is enough long */
		if(2*pow(2*radius_of_circle*(2*radius_of_circle-lenght_of_triangle)-pow(2*radius_of_circle-lenght_of_triangle,2.0),1/2.0)>=lenght_of_triangle){
		outputfile<<"<polygon points=\""<<radius_of_circle<<","<<0;
		outputfile<<" "<<radius_of_circle+lenght_of_triangle/2<<" ,"<<1*(lenght_of_triangle*pow(3,(1/2.0))/2);
		outputfile<<" "<<radius_of_circle-lenght_of_triangle/2<<" ,"<<1*(lenght_of_triangle*pow(3,(1/2.0))/2)<<"\"";
		outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		}
		else {
			outputfile<<"</svg>"<<endl;
			return 0;}
	int triangle_counter=1;
	int copy_i=0;

	/*these three nested for loop are used to fill above half of circle */
	for(int i=2;(i*(lenght_of_triangle*pow(3,(1/2.0))/2))<=radius_of_circle;++i){


		for(int j=1;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2<<","<<i*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle<<" ,"<<(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle<<" ,"<<(i-1)*(lenght_of_triangle*pow(3,1/2.0)/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		
		triangle_counter+=1;	
			}
		int k=0;
		if((pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*(i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){

			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle<<","<<((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2<<" ,"<<i*(lenght_of_triangle*pow(3,(1/2.0))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2<<" ,"<<i*(lenght_of_triangle*pow(3,(1/2.0))/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		k=1;
		triangle_counter+=1;
		}
		/*these two for loop are used to fill one beam that in the middle of circle width triangle*/
		for(int j=2;((j-1+k)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*k*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle<<","<<((i-1)*(lenght_of_triangle*pow(3,(1/2.0)))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2<<" ,"<<i*(lenght_of_triangle*pow(3,(1/2.0))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2<<" ,"<<i*(lenght_of_triangle*pow(3,(1/2.0))/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
	
		triangle_counter+=1;
			}
		copy_i=i;
		}
		
		for(int j=1 ;(j*lenght_of_triangle)<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2<<","<<(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle<<" ,"<<copy_i*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle<<" ,"<<copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;

			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j-1)*lenght_of_triangle/2<<","<<(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+j*lenght_of_triangle<<" ,"<<copy_i*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(2*j+1)*lenght_of_triangle/2<<","<<(copy_i+1)*(lenght_of_triangle*pow(3,1/2.0)/2)<<"\"";

			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		triangle_counter+=1;
			}
		copy_i+=2;
		
		/*these three for loop are used to fill below of circle width triangle*/
		for( ;copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)<=2*radius_of_circle;++copy_i){
	
		for(int j=1;(j*lenght_of_triangle)<=2*pow((2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)),2.0)),1/2.0);++j){
			outputfile<<"<polygon points=\""<<radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(2*j-1)*lenght_of_triangle/2<<","<<(copy_i-1)*(lenght_of_triangle*pow(3,1/2.0))/2;
			outputfile<<" "<<radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+(j-1)*lenght_of_triangle<<" ,"<<copy_i*(lenght_of_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<radius_of_circle-pow(2*radius_of_circle*(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2)-pow(2*radius_of_circle-copy_i*(lenght_of_triangle*pow(3,1/2.0))/2,2.0),1/2.0)+j*lenght_of_triangle<<" ,"<<copy_i*(lenght_of_triangle*pow(3,1/2.0)/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
			triangle_counter+=1;
			}
		
		int z=0;
		if((pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+lenght_of_triangle/2<=(pow(2*radius_of_circle*((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2))-pow((copy_i-1)*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))){

			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+0*lenght_of_triangle<<","<<(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+0*lenght_of_triangle/2<<" ,"<<(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*lenght_of_triangle/2<<" ,"<<(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		z=1;
		triangle_counter+=1;
		}
		/*and the last for loop is used to fill beam(if there is enough long) that in bottom of circle */
		for(int j=2;((j-1+z)*lenght_of_triangle)+((lenght_of_triangle/2)-(2*z*lenght_of_triangle/2))<=2*(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0));++j){
		
			outputfile<<"<polygon points=\""<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))+(j-1)*lenght_of_triangle<<","<<(copy_i*(lenght_of_triangle*pow(3,(1/2.0)))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+(2*j-2)*lenght_of_triangle/2<<" ,"<<(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2);
			outputfile<<" "<<radius_of_circle-(pow(2*radius_of_circle*(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2))-pow(copy_i*(lenght_of_triangle*pow(3,1/2.0)/2),2.0),1/2.0))-lenght_of_triangle/2+2*j*lenght_of_triangle/2<<" ,"<<(copy_i-1)*(lenght_of_triangle*pow(3,(1/2.0))/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		triangle_counter+=1;
		}
	}
	outputfile<<"</svg>";
	outputfile.close();
	return triangle_counter;
}	
int triangles_into_triangle(const double& lenght_of_container_triangle,const double& lenght_of_small_triangle){


	ofstream outputfile;

	outputfile.open("output.svg");

	int triangle_counter=0;


	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<lenght_of_container_triangle<<"\""<<" ";
	outputfile<<"height=\""<<lenght_of_container_triangle*pow(3,1/2.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<lenght_of_container_triangle/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2;
	outputfile<<" "<<lenght_of_container_triangle<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;

	/*This loop determines the total height*/
	for(int i=1;i*(lenght_of_small_triangle*pow(3,1/2.0)/2)<=lenght_of_container_triangle*pow(3,1/2.0)/2;++i){
		
		/*this loop fit triangles in one way*/
		int j=1;
		for( ;j*lenght_of_small_triangle<=(lenght_of_container_triangle-(i-1)*lenght_of_small_triangle);++j){
			
			
			outputfile<<"<polygon points=\""<<(i-1)*lenght_of_small_triangle/2+(2*j-1)*lenght_of_small_triangle/2<<","<<lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<j*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<(j-1)*lenght_of_small_triangle+(i-1)*lenght_of_small_triangle/2<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
			triangle_counter+=1;

		}
		/*this loop fit triangles in other way(dont use the rotate property)*/
		for(int k=1;k<j-1;++k){
			outputfile<<"<polygon points=\""<<(i-1)*lenght_of_small_triangle/2+k*lenght_of_small_triangle<<","<<lenght_of_container_triangle*pow(3,1/2.0)/2-(i-1)*(lenght_of_small_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<(2*k+1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2);
			outputfile<<" "<<(2*k-1)*lenght_of_small_triangle/2+(i-1)*lenght_of_small_triangle/2<<" ,"<<lenght_of_container_triangle*pow(3,1/2.0)/2-i*(lenght_of_small_triangle*pow(3,1/2.0)/2)<<"\"";
			outputfile<<" style=\"fill:red;stroke:purple;stroke-width:0.2\" />"<<endl;
		triangle_counter+=1;
		}

	}
	
	outputfile<<"</svg>";
	outputfile.close();
	
	return triangle_counter;

}

int circles_into_circle(const double& radius_of_container_circle,const double& radius_of_small_circle){

	ofstream outputfile;

	outputfile.open("output.svg");

	/*for the container shape */
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<2*radius_of_container_circle<<"\""<<" ";
	outputfile<<"height=\""<<2*radius_of_container_circle<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<circle cx=\""<<radius_of_container_circle<<"\" ";
	outputfile<<"cy=\""<<radius_of_container_circle<<"\""<<" r=\""<<radius_of_container_circle<<"\" ";
	outputfile<<" fill=\"green\"/>"<<endl;

	
	int height_counter;

	int total_circles=0;

	/*first for loop is to find out how many circles can fit verticaly*/
	for(int i=1;i*2*radius_of_small_circle<=radius_of_container_circle;++i){
		
		outputfile<<"<circle cx=\""<<radius_of_container_circle<<"\" ";
		outputfile<<"cy=\""<<(2*i-1)*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
		outputfile<<" fill=\"red\"/>"<<endl;
		total_circles+=1;
	
		/*this for is to find out how many circles fits into the beam(the length of the beam varies depending on where it cuts the circle.) */
		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*i*radius_of_small_circle)-pow(2*i*radius_of_small_circle,2.0))) && (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*((2*i-1)*radius_of_small_circle)-pow((2*i-1)*radius_of_small_circle,2.0))));++j){
			
			outputfile<<"<circle cx=\""<<radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle<<"\" ";
			outputfile<<"cy=\""<<(i*2)*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
			outputfile<<" fill=\"red\"/>"<<endl;

			outputfile<<"<circle cx=\""<<radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle)<<"\" ";
			outputfile<<"cy=\""<<i*2*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
			outputfile<<" fill=\"red\"/>"<<endl;
			
			total_circles+=2; /*increases the total number of circles*/
		}
	height_counter=i; /*to know and to use later where we are vertically */

	}
	/* up to here the top of the main circle is filling */
	height_counter+=1;
	 
	/* this part for to filling remaining circle which is under part of circle */
	for( ;height_counter*2*radius_of_small_circle<=2*radius_of_container_circle;++height_counter){
		
		outputfile<<"<circle cx=\""<<radius_of_container_circle<<"\" ";
		outputfile<<"cy=\""<<(2*height_counter-1)*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
		outputfile<<" fill=\"red\"/>"<<endl;
		total_circles+=1;
		for(int j=1;((((j*2-1)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-2*height_counter*radius_of_small_circle)-pow(2*radius_of_container_circle-2*height_counter*radius_of_small_circle,2.0))) &&  (((j*2-2)*radius_of_small_circle+radius_of_small_circle*sqrt(3.0))+radius_of_small_circle/3<=sqrt(2*(radius_of_container_circle)*(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle)-pow(2*radius_of_container_circle-(2*height_counter+1)*radius_of_small_circle,2.0))));++j){
			
			outputfile<<"<circle cx=\""<<radius_of_container_circle+radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle<<"\" ";
			outputfile<<"cy=\""<<(height_counter*2)*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
			outputfile<<" fill=\"red\"/>"<<endl;


			outputfile<<"<circle cx=\""<<radius_of_container_circle-(radius_of_small_circle*sqrt(3.0)+(2*j-2)*radius_of_small_circle)<<"\" ";
			outputfile<<"cy=\""<<height_counter*2*radius_of_small_circle<<"\""<<" r=\""<<radius_of_small_circle<<"\" ";
			outputfile<<" fill=\"red\"/>"<<endl;
			
			total_circles+=2;

		}
}
	outputfile<<"</svg>";
	outputfile.close();

	return total_circles;	
}
int circles_into_triangle(const double& lenght_of_triangle,const double& radius_of_circle){


	ofstream outputfile;

	outputfile.open("output.svg");

	int total_circles=0;
	
	
	outputfile<<"<svg version=\"1.1\""<<endl<<"baseProfile=\"full\""<<endl<<"width="<<"\""<<lenght_of_triangle<<"\""<<" ";
	outputfile<<"height=\""<<lenght_of_triangle*pow(3,1/2.0)/2<<"\""<<endl;
	outputfile<<"xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
	outputfile<<"<polygon points=\""<<lenght_of_triangle/2<<","<<0;
	outputfile<<" "<<0<<" ,"<<lenght_of_triangle*pow(3,1/2.0)/2;
	outputfile<<" "<<lenght_of_triangle<<" ,"<<lenght_of_triangle*pow(3,1/2.0)/2<<"\"";
	outputfile<<" fill=\"green\"/>"<<endl;


	/*these two nested for loop are used to fill circles into triangle */
	for(int i=1;i*radius_of_circle*sqrt(3.0)+radius_of_circle<=lenght_of_triangle*sqrt(3.0)/2;++i){
		for(int j=1;(j*2)*radius_of_circle+(radius_of_circle*sqrt(3.0)-radius_of_circle)<=lenght_of_triangle-(radius_of_circle*sqrt(3.0)-radius_of_circle)-(i-1)*2*radius_of_circle;++j){
			outputfile<<"<circle cx=\""<<(i-1)*radius_of_circle+radius_of_circle*sqrt(3.0)+(j*2-2)*radius_of_circle<<"\" ";
			outputfile<<"cy=\""<<lenght_of_triangle*sqrt(3.0)/2-(radius_of_circle+(i-1)*radius_of_circle*sqrt(3.0))<<"\""<<" r=\""<<radius_of_circle<<"\" ";
			outputfile<<"stroke=\"black\" stroke-width=\"0.1\"  ";
			outputfile<<" fill=\"red\"/>"<<endl;
			
			total_circles+=1;
		}
	}
	outputfile<<"</svg>";
	outputfile.close();

	return total_circles;
}


	
	










