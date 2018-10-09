#include <iostream>

using namespace std;

int main() {

	long long int n, x, y;
	bool a, b;

	while (cin >>n && n > 0) {

		a = b = true;

		cin >> x;

		for (long long int i = 1; i < n; i++) {

			cin >> y;

			a = a && x < y;
			b = b && x > y;

			x = y;
		}

		cout << ((a || b) ? "DALTON" : "DESCONOCIDOS") << "\n";

	}

	return 0;
}