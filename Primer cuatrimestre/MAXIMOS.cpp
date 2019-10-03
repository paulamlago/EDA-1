#include <iostream>
using namespace std;

const int MAX = 20000;
typedef int tArray[MAX];

int max(const tArray &v, int &num);

int main(){
	int casos, num, i, sol;
	tArray v;

	cin >> casos;

	while (casos > 0) {
		cin >> num;
		i = 0;

		while (i < num) {
			cin >> v[i];
			i++;
		}

		sol = max(v, num);

		cout << sol << " " << num << endl;
		
		casos--;
	}

	return 0;
}

//{longitud(v) = num}
//int max(int v[], int num) return max
// {Ei: 0 <= i < num: (Vx: 0 <= x < num): v[i] > v[x]}

int max(const tArray &v, int &num) {
	int max = v[0], i = 0, counter = 0;

	while (i < num) {
		if (v[i] > max) {
			max = v[i];
			counter = 1;
		}
		else if (v[i] == max) {
			counter++;
		}

		i++;
	}

	num = counter;
	return max;
}