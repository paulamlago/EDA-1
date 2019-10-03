
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


// Macro para declarar las clases de tipo excepci�n
// que heredan de ExcepcionConMensaje, para ahorrar
// escribir muchas veces lo mismo...
#define DECLARA_EXCEPCION(Excepcion) \
class Excepcion : public ExcepcionTAD { \
public: \
Excepcion() {}; \
Excepcion(const std::string &msg) : ExcepcionTAD(msg) {} \
};

/**
Excepci�n generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(EmptyStackException);

/**
Excepci�n generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(FullStackException);

/**
Excepci�n generada por algunas de las operaciones de las colas.
*/
DECLARA_EXCEPCION(EmptyQueueException);

/**
Excepci�n generada por algunas operaciones de las colas dobles.
*/
DECLARA_EXCEPCION(EmptyDequeException);

/**
Excepci�n generada por algunas operaciones de las listas.
*/
DECLARA_EXCEPCION(EmptyListException);

/**
Excepci�n generada por accesos incorrectos a las listas
(tanto a un n�mero de elemento incorrecto como por
mal manejo de los iteradores).
*/
DECLARA_EXCEPCION(InvalidAccessException);

/**
Excepci�n generada por algunas operaciones de los
�rboles binarios.
*/
DECLARA_EXCEPCION(EArbolVacio);

/**
Excepci�n generada por algunas operaciones de los
diccionarios y �rboles de b�squeda.
*/
DECLARA_EXCEPCION(EClaveErronea);

#endif // __EXCEPCIONES_H

#ifndef __STACK_H
#define __STACK_H

/**
Implementaci�n del TAD Pila utilizando vectores din�micos.

Las operaciones son:

- EmptyStack: -> Stack. Generadora implementada en el
constructor sin par�metros.
- Push: Stack, Elem -> Stack. Generadora
- pop: Stack - -> Stack. Modificadora parcial.
- top: Stack - -> Elem. Observadora parcial.
- empty: Stack -> Bool. Observadora.
- size: Stack -> Entero. Observadora.

@author Marco Antonio G�mez Mart�n
*/
template <class T>
class Stack {
public:

	/** Tama�o inicial del vector din�mico. */
	static const int TAM_INICIAL = 10;

	/** Constructor; operaci�n EmptyStack */
	Stack() {
		inicia();
	}

	/** Destructor; elimina el vector. */
	~Stack() {
		libera();
	}

	/**
	Apila un elemento. Operaci�n generadora.

	@param elem Elemento a apilar.
	*/
	void push(const T &elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}

	/**
	Desapila un elemento. Operaci�n modificadora parcial,
	que falla si la pila est� vac�a.

	pop(Push(elem, p)) = p
	error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException();
		--_numElems;
	}

	/**
	Devuelve el elemento en la cima de la pila. Operaci�n
	observadora parcial, que falla si la pila est� vac�a.

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
	Devuelve true si la pila no tiene ning�n elemento.

	empty(EmptyStack) = true
	empty(Push(elem, p)) = false

	@return true si la pila no tiene ning�n elemento.
	*/
	bool empty() const {
		return _numElems == 0;
	}

	/**
	Devuelve el n�mero de elementos que hay en la
	pila.
	size(EmptyStack) = 0
	size(Push(elem, p)) = 1 + size(p)

	@return N�mero de elementos.
	*/
	int size() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	Stack(const Stack<T> &other) {
		copia(other);
	}

	/** Operador de asignaci�n */
	Stack<T> &operator=(const Stack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
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

	/** Tama�o del vector _v. */
	unsigned int _tam;

	/** N�mero de elementos reales guardados. */
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
		in = n % 10; // el �ltimo d�gito de n
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