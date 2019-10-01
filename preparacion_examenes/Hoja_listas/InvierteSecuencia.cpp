#include "pila.h"
#include "lista.h"
#include <iostream>

using namespace std;

void invierteSegmento(Lista<char> &l, int j, int k){

    Pila<char> p;

    if(j >= l.longitud()) return;

    Lista<char>::Iterator iter = l.begin();
    Lista<char>::Iterator iterAux = l.begin();

    for(int i = 0; i < j; ++i)
        iter.next();

    for(int i = 0; i < k; ++i){
        p.apila(iter.elem());
        iterAux = iter;
        iterAux.next();
        l.eliminar(iter);
        iter = iterAux;
    }

    for(int i = 0; i < k; ++i){
        l.insertar(p.cima(), iter);
        p.desapila();
    }
    
}

int main(){

    int ll, i, k;
    char aux;
    Lista<char> l;

    cout << "Introduzca la longituda de la lista inicial: ";
    cin >> ll;
    cout << "Introduzca la lista inicial: ";

    for(int i = 0; i < ll; ++i){

        cin >> aux;
        l.pon_final(aux);

    }

    cout << "Introduzca el elemento inicio del segmento a invertir: ";
    cin >> i;
    cout << "Introduzca la longitud del segmento a invertir: ";
    cin >> k;

    invierteSegmento(l, i, k);

    Lista<char>::ConstIterator iter = l.cbegin();

    while(iter != l.cend()){

        cout << iter.elem() << " ";
        iter.next();

    }

    cout << "\n";

    return 0;
}
