#include <iostream>

using namespace std;

int main() {

	int n;
	int x;
	int aux;
	int sum;

	while (scanf("%d%d", &n, &x) && (n || x)) {

		aux = x + (((n*n) - n) / 2);

		sum = 0;

		for (int j = 0; j < n; j++) {

			sum += aux + j;

		}

		printf("%d\n", sum);

	}
	

	return 0;
}