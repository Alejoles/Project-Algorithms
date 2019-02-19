#include <iostream>
#include <string>
#include <vector>

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
struct Node{
	private:
		int x,y;
	public:
		Node() : x(0), y(0) {}
		Node(int x, int y) : x(x), y(y) {}
		void ChangePos(Node nod, int x1, int y1, int x2, int y2);
		int NodeGrade(Node n);
		bool pathExistence();
		void searchPath();
		void bestPath();


		
};
//------------------------------Esctructura arista(edge||link)------------------------------------

struct Edge{
	private:
		Node nod1,nod2;
		bool directed = false;
		bool connected = false;
	public:
		Edge(Node nod1, Node nod2) : nod1(nod1) , nod2(nod2) {}
		int GiveValue(Edge);
		bool isConnected(Edge e, Node n1, Node n2);
		void MakeConection(Node con,Node tocon);
		void GiveDirection();
		

};

//------------------------Aca terminan las estructuras del grafo--------------------------------
//---------------------------------------------------------------------------------------
//					Clase del QuadTree
class qtree{
	private:
		vector<int> points;
		Rect frame;
		int capacity;
		bool divided = false;

	public://--------------------Acá definimos la forma de nuestro quadtree--------------------------------------------
		qtree(Rect Frame, int n){
			this->frame = Frame;
			this->capacity = n;
		}

//--------------------------------Ahora vamos a definir las funciones de qtree---------------------------------

		void successor();
		void predeccessor();
		void divide(){
			

		}

		void insert(Point){
			if(points.size() < capacity){
				this->points.push_back(Point);
			}else {
				if(!this->divided){
				this->divide();
				this->divided = true;
				}
			}
		}


		
};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------
//---------------------------------------------------------------------------------------
int main(void){


	return 0;
}

















