#include "Arbin.h"
#include <iostream>

using namespace std;

bool simetricosAux(Arbin<int> a,Arbin<int> b){
    if(a.esVacio() && b.esVacio())return true;
    if(a.esVacio() || b.esVacio())return false;
    if(a.hijoIz().esVacio() && a.hijoDer().esVacio() && b.hijoIz().esVacio() && b.hijoDer().esVacio()){
        return true;
    }
    bool iz = simetricosAux(a.hijoIz(),b.hijoDer());
    bool der = simetricosAux(a.hijoDer(),b.hijoIz());
    if(iz && der)return true;
    else return false;
}

bool simetricos(Arbin<int> a){
 return simetricosAux(a.hijoIz(),a.hijoDer());

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
		cout << simetricos(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF)
			cout << endl;
	}
	return 0;
}
 
