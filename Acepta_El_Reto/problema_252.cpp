#include <iostream>
#include <string>
using namespace std;

bool esPalindromo(string str, int i, int f ) {
	
	if (i < f) {
		
		if (tolower(str[i]) == ' ') return esPalindromo(str, i + 1, f);
		else if (tolower(str[f]) == ' ') return esPalindromo(str, i, f - 1);
		else if (tolower(str[i]) == tolower(str[f])) return esPalindromo(str, i + 1, f - 1);
		else return false;
		
	}
	
	else return tolower(str[i]) == tolower(str[f]);
	
}

int main() {

	string str;
	getline(cin, str);

	while (str != "XXX") {

	cout << (esPalindromo(str, 0, str.length()-1) ? "SI\n" : "NO\n");
	getline(cin, str);

	}

}