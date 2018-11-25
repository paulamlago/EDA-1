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

int numCortes(unsigned int nEslabones, unsigned int f) {

	if (nEslabones <= (2 * f))
		return 0;

	int ss = nEslabones / 3;
	int ls = nEslabones - ss;

	return (1 + numCortes(ss, f) + numCortes(ls, f));

}

int main() {

	unsigned int nEslabones, fuerza, aux;

	in(fuerza);
	in(nEslabones);

	while (fuerza) {

		aux = numCortes(nEslabones, fuerza);
      out(aux);

		in(fuerza);
		in(nEslabones);

	}

	return 0;

}