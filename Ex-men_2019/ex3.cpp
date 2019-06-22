// Diego Atance Sanz

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(
	// Datos del problema
	int k,
	int d,

	int dig,
	int &cont,
	int &sum
) {

	if (dig <= d) {

		if (dig == 1) {
			++dig;
			cont = 0;
			sum = k;
		}

		for (int i = 0; i < 10; ++i) {

			sum += i;
			if (!(sum % dig)) {

				solve(k, d, dig + 1, cont, sum);

			}
			sum -= i;

		}
	}
	else
		++cont;

}

int main() {

	int k, d, cont, sum;

	while (cin >> k && k) {

		cin >> d;

		cont = 0;
		solve(k, d, 1, cont, sum);
		cout << cont << '\n';

	}

	return 0;
}
