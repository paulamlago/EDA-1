#include <iostream>
#include "lista.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
	Lista<int> l;

	for (int i = 0; i < n; i++) {
		l.pon_final(i + 1);
	}

	Lista<int>::Iterator it = l.begin();

	int salva = 1;

	while (l.longitud() > 1) {
		while (salva < m) {
			it.next();

			if (it == l.end()) {
				it = l.begin();
			}

			salva++;
		}

		salva = 1;
		it = l.eliminar(it);

		if (it == l.end()) {
			it = l.begin();
		}
	}

	return it.elem();

}


int main() {
    int n,m;
	while((cin >> n)) {
	   cin >> m;
       cout << afortunado(n,m) << endl;	   
	}
	return 0;
}	
