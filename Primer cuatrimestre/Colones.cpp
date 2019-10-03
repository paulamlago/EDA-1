#include <iostream>
using namespace std;

int colado(int *v, int num);

int main() {
	int casosDePrueba, numEl, i, colados;

	cin >> casosDePrueba;
	
	while (casosDePrueba > 0) {
		cin >> numEl;

		int *v = new int[numEl];

		i = 0;
		while (i < numEl){
			cin >> v[i];
			i++;
		}

		colados = colado(v, numEl);

		cout << colados << endl;

		casosDePrueba--;
	}

	return 0;
}

// Q= {num > 0, Ax: 0 <= x < num. v[x] > 0}
// int fcolado(int vector[], int num) return colado
// S= {E i: 0 <= i < num. E p: i < p < num: v[i] > v[p]}

int colado(int *v, int num) {
	int colado = 0, i = 0, max = v[num -1];

	for (int i = num - 2; i >= 0; i--){
		if (v[i] > max){
			colado++;
		}
		else{
			max = v[i];
		}
	}

	return colado;
}