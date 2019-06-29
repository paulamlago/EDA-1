#include <iostream>

using namespace std;

void resAux(int n, int nV, int v[], int k, int acom, int &ret){

    int aux = 0;

    if(nV == 1){

        for(int i = k; i < n; i++){
            aux += v[i];
        }

        acom = max(acom, aux);
		ret = min(ret, acom);

        return;

    }

    for(int i = k; i < (n - nV + 1); i++){

        aux += v[i];
        resAux(n, nV - 1, v, i + 1, min(aux, acom), ret);

    }

}

int res(int n, int nV, int v[]){

	if (nV == 1){

		int aux = 0;

		for (int i = 0; i < n; i++)
			aux += v[i];

		return aux;
	}

    int ret = 0xFFFFFFF;

    resAux(n, nV, v, 0, 0xFFFFFFF, ret);

    return ret;
}

int main (){

    int n, nV;
    int v[100000];

    while(cin >> n && n){

        cin >> nV;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        cout << res(n, nV, v) << "\n";

    }

    return 0;
}
