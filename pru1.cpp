#include <iostream>
#include <string>
#include <vector>

using namespace std;
//-------------------------------------------------------------------------------------
//					Clase punto(Point)
class Point{
	int x,y;
	public:
		Point(int x, int y){
		this->x = x;
		this->y = y;
		}


};
//------------------------------Acá se acaba la clase Point-------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//					Clase Rectangulo(Rect)
class Rect{
	int x, y, width, height; //variables x,y(lugar) & w,h(width, height) ancho altura.
	public:
		Rect(int x,int y,int w,int h){
			this->x = x;
			this->y = y;
			this->width = w;
			this->height = h;

		}
/*		void set_values(int x,int y,int w,int h){
			this->x = x;
			this->y = y;
			this->width = w;
			this->height = h;

		}
		int x(int x){ 
			x = this->x;
			return x; 
		}
		int y(int y){ 
			y = this->y;
			return y; 
		}
		int w(int w){ 
			w = this->width;
			return w; 
		}
		int h(int h){ 
			h = this->height;
			return h; 
		}

*/	
};
//-----------------------------Acá se acaba la clase Rect-------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//					Clase del QuadTree
class qtree{

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

















