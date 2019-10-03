#include <iostream>
using namespace std;

const int MAX = 10000;
typedef int temper[MAX];

void pyv(const temper &t, int &p, int &v, const int lenght);

int main() {
	int casos, lenght,i = 0, picos, valles;
	temper t;

	cin >> casos;

	while (casos > 0) {
		i = 0;
		cin >> lenght;
		while (i < lenght) {
			cin >> t[i];
			i++;
		}
		picos = 0, valles = 0;

		pyv(t, picos, valles, lenght);

		cout << picos << " " << valles << endl;

		// clean the array
		
		for (int i = 0; i < lenght; i++) {
			t[i] = -60;
		}

		casos--;
	}

	return 0;
}

// Q= {p >= 0, v >= 0, len > 0}
// pyv(t[], p, v}
// S= {E i: 0 < i < lenght. t[i - 1] > t[i], t[i] < t[i + 1]: v++. t[i - 1] < t[i], t[i] > t[i + 1]: p++}
void pyv(const temper &t, int &p, int &v, const int lenght) {
	int i = 0;

	while (i < lenght - 1) {
		if (i > 0) {
			if (t[i - 1] > t[i] && t[i] < t[i + 1]) {
				v++;
			}
			else if (t[i - 1] < t[i] && t[i] > t[i + 1]) {
				p++;
			}
		}
		i++;
	}

}