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

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}

long long int merge(vector<int> & v, vector<int> & aux2, vector<int> & aux) {

	long long inv = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i < v.size() && j < aux2.size()) {

		if (v[i] <= aux2[j]) {

			aux[k] = v[i];
			inv += j;
			++i;

		}
		else {

			aux[k] = aux2[j];
			++j;

		}

		++k;

	}

	while (i < v.size()) {

		aux[k] = v[i];
		inv += j;
		++i;
		++k;

	}

	while (j < aux2.size()) {

		aux[k] = aux2[j];
		++j;
		++k;

	}
	
	return inv;

}

long long mergeSort(vector<int> & v, vector<int> & aux, int a, int b, int c) {

	long long inv = 0;

	if (b - a <= 1) {
		aux[0] = v[a];
		return inv;
	}

	vector<int> aux2(c - a);
	vector<int> aux3(b - c);

	inv += mergeSort(v, aux2, a, c, (a+c)/2);
	inv += mergeSort(v, aux3, c, b, (c+b)/2);

	inv += merge(aux2, aux3, aux);

	return inv;

}

int main() {

	int n;
	int i;
	long long int out_;

	in(n);

	while (n) {

		vector <int> v(n);
		vector <int> aux(n);

		i = 0;
		while (i < n) {

			in(v[i]);
			++i;

		}

		out_ =  mergeSort(v, aux, 0, v.size(), v.size()/2);
		printf("%lld", out_);
        putchar_unlocked('\n');

		in(n);

	}

	return 0;

}