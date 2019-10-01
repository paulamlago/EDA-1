 #include "diccionario.h"
 #include "lista.h"
 #include <iostream>
 #include <string>

 using namespace std;

 Diccionario<string, Lista<int>> referenciasCruzadas(Lista<Lista<string>> lista){

     Diccionario<string, Lista<int>> dicc = Diccionario<string, Lista<int>>();
     Lista<Lista<string>>::ConstIterator iterLinea = lista.cbegin();
     int cont = 1;

     while(iterLinea != lista.cend()){

         Lista<string>::ConstIterator iterPalabra = iterLinea.elem().cbegin();
         while(iterPalabra != iterLinea.elem().cend()){

             Diccionario<string, Lista<int>>::Iterator iterDicc = dicc.busca(iterPalabra.elem());

             if(iterDicc == dicc.end()){

                 Lista<int> aux;
                 aux.pon_final(cont);
                 dicc.inserta(iterPalabra.elem(), aux);

             } else {
                 Lista<int> aux = iterDicc.valor();
                 aux.pon_final(cont);
                 iterDicc.setVal(aux);

             }

             iterPalabra.next();

         }

         iterLinea.next();
         ++cont;

     }

     return dicc;

 }


 int main (){

     Lista<Lista<string>> list = Lista<Lista<string>>();

     Lista<string> l1;
     Lista<string> l2;
     Lista<string> l3;
     Lista<string> l4;

     l1.pon_final("a");
     l1.pon_final("b");
     l1.pon_final("c");
     l1.pon_final("d");
     l1.pon_final("e");
     l1.pon_final("f");

     l2.pon_final("a");
     l2.pon_final("a");
     l2.pon_final("b");
     l2.pon_final("b");
     l2.pon_final("c");
     l2.pon_final("d");
     l2.pon_final("d");
     l2.pon_final("d");

     l3.pon_final("a");
     l3.pon_final("d");
     l3.pon_final("f");
     l3.pon_final("g");
     l3.pon_final("h");
     l3.pon_final("h");
     l3.pon_final("i");

     l4.pon_final("a");
     l4.pon_final("a");
     l4.pon_final("b");
     l4.pon_final("b");
     l4.pon_final("c");

     list.pon_final(l1);
     list.pon_final(l2);
     list.pon_final(l3);
     list.pon_final(l4);

     Diccionario<string, Lista<int>> dicc = referenciasCruzadas(list);

     getchar();

     return 0;
 }
