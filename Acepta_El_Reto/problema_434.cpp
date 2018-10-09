#include <iostream>

using namespace std;

int main() {

	int n;
	int a;
	int b;

	cin >> n;

	while (n--) {

		cin >> a >> b;

		if (a <= b)
			cout << "ROMANCE\n";
		else
			cout << "PRINCIPIO\n";

	}

	return 0;
}