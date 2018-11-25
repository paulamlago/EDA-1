#include <iostream>
#include <string>

using namespace std;

void solve(string num) {

	int i = 0;
	int sum = 0;

	while (i < num.length() - 1){

		cout << num[i] << " + ";
		sum += (num[i] - 48);
		++i;

	}

	sum += (num[i] - 48);
	cout << num[i] << " = " << sum << "\n";

}

int main() {

	string num;

	while (cin >> num && num[0] != '-') {

		solve(num);

	}

	return 0;

}