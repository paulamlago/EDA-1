#include <string>
#include <iostream>

using namespace std;

bool esAbuelaVerdadera (const string &nombre_real, const string nombres[], int n) /*return ret*/ {

    bool ret = true;
    int i = 0;

    if (nombre_real != nombres[n - 1])
        ret = false;

    else {

        while (ret && (i < (n - 1))){

            if (nombres[i] == nombre_real)
                ret = false;

        }

    }

    return ret;

}

int main (){

    int num_casos, n;
    string nombre_real;
    string nombres[100];
    bool abuela;

    cin >> num_casos;

    while (num_casos--){

        cin >> nombre_real;
        cin >> n;

        for (int i = 0; i < n; i++){

            cin >> nombres[i];

        }

        abuela = esAbuelaVerdadera(nombre_real, nombres, n);

    }

    return 0;
}