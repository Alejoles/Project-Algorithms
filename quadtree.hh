#ifndef _quadtree_hh
#define	_quadtree_hh
#include <vector>
#include <iostream>


using namespace std;
//-------------------------------------------------------------------------------------
//					Estructura punto(Point)
struct Point{
	private:
		int x,y;
	public:
		Point() : x(0), y(0) {}
		Point(int x, int y) : x(x), y(y) {}
		// setters & getters--
		int getPX();
		int getPY();
		void setPX(int v);
		void setPY(int v);
		//_----------------
		
		
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
//					Clase del QuadTree
class qtree{
	private:
		Rect frame;
		unsigned capacity;
		vector<Point> points;
		bool divided = false;

	public://--------------------Acá definimos la forma de nuestro quadtree--------------------------------------------
		qtree() : frame(0), capacity(0) {}
		qtree(Rect Frame, unsigned n) : frame(Frame), capacity(n) {}

		void successor();
		void predeccessor();
		void divide();
		void insert(Point x);
		
};
//---------------------------Acá se acaba la clase qtree-------------------------------------------------
#endif //_quadtree_hh_
