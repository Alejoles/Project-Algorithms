#include "quadtree.hh"
#include <stdlib>

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

bool Point::inBounds(Point p){
	//Esta funcion nos dice si el punto pertenece a nuestra "base"
	return (p.x >= ArribaIz.x && p.x <= AbajoDer.x && p.y >= ArribaIz.y && p.y <= AbajoDer.y);
}


//--------------------------------END OF POINT-----------------------------------


//----------------------------------END OF Square-------------------------------



// Metodos del qtree
void Invariante() const{
	if(root == nullptr){
		std::cout << "Root == null pointer." << std::endl;
		exit(EXIT_FAILURE);
	}
	if(!inBounds(x)){
		std::cout << "The point is out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	}
	if(abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1){
		if(Qtree == nullptr){
			Qtree = root;
			std::cout << "The space given for the tree now is so small to continue. (you can expand the bounds)" << std::endl;
			exit(EXIT_FAILURE);
	}
}

void Qtree::insert(QtreeNode * &root, Point x){
	

}
void insert(Point p){

}

QtreeNode Qtree::find()const{
	
}

void Qtree::clear(QtreeNode * &root){
	if(Qtree != nullptr){
		QtreeNode *NorthWest = Qtree->NorthWest;
		QtreeNode *NorthEast = Qtree->NorthEast;
		QtreeNode *SouthWest = Qtree->SouthWest;
		QtreeNode *SouthEast = Qtree->SouthEast;
		delete Qtree;
		clear(NorthWest);
		clear(NorthEast);
		clear(SouthWest);
		clear(SouthEast);
	}
}
void Qtree::clear(void){
	clear(Qtree);
	Qtree = nullptr;
	count = 0;
}



Qtree::~Qtree(){
	clear();
}


