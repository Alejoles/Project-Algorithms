#include "Punto.h"
#include "quadtree.h"
#include <cstdlib>
#include <vector>
#include <fstream>


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
		if(root == nullptr && count <= 0){			// caso base recursivo //contador que me diga la altura maxima del arbol para ir insertando nodos precisamente dentro del arbol para saber su ubicacion.
			root = new QtreeNode;
			root->Padre = Padre;
            int Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
            int Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;
			if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){	// Arriba izquierda
                //file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "NW caso base" << std::endl;
                root->Puntos.push_back(p);
				int topx = root->Padre->TopL.getPX();
				int topy = root->Padre->TopL.getPY();
				root->TopL.setPX(topx);
				root->TopL.setPY(topy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(Midy);
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;
                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                root->leaf = true;
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "NE caso base" << std::endl;

                root->Puntos.push_back(p);
				root->TopL.setPX(Midx);
				root->TopL.setPY(root->Padre->TopL.getPY());
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(Midy);
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
				root->leaf = true;
			}
			else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "SW caso base" << std::endl;

                root->Puntos.push_back(p);
				root->TopL.setPX(root->Padre->TopL.getPX());
				root->TopL.setPY(Midy);
				root->BotR.setPX(Midx);
				root->BotR.setPY(root->Padre->BotR.getPY());
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
				root->leaf = true;
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "SE caso base" << std::endl;

                root->Puntos.push_back(p);
				root->TopL.setPX(Midx);
				root->TopL.setPY(Midy);
				root->BotR.setPX(root->Padre->BotR.getPX());
				root->BotR.setPY(root->Padre->BotR.getPY());
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
				root->leaf = true;
			}
		}
		else if(root == nullptr && count > 0 && Padre == nullptr){
            root = new QtreeNode;
            std::cout << "padre null" << std::endl;

            insert(root,root,p,count,file);
		}
		else if(root == nullptr && count > 0 && Padre != nullptr) {// caso recursivo, va mirando en dónde meter el nodo, y se ejecuta las veces necesarias.
            root = new QtreeNode;
			root->Padre = Padre;
            int Midx = (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2;
            int Midy = (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2;

            if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "NW padre not null" << std::endl;
                root->numNod++;
                root->TopL.setPX(root->Padre->TopL.getPX());
                root->TopL.setPY(root->Padre->TopL.getPY());
                root->BotR.setPX(Midx);
                root->BotR.setPY(Midy);
                std::cout << "#: " << root->numNod << std::endl;


                QtreeNode *next = root->NorthWest;
                next = new QtreeNode;

                next->TopL.setPX(root->Padre->TopL.getPX());
                next->TopL.setPY(root->Padre->TopL.getPY());
                next->BotR.setPX(Midx);
                next->BotR.setPY(Midy);
                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(next, root, p, count,file);
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() <= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Arriba derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "NE padre not null" << std::endl;
                root->numNod++;
                root->TopL.setPX(Midx);
                root->TopL.setPY(root->Padre->TopL.getPY());
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(Midy);
                std::cout << "#: " << root->numNod << std::endl;

                QtreeNode *next = root->NorthEast;
                next = new QtreeNode;

                next->TopL.setPX(Midx);
                next->TopL.setPY(root->Padre->TopL.getPY());
                next->BotR.setPX(root->Padre->BotR.getPX());
                next->BotR.setPY(Midy);

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(next, root, p, count,file);
			}
			else if(p.getPX() <= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo izquierda
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "SW padre not null" << std::endl;
                root->numNod++;
                root->TopL.setPX(root->Padre->TopL.getPX());
                root->TopL.setPY(Midy);
                root->BotR.setPX(Midx);
                root->BotR.setPY(root->Padre->BotR.getPY());
                std::cout << "#: " << root->numNod << std::endl;

                QtreeNode *next = root->NorthEast;
                next = new QtreeNode;

                next->TopL.setPX(root->Padre->TopL.getPX());
                next->TopL.setPY(Midy);
                next->BotR.setPX(Midx);
                next->BotR.setPY(root->Padre->BotR.getPY());

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(next, root, p, count,file);
			}
			else if(p.getPX() >= (root->Padre->TopL.getPX() + root->Padre->BotR.getPX())/2 && p.getPY() >= (root->Padre->TopL.getPY() + root->Padre->BotR.getPY())/2){ // Abajo Derecha
                file << root->Padre->TopL.getPX() << "," << root->Padre->TopL.getPY() << "," << root->Padre->BotR.getPX() << "," << root->Padre->BotR.getPY() << "." <<std::endl;
                std::cout << "SE padre not null" << std::endl;
                root->numNod++;
                root->TopL.setPX(Midx);
                root->TopL.setPY(Midy);
                root->BotR.setPX(root->Padre->BotR.getPX());
                root->BotR.setPY(root->Padre->BotR.getPY());
                std::cout << "#: " << root->numNod << std::endl;

                QtreeNode *next = root->NorthEast;
                next = new QtreeNode;

                next->TopL.setPX(Midx);
                next->TopL.setPY(Midy);
                next->BotR.setPX(root->Padre->BotR.getPX());
                next->BotR.setPY(root->Padre->BotR.getPY());

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(next, root, p, count,file);
			}
		}
        else if(root != nullptr && count > 0){
            if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
                std::cout << "NW busqueda" << std::endl;
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;

                insert(root->NorthWest, root, p, --count,file);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
                std::cout << "NE busqueda" << std::endl;
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->NorthEast, root, p, --count,file);
			}
			else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
                std::cout << "SW busqueda" << std::endl;
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;
                insert(root->SouthWest, root, p, --count,file);
			}
			else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
                std::cout << "SE busqueda" << std::endl;
                root->numNod++;
                std::cout << "#: " << root->numNod << std::endl;

                file << root->TopL.getPX() << "," << root->TopL.getPY() << "," << root->BotR.getPX() << "," << root->BotR.getPY() << "." <<std::endl;

                insert(root->SouthEast, root, p, --count,file);
			}
		}

	}
	else{
		std::cout << "The point is not in bounds" << std::endl;
    }// if(file.is_open()) file.close();
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

void Qtree::remove(QtreeNode * &root, Punto p){
    int i = 0;
    std::cout << "Buscando punto..." << std::endl;
    while(root != nullptr){
        std::cout << "..." << std::endl;
        if(root->leaf == true){
            std::cout << root->Puntos.size() << std::endl;
            root->Puntos.pop_back();
            std::cout << "Punto eliminado!" << std::endl;
            break;
        }
        else if(i<1){
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
    }
   /* if(root != nullptr && (root->leaf)==false){
		if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba izquierda
            std::cout << "Caso recursivo NW" << std::endl;
            if(root->NorthWest != nullptr){
                remove(root->NorthWest, p);
            }else{
                std::cout << "El punto no se encuentra" << std::endl;
            }
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() <= (root->TopL.getPY() + root->BotR.getPY())/2){ // Arriba derecha
            std::cout << "Caso recursivo NE" << std::endl;
            if(root->NorthWest != nullptr){
                remove(root->NorthEast, p);
            }else{
                std::cout << "El punto no se encuentra" << std::endl;
            }
		}
		else if(p.getPX() <= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo izquierda
            std::cout << "Caso recursivo SW" << std::endl;
            if(root->NorthWest != nullptr){
                remove(root->SouthWest, p);
            }else{
                std::cout << "El punto no se encuentra" << std::endl;
            }
		}
		else if(p.getPX() >= (root->TopL.getPX() + root->BotR.getPX())/2 && p.getPY() >= (root->TopL.getPY() + root->BotR.getPY())/2){ // Abajo Derecha
            std::cout << "Caso recursivo SE" << std::endl;
            if(root->NorthWest != nullptr){
                remove(root->SouthEast, p);
            }else{
                std::cout << "El punto no se encuentra" << std::endl;
            }
		}
	}
	else{
        std::cout << "entro al else" << std::endl;
        if(root == nullptr){
            std::cout << "El punto no se encuentra" << std::endl;
            root = root->Padre;
        }
        else if(root->leaf == true){
			for(unsigned i = 0; i< root->Puntos.size(); i++){
				if(root->Puntos[i].getPX() == p.getPX() && root->Puntos[i].getPY() == p.getPY()){
					root->Puntos.pop_back();
                    std::cout << "Punto eliminado!!" << std::endl;
				}else{
                    std::cout << "Buscando punto..." << std::endl;
				}
			}
        }else if(root->Puntos.size()!=0){
            for(unsigned i = 0; i< root->Puntos.size(); i++){
                if(root->Puntos[i].getPX() == p.getPX() && root->Puntos[i].getPY() == p.getPY()){
                    root->Puntos.pop_back();
                    std::cout << "Punto eliminado!!" << std::endl;
                }else{
                    std::cout << "Buscando punto..." << std::endl;
                }
            }
        }
        else{
            std::cout << "ni idea toncs" << std::endl;
        }
    }
    */

}

void Qtree::recorrer(QtreeNode *root){
    if(root != nullptr){
        std::cout << "NumNod: " << root->numNod << std::endl;
        QtreeNode *NorthWest = root->NorthWest;
        QtreeNode *NorthEast = root->NorthEast;
        QtreeNode *SouthWest = root->SouthWest;
        QtreeNode *SouthEast = root->SouthEast;
        std::cout << "NW:  " << std::endl;

        recorrer(NorthWest);
        std::cout << "NE:  " << std::endl;

        recorrer(NorthEast);
        std::cout << "SW:  " << std::endl;

        recorrer(SouthWest);
        std::cout << "SE:  " << std::endl;

        recorrer(SouthEast);
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
    remove(root, p);
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
void Qtree::cubrimiento(QtreeNode *root){

}

void Qtree::cubrimiento(void){
    cubrimiento(root);
}


