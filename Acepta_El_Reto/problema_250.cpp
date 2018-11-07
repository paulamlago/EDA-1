#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

//#####################################
//  # DESCOMENTAR EN ACEPTA EL RETO #
//#####################################

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		putchar_unlocked('\n');
		return; }
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar_unlocked('0');
	putchar_unlocked('\n');
}

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}
*/

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
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



void alg(int *v, int n, int dif) {

	int cont = 0;
	int min = dif;
	int position = 0;
	int aux = dif;
	int aux2 = 0;

	while (cont < n) {

		aux -= v[cont];
		aux2 += v[cont];

		if (abs(aux2 - aux) < abs(min)) {

			position = cont + 1;
			min = abs(aux2 - aux);

		}

		cont++;

	}

	out(position);

}

int main() {

	int n;
	int aux;
	int pos;
	int neg;
	int *v = new int[1000000];

	in(n);
	while (n) {

		pos = 0;
		neg = 0;

		for (int i = 0; i < n; i++) {

			in(aux);

			if (aux >= 0)
				pos += aux;

			else
				neg += aux;

			v[i] = aux;

		}

		if ((pos + neg) == 0)
			out(0);

		else
			alg(v, n, pos + neg);

		in(n);

	}

	return 0;
}