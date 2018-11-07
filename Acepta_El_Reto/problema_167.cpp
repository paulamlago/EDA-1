#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tinta(int l) {

	if (l == 1)
		return 4;

	return (l + tinta(l / 2)) << 2;

}

int main() {

	int l, aux;

	while (cin >> l) {
      
		aux =  tinta(l);
        printf("%d\n", aux);

	}

	return 0;
}