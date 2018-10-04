#include <iostream>
#include <algorithm>

using namespace std;

// { Pre: (1 <= n <= longitud(v)) ^ ord(v, n)
// Donde:
//    ord(v, n) = P.t. k : 0 <= k <= n - 1 : v[k] <= v[k + 1]
// }

int moda(int v[], int n) /* return ret */ {

	int i = 1;
	int ret = v[0];
	int maxfreq = 1;
	int aux = 1;

	while (i < n) {

		if (v[i - 1] < v[i]) {

			aux = 1;

		}

		else {

			aux++;
			if (aux > maxfreq) {

				maxfreq = aux;
				ret = v[i];

			}
		}

		i++;
	}

	return ret;

}

// { Post: freq(v , n, v[ret]) = max i : 0 <= i < n : freq(v, n, v[i])
// Donde:
//    freq(v, n, val) = # i : 0 <= i < n : v[i] = val
// }

int main() {

	int x;
	int ret;
	int v[25000];

	while (cin >> x && x) {

		for (int i = 0; i < x; i++) {

			cin >> v[i];

		}

		sort(&v[0], &v[x]);

		ret = moda(v, x);

		cout << ret << "\n";

	}

	return 0;
}