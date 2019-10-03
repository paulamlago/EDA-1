#include <iostream>
#include <string>
using namespace std;

int numOfTimes(string f, string p);

int main() {
	string frase, patron;
	getline(cin, frase);
	getline(cin, patron);

	int c = numOfTimes(frase, patron);

	cout << c;

	return 0;
}

int numOfTimes(string f, string p) {
	int x = p.length() - 1, y = f.length() - 1, counter = 0;

	while (y > 0) {
		if (f[y] == p[x]) {
			if (f[y - 1] == p[x - 1]) {
				counter++;
			}
		}
		y--;
	}

	return counter;
}