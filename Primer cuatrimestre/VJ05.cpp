#include <iostream>
using namespace std;

int tachar(int *v, int a, int b, int number);

int main() {
	int casos, nc, numero, x = 0, sol;

	cin >> casos;

	while (casos > 0) {
		cin >> nc;
		cin >> numero;

		int *carton = new int[nc];

		nc--;

		x = 0;
		while (x <= nc) {
			cin >> carton[x];
			x++;
		}

		sol = tachar(carton, 0, nc, numero);

		if (sol == -1) {
			cout << "NO";
		}
		else {
			cout << carton[sol];
		}
		cout << endl;
		casos--;
	}

	return 0;
}

int tachar(int *v, int a , int b, int number) {
	int p, m;

	if (a > b) {
		p = -1;
	}

	else {
		m = (a + b) / 2;

		if (v[m] == number + m) {
			p = m;
		}

		else if (v[m] < number + m) {
			p = tachar(v, m + 1, b, number);
		}

		else{
			p = tachar(v, a, m - 1, number);
		}
	}

	return p;
}