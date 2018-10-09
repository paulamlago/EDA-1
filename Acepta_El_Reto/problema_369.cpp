#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

using namespace std;

int main() {

	int a;

	while ((scanf("%d", &a) && a)) {

		while (a--)
			printf("1");

		printf("\n");

	}

	return 0;
}