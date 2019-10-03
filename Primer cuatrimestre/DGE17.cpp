#include <iostream>
using namespace std;

void dyv(int *v, int a, int b, int &min);

int main(){
	int elements, min;

	do{
		cin >> elements;

		if (!cin.eof()){
			if (elements > 0){
				int i = 0;
				int *v = new int[elements];

				while (i < elements){
					cin >> v[i];
					i++;
				}

				min = v[0];
				dyv(v, 0, elements - 1, min);

				cout << min << endl;

				delete[] v;
			}
		}
	} while (!cin.eof());

return 0;
}

// O(n)

void dyv(int *v, int a, int b, int &min){
	if (a < b - 1){
		int m = (a + b) / 2, min1 = 0, min2 = 0;

		//DIVIDO EL PROBLEMA EN DOS SUBPROBLEMAS
		dyv(v, a, m, min1);
		dyv(v, m, b, min2);
		//LOS COMBINO

		if (min1 < min2){
			min = min1;
		}
		else {
			min = min2;
		}
	}

	//CASO BASE
	else{
		if (v[a] > v[b]){
			min = v[b];
		}
		else{
			min = v[a];
		}
	}
}