#ifndef _quadtree_hh
#define	_quadtree_hh
#include <iostream>
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
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//					Clase del QuadTree
class qtree{
	private:
		vector<Point> points;
		Rect frame;
		unsigned capacity;
		bool divided = false;

	public://--------------------Acá definimos la forma de nuestro quadtree--------------------------------------------
		qtree(Rect Frame, unsigned n){
			this->frame = Frame;
			this->capacity = n;
		}

//--------------------------------Ahora vamos a definir las funciones de qtree---------------------------------

		void successor();
		void predeccessor();
		void divide();

		void insert(Point x){
			if(points.size() < capacity){
				this->points.push_back(x);
			}else {
				if(!this->divided){
				this->divide();
				this->divided = true;
				}
			}
		}


		
};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------
#endif
