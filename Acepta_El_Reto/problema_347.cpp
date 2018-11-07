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

int calc(int a, int b) {

	int aux, cont = 0;

	while (a >= 10 && b >= 10) {

		if (a > b) {

			cont += a / b;
			aux = a;
			a = b;
			b = aux % b;

		}

		else {

			cont += b / a;
			aux = b;
			b = a;
			a = aux % a;

		}

	}

	return cont;

}

int main() {

	int a, b, aux;

	in(a);
	in(b);
	while (a && b) {

		aux = calc(a, b);
		out(aux);
		in(a);
		in(b);

	}

	return 0;
}