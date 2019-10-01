 
#include "hotelcli.h"

/*METODOS CLIENTE*/
Cliente::Cliente(const string& DNI, const string& nombre, const int& telefono) {}

const string& Cliente::DNI() const {
	return _DNI;
}
const string& Cliente::nombre() const {
	return _nombre;
}
const int& Cliente::telefono() const {
	return _telefono;
}

bool Cliente::operator==(const Cliente &c2) {

	return this->nombre == c2.nombre;

}

/*METODOS AGENCIA*/

Agencia::Agencia() {}

/**
• aloja(c, h): modifica el estado de la agencia alojando a un cliente c en un
hotel h. Si c ya tenía antes otro alojamiento, éste queda cancelado. Si h no
estaba dado de alta en el sistema, se le dará de alta.
*/
void Agencia::aloja(const Cliente& c, const string& hotel) {

	Diccionario<Cliente, string>::Iterator cliHotelIterator = _cliHotel.busca(c);
	Diccionario<string, Diccionario<Cliente, char>>::Iterator hotelesIterator = _hoteles.busca(hotel);
	Diccionario<Cliente, char> auxDic;
	if (hotelesIterator != _hoteles.end()) {
		hotelesIterator.valor().inserta(c, ' ');
	}
	else {
		auxDic.inserta(c, ' ');
		_hoteles.inserta(hotel, auxDic);
	}
	if (cliHotelIterator!= _cliHotel.end()) {
		cliHotelIterator.setVal(hotel);
	}
	else {
		_cliHotel.inserta(c, hotel);
	}
}

/**
desaloja(c): modifica el estado de una agencia desalojando a un cliente c
del hotel que éste ocupase. Si c no tenía alojamiento, el estado de la
agencia no se altera.
*/
void Agencia::desaloja(Cliente c) {
	Diccionario<Cliente, string>::Iterator cliHotelIterator = _cliHotel.busca(c);
	if(cliHotelIterator != _cliHotel.end()){
		cliHotelIterator.setVal("");
	}
}
/**
alojamiento(c): permite consultar el hotel donde se aloja un cliente c,
siempre que éste tuviera alojamiento. En caso de no tener alojamiento
produce un error.
*/
const string& Agencia::alojamiento(Cliente c) const {
	if (_cliHotel.contiene(c)) {
		return _cliHotel.valorPara(c);
	}
	else return "No esta el cliente";
}
/**
listado_hoteles(): obtiene una lista ordenada de todos los hoteles que
están dados de alta en la agencia.
*/
 Lista<string> Agencia::listado_hoteles() {
	Diccionario<string, Diccionario<Cliente,char>>::ConstIterator _hotelesIterator = _hoteles.cbegin();
	while (_hotelesIterator!=_hoteles.cend()){

		_listaHoteles.pon_final(_hotelesIterator.clave());
		_hotelesIterator.next();
	}
	return _listaHoteles;
}
 /**
 huespedes(h): permite obtener la lista ordenada de clientes que se alojan
 en el hotel h. Dicha lista será vacía si no hay clientes en el hotel.
 */
 Lista<string> Agencia::huespedes(string h) {
 
	 Diccionario<string, Diccionario<Cliente, char>>::ConstIterator _hotelesIterator = _hoteles.cbusca(h);
	// Diccionario<Cliente, char>::ConstIterator _cliIterator 

	 while (_hotelesIterator != _hoteles.cend()) {
		 Diccionario<Cliente, char>::ConstIterator _cliIterator = _hotelesIterator.valor().cbegin();
		 while (_cliIterator!= _hotelesIterator.valor().cend())
		 {
			 _listaClientes.pon_final(_cliIterator.clave());
			 _cliIterator.next();
		 }
		 _hotelesIterator.next();
	 }
	

 }

 int main() {
	 Agencia agencia = Agencia();
	Cliente cPepe=  Cliente("a12", "pepe", 1222);
	Cliente cAna= Cliente("a789", "ana", 5675);
	Cliente cJuan=  Cliente("x456", "juan", 4567);
	 agencia.aloja(cPepe, "Asa");
	 agencia.aloja(cAna, "Melia");
	 agencia.aloja(cJuan, "Melia");
	 agencia.desaloja(cJuan);
	 agencia.alojamiento(cAna);
	 agencia.listado_hoteles();
	 agencia.huespedes("Melia");
	 
 }
