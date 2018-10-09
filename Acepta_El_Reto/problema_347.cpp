#include <iostream>

using namespace std;

int calc(int a, int b) {

	int aux, cont = 0;
		
	while (a >= 10 && b >= 10) {

		if (a > b) {

			cont += a / b;
			aux = a;
			a = b;
			b = aux % b;

		}

		else {

			cont += b / a;
			aux = b;
			b = a;
			a = aux % a;

		}

	}

	return cont;

}

int main() {

	int a, b, aux;

	while ((scanf("%d%d", &a, &b) && a && b)) {

		aux = calc(a, b);
		printf("%d\n", aux);

	}

	return 0;
}