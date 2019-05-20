#include "Punto.h"
#include "quadtree.h"
#include <cstdlib>
#include <vector>
#include <fstream>
#include <math.h>


// Metodos del qtree
/*
 *                  El insert en este caso nos da la opción de decir cuantas veces se va a subdividir el arbol
 *                  tiene 3 casos, el caso base y 2 casos recursivos, uno de los recursivos se ejecutará una
 *                  única vez, eso se hace para que no salte error ya que el primer nodo va a ser null pointer
 *                  entonces no tiene parametros de rango bien definidos, para esto se tuvo que hacer un nodo
 *                  padre, para tomar los parametros de este y asignarlos al nuevo nodo.
 *
 * */


void Qtree::insert(QtreeNode * &root, QtreeNode *Padre, Punto p, int count, std::ofstream &file){
	//chequear en que parte del mapeado estan los puntos y asi mismo agregarlos al arbol
	if(p.inBounds(p)){        
        //if(!file.is_open()) file.open("fs.txt");
        if(root == nullptr && count == 0){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
            root = new QtreeNode;
			root->Padre = Padre;
            int Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
            int Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;
            if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){	// Arriba izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;

                root->Puntos.push_back(p);
                root->leaf = true;
                int topx = root->Padre->TopL.getPX();
                int topy = root->Padre->TopL.getPY();
                root->TopL.setPX(topx);
                root->TopL.setPY(topy);
                root->BotR.setPX(Midx);
                root->BotR.setPY(Midy);
                root->numNod++;
                std::cout << "Caso basee NW" << std::endl;


                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                return;
            }
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->leaf = true;

                root->Puntos.push_back(p);
                root->TopL.setPX(Midx);
                root->TopL.setPY(root->Padre->TopL.getPY());
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(Midy);
                root->numNod++;
                std::cout << "Caso basee NE" << std::endl;


                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                return;
            }
            else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->leaf = true;

                root->Puntos.push_back(p);
                root->TopL.setPX(root->Padre->TopL.getPX());
                root->TopL.setPY(Midy);
                root->BotR.setPX(Midx);
                root->BotR.setPY(root->Padre->BotR.getPY());
                root->numNod++;
                std::cout << "Caso basee SW" << std::endl;


                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                return;
            }
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->leaf = true;

                root->Puntos.push_back(p);
                root->TopL.setPX(Midx);
                root->TopL.setPY(Midy);
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(root->Padre->BotR.getPY());
                root->numNod++;
                std::cout << "Caso basee SE" << std::endl;


                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                return;
            }
		}
		else if(root == nullptr && count > 0 && Padre == nullptr){
            root = new QtreeNode;
            std::cout << "Declaración bounds" << std::endl;

            insert(root,root,p,count,file);
		}
        else if(root == nullptr && count > 0 && Padre != nullptr) {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
            root = new QtreeNode;
            root->Padre = Padre;
            int Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
            int Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;

            if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba izquierda

                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "Caso recursivo varias veces NW" << std::endl;
                root->numNod++;
                root->TopL.setPX(root->Padre->TopL.getPX());
                root->TopL.setPY(root->Padre->TopL.getPY());
                root->BotR.setPX(Midx);
                root->BotR.setPY(Midy);

                /*QtreeNode *next = root;
                next = new QtreeNode;
                next = root;
                next->TopL.setPX(root->Padre->TopL.getPX());
                next->TopL.setPY(root->Padre->TopL.getPY());
                next->BotR.setPX(Midx);
                next->BotR.setPY(Midy);
                next->Padre = Padre;*/
                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->NorthWest, root, p, --count,file);
			}
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->numNod++;
                root->TopL.setPX(Midx);
                root->TopL.setPY(root->Padre->TopL.getPY());
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(Midy);
                std::cout << "Caso recursivo varias veces NE" << std::endl;

                //QtreeNode *next = root->NorthEast;
               /* next = new QtreeNode;
                next->numNod++;
                next->TopL.setPX(Midx);
                next->TopL.setPY(root->Padre->TopL.getPY());
                next->BotR.setPX(root->Padre->BotR.getPX());
                next->BotR.setPY(Midy);*/

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->NorthEast, root, p, --count,file);
			}
            else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->numNod++;
                root->TopL.setPX(root->Padre->TopL.getPX());
                root->TopL.setPY(Midy);
                root->BotR.setPX(Midx);
                root->BotR.setPY(root->Padre->BotR.getPY());
                std::cout << "Caso recursivo varias veces SW" << std::endl;

                //QtreeNode *next = root->NorthEast;
                /*next = new QtreeNode;
                next->numNod++;
                next->TopL.setPX(root->Padre->TopL.getPX());
                next->TopL.setPY(Midy);
                next->BotR.setPX(Midx);
                next->BotR.setPY(root->Padre->BotR.getPY());*/

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->SouthWest, root, p, --count,file);
			}
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                root->numNod++;
                root->TopL.setPX(Midx);
                root->TopL.setPY(Midy);
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(root->Padre->BotR.getPY());
                std::cout << "Caso recursivo varias veces SE" << std::endl;

                //QtreeNode *next = root->NorthEast;
                /*next = new QtreeNode;
                next->numNod++;
                next->TopL.setPX(Midx);
                next->TopL.setPY(Midy);
                next->BotR.setPX(root->Padre->BotR.getPX());
                next->BotR.setPY(root->Padre->BotR.getPY());*/

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->NorthEast, root, p, --count,file);
			}
		}
        else if(root != nullptr && count > 0){
            if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
                root->numNod++;
                std::cout << "Recorrer NW" << std::endl;
                insert(root->NorthWest, root, p, --count,file);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
                root->numNod++;
                std::cout << "Recorrer NW" << std::endl;
                insert(root->NorthEast, root, p, --count,file);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
                root->numNod++;
                std::cout << "Recorrer NW" << std::endl;
                insert(root->SouthWest, root, p, --count,file);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
                root->numNod++;
                std::cout << "Recorrer NW" << std::endl;
                insert(root->SouthEast, root, p, --count,file);
			}
        }else if(root != nullptr && count == 0){
            root->leaf = true;
            root->numNod++;
            root->Puntos.push_back(p);
            std::cout << "caso base 2" << std::endl;
        }

	}
	else{
		std::cout << "The point is not in bounds" << std::endl;
    }
}
void Qtree::insertP(Punto p){
	//incovar el metodo anterior sumando al contador
    file.open("fs.txt");
    insert(root, nullptr, p, 5, this->file);
    file.close();
}

/*
 *                  El método remove en primera instancia era recursivo, pero me pareció mas lindo dejarlo iterativo, igual
 *                  no cambia mucho la complejidad, el caso recursivo se deja comentado a proposito por si se quiere usar,
 *                  pero tiene errores ese caso, lo mejor es que si lo quiere arreglar mire el iterativo y se de una idea de
 *                  cómo sería.
 *
 * */

void Qtree::remove(QtreeNode * &root, Punto p, QtreeNode *root2){
    int i = 0;
    std::cout << "Buscando punto..." << std::endl;
    root2 = root;
    while(root != nullptr){
        std::cout << "..." << std::endl;
        if(root->leaf == true){
            std::cout << "Tiene " <<root->Puntos.size() << " puntos en esta zona." << std::endl;
            root->Puntos.pop_back();
            std::cout << "Punto eliminado!" << std::endl;
            break;
        }
        if(i<1){
            i++;
            if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
                root = root->NorthWest;

            }
            else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
                root = root->NorthEast;

            }
            else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
                root = root->SouthWest;

            }
            else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
                root = root->SouthEast;

            }
        }
        else {
            if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba izquierda
                root = root->NorthWest;

            }
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
                root = root->NorthEast;

            }
            else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
                root = root->SouthWest;

            }
            else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
                root = root->SouthEast;

            }
        }
    }root = root2;

}

void Qtree::recorrer(QtreeNode *root){
    if(root == nullptr) return;
    else{
        if(root->leaf == true){
            std::cout << "llegó a hoja" << std::endl;
        }else {
            std::cout << "recorrer" << root->numNod << std::endl;
            recorrer(root->NorthWest);
        }
    }

}

/*
 *              El método clear, el más sencillo de todos, es una 'copia' (por decirlo así) de la implementación
 *              de la función clear en un BinarySeatchTree, por lo que no da lugar a dudas.
 *
 * */

void Qtree::clear(QtreeNode * &root){
	if(root != nullptr){
		QtreeNode *NorthWest = root->NorthWest;
		QtreeNode *NorthEast = root->NorthEast;
		QtreeNode *SouthWest = root->SouthWest;
		QtreeNode *SouthEast = root->SouthEast;
		delete root;
        clear(NorthWest);
		clear(NorthEast);
		clear(SouthWest);
		clear(SouthEast);
	}
}
void Qtree::recorrer(void){
    recorrer(root);
}

void Qtree::removeP(Punto p){
    remove(root, p, root);
}

void Qtree::clear(void){
	clear(root);
	root = nullptr;
	count = 0;
}

Qtree::~Qtree(){
	clear();
}

/*
 *
 *
 *
 *
 *
 *                      METODOS DEL GRAFO, se hicieron acá para una mayor facilidad de interacción con el quadtree
 *                      ya que los 2 estan conectados es mejor hacerlo todo en uno.
 *
 *
 *
 * */

void Qtree::Traversal(QtreeNode *&root, double &NumP, std::ostream &file){

    if(root != nullptr){

        if(root->leaf == true){
            if(root->numNod > 1){
                NumP = NumP - root->numNod;
                root->numNod = 0;
                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            }
            else {
                --NumP;
                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            }
        }
        std::cout << "NumP: " <<NumP << std::endl;
        if(root->NorthWest != nullptr && NumP >0){
            QtreeNode *next = root->NorthWest;
            Traversal(next,NumP, file);
        }
        if(root->NorthEast != nullptr && NumP >0){
            QtreeNode *next = root->NorthEast;
            Traversal(next,NumP, file);
        }if(root->SouthWest != nullptr && NumP >0){
            QtreeNode *next = root->SouthWest;
            Traversal(next,NumP, file);
        }if(root->SouthEast != nullptr && NumP >0){
            QtreeNode *next = root->SouthEast;
            Traversal(next,NumP, file);
        }

    }
    else {
        return;
    }
}

void faltane(double &faltan, double &aa, double &bb, double &cc, double &dd){
    while(faltan > 0){
        if (faltan>0){
            if(aa <= bb && aa <= cc && aa <= dd){
                aa++;
                faltan--;
            }
        }
        if (faltan>0){
            if(bb <= aa && bb <= cc && bb <= dd){
                bb++;
                faltan--;
            }
        }
        if (faltan>0){
            if(cc <= aa && cc <= bb && cc <= dd){
                    cc++;
                    faltan--;

            }
        }
        if (faltan>0){
            if(dd <= aa && dd <= bb && dd <= cc){
                    dd++;
                    faltan--;
            }
        }
    }
}

void Qtree::cubrimiento(QtreeNode *&root, double NumP,std::ofstream &file, unsigned &i){
    if(root != nullptr){
        unsigned num = root->numNod;
        if(num <= NumP){
            std::cout << "Caso base" << std::endl;
            Traversal(root, NumP, file);
            return;
        }
        /*else if(num > NumP && root->NorthWest == nullptr && i>3 && num > 1 && NumP > 1){
            file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            i = 0;
            return;
        }
        else if(num > NumP && root->NorthEast == nullptr && i>3 && num > 1 && NumP > 1){
            file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            i = 0;
            return;
        }
        else if(num > NumP && root->SouthWest == nullptr && i>3 && num > 1 && NumP > 1){
            file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            i = 0;
            return;
        }
        else if(num > NumP && root->SouthEast == nullptr && i>3 && num > 1){
            file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX()-10 << "," << root->BotR.getPY()-10 << "." <<std::endl;
            i = 0;
            return;
        }*/
        if(num>NumP) {
            std::cout << "Caso recursivo" << std::endl;
            double x = NumP/num;
            unsigned a=0,b=0,c=0,d=0;
            if(root->NorthWest != nullptr) a = root->NorthWest->numNod;
            if(root->NorthEast != nullptr) b = root->NorthEast->numNod;
            if(root->SouthWest != nullptr) c = root->SouthWest->numNod;
            if(root->SouthEast != nullptr) d = root->SouthEast->numNod;

            double aa = floor(x*a);
            double bb = floor(x*b);
            double cc = floor(x*c);
            double dd = floor(x*d);
            std::cout << aa << " " << bb<< " "  << cc << " " << dd << std::endl;

            if(aa+bb+cc+dd < NumP){
                double faltan = NumP - (aa+bb+cc+dd);
                if(a == 1 && aa < 1){
                    aa++;
                    faltan--;
                }
                if(b == 1 && bb < 1){
                    bb++;
                    faltan--;
                }
                if(c == 1 && cc < 1){
                    cc++;
                    faltan--;
                }
                if(d == 1 && dd < 1){
                    dd++;
                    faltan--;
                }
                if(a != 0 && faltan >0){
                    if(a <= b && a <= c && a <= d){
                        aa++;
                        faltan--;
                    }
                }
                if(b != 0 && faltan >0){
                    if(b <= a && b <= c && b <= d){
                        bb++;
                        faltan--;
                    }
                }
                if(c != 0 && faltan >0){
                    if(c <= a && c <= b && c <= d){
                        cc++;
                        faltan--;
                    }
                }
                if(d != 0 && faltan >0){
                    if(d <= a && d <= b && d <= c){
                        dd++;
                        faltan--;
                    }
                }
                std::cout << "Faltan: " << faltan << std::endl;

                if(faltan > 0){
                    faltane(faltan, aa, bb ,cc ,dd);
                }
                std::cout << faltan << std::endl;
            }
            if(aa > 0){
                std::cout << "Cubrimiento NW " << aa << std::endl;
                cubrimiento(root->NorthWest, aa, file,++i);
            }
            if(bb > 0){
                std::cout << "Cubrimiento NE " << bb << std::endl;
                cubrimiento(root->NorthEast, bb, file,++i);
            }
            if(cc > 0){
                std::cout << "Cubrimiento SW " << cc << std::endl;
                cubrimiento(root->SouthWest, cc, file,++i);
            }
            if(dd > 0){
                std::cout << "Cubrimiento SE " << dd << std::endl;
                cubrimiento(root->SouthEast, dd, file,++i);
            }
        }
    }else{
        std::cout << "No es posible hacer un cubrimiento en un arbol null" << std::endl;
        return;
    }
}


void Qtree::cubrimiento(double NumP){
    file.open("fs.txt");
    unsigned i = 0;
    cubrimiento(this->root,NumP, this->file, i);
    file.close();
}


