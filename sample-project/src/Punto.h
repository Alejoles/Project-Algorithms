#ifndef _Punto_h_
#define _Punto_h_


//					Clase punto(Point)

class Punto {
	private:
		int x,y;
	public:
        Punto() : x{0}, y{0} {}
        Punto(int nx, int ny) : x{nx}, y{ny} {}
        ~Punto();
		// setters & getters--
		int getPX();
		int getPY();
		void setPX(int v);
		void setPY(int v);
        bool inBounds(Punto p);
		void PErase();
};
//------------------------------Acá se acaba la structura Point-------------------------------


#endif // Point.hpp
