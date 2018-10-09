#include <iostream>

using namespace std;

int main() {

	int h, c, aux;

	while ((cin >> h >> c) && (c != 0) && (h != 0)) {

		aux = h / c;

		if (!aux)
			cout << "10\n";

		else

			if ((h % c) == 0)
				cout << 10 * aux << "\n";
			
			else
				cout << 10 * (aux + 1) << "\n";

	}

	return 0;
}