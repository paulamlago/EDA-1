#include <iostream>
#include <algorithm>

using namespace std;

void alg(int *v, int n, int dif) {

	int cont = 0;
	int min = dif;
	int position = 0;
	int aux = dif;
	int aux2 = 0;

	while (cont < n) {

		aux -= v[cont];
		aux2 += v[cont];

		if (abs(aux2 - aux) < abs(min)) {

			position = cont + 1;
			min = abs(aux2 - aux);

		}

		cont++;

	}

	cout << position << "\n";

}

int main() {

	int n;
	int aux;
	int pos;
	int neg;
	int *v = new int[1000000];

	while (cin >> n && n != 0) {

		pos = 0;
		neg = 0;

		for (int i = 0; i < n; i++) {

			cin >> aux;

			if (aux >= 0)
				pos += aux;

			else
				neg += aux;

			v[i] = aux;

		}

		if ((pos + neg) == 0)
			cout << "0\n";

		else
			alg(v, n, pos + neg);

	}

	return 0;
}