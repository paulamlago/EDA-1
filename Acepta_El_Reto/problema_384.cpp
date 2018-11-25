#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

long int v[500000];
set<long int> vi;
set<long int> vd;

//#####################################
//  # COMENTAR EN ACEPTA EL RETO #
//#####################################

#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define scanf scanf_s

inline void out(long int n)
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

inline void in(long int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}

bool solve(int n) {

	int m = n - 1;
	long int aux;
	set<long int>::iterator it;

	while (m) {

		if (min(v[m], *vd.begin()) != v[m] && vd.size() > 1) {
			it = vd.upper_bound(v[m]);
			--it;
			aux = *it;
		}
		else
			aux = *vd.begin();

		if (max(aux, v[m]) == v[m]) {

			if (*vi.begin() < aux)
				return 1;

		}

		vd.insert(v[m]);	// o(log(n))
		m--;
		vi.erase(v[m]);		// o(log(n))

	}

	return 0;

}

void a() {

	putchar_unlocked('E');
	putchar_unlocked('L');
	putchar_unlocked('E');
	putchar_unlocked('G');
	putchar_unlocked('I');
	putchar_unlocked('R');
	putchar_unlocked(' ');
	putchar_unlocked('O');
	putchar_unlocked('T');
	putchar_unlocked('R');
	putchar_unlocked('A');
	putchar_unlocked('\n');

}

void b() {

	putchar_unlocked('S');
	putchar_unlocked('I');
	putchar_unlocked('E');
	putchar_unlocked('M');
	putchar_unlocked('P');
	putchar_unlocked('R');
	putchar_unlocked('E');
	putchar_unlocked(' ');
	putchar_unlocked('P');
	putchar_unlocked('R');
	putchar_unlocked('E');
	putchar_unlocked('M');
	putchar_unlocked('I');
	putchar_unlocked('O');
	putchar_unlocked('\n');
	
}

int main() {

	int n;
	long aux;

	while (cin >> n) {

		int i = 0;
		while (n--) {

			in(aux);
			v[i] = aux;

			if(n > 1)
				vi.insert(aux);
			if (!n)
				vd.insert(aux);

			++i;
		}

		(solve(i - 1)) ? a() : b();

		vi.clear();
		vd.clear();

		}

	return 0;

}