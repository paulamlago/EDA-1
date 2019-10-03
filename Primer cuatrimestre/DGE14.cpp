#include <iostream>
using namespace std;

int robo(int *v, int total, int tiempo, int &pos);

int main() {
	int casos, total, vagones, i;

	cin >> casos;

	while (casos > 0) {
		cin >> total >> vagones;
		i = 0;

		int *v = new int[total];

		while (i < total) {
			cin >> v[i];
			i++;
		}

		int pos = 0, sol = robo(v, total, vagones, pos);


		cout << pos  << " " << sol << endl;
		casos--;
	}

	return 0;
}

int robo(int *v, int total, int tiempo, int &pos) {
	int count = 0, count1, i =0, x;

	while (i < total - (tiempo -1)) {
		count1 = 0;
		x = 0;
		while (x < tiempo && i < total) {
			count1 += v[i];
			i++;
			x++;
		}

			if (count1 >= count) {
				pos = i - (tiempo);
				count = count1;
			}
		i = i - (tiempo - 1);
	}

	return count;
}