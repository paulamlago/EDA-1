#include "Racional.h"
#include <cmath> 

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
 
Racional::Racional() {

	_numer = 0;
	_denom = 1;

}

Racional::Racional(long n, long d) {

	if (!d) throw EDenominadorCero();

	_numer = n;
	_denom = d;

	reduce();

}

Racional Racional::suma(Racional f2) {

	long ret_denom = mcm(this->_denom, f2._denom);
	long ret_numer = (this->_numer * (ret_denom / this->_denom)) + (f2._numer * (ret_denom / f2._denom));

	return Racional(ret_numer, ret_denom);

}

Racional Racional::operator-(const Racional & f2) const {

	long ret_denom = mcm(_denom, f2._denom);
	long ret_numer = (_numer * (ret_denom / _denom)) - (f2._numer * (ret_denom / f2._denom));

	return Racional(ret_numer, ret_denom);
}

Racional Racional::operator*=(const Racional & f2) {

	_numer *= f2._numer;
	_denom *= f2._denom;

	reduce();

	return *this;
}

Racional Racional::divideYActualiza(const Racional & f2) {

	if (!f2._numer) throw EDivisionPorCero();

	_numer *= f2._denom;
	_denom *= f2._numer;

	reduce();

	return *this;
}

bool Racional::operator==(const Racional & f2) const {

	return (_numer == f2._numer) && (_denom == f2._denom);
}

  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

