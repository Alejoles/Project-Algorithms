#ifndef _quadtree_h_
#define	_quadtree_h_

#include <iostream>
#include <vector>
#include "Punto.h"
#include <fstream>

//Se elimino la estructura Rect ya que se reemplazo por 2 puntos que marcan las esquinas.

//-------------------------------------------------------------------------------------------------
//					Clase del QuadTree

// Cuando insertar un nuevo nodo en el arbol
class Qtree {
	private:
		struct QtreeNode {
            std::vector<Punto> Puntos;
            Punto TopL = Punto(0,0);		// puntos pueden ir en privado
            Punto BotR = Punto(600,600);
			bool leaf = false;
            QtreeNode *NorthWest = nullptr; //  El QuadTree tiene 4 hijos, esto se puede intuir gracias a su nombre,
            QtreeNode *NorthEast = nullptr; //  cada uno de estos hijos tiene las mismas propiedades que sus hermanos
            QtreeNode *SouthWest = nullptr; //  o su padre.
            QtreeNode *SouthEast = nullptr; //
			QtreeNode *Padre = nullptr;		// Guarda el dato del nodo anterior para así saber de donde viene
            unsigned numNod = 0;

			// QtreeNode(Point v, Node *NW = nullptr, Node *NE = nullptr, Node *SW = nullptr, Node *SE = nullptr): Value{v}, NorthWest{NW}, NorthEast{NE}, SouthWest{SW}, SouthEast{SE} {}

		};


		/*QtreeNode * Successor(QtreeNode *root)const;
		QtreeNode * Predecessor(QtreeNode *root)const;*/

        void remove(QtreeNode * &root, Punto p);
        void insert(QtreeNode * &root, QtreeNode *Padre, Punto p, int count, std::ofstream &file);
		void clear(QtreeNode * &root);
        void recorrer(QtreeNode *root);
        void cubrimiento(QtreeNode *root);

		//-------------- Bounds // Esquinas -------------

		QtreeNode *root = nullptr;
		size_t count = 5;
        std::ofstream file;


        //-----------------------Grafo-----------------------

public:
		Qtree() = default;
		~Qtree();
        void insertP(Punto p);
        void removeP(Punto p);// no estoy seguro de que quitar
		void clear(void);
        void recorrer(void);
        //------------------------Grafo---------------------
        void cubrimiento(void);



};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------






#endif //_quadtree_hh_
