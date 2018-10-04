#include <iostream>
#include <string>


int main() {

	int casos;
	int veces;
	long long int dias;
	long long int horas;
	long long int minutos;
	long long int segundos;
	std::string aux;

	std::cin >> casos;

	while (casos--) {

		std::cin >> veces;
		std::cin >> aux;

		segundos = 3600 * (10 * (int(aux[0]) - 48) + (int(aux[1]) - 48));
		segundos += 60 * (10 * (int(aux[3]) - 48) + (int(aux[4]) - 48));
		segundos += 10 * (int(aux[6]) - 48) + (int(aux[7]) - 48);		

		segundos = veces * segundos;

		dias = segundos / 86400;

		segundos = segundos -(dias * 86400);

		horas = segundos / 3600;

		segundos = segundos - (horas * 3600);

		minutos = segundos / 60;

		segundos = segundos - (minutos * 60);

		std::cout << dias << " ";

		if (horas < 10) {
			std::cout << "0" << horas << ":";
		}
		else
			std::cout << horas << ":";

		if (minutos < 10) {
			std::cout << "0" << minutos << ":";
		}
		else
			std::cout << minutos << ":";

		if (segundos < 10) {
			std::cout << "0" << segundos << "\n";
		}
		else
			std::cout << segundos << "\n";


	}

	getchar();
	getchar();

	return 0;
}