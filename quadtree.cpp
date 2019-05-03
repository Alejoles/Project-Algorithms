#ifndef _quadtree_cpp_
#define _quadtree_cpp_

#include "quadtree.hh"
#include <cstdlib>
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
	Point ArIz = Point(0,0);
	Point BaDe = Point(800,800);
	return (p.x >= ArIz.x && p.x <= BaDe.x && p.y >= ArIz.y && p.y <= BaDe.y);
}


//--------------------------------END OF POINT-----------------------------------


//----------------------------------END OF Square-------------------------------



// Metodos del qtree
void Qtree::Invariante() const{
	
}

void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Point p){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(root == nullptr){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
		root = new QtreeNode;
		root->Padre = Padre;
		if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){	// Arriba izquierda
			root->NorthWest->Puntos.push_back(p);
			root->NorthEast = nullptr;
			root->SouthWest = nullptr;
			root->SouthEast = nullptr;
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
			root->NorthWest = nullptr;
			root->NorthEast->Puntos.push_back(p);
			root->SouthWest = nullptr;
			root->SouthEast = nullptr;
		}
		else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
			root->NorthEast = nullptr;
			root->NorthWest = nullptr;
			root->SouthWest->Puntos.push_back(p);
			root->SouthEast = nullptr;
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
			root->NorthEast = nullptr;
			root->NorthWest = nullptr;
			root->SouthWest = nullptr;
			root->SouthEast->Puntos.push_back(p);
			root->SouthEast->TopL.setPX((root->TopL.getPX() + root->BotR.getPX())/2);
			root->SouthEast->TopL.setPY((root->TopL.getPY() + root->BotR.getPY())/2);
		}
		
		// cada nodo asignarlo en su correspondiente valor
	}
	else {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
		if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ 
			insert()
		}
	}
}
void insertP(Point p){
	//incovar el metodo anterior sumando al contador
	
}

// Se puede crear un metodo para organizar los puntos tal que todos queden en las hojas





/*Qtree::QtreeNode * Qtree::find()const{
	//no se que hacer aca aun
}*/

void Qtree::clear(QtreeNode * &root){
	if(root != nullptr){
		QtreeNode *NorthWest = root->NorthWest;
		QtreeNode *NorthEast = root->NorthEast;
		QtreeNode *SouthWest = root->SouthWest;
		QtreeNode *SouthEast = root->SouthEast;
		delete root;
		clear(NorthWest);
		clear(NorthEast);
		clear(SouthWest);
		clear(SouthEast);
	}
}
void Qtree::clear(void){
	clear(Quadtree);
	Quadtree = nullptr;
	count = 0;
}



Qtree::~Qtree(){
	clear();
}

#endif
