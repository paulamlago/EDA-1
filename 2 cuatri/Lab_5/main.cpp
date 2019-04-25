#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS

bool is_vowel(char c) {

	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	Lista<char>::Iterator it = mensaje.begin();
	Pila<char> p;

	while (it != mensaje.end()) {

		if (!is_vowel(it.elem())) {
			p.apila(it.elem());
			it = mensaje.eliminar(it);
		}
		else {

			while (!p.esVacia()) {

				mensaje.insertar(p.cima(), it);
				p.desapila();

			}
			
			it.next();

		}

	}

	while (!p.esVacia()) {

		mensaje.pon_final(p.cima());
		p.desapila();

	}

}

// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	//invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
