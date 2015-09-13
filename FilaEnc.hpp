// Copyright [2015] <Thomas>
//! Implementação de uma fila encadeada
/*!
 * \author Thomas Fernandes Feijoo
 * \since 13/04/2015
 * \version 1.0
 */
#include "ListaEnc.hpp"
template <typename T>

/*! A classe a seguir implementa uma pilha */
class FilaEnc : private ListaEnc<T>{  //!< A fila encadeada é uma extensão
                                     //!< da lista encadeada
 private:
    Elemento<T> *fim;  //!< Armazena o final da lista

 public:
//! Construtor de uma fila encadeada
/*! O construtor da lista encadeada é chamado */
	FilaEnc<T>() {
	}

//! Destrutor de uma fila encadeada
/*! O Destrutor da lista encadeada é chamado */
	~FilaEnc() {
	}

/*!
* Adiciona um valor no final da fila encadeada
* 
* @param dado O dado que vai ser adicionado na fila
*/
	void inclui(const T& dado) {
        if (this->listaVazia()) {
            ListaEnc<T>::adicionaNoInicio(dado);
            this->fim = this->head;
        } else {
        Elemento<T> *auxiliar = new Elemento<T>(dado, NULL);
        this->fim->setProximo(auxiliar);
        this->fim = auxiliar;
        ListaEnc<T>::tamanho++;
	    }
	}

/*!
* Retira o dado do final da fila encadeada
* 
*/
	T retira() {
        T removido = ListaEnc<T>::retiraDoInicio();
        if (ListaEnc<T>::tamanho == 0) {
            this->fim = NULL;
        }
        return removido;
    }

/*!
* Retorna o ultimo valor da fila
* 
*/
	T ultimo() {
	    if (this->filaVazia()) {
	        throw "A fila já está vazia";
	    }
	    return this->fim->getInfo();
	}

/*!
* Retorna o primeiro valor da fila
* 
*/
	T primeiro() {
	    if (this->filaVazia()) {
	        throw "A fila está vazia";
	    }
	    return ListaEnc<T>::head->getInfo();
	}

/*!
* Retorna se a fila está vazia
* 
*/
	bool filaVazia() {
	    return ListaEnc<T>::listaVazia();
	}

/*!
* Apaga os dados da fila
* 
*/
	void limparFila() {
        ListaEnc<T>::destroiLista();
	}
};
