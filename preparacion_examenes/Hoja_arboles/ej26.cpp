#include "Arbin.h"
#include <iostream>

using namespace std;

bool esHoja(Arbin<int> a){

	return a.hijoDer().esVacio() && a.hijoIz().esVacio();

}

int genealogico(Arbin<int> a) {

	if (a.esVacio())
		return 1;

	if (esHoja(a))
		return 1;

	bool okI = genealogico(a.hijoIz());
	bool okD = genealogico(a.hijoDer());

	bool ok = (a.raiz() >= a.hijoIz().raiz() + 18) && (a.raiz() >= a.hijoDer().raiz() + 18) && (a.hijoIz().raiz() >= a.hijoDer().raiz());

	return ok && okI && okD;

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
		genealogico(lee_arbol(cin))? cout << "Es valido\n" : cout << "No es valido\n";
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF)
			cout << endl;
	}
	return 0;
}

