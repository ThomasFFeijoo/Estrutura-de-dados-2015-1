// Copyright [2015] <Thomas>
//! Implementação de uma lista circular duplamente encadeada
/*!
* \author Thomas Fernandes Feijoo
* \since 20/04/2015
* \version 1.0
*/
#include "ListaDupla.hpp"
template <typename T>

class ListaDuplaCirc : private ListaDupla<T>  {
/*!
* Construtor de uma lista circular duplamente encadeada
*/
 public:
	ListaDuplaCirc() {
	ElementoDuplo<T> *sentinela = new ElementoDuplo<T>(0, NULL, NULL);
    sentinela->setAnterior(sentinela);
    sentinela->setProximo(sentinela);
    this->head = sentinela;
    this->tamanho = 0;
	}

/*!
* Destrutor de uma lista circular
*/
	~ListaDuplaCirc() {
	}

/*!
* Adiciona um novo dado no início da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adicionaNoInicioDuplo(const T& dado) {
	    ElementoDuplo<T> *sentinela = this->head->getAnterior();
        ElementoDuplo<T> *auxiliar;
        auxiliar = new ElementoDuplo<T>(dado, this->head, sentinela);
        this->head = auxiliar;
        sentinela->setProximo(auxiliar);
        auxiliar->getProximo()->setAnterior(auxiliar);
        this->tamanho++;
	}

/*!
* Remove e retorna o elemento presente no inicio da lista
*/
	T retiraDoInicioDuplo() {
    	if (this->listaVazia()) {
            throw "Lista vazia";
        }
        T valorRetornado;
        ElementoDuplo<T> *sentinela = this->head->getAnterior();
        ElementoDuplo<T> *auxiliar = this->head;
        auxiliar->getProximo()->setAnterior(sentinela);
        valorRetornado = auxiliar->getInfo();
        if (auxiliar->getProximo() != NULL) {
            auxiliar->getProximo()->setAnterior(sentinela);
            sentinela->setProximo(auxiliar->getProximo());
            this->head = auxiliar->getProximo();
        }
        delete auxiliar;
        this->tamanho--;
        return valorRetornado;
	}

/*!
* Remove o elemento presente no início da lista
*/
	void eliminaDoInicioDuplo() {
    	if (this->listaVazia()) {
            throw "Lista vazia";
        }
        T valorRetornado;
        ElementoDuplo<T> *sentinela = this->head->getAnterior();
        ElementoDuplo<T> *auxiliar = this->head;
        auxiliar->getProximo()->setAnterior(sentinela);
        valorRetornado = auxiliar->getInfo();
        if (auxiliar->getProximo() != NULL) {
            auxiliar->getProximo()->setAnterior(sentinela);
            sentinela->setProximo(auxiliar->getProximo());
            this->head = auxiliar->getProximo();
        }
        delete auxiliar;
        this->tamanho--;
	}

/*!
* Adiciona um novo elemento em determinada posicao da lista
* 
* @param dado O dado a ser adicionado na lista
* @param pos A posicao que o elemento será adicionado
*/
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
	        ListaDupla<T>::adicionaNaPosicaoDuplo(dado, pos);
	}

/*!
* Retorna a posicao de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	int posicaoDuplo(const T& dado) const {
	    return ListaDupla<T>::posicaoDuplo(dado);
	}

/*!
* Retorna a posicao de memória de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	T* posicaoMemDuplo(const T& dado) const {
	    return ListaDupla<T>::posicaoMemDuplo(dado);
	}

/*!
* Verifica, e retorna, se um determinado dado está na lista
* 
* @param dado O dado a ser procurado na lista
*/
	bool contemDuplo(const T& dado) {
	    return ListaDupla<T>::contemDuplo(dado);
	}

/*!
* Retira, e retorna, um dado de determinada posicao
* 
* @param pos A posicao que contem o dado a ser retirado
*/
	T retiraDaPosicaoDuplo(int pos) {
	    return ListaDupla<T>::retiraDaPosicaoDuplo(pos);
	}

/*!
* Adiciona um novo elemento no final da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adicionaDuplo(const T& dado) {
    	if (this->listaVazia()) {
            return this->adicionaNoInicioDuplo(dado);
        }
        ElementoDuplo<T> *sentinela = this->head->getAnterior();
        ElementoDuplo<T> *auxiliar = sentinela->getAnterior();
        ElementoDuplo<T> *novo;
        novo = new ElementoDuplo<T>(dado, sentinela, auxiliar);
        auxiliar->setProximo(novo);
        sentinela->setAnterior(novo);
        this->tamanho++;
	}

/*!
* Retira o ultimo elemento da lista
*/
	T retiraDuplo() {
    	if (this->listaVazia()) {
            throw "Lista vazia";
        } else if (this->tamanho == 1) {
            return this->retiraDoInicioDuplo();
        } else {
        ElementoDuplo<T> *sentinela = this->head->getAnterior();
        ElementoDuplo<T> *auxiliar = sentinela->getAnterior();
        T valorRetornado = auxiliar->getInfo();
        auxiliar->getAnterior()->setProximo(sentinela);
        sentinela->setAnterior(auxiliar->getAnterior());
        delete auxiliar;
        this->tamanho--;
        return valorRetornado;
        }
	}

/*!
* Retira um determinado dado da lista
* 
* @param dado O dado a ser procurado e removido na lista
*/
	T retiraEspecificoDuplo(const T& dado) {
	    return ListaDupla<T>::retiraEspecificoDuplo(dado);
	}

/*!
* Retorna o dado presente em determinada posicao
* 
* @param pos A posicao a ser procurada na lista
*/
	T mostra(int pos) {
	    return ListaDupla<T>::mostra(pos);
	}

/*!
* Adiciona um novo elemento na ordem seguida pela lista
* 
* @param data O dado a ser adicionado na lista
*/
	void adicionaEmOrdem(const T& data) {
	    ListaDupla<T>::adicionaEmOrdem(data);
	}

/*!
* Retorna a posicao do ultimo elemento da lista
*/
	int verUltimo() {
	    return ListaDupla<T>::verUltimo();
	}

/*!
* Retorna se a lista está vazia
*/
	bool listaVazia() const {
	    return ListaDupla<T>::listaVazia();
	}

/*!
* Verifica se dois determinados dados são iguais
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool igual(T dado1, T dado2) {
	    return ListaDupla<T>::igual(dado1, dado2);
	}

/*!
* Verifica se um dado é maior do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool maior(T dado1, T dado2) {
	    return ListaDupla<T>::maior(dado1, dado2);
	}

/*!
* Verifica se um dado é menor do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool menor(T dado1, T dado2) {
	    return ListaDupla<T>::menor(dado1, dado2);
	}

/*!
* Destroi a lista e seus elementos da memória
*/
	void destroiListaDuplo() {
	    ListaDupla<T>::destroiListaDuplo();
	}
};

