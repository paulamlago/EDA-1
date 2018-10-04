#include <iostream>

int colaValida(int n, int v[10000]) {

	int ret = 0;
	bool valid = true, par = false;
	int i = n - 1;

	while (valid && 0 <= i) {

		if (v[i] % 2 != 0 && !par)
			ret++;

		else if (v[i] % 2 == 0)
			par = true;

		else
			valid = false;
		

		i--;
	}

	if (!valid)
		ret = -1;

	return ret;
}

int main() {

	int x, n, ret;
	int v[10000];

	std::cin >> x;

	while (x--) {

		std::cin >> n;

		for (size_t i = 0; i < n; i++) {

			std::cin >> v[i];

		}

		ret = colaValida(n, v);

		if (ret >= 0)
			std::cout << "SI " << n - ret << "\n";
		else
			std::cout << "NO\n";

	}

	getchar();
	getchar();

	return 0;
}