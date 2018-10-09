#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	float a, b, c;

	cin >> n;

	while (n--) {

		cin >> a >> b >> c;

		cout << ceil(c / (a * b)) << "\n";

	}

	return 0;
}