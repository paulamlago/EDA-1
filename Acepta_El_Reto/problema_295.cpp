#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int K = 31543;

//#####################################
//  # COMENTAR EN ACEPTA EL RETO #
//#####################################

#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define scanf scanf_s

//#####################################

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		putchar_unlocked('\n');
		return;
	}
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

int solve(const int a, int b) {

	if (!b)
		return 1;

	if (b % 2)
		return (((solve(a, (b - 1) / 2) * solve(a, (b - 1) / 2)) % K) * a) % K;
	
	else 
		return (solve(a, b / 2) * solve(a, b / 2)) % K;
		
}

int main() {

	int a;
	int b;

	in(a);
	in(b);

	while (a || b) {

	//	int aux = solve(a % K, b);
		out(solve(a % K, b));

		in(a);
		in(b);
	
	}

	return 0;
}

/*

Version 1 linea

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int K = 31543;

//#####################################
//  # COMENTAR EN ACEPTA EL RETO #
//#####################################

#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define scanf scanf_s

//#####################################

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		putchar_unlocked('\n');
		return;
	}
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

int solve(const int a, int b) {

	return (!b)? 1 : (b % 2)? (((solve(a, (b - 1) / 2) * solve(a, (b - 1) / 2)) % K) * a) % K : (solve(a, b / 2) * solve(a, b / 2)) % K;
		
}

int main() {

	int a;
	int b;

	in(a);
	in(b);

	while (a || b) {

		out(solve(a % K, b));

		in(a);
		in(b);
	
	}

	return 0;
}
*/