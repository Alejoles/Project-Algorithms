#ifndef _graph_hh_
#define _graph_hh_
#include <vector>
#include "Point.hpp"
#include "Simpleg.hpp"

//-----------------------------Acá empiezan las estructuras del grafo---------------------------
//----------------------------------------Estructura Nodo(vertice||vertex)---------------------------------------------

// ARISTAS SERIAN LOS PUNTOS DONDE HAY MAYOR TASA DE ACCIDENTES

class Graph {
private:
	SimpleGraph grafo;
	std::vector<Point> puntos;	// Puntos que almacena el grafo para posteriormente hacer el cubrimiento
public:
	Graph();					// Default constructor
	~Graph();					// Constructor parametrizado
	void ChangePos(Node &nod, unsigned x0, unsigned y0); 		// Cambia la posición del nodo
	bool pathExistence(Node nod1, Node nod2);			// Verifica si hay un camino entre 2 nodos "Helper function"
	void bestPath(Node nod1, Node nod2);			// Busca el mejor camino entre 2 nodos.
	void Cubrimiento(); // U Know


};


//------------------------Aca terminan las estructuras del grafo--------------------------

#endif // _graph_hh_
