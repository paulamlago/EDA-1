#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;

const int MAX = 200000;
typedef int vec[MAX];

int alg(vec v, int n) {

	int i = 1;
	int ret = 1;
	int alt_max = v[0];
	int alt_ninos = v[0];

	while (i < n) {

		if (v[i] > alt_max)
			alt_max = v[i];

		if (v[i] <= alt_ninos) {

			ret = i + 1;
			alt_ninos = alt_max;

		}

		i++;

	}

	return ret;

}

int main() {

	int n;
	vec v;
	int aux;

	while (scanf("%d", &n) && n) {

		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);

		aux = alg(v, n);
		printf("%d\n", aux);

	}

	return 0;
}