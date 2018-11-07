#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int F, C;
char grid[100][100];
int nextf[] = { 1, 0, -1, 0 };
int nextc[] = { 0, -1, 0, 1 };

int floodfill(int f, int c) {

	if (f < 0 || f >= F || c < 0 || c >= C) 
		return 0;

	if (grid[f][c] != '#')
		return 0;

	int ret = 1;

	grid[f][c] = ' ';	// "vaciamos" la casilla ya comprobada

	for (int i = 0; i < 4; i++)
		ret += floodfill(f + nextf[i], c + nextc[i]);

	return ret;

}

int main() {

	while (cin >> F >> C) {

		cin.get();
		for (int i = 0; i < F; i++) {

			string s; 
			getline(cin, s);

			for (int j = 0; j < C; j++)
				grid[i][j] = s[j];

		}

		int ccMaxSize = 0;

		for (int i = 0; i < F; i++)
			for (int j = 0; j < C; j++)
				ccMaxSize = max(ccMaxSize, floodfill(i, j));

		cout << ccMaxSize << endl;
	}

	return 0;

}