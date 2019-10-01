#include "lista.h" 
#include <iostream>

using namespace std;

int main (){

    Lista<int> l;
    int n, aux;

    cout << "Numero elementos: ";
    cin >> n;

    while(n--){

        cin >> aux;
        l.pon_final(aux);

    }

    l.invertir();

    Lista<int>::ConstIterator iter = l.cbegin();

    while(iter != l.cend()){

        cout << iter.elem() << " ";
        iter.next();

    }

    return 0;
}