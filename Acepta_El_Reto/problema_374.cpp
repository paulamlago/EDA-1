#include <iostream>

using namespace std;

int main() {

	int n;
	long long int x;
	int min_cont, max_cont;
	long long int min, max;

	cin >> n;

	while (n--) {

		min = 0x7fffffffffffffff;
		max = min_cont = max_cont = 0;

		while (cin >> x && x != 0) {

			if (x == min) {

				min_cont++;

			}

			else if (x < min) {

				min = x;
				min_cont = 1;

			}

			if (x == max) {

				max_cont++;

			}

			else if (x > max) {

				max = x;
				max_cont = 1;

			}

		}

		cout << min << " " << min_cont << " " << max << " " << max_cont << "\n";

	}

	return 0;
}