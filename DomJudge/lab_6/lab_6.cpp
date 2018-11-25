#include <iostream>
#include <string>

using namespace std;
//a = b = 2
//k = 0
//o(log n)
int solve(const string str[], int ini, int fin) {

	int med;

	if (ini != fin) {

		if (str[ini] == str[fin])
			return 1;

		else {

			med = (fin + ini) / 2;
			if (str[med] == str[med + 1])
				return (solve(str, ini, med) + solve(str, med + 1, fin)) - 1;
			else
				return solve(str, ini, med) + solve(str, med + 1, fin);

		}
	}
	else
		return 1;

}

int main() {

	int n;
	string str[10000];

	while (cin >> n && n) {

		int aux = n;
		int i = 0;
		while (aux--) {

			cin >> str[i];
			++i;

		}

		cout << solve(str, 0, n - 1) << "\n";

	}

	return 0;
}