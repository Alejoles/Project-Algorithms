#ifndef _graph_cpp_
#define _graph_cpp_

#include "graph.hh"
#include "Point.cpp"

//---------------------------Vamos a definir los metodos de la clase Node----------------------


void Graph::ChangePos(Node &nod, unsigned x0, unsigned y0){
	nod.Punto.setPX(x0);
	nod.Punto.setPY(y0);
}
/*
bool Node::PathExistence(){
}
void Node::searchPath(){ // Buscar el camino en la matriz de adyacencia
}
void Node::bestPath(){

}

*/


//---------------------------------------------------------------------------------------------------

#endif // graph.cpp
