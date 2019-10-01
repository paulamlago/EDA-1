#include "Arbin.h"
#include <iostream>

using namespace std;

bool esHoja(Arbin<int> a){ return a.hijoDer().esVacio() && a.hijoIz().esVacio(); }

int nivelCurioso(Arbin<int> a, int nivel, int &numCuriosos){

    if (a.esVacio()) return 0;
    if(esHoja(a)) {

        if(nivel == a.raiz()) numCuriosos++;
        return 1;

    }

    int hijosIz = nivelCurioso(a.hijoIz(), nivel+1, numCuriosos);
    int hijosDer = nivelCurioso(a.hijoDer(), nivel+1, numCuriosos);

    if((hijosIz + nivel) == a.raiz()) numCuriosos++;

    return hijosIz + hijosDer + 1;

}

int curioso(Arbin<int> a){

    int numCuriosos = 0;
    nivelCurioso(a, 0, numCuriosos);
    return numCuriosos;

}

Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#':
		return Arbin<int>();
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
	default:
		return Arbin<int>();
	}
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		cout << curioso(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF)
			cout << endl;
	}
	return 0;
}
