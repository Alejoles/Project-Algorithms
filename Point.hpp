#ifndef _Point_hpp_
#define _Point_hpp_


//					Clase punto(Point)

class Point {
	private:
		int x,y;
	public:
		Point() : x{0}, y{0} {}
		Point(int nx, int ny) : x{nx}, y{ny} {}
		~Point();
		// setters & getters--
		int getPX();
		int getPY();
		void setPX(int v);
		void setPY(int v);
		bool inBounds(Point p);
		void PErase();
};
//------------------------------Acá se acaba la structura Point-------------------------------


#endif // Point.hpp
