#ifndef _quadtree_hh
#define	_quadtree_hh
#include <iostream>
#include <vector>


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
		bool inBounds(Point p);
		
};
//------------------------------Acá se acaba la structura Point-------------------------------

//Se elimino la estructura Rect ya que se reemplazo por 2 puntos que marcan las esquinas.

//-------------------------------------------------------------------------------------------------
//					Clase del QuadTree
class Qtree {
	private:
		struct QtreeNode {
			vector<Point> Puntos;
			Point TopL = Point(0,0);		// puntos pueden ir en privado
			Point BotR = Point(800,800);
			bool leaf;
			QtreeNode *NorthWest = nullptr;
			QtreeNode *NorthEast = nullptr;
			QtreeNode *SouthWest = nullptr;
			QtreeNode *SouthEast = nullptr;
			QtreeNode *Padre = nullptr;	//devolver
			
			// QtreeNode(Point v, Node *NW = nullptr, Node *NE = nullptr, Node *SW = nullptr, Node *SE = nullptr): Value{v}, NorthWest{NW}, NorthEast{NE}, SouthWest{SW}, SouthEast{SE} {}
			
		};
		
		
		/*QtreeNode * Successor(QtreeNode *root)const;
		QtreeNode * Predecessor(QtreeNode *root)const;*/
		
		void remove(QtreeNode * &root, Point p);
		void insert(QtreeNode * &root, Point p);
		void clear(QtreeNode * &root);
		void calificar(); // lo que hace esta funcion es ver que nodos son hojas y que nodos no lo son
		QtreeNode * find(QtreeNode *root, Point p)const;
		
		//size_t Num_Leaves(QtreeNode *root)const;
		
		//-------------- Bounds // Esquinas -------------
		
		Node *Quadtree = nullptr;
		size_t count = 0;

	public:
		Qtree() = default;
		~Qtree();
		void insert(Point p);
		QtreeNode find(Point p)const;//not sure
		void remove(Point p);// no estoy seguro de que quitar
		void clear(void);
		
		
		
};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------






#endif //_quadtree_hh_
