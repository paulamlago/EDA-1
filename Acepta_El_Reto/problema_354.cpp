#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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

const int MAX = 200000;
typedef int vec[MAX];

int alg(vec v, int n) {

	int i = 1;
	int ret = 1;
	int alt_max = v[0];
	int alt_ninos = v[0];

	while (i < n) {

		if (v[i] > alt_max)
			alt_max = v[i];

		if (v[i] <= alt_ninos) {

			ret = i + 1;
			alt_ninos = alt_max;

		}

		i++;

	}

	return ret;

}

int main() {

	int n;
	vec v;
	int aux;

	in(n);
	while (n) {

		for (int i = 0; i < n; i++)
			in(v[i]);

		aux = alg(v, n);
		out(aux);
		in(n);

	}

	return 0;
}


/*

##################
  # CÓDIGO EN C #
##################

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

using namespace std;

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

const int MAX = 200000;
typedef int vec[MAX];

int alg(vec v, int n) {

	int i = 1;
	int ret = 1;
	int alt_max = v[0];
	int alt_ninos = v[0];

	while (i < n) {

		if (v[i] > alt_max)
			alt_max = v[i];

		if (v[i] <= alt_ninos) {

			ret = i + 1;
			alt_ninos = alt_max;

		}

		i++;

	}

	return ret;

}

int main() {

	int n;
	vec v;
	int aux;

	in(n);
	while (n) {

		for (int i = 0; i < n; i++)
			in(v[i]);

		aux = alg(v, n);
		out(aux);
		in(n);

	}

	return 0;
}

*/