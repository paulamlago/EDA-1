#include <iostream>

using namespace std;

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar('0');
		putchar('\n');
		return; }
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar('0');
    putchar('\n');
}

inline void in(int &n)
{
	n = 0;
	int ch = getchar(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
	n = n * sign;
}

int casoPrueba(int v[], int n, int k) {

	int vi = 0, vf = 0;
	int vMax = 0;
	int ret = 0;
	int cont = 0;

	while (vf < n) {

		if (v[vi] == 0) {

				vi++;

		}

		else {

			if (v[vf] == 1) {

					vMax = vf - vi + 1;
					vf++;
					cont = 0;	

			}
			else {

				cont++;
				vf++;

			}

		}

		if (cont > k) {

			cont--;
			vi++;
			vf = vi;

		}

		if (vMax > ret)
			ret = vMax;

		if (vi > vf)
			vf = vi;
	}

	return ret;
}

int main() {

	int aux, aux2;
	int v[100000], n, k;

	in(n);
	in(k);
	while (n || k) {

		for (int i = 0; i < n; i++) {

			in(aux);
			v[i] = aux;

		}

		aux2 = casoPrueba(v, n, k);
		out(aux2);
		in(n);
		in(k);

	}

	return 0;
}