#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <string>

using namespace std;

int alg(string str, int x) {

	int ret = 0;
	int sum = (str[0] - 48);
	int ini = 0;
	int i = 0;

	while (ini < str.length() && i < str.length()) {

		if (sum < x) {

			i++;
			sum += (str[i] - 48);

		}
		else if (sum == x) {

			ret++;
			sum -= (str[ini] - 48);
			ini++;

		}

		else {

			sum -= (str[ini] - 48);
			ini++;

		}

	}

	return ret;

}

int main() {

	int n;
	int x;
	int trash;
	string str;
	int aux;

	scanf("%d", &n);

	while (n--) {

		scanf("%d", &x);
		scanf("%c", &trash);
		getline(cin, str);

		aux = alg(str, x);
		printf("%d\n", aux);

	}

	return 0;
}