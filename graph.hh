#ifndef _graph_hh_
#define _graph_hh_

using namespace std;
//-----------------------------Acá empiezan las estructuras del grafo---------------------------
//----------------------------------------Estructura Nodo(vertice||vertex)---------------------------------------------
class Graph{
private:
	struct Node {
		Point p;
		Node * link;
	};
	struct Edge {
		unsigned Value;
		Node * Tail;
		Node * Head;
		bool Connected;
	}
public:
	Graph();				// Default constructor
	~Graph();				// Constructor parametrizado
	void ChangePos(Node nod); 	// Cambia la posición del nodo
	void searchPath(Node nod);		// Busca todos los caminos que haya		
	bool pathExistence(Node nod);		// Verifica si hay un camino entre 2 nodos
	void bestPath(Node nod1);		// Busca el mejor camino entre 2 nodos.


		
};


//------------------------Aca terminan las estructuras del grafo--------------------------

#endif // _graph_hh_
