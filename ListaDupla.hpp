// Copyright [2015] <Thomas>
//! Implementação de uma lista duplamente encadeada
/*!
 * \author Thomas Fernandes Feijoo
 * \since 13/04/2015
 * \version 1.0
 */

#include "ElementoDuplo.hpp"
template <typename T>
class ListaDupla {
 private:
    ElementoDuplo<T> *head;  //!< Elemento duplo que contém a cabeça da lista
    int tamanho;  //!< Váriavel com o tamanho da lista

 public:
/*!
* Construtor de uma lista duplamente encadeada
*/
	ListaDupla() {
	    this->head = NULL;
	    this->tamanho = 0;
	}

/*!
* Destrói a lista, e todos os seus elementos, da memória
*/
	~ListaDupla() {
	    this->destroiListaDuplo();
	}

/*!
* Adiciona um novo dado no início da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adicionaNoInicioDuplo(const T& dado) {
	    ElementoDuplo<T> *auxiliar;
	    auxiliar = new ElementoDuplo<T>(dado, this->head, NULL);
	    this->head = auxiliar;
	    if (auxiliar->getProximo() != NULL) {
	        auxiliar->getProximo()->setAnterior(auxiliar);
	    }
	    this->tamanho += 1;
	}

/*!
* Remove e retorna o elemento presente no inicio da lista
*/
	T retiraDoInicioDuplo() {
	    ElementoDuplo<T> *auxiliar;
	    T dadoRetornado;
	    if (this->listaVazia()) {
	        throw "A lista está vazia.";
	    } else {
	        auxiliar = head;
	        dadoRetornado = auxiliar->getInfo();
	        this->head = auxiliar->getProximo();
	        if (this->head != NULL) {
	            this->head->setAnterior(NULL);
	        }
	        this->tamanho -= 1;
	        delete auxiliar;
	        return dadoRetornado;
	    }
	}

/*!
* Remove o elemento presente no início da lista
*/
	void eliminaDoInicioDuplo() {
	    ElementoDuplo<T> *auxiliar;
	    if (this->listaVazia()) {
	        throw "A lista já esta vazia";
	    } else {
	        auxiliar = this->head;
	        this->head = auxiliar->getProximo();
	        if (this->head != NULL) {
	            this->head->setAnterior(NULL);
                delete this->head->getAnterior();
	        }
	        this->tamanho -= 1;
	    }
	}

/*!
* Adiciona um novo elemento em determinada posicao da lista
* 
* @param dado O dado a ser adicionado na lista
* @param pos A posicao que o elemento será adicionado
*/
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	    ElementoDuplo<T> *auxiliar, *anterior;
	    if (pos == 0 || this->listaVazia()) {
            this->adicionaNoInicioDuplo(dado);
        }
	    if (pos >= this->tamanho || pos < 0) {
	        throw "Erro de posicao";
	    }
	    anterior = this->head;
	    int i;
	    for (i = 0; i < pos -1; i++) {
	        anterior = anterior->getProximo();
	    }
	    auxiliar = new ElementoDuplo<T>(dado, anterior->getProximo(), anterior);
	    if (auxiliar->getProximo() != NULL) {
            auxiliar->getProximo()->setAnterior(auxiliar);
        }
        anterior->setProximo(auxiliar);
        this->tamanho += 1;
	    }

/*!
* Retorna a posicao de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	int posicaoDuplo(const T& dado) const {
	    ElementoDuplo<T> *auxiliar;
	    if (this->listaVazia()) {
	        throw "A lista está vazia";
	    } else {
	        auxiliar = this->head;
	        int i;
	        for (i = 0; i < this->tamanho -1; i++) {
	            if (auxiliar->getInfo() == dado) {
	                return i;
	            }
	            auxiliar = auxiliar->getProximo();
	            if (auxiliar == NULL) {
	                throw "É nulo";
	            }
	        }
	        throw "Não encontrado";
	    }
	}

/*!
* Retorna a posicao de memória de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	T* posicaoMemDuplo(const T& dado) const {
	    ElementoDuplo<T> *auxiliar;
	    T posicao;
	    if (this->listaVazia()) {
	        throw "A lista está vazia";
	    } else {
	        auxiliar = this->head;
	        int i;
	        for (i = 0; i < this->tamanho-1; i++) {
	            if (auxiliar->getInfo() == dado) {
	                posicao = auxiliar->getInfo();
	                return &posicao;
	            }
	            auxiliar = auxiliar->getProximo();
	        }
	    }
	    throw "Não existe o dado";
	}

/*!
* Verifica, e retorna, se um determinado dado está na lista
* 
* @param dado O dado a ser procurado na lista
*/
	bool contemDuplo(const T& dado) {
	    ElementoDuplo<T> *auxiliar;
	    if (this->listaVazia()) {
	        throw "A lista está vazia";
	    } else {
	        auxiliar = this->head;
	        int i;
	        for (i = 0; i <= this->tamanho -1; i++) {
	            if (auxiliar->getInfo() == dado) {
	                return true;
	            }
	            auxiliar = auxiliar->getProximo();
	        }
	        return false;
        }
	}

/*!
* Retira, e retorna, um dado de determinada posicao
* 
* @param pos A posicao que contem o dado a ser retirado
*/
	T retiraDaPosicaoDuplo(int pos) {
	    ElementoDuplo<T> *auxiliar, *eliminar;
	    T dadoRetornado;
	    if (this->listaVazia()) {
	        throw "A lista está vazia";
	    }
	    if (pos >= this->tamanho || pos < 0) {
	        throw "Erro de posicao";
	    }
	    if (pos == 0) {
	        return this-> retiraDoInicioDuplo();
	    }
	    int i;
	    auxiliar = this->head;
	    for (i = 0; i < pos -1; i++) {
	        auxiliar = auxiliar->getProximo();
	    }
	    if (auxiliar == NULL) {
	        throw "Não existe";
	    }
	    eliminar = auxiliar->getProximo();
	    dadoRetornado = eliminar->getInfo();
	    auxiliar->setProximo(eliminar->getProximo());
	    if (auxiliar->getProximo() != NULL) {
	        eliminar->getProximo()->setAnterior(auxiliar);
	    }
	    delete eliminar;
	    this->tamanho -= 1;
	    return dadoRetornado;
	}

/*!
* Adiciona um novo elemento no final da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adicionaDuplo(const T& dado) {
	    ElementoDuplo<T> *auxiliar, *novo;
	    if (this->listaVazia()) {
	        return this->adicionaNoInicioDuplo(dado);
	    } else {
	        auxiliar = this->head;
	        int i;
	        for (i = 0; i < this->tamanho-1; i++) {
	            auxiliar = auxiliar->getProximo();
	        }
	        novo = new ElementoDuplo<T>(dado, NULL, auxiliar);
	        auxiliar->setProximo(novo);
	        this->tamanho += 1;
	    }
	}

/*!
* Retira o ultimo elemento da lista
*/
	T retiraDuplo() {
	    ElementoDuplo<T> *auxiliar;
	    T dadoRemovido;
	    if (this->listaVazia()) {
	        throw "A lista já está vazia";
	    } else {
	        auxiliar = this->head;
	        int i;
	        if (this->tamanho == 1) {
	            return this->retiraDoInicioDuplo();
	        }
	        for (i = 0; i < this->tamanho -2; i++) {
	            auxiliar = auxiliar->getProximo();
	        }
	        dadoRemovido = auxiliar->getProximo()->getInfo();
	        delete auxiliar->getProximo();
	        auxiliar->setProximo(NULL);
	        this->tamanho -= 1;
	        return dadoRemovido;
	    }
	}

/*!
* Retira um determinado dado da lista
* 
* @param dado O dado a ser procurado e removido na lista
*/
	T retiraEspecificoDuplo(const T& dado) {
	    return this->retiraDaPosicaoDuplo(this->posicaoDuplo(dado));
	}

/*!
* Retorna o dado presente em determinada posicao
* 
* @param pos A posicao a ser procurada na lista
*/
	T mostra(int pos) {
	    ElementoDuplo<T> *auxiliar;
	    if (pos < 0 || pos >= this->tamanho) {
	        throw "Posicao Inválida";
	    } else {
	        auxiliar = this->head;
	        int i;
	        for (i = 0; i < pos; i++) {
	            auxiliar = auxiliar->getProximo();
	        }
	        return auxiliar->getInfo();
	    }
	}

/*!
* Adiciona um novo elemento na ordem seguida pela lista
* 
* @param data O dado a ser adicionado na lista
*/
	void adicionaEmOrdem(const T& data) {
	    ElementoDuplo<T> *auxiliar;
	    if (this->listaVazia()) {
	        return this->adicionaNoInicioDuplo(data);
	    } else {
	        auxiliar = this->head;
	        int posicao = 0;
	        while (auxiliar->getProximo() != NULL &&
	            this->maior(data, auxiliar->getInfo())) {
	            auxiliar = auxiliar->getProximo();
	            posicao++;
	        }
	        if (this->maior(data, auxiliar->getInfo())) {
	            this->adicionaNaPosicaoDuplo(data, posicao +1);
	        } else {
	            this->adicionaNaPosicaoDuplo(data, posicao);
	        }
	    }
	}

/*!
* Retorna a posicao do ultimo elemento da lista
*/
	int verUltimo() {
	    if (this->listaVazia()) {
	        throw "Lista vazia";
	    } else {
	        return this->tamanho -1;
	    }
	}

/*!
* Retorna se a lista está vazia
*/
	bool listaVazia() const {
	    return this->tamanho == 0;
	}

/*!
* Verifica se dois determinados dados são iguais
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool igual(T dado1, T dado2) {
	    return dado1 == dado2;
	}

/*!
* Verifica se um dado é maior do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool maior(T dado1, T dado2) {
	    return dado1 > dado2;
	}

/*!
* Verifica se um dado é menor do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool menor(T dado1, T dado2) {
	    return dado1 < dado2;
	}

/*!
* Destroi a lista e seus elementos da memória
*/
	void destroiListaDuplo() {
	    ElementoDuplo<T> *auxiliar, *anterior;
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
