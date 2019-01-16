// Diego Atance Sanz - 70901140Y

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//	{ O(n^(k + 1) } -> reducimos el tamaño de datos por subtracción, elemento a elemento y hacemos 1 llamada recursiva, al ser de complejidad O(0) cada llamada, la complejidad final será:
//	{ O(n) }

bool solve(int n, int &sum, int &digits) {

	if (n < 10) {
		sum = n;
		digits = 1;
		return 1;
	}

	bool ok = solve(((n - (n % 10)) / 10), sum, digits);

	sum += (n % 10);
	++digits;

	return ok && !(sum % digits);

}

int main() {

	int n;
	int s = 0, d = 1;

	while (cin >> n && n)
		solve(n, s, d) ? (cout << "SI\n") : (cout <<"NO\n");

	return 0;
}