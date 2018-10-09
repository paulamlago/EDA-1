#include <iostream>
#include <string>

using namespace std;

bool alg() {

	int x, y, cont = 0;
	bool prim = true;

	cin >> x;

	if (!x)
		return false;

	cin >> y;

	while (x) {

		if ((x + 1) == y)
			cont++;

		else {

			if (!prim)
				cout << ",";

			if (cont > 0) {

				cout << x - cont << "-" << x;
				cont = 0;

			}

			else
				cout << x;

			prim = false;

		}

		x = y;

		if (y > 0)
			cin >> y;

	}

	cout << "\n";

	return true;

}

int main() {

	while (alg()) {};

	return 0;
}