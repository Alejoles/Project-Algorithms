#include "graph.hh"

//---------------------------Vamos a definir los metodos de la clase Node----------------------


void Node::ChangePos(int x1, int y1){
	this->x = x1;
	this->y = y1;

}
/*
bool Node::PathExistence(){ 
}
void Node::searchPath(){ // Buscar el camino en la matriz de adyacencia
}
void Node::bestPath(){

}

*/

//------------------------------------Vamos a definir los metodos de edge----------------------------

bool Edge::isConnected(){
	return true;
}			
void Edge::MakeConection(Node con,Node tocon){

}	
void Edge::GiveDirection(){

}
bool Edge::directionTo(){
	return true;
}


//---------------------------------------------------------------------------------------------------
