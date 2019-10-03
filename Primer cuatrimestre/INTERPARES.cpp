#include <iostream>
using namespace std;

const int MAX = 10000;
typedef int Vector[MAX];

void compute(Vector v, int &interimpar, int &interpar, const int longitud);

int main() {
	Vector v;
	int longi, i = 0, interpar, interimpar, p;

	cin >> longi;

	while (longi > 0) {

		p = longi - 1; // to save it

		while (longi > 0) {
			cin >> v[i];
			i++;
			longi--;
		}
		interpar = 0, interimpar = 0;
		compute(v, interimpar, interpar, p);

		cout << interpar << " " << interimpar << endl;

		//clean the array

		for (int i = 0; i < MAX; i++) {
			v[i] = -1;
		}
		i = 0;
		cin >> longi;
	}
	return 0;
}

void compute(Vector v, int &interimpar, int &interpar, const int longitud) {
	int p = 0;

	while (p < longitud) {
		if (p > 0 && p < longitud) {
			if (v[p - 1] % 2 == 0 && v[p + 1] % 2 == 0) {
				interpar++;
			}
			else if (v[p - 1] % 2 == 1 && v[p + 1] % 2 == 1) {
				interimpar++;
			}
		}
		p++;
	}

}