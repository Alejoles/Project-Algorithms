#include "quadtree.hh"
#include <cstdlib>
#include <vector>
#include "Point.hpp"


Qtree::Qtree(){
	root = new QtreeNode;
	this->count = 5;
}

// Metodos del qtree
void Qtree::Invariante() const{

}

void Qtree::insert(QtreeNode * &root, Point p, unsigned count){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(p.inBounds(p)){
		unsigned Midx = (root->TopL.getPX() + root->BotR.getPX())/2;
		unsigned Midy = (root->TopL.getPY() + root->BotR.getPY())/2;
		if(root == nullptr && count <= 0){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
			std::cout << "If Primero" << std::endl;
			root = new QtreeNode;
			//root->Padre = Padre;
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

		else if(root == nullptr && count > 0) {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
			root = new QtreeNode;
			std::cout << "If recursivo" << std::endl;
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
				root->NorthWest->TopL.setPX(root->TopL.getPX());
				root->NorthWest->TopL.setPY(root->TopL.getPY());
				root->NorthWest->BotR.setPX(Midx);
				root->NorthWest->BotR.setPY(Midy);
				insert(root->NorthWest, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->NorthEast->TopL.setPX(Midx);
				root->NorthEast->TopL.setPY(root->TopL.getPY());
				root->NorthEast->BotR.setPX(root->BotR.getPX());
				root->NorthEast->BotR.setPY(Midy);
				insert(root->NorthEast, p, count--);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->SouthWest->TopL.setPX(root->TopL.getPX());
				root->SouthWest->TopL.setPY(Midy);
				root->SouthWest->BotR.setPX(Midx);
				root->SouthWest->BotR.setPY(root->BotR.getPY());
				insert(root->SouthWest, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->SouthEast->TopL.setPX(Midx);
				root->SouthEast->TopL.setPY(Midy);
				root->SouthEast->BotR.setPX(root->BotR.getPX());
				root->SouthEast->BotR.setPY(root->BotR.getPY());
				insert(root->SouthEast, p, count--);
			}
		}
		else{
			std::cout << "If recursivo 2" << std::endl;
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
				insert(root->NorthWest, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				insert(root->NorthEast, p, count--);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				insert(root->SouthWest, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				insert(root->SouthEast, p, count--);
			}
		}
	}
	else{
		std::cout << "The point is not in bounds" << std::endl;
	}
}
void Qtree::insertP(Point p){
	//incovar el metodo anterior sumando al contador
	insert(root, p, 5);
}

void Qtree::remove(QtreeNode * &root, Point p){
	if(!(root->leaf) && root != nullptr){
		if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
			remove(root->NorthWest, p);
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
			remove(root->NorthEast, p);
		}
		else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
			remove(root->SouthWest, p);
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
			remove(root->SouthEast, p);
		}
	}
	else{
		if(root == nullptr) std::cout << "El punto no se encuentra" << std::endl;
		else if(root->leaf){
			for(unsigned i = 0; i< root->Puntos.size(); i++){
				if(root->Puntos[i].getPX() == p.getPX() && root->Puntos[i].getPY() == p.getPY()){
					root->Puntos.pop_back();
				}
			}
		}
	}
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
	clear(root);
	root = nullptr;
	count = 0;
}



Qtree::~Qtree(){
	clear();
}

