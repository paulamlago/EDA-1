#include <iostream>
using namespace std;

int esVidente(int *array, int n);

int main() {

	int casos, total, i, *array, p;

	cin >> casos;

	while (casos > 0) {
		cin >> total;
		array = new int[total];
		i = 0;
		while (i < total) {
			cin >> array[i];
			i++;
		}

		p = esVidente(array, total - 1);

		if (p == -1) {
			cout << "No";
		}

		else {
			cout << "Si " << p; 
		}

		cout << endl;

		delete[] array;
		casos--;
	}

	return 0;
}

int esVidente(int *array, int n) {
	int p = n, accu =0;
	while (p >= -1) {
		if (array[p] == accu) {
			return p;
		}
		accu += array[p];
		p--;
	}
	return -1;
}