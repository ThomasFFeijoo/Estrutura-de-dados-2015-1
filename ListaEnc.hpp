// Copyright [2015] <Thomas>
// !Implementação de uma Lista Encadeada
/*!
 * \author: Thomas Fernandes Feijoo
 * \since 06/04/2015
 * \version 1.0
 */

#include "Elemento.hpp"

template<typename T>

/*! A classe a seguir implementa uma lista encadeada*/
class ListaEnc {
 private:
	Elemento<T>* head;  //!< Ponteiro para o primeiro elemento da lista
    int tamanho;  //!< Variável que armazena o tamanho máximo da lista

 public:
//! Construtor de uma lista
/*! Este construtor apenas inicializa os atributos da lista */
	ListaEnc() {
        this->head = NULL;
        this->tamanho = 0;
	}
//! Destrutor
/*! Este destrutor chama o metodo destroiLista 
\para liberar a memoria utilizada pela lista*/
	~ListaEnc() {
	    this->destroiLista();
	}

	// inicio
//! Método o qual adiciona um dado na primeira posicao da lista.
/*!
\parametro genérico "dado" será um novo dado inserido no inicio da lista
\ao passo que o "tamanho" é incrementado em 1
*/
	void adicionaNoInicio(const T& dado) {
	    Elemento<T> *auxiliar;
	    auxiliar = new Elemento<T>(dado, this->head);
	    if (auxiliar == NULL) {
	        throw "Erro Lista Cheia";
        } else {
            this->head = auxiliar;
            this->tamanho += 1;
        }
	}

//! Método o qual remove um dado no inicio da lista.
/*!
\remove o primeiro valor da lista e o retorna     
*/
	T retiraDoInicio() {
	    Elemento<T> *auxiliar;
	    T valorRetornado;
	    if (this->listaVazia()) {
	        throw "Erro Lista vazia";
        } else {
            auxiliar = this->head;
            valorRetornado = auxiliar->getInfo();
            this->head = auxiliar->getProximo();
            this->tamanho -= 1;
            delete auxiliar;
            return valorRetornado;
        }
	}

//! Método o qual remove um dado no inicio da lista.
/*!
\remove o primeiro valor da lista
*/
	void eliminaDoInicio() {
	    Elemento<T> *auxiliar;
	    if (this->listaVazia()) {
	        throw "Erro Lista Vazia";
	    } else {
	        auxiliar = this->head;
	        this->head = auxiliar->getProximo();
	        this->tamanho -= 1;
	        delete auxiliar;
	    }
	}

	// posicao
//! Método o qual adiciona um dado numa posicao especifica.
/*!
\Adiciona um "dado" em uma "pos" determinada,
\enquanto os dados presentes após tal "pos" são deslocados uma posicao para trás.
\O tamanho da lista é incrementado em 1.
*/
	void adicionaNaPosicao(const T& dado, int pos) {
	    if (pos == 0) {
            return this->adicionaNoInicio(dado);
        } else if (pos < 0 || pos > this->tamanho) {
            throw "Posição inválida";
        }
        Elemento<T> *anterior = this->head;
        Elemento<T> *novo;
        int i;
        for (i = 0; i < pos -1; i++) {
            anterior = anterior->getProximo();
        }
        novo = anterior->getProximo();
        anterior->setProximo(new Elemento<T>(dado, novo));
        this->tamanho += 1;
	}

//! Método o qual retorna a posicao de um determinado "dado".
	int posicao(const T& dado) const {
	    int i;
	    Elemento<T> *auxiliar = this->head;
	    for (i = 0; i < this->tamanho; i++) {
	        if (auxiliar->getInfo() == dado) {
	        return i;
            }
            auxiliar = auxiliar->getProximo();
	    }
	    throw "Dado não encontrado";
	}

//! Método o qual retorna a posicao de memória de um determinado "dado".
	T* posicaoMem(const T& dado) const {
	    int i;
        Elemento<T> *auxiliar = this->head;
        for (i = 0; i < this->tamanho; i++) {
            if (auxiliar->getInfo() == dado) {
                T valorInfo = auxiliar->getInfo();
                return &valorInfo;
        }
            auxiliar = auxiliar->getProximo();
        }
    }

//! Método o qual verifica a presença de um determinado "dado" na lista.
	bool contem(const T& dado) {
	    Elemento<T> *auxiliar = this->head;
	    int i;
	    for (i = 0; i < this->tamanho; i++) {
	        if (auxiliar == NULL) {
	            throw "Erro Temporario auxiliar nulo";
	        } else if (auxiliar->getInfo() == dado) {
	            return true;
	        }
	        auxiliar = auxiliar->getProximo();
	    }
	    return false;
	}

//! Método o qual retira um dado de uma posicao "pos" especifica.
/*!
\Retira um dado de uma determinada posicao "pos".
\O tamanho da lista é decrementado em 1.
\Retorna o dado retirado.
*/
	T retiraDaPosicao(int pos) {
	    Elemento<T> *auxiliarEliminado, *anterior;
	    T dadoRetornado;
	    if (pos > this->tamanho) {
	        throw "posicao inválida";
	    } else {
	        if (pos == 0) {
	            return retiraDoInicio();
	        } else {
	            anterior = this->head;
	            int i;
	            for (i = 0; i < pos -1; i++) {
	                anterior = anterior->getProximo();
	                    if (anterior == NULL) {
	                        throw "Erro, temporario anterior é nulo";
	                    }
	            }
	            auxiliarEliminado = anterior->getProximo();
	            dadoRetornado = auxiliarEliminado->getInfo();
	            anterior->setProximo(auxiliarEliminado->getProximo());
	            this->tamanho -= 1;
	            delete auxiliarEliminado;
	            return dadoRetornado;
	        }
	    }
	}

	// fim
//! Método o qual adiciona um "dado" na lista.
/*!
\O tamanho da lista é incrementado em 1.
*/
	void adiciona(const T& dado) {
	    if (this->listaVazia()) {
	        return this->adicionaNoInicio(dado);
	    } else {
	        Elemento<T> *auxiliar = this->head;
	        int i;
	        for (i = 0; i < this->tamanho-1; i++) {
	            auxiliar = auxiliar->getProximo();
	        }
        Elemento<T> *novoAux = new Elemento<T>(dado, NULL);
        auxiliar->setProximo(novoAux);
        this->tamanho +=1;
	    }
	}

//! Método o qual retira um "dado" na lista.
/*!
\O tamanho da lista é decrementado em 1.
*/
	T retira() {
        int i, maximo;
        Elemento<T> *auxiliar = this->head;
        maximo = this->tamanho - 2;
        if (this->listaVazia()) {
            throw "Erro lista está vazia";
        } else {
            if (maximo < 0) {
                return this->retiraDoInicio();
            } else {
                for (i = 0; i < maximo; i++) {
                    auxiliar = auxiliar->getProximo();
                    if (auxiliar == NULL) {
                        throw "Erro temporario auxiliar é nulo";
                    }
                }
            }
	    Elemento<T> *proximo = auxiliar->getProximo();
	    T valorInfo = proximo->getInfo();
	    auxiliar->setProximo(proximo->getProximo());
	    this->tamanho -= 1;
	    delete proximo;
	    return valorInfo;
	}
	}

	// especifico
//! Método o qual retira um dado especifico da lista.
/*!
\Descobre a posicao do "dado" utilizando o metodo posicao()
\e a posicao é repassada para o metodo retiraDaPosicao()
*/
	T retiraEspecifico(const T& dado) {
	    return this->retiraDaPosicao(this->posicao(dado));
	}

//! Método o qual adiciona um dado "data" na ordem correta na lista.
/*!
\Método compara o dado "data" com os existentes para determinar
\em qual posicao ele deverá ser adicionado
*/
	void adicionaEmOrdem(const T& data) {
	    Elemento<T> *auxiliar;
	    int posicao;
	    if (this->listaVazia()) {
	        return adicionaNoInicio(data);
	    } else {
	        auxiliar = this->head;
	        posicao = 0;
	        while (auxiliar->getProximo() != NULL &&
                    this->maior(data, auxiliar->getInfo())) {
	            auxiliar = auxiliar->getProximo();
	            posicao += 1;
	        }
	        if (this->maior(data, auxiliar->getInfo())) {
	            return this->adicionaNaPosicao(data, posicao +1);
	        } else {
	            return this->adicionaNaPosicao(data, posicao);
	        }
	}
	}

//! Método o qual verifica se a lista está vazia.
	bool listaVazia() const {
	    return this->tamanho == 0;
	}

//! Método o qual verifica se "dado1" é maior que "dado2".
	bool igual(T dado1, T dado2) {
	    return dado1 == dado2;
	}

//! Método o qual verifica se "dado1" é igual a "dado2".
	bool maior(T dado1, T dado2) {
	    return dado1 > dado2;
	}

//! Método o qual verifica se "dado1" é menor que "dado2".
	bool menor(T dado1, T dado2) {
	    return dado1 < dado2;
	}

//! Método o qual destroi a lista.
/*!
\Método limpa a lista e libera a memoria
*/
	void destroiLista() {
	    Elemento<T> *auxiliar, *anterior;
	    auxiliar = this->head;
	    int i;
	    for (i = 0; i < this->tamanho; i++) {
	        anterior = auxiliar;
	        auxiliar = auxiliar->getProximo();
	        delete anterior;
	    }
	    this->head = NULL;
	    this->tamanho = 0;
	}
};
