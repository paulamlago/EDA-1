#include <iostream>
using namespace std;

const int MAX = 20000;

typedef int tvector[MAX];

void numberOfMax(const tvector &vec, int &max, int &time);

int main(){
	int casosDePrueba, DIM, i, max, time;
	tvector vector;

	cin >> casosDePrueba;

	while (casosDePrueba > 0){

		cin >> DIM;
		i = 0;

		while (DIM > 0 && DIM <= MAX){
			cin >> vector[i];
			i++;
			DIM--;
		}

		time = 1;
		i = 0;
		max = vector[i];
		numberOfMax(vector, max, time);

		cout << max << " " << time << endl;

		for (int i = 0; i < MAX; i++){
			vector[i] = -453405430; // For INSTANCE
		}

		casosDePrueba--;
	}

	return 0;
}

void numberOfMax(const tvector &vec, int &max, int &time){
	int i = 0;

	while (vec[i] >= 0){
		if (vec[i] == max && i != 0){
			time++;
		}
		if (vec[i] > max){
			max = vec[i];
			time = 1;
		}
		i++;
	}
}
