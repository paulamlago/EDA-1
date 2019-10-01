//Daniel Nasim Santos Ouafki

#include <iostream>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "queue_eda.h"
#include "sortedList.h"

using namespace std;

bool resuelveCaso() {

	int numero;
	sortedList<int> lista;
	sortedList<int> lista_a_insertar;
	
	sortedList<int> lista2;
	sortedList<int> lista_a_insertar2;


	cin >> numero;
	while(numero != 0) {
		lista.push(numero);
		lista2.push(numero);
		cin >> numero;
	}

	cin >> numero;
	while (numero != 0){
		lista_a_insertar.push(numero);
		lista_a_insertar2.push(numero);
		cin >> numero;
	}

	/*
	cout << "Lista 1: ";
	lista.print();
	cout << "\n";

	cout << "Lista 2: ";
	lista_a_insertar.print();
	cout << "\n";
	*/
	

	lista.insertarLista(lista_a_insertar);
	lista2.addListSorted(lista_a_insertar);

	//cout << "Resultado : ";
	lista.print();
	cout << "\nSol Psycho: ";
	lista2.print();
	

	cout << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		//cout << "Insercion " << i << "\n";
		resuelveCaso();
	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;

}
