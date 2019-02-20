#include <iostream>
#include <string>
#include <vector>
//     	wxWidgets	UML Use Case // Activity diagrams  Matching(GRAFOS)

using namespace std;
//-------------------------------------------------------------------------------------
//					Estructura punto(Point)
struct Point{
	private:
		int x,y;
	public:
		Point() : x(0), y(0) {}
		Point(int x, int y) : x(x), y(y) {}
};
//------------------------------Acá se acaba la structura Point-------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//					Estructura Rectangulo(Rect)
struct Rect{
	private:
	int x, y, width, height; //variables x,y(lugar) & w,h(width, height) ancho altura.
	public:
		Rect(): x(0),y(0),width(0),height(0) {}
		Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {} 

	
};
//-----------------------------Acá se acaba la estructura Rect-------------------------------------
//---------------------------------------------------------------------------------------
//-----------------------------Acá empiezan las estructuras del grafo---------------------------
//----------------------------------------Estructura Nodo(vertice||vertex)---------------------------------------------
class Node{
	private:
		int x,y;
	public:
		Node() : x(0), y(0) {}
		Node(int rx, int ry) : x(rx), y(ry) {}
		void ChangePos(int x1, int y1); 	// Cambia la posición del nodo
		int NodeGrade(Node n);			// Me retorna el grado del nodo(definido por las aristas que tiene conectadas a el)
		void searchPath(Node nod);			// Busca todos los caminos que haya		
		bool pathExistence(Node nod);			// Verifica si hay un camino entre 2 nodos
		void bestPath(Node nod1);	// Busca el mejor camino entre 2 nodos.


		
};
//---------------------------Vamos a definir los metodos de la clase Node----------------------


void Node::ChangePos(int x1, int y1){
	x = x1;
	y = y1;

}

int Node::NodeGrade(){  //Matriz de incidencia

}

void Node::searchPath(Node n){ // Buscar el camino en la matriz de adyacencia



}

bool Node::PathExistence(Node n){ 

}

//------------------------------Esctructura arista(edge||link)------------------------------------

class Edge{
	private:
		Node nod1;
		Node nod2;
		int value;
		bool directed = false;
		bool connected = false;
		vector<Node> edges;
	public:
		Edge(Node nod1, Node nod2, int value) : nod1(nod1) , nod2(nod2), value(value) {}  // Def de la clase arista
		bool isConnected(); 				// True si hay conexión 
		void MakeConection(Node con,Node tocon); 	//Hace una coneccion del nodocon al nodo tocon
		void GiveDirection(); 				// Le da una dirección a la arista
		bool directionTo(); 		// Me va a decir true si el nodo al que quiero llegar tiene una arista dirigida a él
		
};
//------------------------------------Vamos a definir los metodos de edge----------------------------


bool Edge::isConnected(){
	
	if(  )

}


//------------------------Aca terminan las estructuras del grafo--------------------------
//---------------------------------------------------------------------------------------
int main(void){


	return 0;
}

















