#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;

// { Pre: 0 <= n <= longitud(v) }

int nPares(int n, int v[10000]) /* {return ret} */ {

	int i = 0;
	int ret = 0;

	// Invariante: { (0 <= i <= n) ^ (ret = #j : 0 <= j < i : v[j] % 2 = 0 ) }
	// Cota : C = n - i

	while (i != n) {

		// { (0 <= i <= n) ^ (ret = #j : 0 <= j < i : v[j] % 2 = 0 ) ^
		// (i != n) }

		if (!(v[i] % 2))
			ret++;

		// { (0 <= (i + 1) <= n) ^ (ret = #j : 0 <= j < (i + 1) : v[j] % 2 = 0 ) }
		i++;
		// { (0 <= i <= n) ^ (ret = #j : 0 <= j < i : v[j] % 2 = 0 ) }

	}

	return ret;

}

// { Post: ret = #j : 0 <= j < n : v[j] % 2 = 0 }

int main() {

	int x, n, ret, aux;
	int v[10000];

	scanf("%d", &x);

	while (x--) {

		scanf("%d", &n);

		for (size_t i = 0; i < n; i++) {

			scanf("%d", &aux);
			v[i] = aux;

		}

		ret = nPares(n, v);

		printf("%d\n", ret);

	}

	getchar();
	getchar();

	return 0;
}


/*

Solución AER

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;

int main() {

	int x, n, ret, aux;

	scanf("%d", &x);

	while (x--) {

		scanf("%d", &n);

		ret = n;
		while (n--) {

			scanf("%d", &aux);
			ret -= (aux & 1);

		}

		printf("%d\n", ret);

	}

	return 0;
}

*/