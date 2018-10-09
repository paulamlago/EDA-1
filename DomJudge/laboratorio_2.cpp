#include <iostream>

using namespace std;

// Complejidad = O(n)

// { Pre: (0 <= n < longitud(v)) ^ (0 < longitud <= n) }

bool esCiclico(int v[], int n, int longitud) /* return ret */ {

	int i = 0;
	bool ret = true;

	// Invariante:
		// (0 <= i <= (n - longitud)) ^
		// ret = P.t. j : 0 <= j < i : v[j] = v[j + longitud]

	while (i < n - longitud && ret) {

		ret = (v[i] == v[i + longitud]);
		i++;

	}

	return ret;
}

// { Pos: ret = P.t. i : 1 <= i < (n - longitud) : v[i] = v[i + longitud] }


// Complejidad = O(n^2)

int longitudCiclo(int v[], int n) {

	int i = 1;

	while ((i < n) && (!esCiclico(v, n, i)))
		i++;

	return i;

}

int main() {

	int v[1000];
	int n;

	while (cin >> n && n != 0) {

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << longitudCiclo(v, n) << endl;

	}

	return 0;
}