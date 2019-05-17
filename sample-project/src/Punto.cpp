#include "Punto.h"


//--------------------------METODOS DE LA CLASE POINT------------------------------
void Punto::PErase(){
    this->x = -10;
    this->y = -10;
}
Punto::~Punto(){
    PErase();
}



int Punto::getPX(){
	return this->x;
}
int Punto::getPY(){
	return this->y;
}
void Punto::setPX(int v){
	this->x = v;
}
void Punto::setPY(int v){
	this->y = v;
}

bool Punto::inBounds(Punto p){
	//Esta funcion nos dice si el punto pertenece a nuestra "base"
    Punto ArIz = Punto(0,0);
    Punto BaDe = Punto(800,800);
	return (p.x >= ArIz.x && p.x <= BaDe.x && p.y >= ArIz.y && p.y <= BaDe.y);
}


//--------------------------------END OF POINT-----------------------------------


