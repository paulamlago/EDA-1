#include <iostream>
#include <cmath>
using namespace std;

int log(int b, int n, int r);

int main() {
	int casos, b, n, r;

	cin >> casos;

	while (casos > 0) {
		cin >> b;
		cin >> n;

		r = log(b, n, 1);

		cout << r << endl;
		casos--;
	}

	return 0;
}

int log(int b, int n, int r) {

	if (b > n) {
		return 0;
	}

	else {
		if (pow(b, r) <= n && pow(b, r + 1) > n) {
			return r;
		}
		else {
			return log(b, n, r + 1);
		}
	}
}