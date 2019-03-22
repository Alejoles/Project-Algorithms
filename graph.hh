#ifndef _graph_hh_
#define _graph_hh_

using namespace std;
//-----------------------------Acá empiezan las estructuras del grafo---------------------------
//----------------------------------------Estructura Nodo(vertice||vertex)---------------------------------------------
class Node{
	private:
		int x,y;
	public:
		Node() : x(0), y(0) {}			// Default constructor
		Node(int rx, int ry) : x(rx), y(ry) {}	// Constructor parametrizado
		void ChangePos(int x1, int y1); 	// Cambia la posición del nodo
		void searchPath(Node nod);		// Busca todos los caminos que haya		
		bool pathExistence(Node nod);		// Verifica si hay un camino entre 2 nodos
		void bestPath(Node nod1);		// Busca el mejor camino entre 2 nodos.


		
};

//------------------------------Esctructura arista(edge||link)------------------------------------

class Edge{
	private:
		Node nod1;
		Node nod2;
		int value;
		vector<Node> edges;
	public:
		Edge() : nod1(0), nod2(0), value(0) {}		// Default constructor
		Edge(Node nod1, Node nod2, int value) : nod1(nod1) , nod2(nod2), value(value) {}  // Def de la clase arista
		//~Edge();
		bool isConnected(); 				// True si hay conexión 
		void MakeConection(Node con,Node tocon); 	//Hace una coneccion del nodocon al nodo tocon
		void GiveDirection(); 				// Le da una dirección a la arista
		bool directionTo(); 				// Me va a decir true si el nodo al que quiero llegar tiene una arista dirigida a él
		
};

//------------------------Aca terminan las estructuras del grafo--------------------------

#endif // _graph_hh_
