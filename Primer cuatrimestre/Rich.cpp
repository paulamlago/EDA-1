#include <iostream>
#include <cmath>
using namespace std;

int algorithms(const int cents);

int main(){
	int casos, cents, sol;

	cin >> casos;

	while (casos > 0){
		cin >> cents;

		if (cents >= 0 && cents <= pow(10,9)){
			sol = algorithms(cents);
			cout << sol << endl;
		}

		casos--;
	}

	return 0;
}

int algorithms(const int cents){
	int money = 2, money0 = 1, money1 = 1, count = 2, aux;

	while (money < cents && cents > 2){
		money += (2 * money0) + money1;
		
		aux = money0;
		money0 = money1;
		money1 += aux*2;

		count++;
	}

	if (cents <= 2){
		count = cents;
	}

	return count;
}