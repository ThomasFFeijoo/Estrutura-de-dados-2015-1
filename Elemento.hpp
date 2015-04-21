// Copyright [2015] <Thomas>
// !Implementação de um Elemento para ser usado na Lista Encadeada
/*!
 * \author: Thomas Fernandes Feijoo
 * \since 06/04/2015
 * \version 1.0
 */
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>

/*! A classe a seguir implementa um Elemento*/
class Elemento {
 private:
	T *info; /*!<Ponteiro que contem a informação armazenada*/
	Elemento<T>* _next; /*!<Ponteiro para o próximo elemento*/

//! Construtor.
/*! Contrutor é inicializado com um elemento passando o ponteiro da informacao e 
* o ponteiro para o proximo elemento.
*/
 public:
	Elemento(const T& info, Elemento<T>* next) : info(new T(info)), _next(next) {}

//! Destrutor.
/*! Apaga os ponteiros da informação.
*/
	~Elemento() {
		delete info;
	}

//! Metodo retorna o proximo elemento
/*! 
* Retorna o ponteiro do proximo elemento.
*/
	Elemento<T>* getProximo() const {
		return _next;
	}

//! Metodo retorna info
/*! 
* Retorna o ponteiro que contem a informação do elemento
*/
	T getInfo() const {
		return *info;
	}

//! Metodo determina o proximo elemento
/*! O proximo elemento é passado para este elemento atraves do paramentro "next"
*/
	void setProximo(Elemento<T>* next) {
		_next = next;
	}
};

#endif
