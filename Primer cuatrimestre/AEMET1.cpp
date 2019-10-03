#include <iostream>
using namespace std;

const int MAX = 100;
typedef int temper[MAX];

void picosyvalles(const temper &temp);

int main(){
	int casos, num, i = 0;
	temper temp;

	cin >> casos;

	while (casos > 0){
		cin >> num;
		
		while (num > 0 && num < 10000){
			cin >> temp[i];
			num--;
			i++;
		}

		picosyvalles(temp);

		for (int i = 0; i < MAX; i++){
			temp[i] = -51;
		}

		i = 0;
		casos--;
		if (casos > 0){
			cout << endl;
		}
	}


	return 0;
}

void picosyvalles(const temper &temp){
	int numpic = 0, i= 0, numValle = 0; 

	while (temp[i] > -50){
		if (i > 0 && temp[i + 1] > -50){
			if ((temp[i - 1] < temp[i]) && (temp[i] > temp[i + 1])){
				numpic++;
			}
			if ((temp[i - 1] > temp[i]) && (temp[i] < temp[i + 1])){
				numValle++;
			}
		}
		i++;
	}

	cout << numpic << " " << numValle;
}