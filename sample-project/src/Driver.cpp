#include <iostream>
#include "quadtree.h"
#include "console.h"
#include "ginteractors.h" // for GWindow
#include "gwindow.h" // for GWindow
#include <string>
//#include "Grafo.h"
//#include "Punto.h"
using namespace std;

void leerCrear(GWindow *gw){
    string x;
    string y;
    string w;
    string h;
    string str;
    ifstream archivo;
    archivo.open("fs.txt");
    if(archivo.is_open()){
        while(getline(archivo,str)){
            int cont = 0;
            for(unsigned i = 0; i<str.size();i++){
                if(str[i] == ',' || str[i] == '.') cont++;
                else{
                    if(cont < 1){
                        x+= str[i];
                    }
                    else if(cont <=1 && cont < 2){
                        y+= str[i];
                    }
                    else if(cont <=2 && cont < 3){
                        w+= str[i];
                    }
                    else if(cont <=3 && cont < 4){
                        h+= str[i];
                    }
                }
            }
            int xx,yy,ww,hh;
            xx = stoi(x);
            yy = stoi(y);
            ww = stoi(w);
            hh = stoi(h);
            gw->drawRect(xx,yy,ww-xx,hh-yy);
            x.clear();
            y.clear();
            w.clear();
            h.clear();
        }
    }
    archivo.close();


}
void leerCrearCu(GWindow *gw){
    string x;
    string y;
    string w;
    string h;
    string str;
    ifstream archivo;
    archivo.open("fs.txt");
    if(archivo.is_open()){
        gw->setFillColor("Blue");

        while(getline(archivo,str)){
            int cont = 0;
            for(unsigned i = 0; i<str.size();i++){
                if(str[i] == ',' || str[i] == '.') cont++;
                else{
                    if(cont < 1){
                        x+= str[i];
                    }
                    else if(cont <=1 && cont < 2){
                        y+= str[i];
                    }
                    else if(cont <=2 && cont < 3){
                        w+= str[i];
                    }
                    else if(cont <=3 && cont < 4){
                        h+= str[i];
                    }
                }
            }
            int xx,yy,ww,hh;
            xx = stoi(x);
            yy = stoi(y);
            ww = stoi(w);
            hh = stoi(h);
            gw->fillRect(ww+5,hh+5,5,5);
            x.clear();
            y.clear();
            w.clear();
            h.clear();
        }
    }
    archivo.close();

}

int main(){
    GWindow* window = new GWindow(1000, 1000);
    window->setTitle("Qtree Prueba1");
    window->setLocation(0, 0);
    window->setExitOnClose(true);
    window->setBackground("White");
    window->clear();
    window->setColor("Black");
    window->setVisible(true);
    window->requestFocus();
    window->setFillColor("Red");

    Qtree q;
    Punto punto;
    for(unsigned i = 0; i<0; i++){
        Punto punto;
        punto.setPX(rand()%600);
        punto.setPY(rand()%600);
        int x = punto.getPX();
        int y = punto.getPY();
        q.insertP(punto);
        window->fillOval(x,y,5,5);
        leerCrear(window);
    }
   /* punto = Punto(55,99);
    q.insertP(punto);
    window->fillOval(punto.getPX(),punto.getPY(),5,5);
    leerCrear(window);*/
    punto = Punto(5,5);
    q.insertP(punto);
    window->fillOval(punto.getPX(),punto.getPY(),5,5);
    leerCrear(window);
    punto = Punto(400,580);
    q.insertP(punto);
    window->fillOval(punto.getPX(),punto.getPY(),5,5);
    leerCrear(window);
    q.cubrimiento(2);
    leerCrearCu(window);
	return 0;
}
