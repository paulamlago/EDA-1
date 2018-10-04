#include <iostream>
#include <string>

int main() {

	std::string aux;

	while (std::cin >> aux) {

		for (int i = 0; i < aux.size(); i++) {

			std::cout << aux[i];

			if (i != aux.size() - 1)
				std::cout << "0";

		}

		std::cout << "\n";

	}

	return 0;
}