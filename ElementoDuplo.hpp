// Copyright [2015] <Thomas>
// !Implementação de um Elemento para ser usado na Lista Duplamente Encadeada
/*!
 * \author: Thomas Fernandes Feijoo
 * \since 13/04/2015
 * \version 1.0
 */
#ifndef ELEMENTODUPLO_HPP
#define ELEMENTODUPLO_HPP

template<typename T>

/*! A classe a seguir implementa um Elemento*/
class ElementoDuplo {
 private:
	T *info; /*!<Ponteiro que contem a informação armazenada*/
	ElementoDuplo<T>* _proximo; /*!<Ponteiro para o próximo elemento*/
	ElementoDuplo<T>* _anterior; /*!<Ponteiro para o elemento anterior*/

//! Construtor.
/*! Contrutor é inicializado com um elemento passando o ponteiro da informacao, 
* o ponteiro para o proximo elemento e o ponteiro para o elemento anterior.
*/
 public:
	ElementoDuplo(const T& info, ElementoDuplo<T>* proximo,
	            ElementoDuplo<T>* anterior) : info(new T(info)), _proximo(proximo),
	            _anterior(anterior) {}

//! Destrutor.
/*! Apaga os ponteiros da informação.
*/
	~ElementoDuplo() {
		delete info;
	}

//! Metodo retorna o proximo elemento
/*! 
* Retorna o ponteiro do proximo elemento.
*/
	ElementoDuplo<T>* getProximo() const {
		return _proximo;
	}

//! Metodo retorna o elemento anterior
/*! 
* Retorna o ponteiro do elemento anterior.
*/
	ElementoDuplo<T>* getAnterior() const {
		return _anterior;
	}

//! Metodo retorna info
/*! 
* Retorna o ponteiro que contem a informação do elemento
*/
	T getInfo() const {
		return *info;
	}

//! Metodo determina o proximo elemento
/*! O proximo elemento é passado para este elemento atraves do paramentro "proximo"
*/
	void setProximo(ElementoDuplo<T>* proximo) {
		_proximo = proximo;
	}

//! Metodo determina o elemento anterior
/*! O elemento anterior é passado para este elemento atraves do paramentro "anterior"
*/
	void setAnterior(ElementoDuplo<T>* anterior) {
		_anterior = anterior;
	}
};

#endif
