#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;

int main() {

	int n;
	long long int v[100000];
	long long int total;
	long long int result;

	while (scanf("%lld", &n) && n != 0) {

		total = 0;

		for (int i = 0; i < n; i++) {

			scanf("%lld", &v[i]);
			total += v[i];

		}

		result = (total * (total - 1)) / 2;

		for (int i = 0; i < n; i++) {

			result -= (v[i] * (v[i] - 1)) / 2;

		}

		printf("%lld\n", result);

	}

	return 0;
}