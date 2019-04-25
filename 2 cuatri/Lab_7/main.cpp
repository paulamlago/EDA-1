/**
Este programa lee árboles de la entrada estándar, 
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada árbol leído, escribe en la salida estándar
el número de nodos singulares de dicho árbol.
	
Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el árbol vacío. Al no tener nodos,
un árbol vacío tiene 0 nodos sigulares.
-El segundo representa un árbol con un único nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene 
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0. 
-El tercero representa otro árbol con un único nodo, cuyo
valor es 5. Por la misma razón que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente árbol:
     
	       1
		  /  \
		  3  -4
         / \  
        4  -3 

Este árbol tiene 2 nodos sigulares: la raíz, y la raíz del hijo 
izquierdo. 

Por tanto, la salida del programa para estos casos será:

0
1
1
2

*/
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

void aux(const Arbin<int> &a, int sup, int &inf, unsigned int &ret) {

	// vacio
	if (a.esVacio()) return;

	// hoja
	if (a.hijoDer().esVacio() && a.hijoIz().esVacio()) {		
		ret += (sup == 0);
		inf += a.raiz();
		return;
	}

	// intermedios

	int infDer = 0;
	int infIzq = 0;

	aux(a.hijoIz(), sup + a.raiz(), infIzq, ret);
	aux(a.hijoDer(), sup + a.raiz(), infDer, ret);
	
	inf += (infDer + infIzq);

	ret += (inf == sup);
	inf += a.raiz();

	return;


}

/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de esta función
			   
			o(n)	Siendo n el número de nodos

			ya que solo se pasa 1 sola vez por cada nodo.

*/
unsigned int numero_singulares(const Arbin<int>& a) {
	
	int inf = 0;
	unsigned int ret = 0;

	aux(a, 0, inf, ret);
	
	return ret;

}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
