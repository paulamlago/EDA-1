#include <iostream>
using namespace std;

int divide(int n) {
	if (!n) return 0;
	return 1 + divide(n / 2);
}

void resuelve(int n) {

	cout<<divide(n)<<'\n';
	
}

int main() {
  
  	int n;
	while(cin >> n){
      resuelve(n);
    }
	return 0;
  
}