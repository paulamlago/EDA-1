#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int x, y;
	int sum;

	while ((cin >> x) && (x >= 0)) {

		sum = 0;

		while (cin >> y && y != -1) {

			sum += abs(abs(y) - x);
			x = abs(y);

		}

		cout << sum << "\n";

	}

	return 0;
}