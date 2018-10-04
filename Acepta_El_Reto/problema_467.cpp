#include <iostream>
#include <string>
using namespace std;


bool casoPrueba(string palabra1, string palabra2) {

	bool ret = false;
	int i = 0;

	while (palabra1[i]) {

		palabra1[i] = tolower(palabra1[i]);
		i++;

	}

	i = 0;
	while (palabra2[i]) {

		palabra2[i] = tolower(palabra2[i]);
		i++;

	}

	if (palabra1 == palabra2)
		ret = true;

	return ret;
}



int main() {

	int numCasos;
	string palabra1, palabra2, esp;

	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {

		cin >> palabra1 >> esp >> palabra2;

		if (casoPrueba(palabra1, palabra2))
			cout << "TAUTOLOGIA\n";

		else
			cout << "NO TAUTOLOGIA\n";

	}
	return 0;
}