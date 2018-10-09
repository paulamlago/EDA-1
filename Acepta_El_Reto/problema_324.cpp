#include <iostream>

using namespace std;

int Mcd(int a, int b) {

	int t;

	while (b) {

		t = b;
		b = a % b;
		a = t;

	}

	return a;

}

int done(bool b[100], int n) {

	for (int i = 0; i < n; i++) {

		if (b[i] == true)
			return i;

	}

	return -1;

}

int alg(int v[100], bool b[100], int n) {

	int i;
	int mcm = 1;
	int cont;
	int j;

	i = done(b, n);

	while (i != -1) {

		cont = 1;
		j = i;
		b[i] = 0;

		while (v[i] != j) {

			i = v[i];
			b[i] = 0;
			cont++;

		}

		mcm = (mcm * cont) / Mcd(mcm, cont);

		i = done (b, n);

	}

	return mcm;

}

int main() {

	int aux;
	int n;
	int v[100];
	bool b[100];
	int ret;

	while (cin >> n && n > 0) {

		for (int i = 0; i < n; i++) {

			cin >> aux;
			v[i] = aux - 1;
			b[i] = true;

		}

		ret = alg(v, b, n);

		cout << ret << "\n";

	}

	return 0;
}