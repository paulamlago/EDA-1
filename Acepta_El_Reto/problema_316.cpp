#include <iostream>

using namespace std;

int main() {

	int x;
	int n;
	int aux;
	int sum;
	int osum;
	int fin;
	int ofin;
	int ini;
	int oini;

	cin >> x;

	while (x--) {

		cin >> n;

		ini = 1;
		fin = n;
		sum = -10000;
		osum = -10000;

		for (int i = 1; i <= n; i++) {

			cin >> aux;

			if (aux >= (sum + aux)) {

				ini = fin = i;
				sum = aux;

			}
			else {

				fin++;
				sum += aux;

			}

			if (sum > osum) {

				oini = ini;
				ofin = fin;
				osum = sum;

			}

			else if ((sum == osum) && ((fin - ini) < (ofin - oini))) {

				oini = ini;
				ofin = fin;

			}

		}

		cout << oini << " " << ofin << "\n";

	}

	return 0;
}