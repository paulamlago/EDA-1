#include <iostream>
using namespace std;

const int MAX = 10000;
typedef int tEntrada[MAX];
typedef int tSalida[MAX];

void acumular(const tEntrada &entrada, tSalida &salida);

int main(){
	int i = 0, counter;
	tEntrada entrada;
	tSalida salida;

	cin >> entrada[i];

	while (entrada[i] != 0){
		while (entrada[i] != 0){
			i++;
			cin >> entrada[i];
		}
		i = 0;

		acumular(entrada, salida);

		int counter = 0;

		while (entrada[i] > 0){
			counter++;
			i++;
		}

		for (int p = 0; p < MAX; p++){
			entrada[p] = -1;
		}
		i = 0;
		while (i < counter){
			cout << salida[i];
			if (salida[i + 1] != 0){
				cout << " ";
			}
			i++;
		}

		cout << endl;
		i = 0;
		cin >> entrada[i];

	}
	return 0;
}

void acumular(const tEntrada &entrada, tSalida &salida){

	for (int i = 0; i < MAX; i++){
		salida[i] = 0;
	}

	for (int i = 0; entrada[i] != 0; i++){
		int p = i;
		while (i >= 0){
			salida[p] = salida[p] + entrada[i];
			i--;
		}
		i = p;
	}
}
