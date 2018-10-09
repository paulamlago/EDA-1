#include <stdio.h>

using namespace std;

int main() {

	long long int n, p, a;

	while ((scanf("%lld%lld", &n, &p)) && (n >= 0) && (p >= 0)) {

		a = (2 * n) + (2 * p);
		printf("%lld\n", a);

	}

	return 0;
}