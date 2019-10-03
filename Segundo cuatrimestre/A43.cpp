
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

#ifndef __STACK_H
#define __STACK_H

/**
Implementación del TAD Pila utilizando vectores dinámicos.

Las operaciones son:

- EmptyStack: -> Stack. Generadora implementada en el
constructor sin parámetros.
- Push: Stack, Elem -> Stack. Generadora
- pop: Stack - -> Stack. Modificadora parcial.
- top: Stack - -> Elem. Observadora parcial.
- empty: Stack -> Bool. Observadora.
- size: Stack -> Entero. Observadora.

@author Marco Antonio Gómez Martín
*/
template <class T>
class Stack {
public:

	/** Tamaño inicial del vector dinámico. */
	static const int TAM_INICIAL = 10;

	/** Constructor; operación EmptyStack */
	Stack() {
		inicia();
	}

	/** Destructor; elimina el vector. */
	~Stack() {
		libera();
	}

	/**
	Apila un elemento. Operación generadora.

	@param elem Elemento a apilar.
	*/
	void push(const T &elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}

	/**
	Desapila un elemento. Operación modificadora parcial,
	que falla si la pila está vacía.

	pop(Push(elem, p)) = p
	error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException();
		--_numElems;
	}

	/**
	Devuelve el elemento en la cima de la pila. Operación
	observadora parcial, que falla si la pila está vacía.

	top(Push(elem, p) = elem
	error: top(EmptyStack)

	@return Elemento en la cima de la pila.
	*/
	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _v[_numElems - 1];
	}

	/**
	Devuelve true si la pila no tiene ningún elemento.

	empty(EmptyStack) = true
	empty(Push(elem, p)) = false

	@return true si la pila no tiene ningún elemento.
	*/
	bool empty() const {
		return _numElems == 0;
	}

	/**
	Devuelve el número de elementos que hay en la
	pila.
	size(EmptyStack) = 0
	size(Push(elem, p)) = 1 + size(p)

	@return Número de elementos.
	*/
	int size() const {
		return _numElems;
	}

	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //

	/** Constructor copia */
	Stack(const Stack<T> &other) {
		copia(other);
	}

	/** Operador de asignación */
	Stack<T> &operator=(const Stack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const Stack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		for (unsigned int i = 0; i < _numElems; ++i)
			if (_v[i] != rhs._v[i])
				return false;
		return true;
	}

	bool operator!=(const Stack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void inicia() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}

	void libera() {
		delete[]_v;
		_v = NULL;
	}

	void copia(const Stack &other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

	void amplia() {
		T *viejo = _v;
		_tam *= 2;
		_v = new T[_tam];

		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = viejo[i];

		delete[]viejo;
	}

private:

	/** Puntero al array que contiene los datos. */
	T *_v;

	/** Tamaño del vector _v. */
	unsigned int _tam;

	/** Número de elementos reales guardados. */
	unsigned int _numElems;
};

#endif // __STACK_H

#include <iostream>
using namespace std;

Stack<int> meterEnLaPila(long long int &n);
void printStack(Stack<int> &s);

int main(){
	long long int n;
	Stack<int> s;

	cin >> n;

	while (n != -1){
		s = meterEnLaPila(n);
		printStack(s);
		cin >> n;
	}

	return 0;
}

Stack<int> meterEnLaPila(long long int &n){
	Stack<int> s;

	int in;
	do{
		in = n % 10; // el último dígito de n
		s.push(in);
		n = n / 10;
	} while (n != 0);

	return s;
}

void printStack(Stack<int> &s){
	int add = 0;

	while (!s.empty()){
		add += s.top();
		cout << s.top();
		s.pop();
		if (!s.empty()){
			cout << " + ";
		}
	}

	cout << " = " << add << endl;
}