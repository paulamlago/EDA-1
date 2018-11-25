#include <iostream>

using namespace std;

const int MAX = 31;
typedef int tMatrix[3][3];

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

void ini_calc(tMatrix &calc) {

	calc[0][0] = 7;
	calc[0][1] = 8;
	calc[0][2] = 9;
	calc[1][0] = 4;
	calc[1][1] = 5;
	calc[1][2] = 6;
	calc[2][0] = 1;
	calc[2][1] = 2;
	calc[2][2] = 3;

}

bool wins(const tMatrix &calc, int sum, int n, int x, int y) {

	if (sum >= MAX)
		return false;

	int i = 0;
	while (i < 3) {

		int j = 0;
		while (j < 3) {

			if (i != x && j == y) {

				if (wins(calc, sum + calc[i][j], calc[i][j], i, j))
					return false;

			}

			if (i == x && j != y) {

				if (wins(calc, sum + calc[i][j], calc[i][j], i, j))
					return false;

			}

			++j;

		}

		++i;

	}

	return true;

}

void res() {

	int sum, n, x, y;
	tMatrix calc;

	in(sum);
	in(n);
	ini_calc(calc);

	switch (n) {

	case 7: x = y = 0; break;
	case 8: x = 0; y = 1; break;
	case 9: x = 0; y = 2; break;
	case 4: x = 1; y = 0; break;
	case 5: x = y = 1; break;
	case 6: x = 1; y = 2; break;
	case 1: x = 2; y = 0; break;
	case 2: x = 2; y = 1; break;
	case 3: x = y = 2; break;

	}

	if (wins(calc, sum, n, x, y)) {

		putchar_unlocked('P');
		putchar_unlocked('I');
		putchar_unlocked('E');
		putchar_unlocked('R');
		putchar_unlocked('D');
		putchar_unlocked('E');
		putchar_unlocked('\n');

	}
	else {

		putchar_unlocked('G');
		putchar_unlocked('A');
		putchar_unlocked('N');
		putchar_unlocked('A');
		putchar_unlocked('\n');
		
	}

}

int main() {

	int n;

	in(n);
	while (n--) {
		res();
	}

	return 0;
}