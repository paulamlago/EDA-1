#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int a;
	int i;
	long long int b;

	while ((cin >> a >> b) && (a != 0) && (b != 0)) {

		i = 0;
		b *= 1000000;

		while (a * pow(2, i) < b)
			i++;

		cout << i << "\n";

	}

	return 0;
}