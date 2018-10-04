#include <iostream>
#include <cmath>

using namespace std;

inline int puzzle(int n) {

	int a = sqrt(n);

	while ((n % a) > 0) {

		a--;

	}

	return n / a;
}

int main() {

	int n;

	while (cin >> n  && n != 0) {

		cout << puzzle(n) << "\n";

	}

	return 0;
}

// Versión en C -> Más eficiente

/*

#include <stdio.h>
#include <math.h>

int main() {

	int n, a, aux;
	scanf_s("%d", &n);

	while (n != 0) {

		a = sqrt(n);

		while ((n % a) > 0)
			a--;

		aux = n / a;
		printf("%d\n", aux);
		scanf_s("%d", &n);

	}

	return 0;
}

*/