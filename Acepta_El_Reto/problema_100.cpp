#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	string a, b;
	int n, aux;
	int num;

	cin >> num;

	while (num--) {

		cin >> a;

		n = 0;

		while (a != "6174") {

			while (a.length() != 4)
				a.insert(0, "0");

			sort(a.begin(), a.end());

			if (a[0] == a[3]) {

				n = 8;
				break;

			}

			b = a;

			sort(b.begin(), b.end(), greater<char>());

			aux = stoi(b) - stoi(a);

			if (aux == 0) {
				n = 8;
				break;
			}

			a = to_string(aux);

			n++;
		}

		cout << n << "\n";

	}

	getchar();
	getchar();

	return 0;
}