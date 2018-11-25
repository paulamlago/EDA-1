#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
//		putchar('\n');
		return;
	}
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar_unlocked('0');
//	putchar('\n');
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

void solve(int num) {

	int res = 0;
	int b6[8];
	int j = 0;

	do {

		res = num % 6;
		b6[j] = res;
		++j;
		num /= 6;

	} while (num >= 6);
	
	if (num) {

		b6[j] = num;
		j++;

	}

	for (int i = j - 1; i >= 0; i--) {

		out(b6[i]);

	}

	putchar('\n');

}

int main() {

	int n;
	int num;

	in(n);
	while (n--) {

		in(num);;
		solve(num);

	}

	return 0;

}