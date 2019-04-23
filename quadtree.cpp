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


//----------------------------------END OF Square-------------------------------



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

bool qtree::inBounds(Point p){
	//Esta funcion nos dice si el punto pertenece a nuestra "base"
	return (p.x >= ArribaIz.x && p.x <= AbajoDer.x && p.y >= ArribaIz.y && p.y <= AbajoDer.y);
}

QtreeNode * Qtree::Search(){

}





