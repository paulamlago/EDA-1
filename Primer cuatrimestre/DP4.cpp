#include <iostream>
using namespace std;

const int MAX = 100000;
typedef int tMesetas[MAX];

int findLangest(tMesetas &m, int b, int &x);

int main() {
	int elem, i;
	tMesetas m;

	cin >> elem;

	while (elem != 0){
		i = 0;

		while (i < elem) {
			cin >> m[i];
			i++;
		}

		i = 0;

		int sol = findLangest(m, elem, i);

		cout << i << " " << i + sol - 1 << endl;

		cin >> elem;
	}

	return 0;
}


int findLangest(tMesetas &m, int b, int &x) {
	int i = 0, max = 1, g = 1;

	while (i < b) {
		if (i > 0 && m[i] == m[i - 1]) {
			max++;
		}
		else if (g < max) {
			x = i - max;
			g = max;
			max = 1;
		}
		else {
			max = 1;
		}
		i++;
	}

	if (g < max) {
		x = i - max;
		g = max;
	}

	return g;
}