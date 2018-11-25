#include <iostream>;

// Comentar para AER

#define getchar_unlocked getchar
#define putchar_unlocked putchar

using namespace std;

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}

int main() {

	int ini, fin, n;
	int k, x;
	int i;

	in(ini);
	in(fin);
	in(n);

	while (ini && fin && n) {

		in(k);

		i = 0;
		while (i < k) {
			
			in(x);

			if (x < ini) {}

			else if (x > fin) {}

			else if (n < x)
				fin = x - 1;

			else
				ini = x;

			++i;
		}

		if (ini == fin) {

			putchar_unlocked('L');
			putchar_unlocked('O');
			putchar_unlocked(' ');
			putchar_unlocked('S');
			putchar_unlocked('A');
			putchar_unlocked('B');
			putchar_unlocked('E');
			putchar_unlocked('\n');

		}

		else {

			putchar_unlocked('N');
			putchar_unlocked('O');
			putchar_unlocked(' ');
			putchar_unlocked('L');
			putchar_unlocked('O');
			putchar_unlocked(' ');
			putchar_unlocked('S');
			putchar_unlocked('A');
			putchar_unlocked('B');
			putchar_unlocked('E');
			putchar_unlocked('\n');

		}

		in(ini);
		in(fin);
		in(n);

	}

	return 0;

}