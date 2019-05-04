#ifndef _quadtree_cpp_
#define _quadtree_cpp_

#include "quadtree.hh"
#include <cstdlib>
#include <vector>
#include "Point.cpp"


//----------------------------------END OF Square-------------------------------



// Metodos del qtree
void Qtree::Invariante() const{

}

void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Point p, unsigned count = 5){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(p.inBounds(p)){
		unsigned Midx = (root->TopL.getPX() + root->BotR.getPX())/2;
		unsigned Midy = (root->TopL.getPY() + root->BotR.getPY())/2;
		if(root == nullptr && count == 0){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
			root = new QtreeNode;
			root->Padre = Padre;
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){	// Arriba izquierda
				root->NorthWest->Puntos.push_back(p);
				root->NorthEast = nullptr;
				root->SouthWest = nullptr;
				root->SouthEast = nullptr;
				root->NorthWest->TopL.setPX(root->TopL.getPX());
				root->NorthWest->TopL.setPY(root->TopL.getPY());
				root->NorthWest->BotR.setPX(Midx);
				root->NorthWest->BotR.setPY(Midy);
				root->NorthWest->leaf = true;
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				root->NorthWest = nullptr;
				root->NorthEast->Puntos.push_back(p);
				root->SouthWest = nullptr;
				root->SouthEast = nullptr;
				root->NorthEast->TopL.setPX(Midx);
				root->NorthEast->TopL.setPY(root->TopL.getPY());
				root->NorthEast->BotR.setPX(root->BotR.getPX());
				root->NorthEast->BotR.setPY(Midy);
				root->NorthEast->leaf = true;
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				root->NorthEast = nullptr;
				root->NorthWest = nullptr;
				root->SouthWest->Puntos.push_back(p);
				root->SouthEast = nullptr;
				root->SouthWest->TopL.setPX(root->TopL.getPX());
				root->SouthWest->TopL.setPY(Midy);
				root->SouthWest->BotR.setPX(Midx);
				root->SouthWest->BotR.setPY(root->BotR.getPY());
				root->SouthWest->leaf = true;
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				root->NorthEast = nullptr;
				root->NorthWest = nullptr;
				root->SouthWest = nullptr;
				root->SouthEast->Puntos.push_back(p);
				root->SouthEast->TopL.setPX(Midx);
				root->SouthEast->TopL.setPY(Midy);
				root->SouthEast->BotR.setPX(root->BotR.getPX());
				root->SouthEast->BotR.setPY(root->BotR.getPY());
				root->SouthEast->leaf = true;
			}
		}
		// cada nodo asignarlo en su correspondiente valor

		else {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
				root = new QtreeNode;
				root->Padre = Padre;
				root->NorthWest->TopL.setPX(root->TopL.getPX());
				root->NorthWest->TopL.setPY(root->TopL.getPY());
				root->NorthWest->BotR.setPX(Midx);
				root->NorthWest->BotR.setPY(Midy);
				insert(root->NorthWest, Padre, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				root = new QtreeNode;
				root->Padre = Padre;
				root->NorthEast->TopL.setPX(Midx);
				root->NorthEast->TopL.setPY(root->TopL.getPY());
				root->NorthEast->BotR.setPX(root->BotR.getPX());
				root->NorthEast->BotR.setPY(Midy);
				insert(root->NorthEast, Padre, p, count--);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				root = new QtreeNode;
				root->Padre = Padre;
				root->SouthWest->TopL.setPX(root->TopL.getPX());
				root->SouthWest->TopL.setPY(Midy);
				root->SouthWest->BotR.setPX(Midx);
				root->SouthWest->BotR.setPY(root->BotR.getPY());
				insert(root->SouthWest, Padre, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				root = new QtreeNode;
				root->Padre = Padre;
				root->SouthEast->TopL.setPX(Midx);
				root->SouthEast->TopL.setPY(Midy);
				root->SouthEast->BotR.setPX(root->BotR.getPX());
				root->SouthEast->BotR.setPY(root->BotR.getPY());
				insert(root->SouthEast, Padre, p, count--);
			}
		}
	}
	else{
		std::cout << "The point is not in bounds" << std::endl;
	}
}
void Qtree::insertP(Point p){
	//incovar el metodo anterior sumando al contador

}

void Qtree::remove(root * &root, Point p){

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
