#ifndef _quadtree_hh
#define	_quadtree_hh
#include <iostream>


using namespace std;
//-------------------------------------------------------------------------------------
//					Estructura punto(Point)
struct Point {
	private:
		int x,y;
	public:
		Point() : x{0}, y{0} {}
		Point(int nx, int ny) : x{nx}, y{ny} {}
		// setters & getters--
		int getPX();
		int getPY();
		void setPX(int v);
		void setPY(int v);
		
};
//------------------------------Acá se acaba la structura Point-------------------------------

//Se elimino la estructura Rect ya que se reemplazo por 2 puntos que marcan las esquinas.

//-------------------------------------------------------------------------------------------------
//					Clase del QuadTree
class Qtree {
	private:
		struct QtreeNode {
			Point Value;
			QtreeNode *NorthWest;
			QtreeNode *NorthEast;
			QtreeNode *SouthWest;
			QtreeNode *SouthEast;
			QtreeNode *Padre;
			// Node(Point v, Node *NW = nullptr, Node *NE = nullptr, Node *SW = nullptr, Node *SE = nullptr): Value{v}, NorthWest{NW}, NorthEast{NE}, SouthWest{SW}, SouthEast{SE} {}
			
		};
		
		//-------------- Bounds // Esquinas -------------
		Point ArribaIz = Point(0,0);
		Point AbajoDer = Point(400,400);
		
		
		QtreeNode * Successor(QtreeNode *root)const;
		QtreeNode * Predecessor(QtreeNode *root)const;
		
		Node *Quadtree = nullptr;

	public:
		Qtree();
		~Qtree();
		void insert(Node *nuevo);
		bool inBounds(Point p);
		Node * Search(Point p);
		void remove();
		
};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------
#endif //_quadtree_hh_
