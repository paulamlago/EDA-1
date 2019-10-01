 
#ifndef _HOTELCLI_H
#define _HOTELCLI_H

#include "diccionario.h"
#include "lista.h"
#include <string>
using namespace std;

typedef struct {
	string DNI;
	string nombre;
	int telefono;
}InfoCliente;

class Cliente {
public:
	/**
	Construye un mensaje
	@param id El identificador del mensaje
	@param remitente El nombre del usuario que envía el mensaje
	@param asunto El asunto del mensaje
	@param cuerpo El contenido del mensaje
	*/
	Cliente(const string& DNI,const string& nombre, const int& telefono);
	
	const string& DNI() const;
	const string& nombre() const;
	const int& telefono() const;

	bool operator ==(const Cliente &c2);

private:

	string _DNI;     // cuerpo
	string _nombre;
	int _telefono;
};


/**
Excepción señalada cuando se trata de enviar un mensaje con un
identificador duplicado
*/
class EMIDDuplicado {};

/**
Excepción señalada cuando se consulta un mensaje que no existe
*/
class ENoHayMensaje {};

class Agencia {
public:
	/**
	Operacion 'crea'. Crea un foro vacío.
	*/
	Agencia();
	/**
	• aloja(c, h): modifica el estado de la agencia alojando a un cliente c en un
	hotel h. Si c ya tenía antes otro alojamiento, éste queda cancelado. Si h no
	estaba dado de alta en el sistema, se le dará de alta.
	*/
	void aloja(const Cliente& c, const string& hotel);
	/**
	desaloja(c): modifica el estado de una agencia desalojando a un cliente c
	del hotel que éste ocupase. Si c no tenía alojamiento, el estado de la
	agencia no se altera.
	*/
	void desaloja(Cliente c) ;

	/**
	alojamiento(c): permite consultar el hotel donde se aloja un cliente c,
	siempre que éste tuviera alojamiento. En caso de no tener alojamiento
	produce un error.
	*/
	const string& alojamiento(Cliente c )const ;
	/**
	listado_hoteles(): obtiene una lista ordenada de todos los hoteles que
	están dados de alta en la agencia.
	*/
	Lista<string> listado_hoteles();
	/**
	huespedes(h): permite obtener la lista ordenada de clientes que se alojan
	en el hotel h. Dicha lista será vacía si no hay clientes en el hotel.
	*/
	Lista<string> huespedes(string h) ;
private:
	Diccionario < string,Diccionario<Cliente,char>> _hoteles;
	Diccionario <Cliente, string>_cliHotel;
	Lista<string>_listaHoteles;
	Lista<Cliente>_listaClientes;
};

#endif
