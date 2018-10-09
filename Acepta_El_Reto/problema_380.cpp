#include <iostream>

using namespace std;

int main (){

	int n;
	int aux;
	int sum;

	while (cin >> n && n) {

		sum = 0;

		for (int i = 0; i < n; i++) {

			cin >> aux;
			sum += aux;

		}

		cout << sum << "\n";

	}


	return 0;
}