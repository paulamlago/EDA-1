#include <iostream>

using namespace std;

int main() {

	int n, p;

	while ((cin >> n >> p) && ((n > 0) || (p > 0))) {

		if (n <= p)
			cout << "YES\n";

		else
			cout << "NO\n";

	}

	return 0;
}