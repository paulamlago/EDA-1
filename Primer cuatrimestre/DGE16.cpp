#include <iostream>
using namespace std;

int sumAllButMax(int *v, int n);

int main() {
	int *v, casos, total, i;

	cin >> casos;
	while (casos > 0) {
		cin >> total;
		v = new int[total];
		i = 0;
		while (i < total) {
			cin >> v[i];
			i++;
		}

		cout << sumAllButMax(v, total - 1) << endl;

		casos--;
	}

	return 0;
}


// n > 0
// fun sumAllButMax(int *v, int n) return s
// Q = {s: Zi: 0 <= i < n A v[i] != maximum(v, n): v[i]}
//maximum(v, n) = max: 0 <= i < n: v[i];

int sumAllButMax(int *v, int n) {
	int s = 0, max = 0, count = 0;

	while (n >= 0) { //1
		s += v[n]; //3
											//caso peor: 10n + 1 COMPLEJIDAD LINEAL
		if (v[n] == max) {
			count++;
		}
		else if (v[n] > max) { //2
			max = v[n]; //2			//5
			count = 1;//1
		}

		n--; //1
	}

	return s - (count * max);
}