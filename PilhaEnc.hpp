// Copyright [2015] <Thomas>
//! Implementação de uma pilha encadeada
/*!
* \author Thomas Fernandes Feijoo
* \since 13/04/2015
* \version 1.0
*/

#include "ListaEnc.hpp"
template<typename T>

/*! A classe a seguir implementa uma pilha encadeada*/
class PilhaEnc : private ListaEnc<T> {  //!< A pilha encadeada é uma extensão
                                        //!< da lista encadeada
 public:
//! Construtor de uma pilha encadeada
/*! O construtor da lista encadeada é chamado */
    PilhaEnc() {
    }

//! Destrutor de uma pilha encadeada
/*! O destrutor da lista encadeada é chamado */
    ~PilhaEnc() {
    }

/*!
* Adiciona ao head da pilha um determinado dado
*
* @param: dado O dado que será empilhado
*/
    void empilha(const T& dado) {
        ListaEnc<T>::adicionaNoInicio(dado);
    }

/*!
* Retira o primeiro dado da pilha
*/
    T desempilha() {
        return ListaEnc<T>::retiraDoInicio();
    }

/*!
* Retorna o dado presente no head da pilha
*/
	T topo() {
	    T valorTopo = ListaEnc<T>::retiraDoInicio();
	    ListaEnc<T>::adicionaNoInicio(valorTopo);
	    return valorTopo;
	}

/*!
* Apaga todos os dados da pilha
*/
	void limparPilha() {
	    ListaEnc<T>::destroiLista();
	}

/*!
* Verifica se a pilha está vazia
*/
	bool PilhaVazia() {
	    return ListaEnc<T>::listaVazia();
	}
};
