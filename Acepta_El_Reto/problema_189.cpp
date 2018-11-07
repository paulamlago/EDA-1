
	// VERSIÓN QUE COMBINA <vector> y <algorithm>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int n;
	int aux;
	int m;
	string action;
	int act;

	while (scanf("%d", &n) && n) {

		vector<int> w;

		while (n--) {

			scanf("%d", &aux);
			w.push_back(aux);

		}

		scanf("%d", &m);

		while (m--) {

			cin >> action;
			scanf("%d", &act);

			if (action == "EMBARQUE") {

				w.erase(remove(w.begin(), w.end(), act), w.end());
				
				printf("%d\n", w.size());


			}
			else {

				printf("%d\n", w[act - 1]);

			}

		}

		printf("*\n");

	}

	return 0;
}

/*

	VERSIÓN CON LAS ELIMINACIONES MANUALES

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<int> w;
	int n;
	int aux;
	int m;
	string action;
	int act;
	int i;
	int cont;

	while (scanf("%d", &n) && n) {

		while (n--) {

			scanf("%d", &aux);
			w.push_back(aux);

		}

		scanf("%d", &m);
		while (m--) {

			cin >> action;
			scanf("%d", &act);

			if (action == "EMBARQUE") {

				i = 0;
				cont = 0;

				while (i < w.size()) {

					if (w[i] == act) {
						cont++;
					}
					else {
						w[i - cont] = w[i];
					}
					++i;

				}

				for (int k = 0; k < cont; k++) {
					w.pop_back();
				}

				printf("%d\n", w.size());

			}
			else {

				printf("%d\n", w[act - 1]);

			}

		}

		w.clear();

		printf("*\n");

	}

	return 0;
}
*/