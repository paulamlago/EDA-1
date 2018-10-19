#include <iostream>
#include <string>

using namespace std;


// Complejidad : O(n)  -> En el peor de los casos sería complejidad 2n
// { Pre : k >= 0 ^ 1 <= str.length() <= 10^6 }

int maxProblemas(string v, int k) /* return ret */ {

	int ret = 0;
	int ini = 0;
	int fin = 0;
	int Bcont = 0;

	// {Invariante : (0 <= ini <= fin <= v.length) ^ (0 <= Bcont <= k) ^
	// (ret = max i, j : ini <= i < j < fin) ^ const(v, i, j) <= k : j - i }
	//	const(v, i, j) = (#n : i <= n < j : v[n] = 'B'))
	// }
	// { Cota : str.lenght() - fin }

	while (fin < v.length()) {

		if (v[fin] == 'B') {

			++Bcont;

		}
		if (Bcont > k) {

			if (v[ini] == 'B')
				--Bcont;

			++ini;

		}
		else
			++ret;

		++fin;
	
	}

	return ret;
}

// { Pos : ret = max i, j : 0 <= i < j < v.length() ^ const(v, i, j) <= k : j - i }
//	const(v, i, j) = (#n : i <= n < j : v[n] = 'B')

int main() {
	int k;
	string str;
	
	

	while (cin >> k >> str) {

		cout << maxProblemas(str, k) << "\n";

	}

	system("PAUSE");

	return 0;
}