#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	long long int n, aux;
	int nd;

	while (cin >> n) {

		nd = 0;
		aux = n;
		while (aux > 0) {

			aux /= 10;
			++nd;

		}

		while (nd && !(n % nd)) {

			n /= 10;
			--nd;

		}

        // Usar putchar() para compilar en Visual pijoStudio

		if (!nd) {
			putchar_unlocked('P');
			putchar_unlocked('O');
			putchar_unlocked('L');
			putchar_unlocked('I');
			putchar_unlocked('D');
			putchar_unlocked('I');
			putchar_unlocked('V');
			putchar_unlocked('I');
			putchar_unlocked('S');
			putchar_unlocked('I');
			putchar_unlocked('B');
			putchar_unlocked('L');
			putchar_unlocked('E');
			putchar_unlocked('\n');
		}
		else {
			putchar_unlocked('N');
			putchar_unlocked('O');
			putchar_unlocked(' ');
			putchar_unlocked('P');
			putchar_unlocked('O');
			putchar_unlocked('L');
			putchar_unlocked('I');
			putchar_unlocked('D');
			putchar_unlocked('I');
			putchar_unlocked('V');
			putchar_unlocked('I');
			putchar_unlocked('S');
			putchar_unlocked('I');
			putchar_unlocked('B');
			putchar_unlocked('L');
			putchar_unlocked('E');
			putchar_unlocked('\n');
		}

	}

	return 0;
}
