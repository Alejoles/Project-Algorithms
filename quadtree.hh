#ifndef
#define
//---------------------------------------------------------------------------------------
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
