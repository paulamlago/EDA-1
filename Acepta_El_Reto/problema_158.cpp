#include <iostream>

using namespace std;

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
  
    cin >> n;
    for (int i = 0; i < n; i++) {
      
        cin >> m;
      
        int * v = new int [m];
      
        for (int j = 0; j < m; j++)
            cin >> v[j];

        solve(v, m, r1, r2);
        cout << r1 << " " << r2 << "\n";
      
    }

    return 0;
}