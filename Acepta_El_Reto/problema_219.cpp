#include <iostream>

// { Pre: 0 <= n < longitud(v) }
int nPares(int n, int v[10000]) /* {return ret} */ {

	int cont = 0;

	for (size_t i = 0; i < n; i++) {

		if ((v[i] % 2) == 0)
			cont++;

	}

	return cont;

}

// { Post: ret = #i : 0 <= i < n : v[i] % 2 = 0 }

int main() {

	int x, n, ret;
	int v[10000];

	std::cin >> x;

	while (x--) {

		std::cin >> n;

		for (size_t i = 0; i < n; i++) {

			std::cin >> v[i];

		}

		ret = nPares(n, v);

		std::cout << ret << "\n";

	}

	getchar();
	getchar();

	return 0;
}