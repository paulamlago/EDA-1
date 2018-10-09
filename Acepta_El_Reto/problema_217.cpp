#include <iostream>

using namespace std;

int main() {

	int n;

	while (scanf("%d", &n) && n) {

		if (n % 2)
			printf("IZQUIERDA\n");
		else
			printf("DERECHA\n");

	}

	return 0;
}