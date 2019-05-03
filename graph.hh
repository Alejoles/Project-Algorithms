#ifndef _graph_hh_
#define _graph_hh_
#include <vector>

#include "Point.cpp"
//-----------------------------Acá empiezan las estructuras del grafo---------------------------
//----------------------------------------Estructura Nodo(vertice||vertex)---------------------------------------------

class Graph {
private:
	struct Node {
		Point Punto;
		Node *link;
	};
	struct Edge {
		unsigned Value;
		Node * Tail;
		Node * Head;
	};
	Node * grafo = nullptr;
	std::vector<Point> puntos;
public:
	Graph();					// Default constructor
	~Graph();					// Constructor parametrizado
	void ChangePos(Node &nod, unsigned x0, unsigned y0); 		// Cambia la posición del nodo
	void searchPath(Node nod);			// Busca todos los caminos que haya
	bool pathExistence(Node nod);			// Verifica si hay un camino entre 2 nodos
	void bestPath(Node nod1);			// Busca el mejor camino entre 2 nodos.



};


//------------------------Aca terminan las estructuras del grafo--------------------------

#endif // _graph_hh_
