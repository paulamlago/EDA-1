#include <string>
#include <iostream>

using namespace std;

int main() {

	string str, trash;
	int n;

	cin >> n;
	getline(cin, trash);

	while (n--) {

		getline(cin, str);

		cout << "Hola, ";

		for (int i = 4; i < str.size(); i++) {


			cout << str[i];

		}

		cout << ".\n";

	}

	return 0;
}