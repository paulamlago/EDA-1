#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//#####################################
//  # COMENTAR EN ACEPTA EL RETO #
//#####################################

#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define scanf scanf_s

//#####################################

string str = "";

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}

void escribe(int c, int v, string prefijo) {

	if (!c && !v) {
		str +=  prefijo + " ";
		return;
	}

	else {

		if (c) {

			escribe(c - 1, v, prefijo + "C");

		}

		if (v) {

			escribe(c, v - 1, prefijo + "V");

		}

	}

}

int main() {

	int n;
	int c;
	int v;

	in(n);
	
	while (n--) {

		in(c);
		in(v);

		escribe(c, v, "");

		for (int i = 0; i < str.size() - 1; i++) {

				putchar_unlocked(str[i]);

		}

		putchar_unlocked('\n');

		str = "";

	}

	return 0;
}