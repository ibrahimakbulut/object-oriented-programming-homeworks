
exe :  151044077_driver.o Shape.o Triangle.o Circle.o Rectangle.o Polygon.o PolygonDyn.o PolygonVect.o composedShape.o  
	g++ -o  exe 151044077_driver.o Shape.o Triangle.o Rectangle.o Circle.o Polygon.o PolygonDyn.o   PolygonVect.o composedShape.o   


Shape.o : Shape.cpp
	g++ -c -std=c++0x Shape.cpp


Triangle.o : Triangle.cpp
	g++ -c -std=c++0x Triangle.cpp
Circle.o : Circle.cpp
	g++ -c -std=c++0x Circle.cpp

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++0x Rectangle.cpp

Polygon.o : Polygon.cpp
	g++ -c -std=c++0x Polygon.cpp

PolygonDyn.o : PolygonDyn.cpp
	g++ -c -std=c++0x PolygonDyn.cpp

PolygonVect.o : PolygonVect.cpp
	g++ -c -std=c++0x PolygonVect.cpp

composedShape.o : composedShape.cpp
	g++ -c -std=c++0x composedShape.cpp

151044077_driver.o : 151044077_driver.cpp
	g++ -c -std=c++0x 151044077_driver.cpp













clean:
	rm *.o exe

