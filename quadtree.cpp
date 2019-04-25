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
void Qtree::Invariante() const{
	
}

void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Point p){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(root == nullptr){			// caso base recursivo
		root = new QtreeNode;
		root->Padre = Padre;
		if(p.x <= (TopL.x + BotR.x)/2 && p.y <= (TopL.y + BotR.y)/2){	// Arriba izquierda
			root->NorthWest->Puntos.push_back(p);
			root->NorthEast = nullptr;
			root->SouthWest = nullptr;
			root->SouthEast = nullptr;
		}
		else if(p.x >= (TopL.x + BotR.x)/2 && p.y <= (TopL.y + BotR.y)/2){ // Arriba derecha
			root->NorthWest = nullptr;
			root->NorthEast->Puntos.push_back(p);
			root->SouthWest = nullptr;
			root->SouthEast = nullptr;
		}
		else if(p.x <= (TopL.x + BotR.x)/2 && p.y >= (TopL.y + BotR.y)/2){ // Abajo izquierda
			root->NorthEast = nullptr;
			root->NorthWest = nullptr;
			root->SouthWest->Puntos.push_back(p);
			root->SouthEast = nullptr;
		}
		else if(p.x >= (TopL.x + BotR.x)/2 && p.y >= (TopL.y + BotR.y)/2){ // Abajo Derecha
			root->NorthEast = nullptr;
			root->NorthWest = nullptr;
			root->SouthWest = nullptr;
			root->SouthEast->Puntos.push_back(p);
		}
		
		// cada nodo asignarlo en su correspondiente valor
	}
	else {
		if(p.x <= TopL.x){ // caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
			
		}
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


