#include <iostream>
#include "lista_ej1.h"

using namespace std;

int main (){

    unsigned int n;
    int aux;
    Lista<int> list;

    while(cin >> n && n){

        for (int i = 0; i < n; i++){
            cin >> aux;
            list.pon_final(aux);
        }
        
        list.repartir();

        for (int i = 0; i < n; i++){
            cout << list.primero() << " ";
            list.quita_ppio();
        }

        cout << "\n";

    }

    return 0;
}
