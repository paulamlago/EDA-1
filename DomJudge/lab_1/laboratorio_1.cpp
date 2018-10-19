#include <string>
#include <iostream>

using namespace std;

// { Pre: 3 <= n <= longitud(v) }

int sumaMaximos(int v[], int n) /* return ret */ {

	int i;
	int a, b, c;

	a = v[0];
	b = v[1];
	c = v[2];

	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);

	i = 3;

	// Invariante:

	// {I: 
	// a <= b <= c ^
	// 3 <= i <= n ^
	// a + b + c = max j, k, l : 0 <= j < k < l < i : v[j] + v[k] + v[l]
	// Ex. j : 0 <= j <= i : v[j] = a ^
	// Ex. k : 0 <= k <= i : v[k] = a ^
	// Ex. l : 0 <= l <= i : v[l] = a ^
	// }

	while (i < n) {

		if (a < v[i]) {

			a = v[i];

			if (a > b) swap(a, b);
			if (a > c) swap(a, c);
			if (b > c) swap(b, c);

		}

		// Incremento

		i++;

	}

	return a + b + c;
}

// { Post: ret = max j, k, l : 0 <= i < j < k < n : v[i] + v[j] + v[k] }


int main() {

	int v[10000];
	int aux, n;

	while (cin >> aux && aux != 0) {

		for (int i = 0; i < aux; i++) {

			cin >> v[i];

		}

		n = sumaMaximos(v, aux);

		cout << n << "\n";

	}

	return 0;
}