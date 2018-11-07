#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c) {

	return (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0');

}

int solve() {

	char c;
	int x, y;

	cin >> c;

	if (!isDigit(c)) {

		x = solve();
		y = solve();

		switch (c) {

		case '+': 
			
			return x + y;
			break;

		case '-': 
			
			return x - y;
			break;

		case '*': 
		
			return x * y;
			break;

		case '/': 
			
			return x / y;
			break;
		
		}

	}

	else
		return int(c) - 48;
		
}


int main() {
	
	int n;
	string str;
	string trash;

	cin >> n;
	getline(cin, trash);

	while (n--) {

		cout << solve() << '\n';
		getline(cin, trash);
		
	}


	return 0;
}