#include <iostream>

using namespace std;

void fact();

int main() {

	int num_casos, n;

	cin >> num_casos;

	while (num_casos--) {

		fact(n);

	}

	return 0;
}

void fact(int n){

cin >> n;

		if (n == 0)
			cout << "1 \n";
		else if (n == 3)
			cout << "6 \n";
		else if (n < 5)
			cout << n << "\n";
		else
			cout << "0 \n";

}