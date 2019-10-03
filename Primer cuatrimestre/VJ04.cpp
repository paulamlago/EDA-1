#include<iostream>
using namespace std;

int searchMissingNumber(int *v, int a, int b, int x);

int main() {
	int casos, n1, n2, x, i, sol;
	cin >> casos;

	while (casos > 0) {
		cin >> n1;
		cin >> n2;

		int *presos = new int[n2 - n1];

		x = n1;
		i = 0;

		while (x < n2) {
			cin >> presos[i];

			i++;
			x++;
		}

		sol = searchMissingNumber(presos, n1, n2, 0);

		cout << sol << endl;

		casos--;
	}

	return 0;
}


int searchMissingNumber(int *v, int a, int b, int x) {
	int d;

	if (a < b){
		d = v[x + 1] - v[x];
		if (d > 1) {
			return a + 1;
		}
		else {
			return searchMissingNumber(v, a + 1, b, x + 1);
		}
	}

	return 0;
}