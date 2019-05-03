#ifndef _Point_cpp_
#define _Point_cpp_

#include "Point.hpp"


//--------------------------METODOS DE LA CLASE POINT------------------------------

Point::~Point(){
	 PErase();
}

void PErase(Point p){
	this->x = -1;
	this->y = -1;
}

int Point::getPX(){
	return this->x;
}
int Point::getPY(){
	return this->y;
}
void Point::setPX(int v){
	this->x = v;
}
void Point::setPY(int v){
	this->y = v;
}

bool Point::inBounds(Point p){
	//Esta funcion nos dice si el punto pertenece a nuestra "base"
	Point ArIz = Point(0,0);
	Point BaDe = Point(800,800);
	return (p.x >= ArIz.x && p.x <= BaDe.x && p.y >= ArIz.y && p.y <= BaDe.y);
}


//--------------------------------END OF POINT-----------------------------------





#endif // Point.cpp
