#include <iostream>

using namespace std;

int main() {

	int max;
	int i;
	int j;
	int n[100000];
	int result;

	while (cin >> max && max != 0) {

		result = 1;
		i = 0;

		while (max--) {

			cin >> n[i];
			i++;

		}

		max = i;
		i--;
		j = max - 2;

		while (i > 0) {

			if (n[j] <= n[i]) {

				if (j > 0) {
					j--;
				}
				else
					i = 0;
			}

			else {

				result++;
				i = j;
				j--;

			}

		}

		cout << result << endl;

	}

	return 0;
}