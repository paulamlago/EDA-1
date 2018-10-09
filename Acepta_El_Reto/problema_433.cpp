#include <iostream>

using namespace std;

int main (){

	int n;
	int i;
	int sum;
	int cont;

	while (cin >> n && n) {

		cont  = sum = i = 1;

		while (n > sum) {

			i++;
			sum += i;
			cont++;

		}

		cout << cont << "\n";

	}

	return 0;
}