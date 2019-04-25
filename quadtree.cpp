#include "quadtree.hh"
#include <stdlib>
#include <vector>

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
	
}

void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Point p){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(root == nullptr){
		root = new QtreeNode;
		root->Puntos.push_back(p);
		root->Padre = Padre;
		if()
		root->NorthWest = nullptr;
		root->NorthEast = nullptr;
		root->SouthWest = nullptr;
		root->SouthEast = nullptr;
		// cada nodo asignarlo en su correspondiente valor
	}
}
void insert(Point p){
	//incovar el metodo anterior sumando al contador
}

// Se puede crear un metodo para organizar los puntos tal que todos queden en las hojas


QtreeNode Qtree::find()const{
	//no se que hacer aca aun
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


