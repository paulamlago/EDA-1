#include <iostream>
using namespace std;

const int MAX = 100000;
typedef int tBanco[MAX];

int suma(tBanco &b, int max);
int cuantas(tBanco &b, int max, int sumaTotal);

int main() {
	int num,x;
	tBanco b;

	cin >> num;

	while (num > 0) {
		x = 0;
		while (x < num) {
			cin >> b[x];
			x++;
		}

		cout<< cuantas(b, num, suma(b, num)) << endl;

		cin >> num;
	}

	return 0;
}

int suma(tBanco &b, int max) {
	int x = 0;

	for (int i = 0; i < max; i++) {
		x += b[i];
	}

	return x;
}


int cuantas(tBanco &b, int max, int sumaTotal) {
	int sum = 0, x = 0, count = 0;

	if (sumaTotal == 0) {
		count++;
	}

	while (x < max) {
		sum += b[x];
		sumaTotal = sumaTotal - b[x];
		if (sum == sumaTotal) {
			count++;
		}
		x++;
	}

	return count;
}