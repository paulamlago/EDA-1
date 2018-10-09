#include <iostream>;

using namespace std;

int main() {

	int a, b, c, d;

	while ((cin >> a >> b >> c >> d) && (a <= c) && (b <= d)) {

		cout << (c - a) * (d - b) << "\n";

	}

	return 0;
}