#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//#####################################
//  # DESCOMENTAR EN ACEPTA EL RETO #
//#####################################

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;	
	if (N == 0) { 
      putchar_unlocked('0'); 
      //putchar_unlocked('\n'); 
      return; }
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar_unlocked('0');
	//putchar_unlocked('\n');
}

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}


// { Pre: 0 <= n <= longitud(v) }

void solve(int v[], int n, int & ret1 /* out */, int & ret2 /* out */) {
  
    int i = 1;
    ret1 = ret2 = 0;
  
    while (i < n) {
      
        if (v[i] > v[i-1]) 
          ret1++;
      
        else if (v[i] < v[i-1]) 
          ret2++;
          
        i++;
      
    }
}

// { Pos: 
//      ret1 = # i : 0 < i < n : v[i] > v[i-1] ^
//      ret2 = # j : 0 < j < n : v[j] < v[j-1]
// }


int main() {

	int n, m, r1, r2;

	in(n);
	for (int i = 0; i < n; i++) {

		cin >> m;

		int * v = new int[m];

		for (int j = 0; j < m; j++)
			cin >> v[j];

		solve(v, m, r1, r2);
		out(r1);
		putchar_unlocked(' ');
		out(r2);
		putchar_unlocked('\n');

	}

	return 0;
}