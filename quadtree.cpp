#include "quadtree.hh"
#include <cstdlib>
#include <vector>
#include "Point.hpp"


// Metodos del qtree
void Qtree::Invariante() const{

}

void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Point p, unsigned count){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(p.inBounds(p)){
		std::cout << "Entro a antes de evaluar mid" << std::endl;
		
		//std::cout << "evaluó el midx y el midx" << std::endl;
		if(root == nullptr && count <= 0){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
			root = new QtreeNode;
			root->Padre = Padre;
			std::cout << "If caso base" << std::endl;
			unsigned Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
			unsigned Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;
			if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){	// Arriba izquierda
				root->Puntos.push_back(p); 
				int topx = root->Padre->TopL.getPX();
				int topy = root->Padre->TopL.getPY();
				root->TopL.setPX(topx);
				root->TopL.setPY(topy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(Midy);
				root->leaf = true;
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
				root->Puntos.push_back(p);
				root->TopL.setPX(Midx);
				root->TopL.setPY(root->Padre->TopL.getPY());
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(Midy);
				root->leaf = true;
			}
			else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
				root->Puntos.push_back(p);
				root->TopL.setPX(root->Padre->TopL.getPX());
				root->TopL.setPY(Midy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(root->Padre->BotR.getPY());
				root->leaf = true;
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
				root->Puntos.push_back(p);
				root->TopL.setPX(Midx);
				root->TopL.setPY(Midy);
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(root->Padre->BotR.getPY());
				root->leaf = true;
			}
		}
		// cada nodo asignarlo en su correspondiente valor
		else if(root == nullptr && count > 0 && Padre == nullptr){
			std::cout << "If recursivo con padre null" << std::endl;
			root = new QtreeNode;
			unsigned Midx = (root->TopL.getPX() + root->BotR.getPX())/2;
			unsigned Midy = (root->TopL.getPY() + root->BotR.getPY())/2;
			std::cout << "MIIIIIIX" << std::endl;
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
				root->TopL.setPX(root->TopL.getPX());
				root->TopL.setPY(root->TopL.getPY());
				root->BotR.setPX(Midx);
				root->BotR.setPY(Midy);
				insert(root->NorthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(Midx);
				root->TopL.setPY(root->TopL.getPY());
				root->BotR.setPX(root->BotR.getPX());
				root->BotR.setPY(Midy);
				insert(root->NorthEast, root, p, count--);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(root->TopL.getPX());
				root->TopL.setPY(Midy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(root->BotR.getPY());
				insert(root->SouthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(Midx);
				root->TopL.setPY(Midy);
				root->BotR.setPX(root->BotR.getPX());
				root->BotR.setPY(root->BotR.getPY());
				insert(root->SouthEast, root, p, count--);
			}
		}
		else if(root == nullptr && count > 0 && Padre != nullptr) {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
			std::cout << "If recursivo" << std::endl;
			root = new QtreeNode;
			root->Padre = Padre;
			unsigned Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
			unsigned Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;
			if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba izquierda
				root->TopL.setPX(root->Padre->TopL.getPX());
				root->TopL.setPY(root->Padre->TopL.getPY());
				root->BotR.setPX(Midx);
				root->BotR.setPY(Midy);
				insert(root->NorthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(Midx);
				root->TopL.setPY(root->Padre->TopL.getPY());
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(Midy);
				insert(root->NorthEast, root, p, count--);
			}
			else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(root->Padre->TopL.getPX());
				root->TopL.setPY(Midy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(root->Padre->BotR.getPY());
				insert(root->SouthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
				//root = new QtreeNode;
				//root->Padre = Padre;
				root->TopL.setPX(Midx);
				root->TopL.setPY(Midy);
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(root->Padre->BotR.getPY());
				insert(root->SouthEast, root, p, count--);
			}
		}
		else if(root != nullptr && count > 0){
			std::cout << "If recursivo 2" << std::endl;
			if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
				std::cout << "else arriba izquierda 2" << std::endl;
				insert(root->NorthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
				std::cout << "else arriba derecha 2" << std::endl;
				insert(root->NorthEast, root, p, count--);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
				std::cout << "else abajo izquierda 2" << std::endl;
				insert(root->SouthWest, root, p, count--);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
				std::cout << "else abajo derecha 2" << std::endl;
				insert(root->SouthEast, root, p, count--);
			}
		}
	}
	else{
		std::cout << "The point is not in bounds" << std::endl;
	}
}
void Qtree::insertP(Point p){
	//incovar el metodo anterior sumando al contador
	insert(root, nullptr, p, 5);
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

