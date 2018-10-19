#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

	int n, a, aux;
	scanf("%d", &n);

	while (n != 0) {

		a = sqrt(n);

		while ((n % a) > 0)
			a--;

		aux = n / a;
		printf("%d\n", aux);
		scanf("%d", &n);

	}

	return 0;
}