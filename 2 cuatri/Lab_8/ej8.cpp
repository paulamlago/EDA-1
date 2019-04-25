#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {

     Lista<string>::ConstIterator iterBien = bien.cbegin();
     Lista<string>::ConstIterator iterMal = mal.cbegin();
     Diccionario<string, int> dicc = Diccionario<string, int>();

     while(iterBien != bien.cend()){

         Diccionario<string, int>::Iterator iterDicc = dicc.busca(iterBien.elem());

         if(iterDicc == dicc.end()){

             dicc.inserta(iterBien.elem(), 1);

         } else {

             iterDicc.setVal(iterDicc.valor() + 1);

         }

         iterBien.next();

     }

     while(iterMal != mal.cend()){

         Diccionario<string, int>::Iterator iterDicc = dicc.busca(iterMal.elem());

         if(iterDicc == dicc.end()){

             dicc.inserta(iterMal.elem(), -1);

         } else {

             iterDicc.setVal(iterDicc.valor() - 1);

         }

         iterMal.next();

     }

     Diccionario<string, int>::Iterator iterDicc = dicc.begin();
     while(iterDicc != dicc.end()){

         if (iterDicc.valor()){

             Puntuacion aux = Puntuacion(iterDicc.clave(), iterDicc.valor());
             listado.pon_final(aux);

         }

         iterDicc.next();

     }


}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();
  }
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;
}
