#include <iostream>
#include "cola_ej1.h"

using namespace std;

int main(){

    Cola<int> cola;

    int n, aux, pos;

    while(cin >> n && n){

    	for (int i = 0; i < n; ++i){
    		cin >> aux;
    		cola.pon(aux);
    	}

    	cin >> pos;
    	cola.llevarAlPrincipio(pos);

    	for (int i = 0; i < n; ++i){
    		cout << cola.primero() << " ";
    		cola.quita();

    	}

    }

    getchar();
    getchar();

    return 0;
}
