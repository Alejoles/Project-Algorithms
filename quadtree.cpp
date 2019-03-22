#include "quadtree.hh"

//--------------------------METODOS DE LA CLASE POINT------------------------------


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


//--------------------------------END OF POINT-----------------------------------

//-------------------------METODOS DE LA CLASE RECT-----------------------------





//----------------------------------END OF RECT-------------------------------



// Metodos del qtree
void qtree::insert(Point x){
	if(points.size() < capacity){
		this->points.push_back(x);
	}else {
		if(!this->divided){
		this->divide();
		this->divided = true;
		}
	}
}
