#include <string>
#include <iostream>

using namespace std;

int main() {

	string a, b = "";
	int desp, i, aux;

	while (b != "FIN") {

		getline(cin, a);

		b = "";

		desp = 112 - a[0];

		for (size_t i = 1; i < a.length(); i++) {

			// if ((a[i] < 65) || (a[i] > 122) || ((90 < a[i]) && (a[i] < 97)))
			if (!(isalpha(a[i])))
				b += a[i];

			else {

				int aux = a[i] + desp;

				if ((a[i] <= 90) && (aux > 90))
					b += char(aux - 26);

				else if ((a[i] <= 90) && (aux < 65))
					b += char(aux + 26);

				else if ((a[i] >= 97) && (a[i] <= 122) && (aux > 122))
					b += char(aux - 26);

				else if ((a[i] >= 97) && (a[i] <= 122) && (aux < 97))
					b += char(aux + 26);

				else
					b += char(aux);
			}

		}

		// cout << b << "\n";

		if (b != "FIN") {

			i = 0;
			aux = 0;
			while (i < b.length()) {

				if ((tolower(b[i]) == 'a') || (tolower(b[i]) == 'e') || (tolower(b[i]) == 'i') || (tolower(b[i]) == 'o') || (tolower(b[i]) == 'u'))
					aux++;

				i++;
			}

			cout << aux << "\n";

		}
	}

	getchar();
    getchar();

	return 0;
}