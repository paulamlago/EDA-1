
#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>
#include <iosfwd>
/**
Clase de la que heredan todas las excepciones, y
que proporciona el atributo que almacena el
mensaje de error.
*/
class ExcepcionTAD {
public:
	ExcepcionTAD() {}
	ExcepcionTAD(const std::string &msg) : _msg(msg) {}

	const std::string msg() const { return _msg; }

	friend std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e);

protected:
	std::string _msg;
};

inline std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e) {
	out << e._msg;
	return out;
}


// Macro para declarar las clases de tipo excepción
// que heredan de ExcepcionConMensaje, para ahorrar
// escribir muchas veces lo mismo...
#define DECLARA_EXCEPCION(Excepcion) \
class Excepcion : public ExcepcionTAD { \
public: \
Excepcion() {}; \
Excepcion(const std::string &msg) : ExcepcionTAD(msg) {} \
};

/**
Excepción generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(EmptyStackException);

/**
Excepción generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(FullStackException);

/**
Excepción generada por algunas de las operaciones de las colas.
*/
DECLARA_EXCEPCION(EmptyQueueException);

/**
Excepción generada por algunas operaciones de las colas dobles.
*/
DECLARA_EXCEPCION(EmptyDequeException);

/**
Excepción generada por algunas operaciones de las listas.
*/
DECLARA_EXCEPCION(EmptyListException);

/**
Excepción generada por accesos incorrectos a las listas
(tanto a un número de elemento incorrecto como por
mal manejo de los iteradores).
*/
DECLARA_EXCEPCION(InvalidAccessException);

/**
Excepción generada por algunas operaciones de los
árboles binarios.
*/
DECLARA_EXCEPCION(EArbolVacio);

/**
Excepción generada por algunas operaciones de los
diccionarios y árboles de búsqueda.
*/
DECLARA_EXCEPCION(EClaveErronea);

#endif // __EXCEPCIONES_H

#ifndef __LINKED_LIST_QUEUE_H
#define __LINKED_LIST_QUEUE_H

/**
Implementación del TAD Cola utilizando una lista enlazada.

Las operaciones son:

- EmptyQueue: -> Queue. Generadora implementada en el
constructor sin parámetros.
- push_back: Queue, Elem -> Queue. Generadora
- pop_front: Queue - -> Queue. Modificadora parcial.
- front: Queue - -> Elem. Observadora parcial.
- empty: Queue -> Bool. Observadora.
- size: Queue -> Entero. Observadora.

@author Marco Antonio Gómez Martín
*/
template <class T>
class Queue {
public:

	/** Constructor; operacion EmptyQueue */
	Queue() : _prim(NULL), _ult(NULL), _numElems(0) {
	}

	/** Destructor; elimina la lista enlazada. */
	~Queue() {
		libera();
		_prim = _ult = NULL;
	}

	/**
	Añade un elemento en la parte trasera de la cola.
	Operación generadora.

	@param elem Elemento a añadir.
	*/
	void push_back(const T &elem) {
		Nodo *nuevo = new Nodo(elem, NULL);

		if (_ult != NULL)
			_ult->_sig = nuevo;
		_ult = nuevo;
		// Si la cola estaba vacía, el primer elemento
		// es el que acabamos de añadir
		if (_prim == NULL)
			_prim = nuevo;
		_numElems++;
	}

	/**
	Elimina el primer elemento de la cola.
	Operación modificadora parcial, que falla si
	la cola está vacía.

	pop_front(Push_back(elem, EmptyQueue)) = EmptyQueue
	pop_front(Push_back(elem, xs)) = push_back(elem, pop_front(xs)) si !empty(xs)
	error: pop_front(EmptyQueue)
	*/
	void pop_front() {
		if (empty())
			throw EmptyQueueException();
		Nodo *aBorrar = _prim;
		_prim = _prim->_sig;
		delete aBorrar;
		--_numElems;
		// Si la cola se quedó vacía, no hay
		// último
		if (_prim == NULL)
			_ult = NULL;
	}

	/**
	Devuelve el primer elemento de la cola. Operación
	observadora parcial, que falla si la cola está vacía.

	front(Push_back(elem, EmptyQueue)) = elem
	front(Push_back(elem, xs)) = primero(xs) si !empty(xs)
	error: front(EmptyQueue)

	@return El primer elemento de la cola.
	*/
	const T &front() const {
		if (empty())
			throw EmptyQueueException();
		return _prim->_elem;
	}

	/**
	Devuelve true si la cola no tiene ningún elemento.

	empty(EmptyQueue) = true
	empty(Push_back(elem, p)) = false

	@return true si la cola no tiene ningún elemento.
	*/
	bool empty() const {
		return _prim == NULL;
	}

	/**
	Devuelve el número de elementos que hay en la
	cola.
	size(EmptyQueue) = 0
	size(Push_back(elem, p)) = 1 + size(p)

	@return Número de elementos.
	*/
	int size() const {
		return _numElems;
	}

	void invert(int k) {
		int i = 1;
		
		Nodo *top = _prim;
		Nodo *saveLastPrim = _prim;
		Nodo *saveNexElem = _prim->_sig;

		while (i < k && i < _numElems) {
			if (i == 0)  top->_sig = NULL;
			_prim = saveNexElem;
			saveNexElem = _prim->_sig;
			_prim->_sig = saveLastPrim;
			saveLastPrim = _prim;
			i++;
		}

		top->_sig = saveNexElem;
	}

	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //

	/** Constructor copia */
	Queue(const Queue<T> &other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}

	/** Operador de asignación */
	Queue<T> &operator=(const Queue<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const Queue<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *p1 = _prim;
		Nodo *p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL)) {
			if (p1->_elem != p2->_elem)
				return false;
			p1 = p1->_sig;
			p2 = p2->_sig;
		}

		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const Queue<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
		libera(_prim);
	}

	void copia(const Queue &other) {

		if (other.empty()) {
			_prim = _ult = NULL;
			_numElems = 0;
		}
		else {
			Nodo *act = other._prim;
			Nodo *ant;
			_prim = new Nodo(act->_elem);
			ant = _prim;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_ult = ant;
			_numElems = other._numElems;
		}
	}

private:

	/**
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que podría ser NULL si
	el nodo es el último de la lista enlazada.
	*/
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	/**
	Elimina todos los nodos de la lista enlazada cuyo
	primer nodo se pasa como parámetro.
	Se admite que el nodo sea NULL (no habrá nada que
	liberar).
	*/
	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	/** Puntero al primer elemento. */
	Nodo *_prim;

	/** Puntero al último elemento. */
	Nodo *_ult;

	/** Número de elementos */
	int _numElems;
};

#endif // __LINKED_LIST_QUEUE_H

#include<iostream>
using namespace std;

int main() {
	int n, k, x;
	cin >> n;

	while (n > 0) {
		Queue<int> cola;
		Queue<int> saveOriginal;

		cin >> x;
		while (x != -1) {
			cola.push_back(x);
			cin >> x;
		}

		cin >> k;

		saveOriginal = cola;

		if (k >= 2) cola.invert(k);

		cout << "{";
		while (!saveOriginal.empty()) {
			cout << saveOriginal.front();
			saveOriginal.pop_front();
			if (!saveOriginal.empty())cout  << ",";
		}
		cout << "}" << endl;

		cout << "{";
		while (!cola.empty()) {
			cout << cola.front();
			cola.pop_front();
			if (!cola.empty())cout << ",";
		}
		cout << "}" << endl;

		n--;
	}

	return 0;
}