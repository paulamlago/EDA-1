#include <iostream>
#include<string>
#include <ctype.h>
#include "pila.h"
using namespace std;

int evaluar(string exp) {

	Pila<int> p = Pila<int>();

	for (int i = 0; i < exp.length(); ++i) {

		if (isdigit(exp[i])) {

			p.apila(exp[i] - '0');

		}
		else {

			int a = p.cima();
			p.desapila();
			int b = p.cima();
			p.desapila();

			switch (exp[i]) {

			case '+': p.apila(a + b); break;
			case '-': p.apila(b - a); break;
			case '*': p.apila(a * b); break;
			case '/': p.apila(b / a); break;

			}

		}

	}

	return p.cima();
	
}

int main() {
	
	string expresion;
	while (cin >> expresion) 
		cout << evaluar(expresion) << endl;

	
	return 0;
}

