// Diego Atance Sanz - 70901140Y

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//	{ O(n) }
/*  { Pre: 0 <= n < long(v) ^ (0 <= k < n) }
	El vector deberá ser booleano (si se introduce un vector no booleano, C contará todo caracter distinto de "0" como true. El algoritmo funcionaría.
	k puede tomar cualquier valor, si es 0, mayor que n o mayor que long(v), devolverá n + 1, la precondición se establece con tal de cumplir el enunciado.
*/

int solve(bool v[], int n, int k) /* return ret */ {

	int i = 0;
	int cont = 0;
	int tam = 0;
	int ret = (n + 1);

	/*	{ I: (0 <= i < n) ^
		(cont = (#x : 0 <= x <n : v[x] = true)) ^
		(tam = (b - a) : (0 <= a <= b < i) : ((#x : a <= x <= b : v[x] = true)) ^
		(ret = (min (b - a) : (0 <= a <= b < i) : ((#x : a <= x <= b : v[x] = true) = k))) }
	*/
	//	{ Cota: n - i }

	while (i < n) {

		if (v[i]) {

			++cont;
			++tam;

		}
		else {

			if (cont)
				++tam;

		}

		if (cont == k) {

			ret = min(tam, ret);
			cont = v[i];
			tam = v[i];

		}

		++i;

	}

	return ret;

}
/*	{ Pos: ret = (min (b - a) : (0 <= a <= b < n) : ((#x : a <= x <= b : v[x] = true) = k)) }
*/


int main() {

	bool v[100];
	int n, k;

	while (cin >> n && (n + 1)) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cin >> k;

		cout << solve(v, n, k) << '\n';

	}

	return 0;
}