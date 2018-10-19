#include <iostream>

int main() {

	int x;
	int n;
	int max;

	while  (std::cin >> x) {

		max = 0;

		while (x--) {

			std::cin >> n;

			if (n > max)
				max = n;

		}

		std::cout << max << "\n";

	}

	return 0;
}