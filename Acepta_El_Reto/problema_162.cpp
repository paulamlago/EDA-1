#include <iostream>
#include <string>

using namespace std;

int main() {

	int n;
	char c;
	string spc;
	string esc;

	while (cin >> n && n) {

		cin >> c;

		esc = c;

		for (int i = 0; i < n - 1; i++) {

			esc += c;

		}

		spc = " ";

		for (int i = 0; i < n - 1; i++) {

			spc += " ";

		}

		cout << "|";

		for (int i = 0; i < 8 * n; i++) {

			cout << "-";

		}

		cout << "|\n";

		for (int j = 0; j < 4; j++) {

			for (int j = 0; j < n; j++) {

				cout << "|";

				for (int i = 0; i < 4; i++) {

					cout << spc;
					cout << esc;

				}

				cout << "|";

				cout << "\n";

			}

			for (int j = 0; j < n; j++) {

				cout << "|";

				for (int i = 0; i < 4; i++) {

					cout << esc;
					cout << spc;

				}

				cout << "|";

				cout << "\n";

			}

		}

		cout << "|";

		for (int i = 0; i < 8 * n; i++) {

			cout << "-";

		}

		cout << "|\n";
	}

	return 0;
}