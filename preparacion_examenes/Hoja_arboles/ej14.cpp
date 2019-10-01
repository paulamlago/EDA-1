#include "Arbin.h"
#include <iostream>

using namespace std;

int maxNivel(Arbin<int> a) {

	if (a.esVacio()) return 0;

	return max(1, maxNivel(a.hijoIz()) + maxNivel(a.hijoDer()));

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
		cout << maxNivel(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF)
			cout << endl;
	}
	return 0;
}
