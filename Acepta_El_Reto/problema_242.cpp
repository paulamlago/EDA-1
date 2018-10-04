#include <iostream>

using namespace std;

int main() {

	int n_paises;
	long long int array_paises[100000];
	long long int total;
	long long int result;

	while (cin >> n_paises && n_paises != 0) {

		total = 0;

		for (size_t i = 0; i < n_paises; i++) {

			cin >> array_paises[i];
			total += array_paises[i];

		}

		result = (total * (total - 1)) / 2;

		for (size_t i = 0; i < n_paises; i++) {

			result -= (array_paises[i] * (array_paises[i] - 1)) / 2;

		}

		cout << result << "\n";


	}

	getchar();

	return 0;
}