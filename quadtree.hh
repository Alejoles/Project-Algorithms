#ifndef _quadtree_hh
#define	_quadtree_hh

#include <iostream>
#include <vector>
#include "Point.hpp"


//Se elimino la estructura Rect ya que se reemplazo por 2 puntos que marcan las esquinas.

//-------------------------------------------------------------------------------------------------
//					Clase del QuadTree

// Cuando insertar un nuevo nodo en el arbol
class Qtree {
	private:
		struct QtreeNode {
			std::vector<Point> Puntos;
			Point TopL = Point(0,0);		// puntos pueden ir en privado
			Point BotR = Point(800,800);
			bool leaf = false;
			QtreeNode *NorthWest = nullptr;
			QtreeNode *NorthEast = nullptr;
			QtreeNode *SouthWest = nullptr;
			QtreeNode *SouthEast = nullptr;
			QtreeNode *Padre = nullptr;		// Guarda el dato del nodo anterior para así saber de donde viene

			// QtreeNode(Point v, Node *NW = nullptr, Node *NE = nullptr, Node *SW = nullptr, Node *SE = nullptr): Value{v}, NorthWest{NW}, NorthEast{NE}, SouthWest{SW}, SouthEast{SE} {}

		};


		/*QtreeNode * Successor(QtreeNode *root)const;
		QtreeNode * Predecessor(QtreeNode *root)const;*/

		void remove(QtreeNode * &root, Point p);
		void insert(QtreeNode * &root, QtreeNode *Padre, Point p, unsigned count);
		void clear(QtreeNode * &root);
		void calificar(); // lo que hace esta funcion es ver que nodos son hojas y que nodos no lo son
		//QtreeNode * find(QtreeNode *root, Point p)const;
		void Invariante() const;

		//size_t Num_Leaves(QtreeNode *root)const;

		//-------------- Bounds // Esquinas -------------

		QtreeNode *root = nullptr;
		size_t count = 5;


	public:
		Qtree() = default;
		~Qtree();
		void insertP(Point p);
		bool find(Point p)const;//not sure
		void remove(Point p);// no estoy seguro de que quitar
		void clear(void);



};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------






#endif //_quadtree_hh_
