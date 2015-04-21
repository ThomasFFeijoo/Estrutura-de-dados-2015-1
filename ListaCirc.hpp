// Copyright [2015] <Thomas>
//! Implementação de uma lista circular
/*!
* \author Thomas Fernandes Feijoo
* \since 20/04/2015
* \version 1.0
*/
#include "ListaEnc.hpp"
template <typename T>

class ListaCirc : private ListaEnc<T> {
 private:
    Elemento<T> *sentinela;  //!< Elemento atachado ao head da lista

 public:
/*!
* Construtor de uma lista circular
*/
	ListaCirc() {
	    this->head = new Elemento<T>(0, NULL);
        this->head->setProximo(this->head);
        this->tamanho = 0;
	}

/*!
* Destrutor de uma lista circular
*/
	~ListaCirc() {
	}

/*!
* Adiciona um novo dado no início da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adicionaNoInicio(const T& dado) {
	    ListaEnc<T>::adicionaNoInicio(dado);
	    sentinela = this->head;
	    int i;
	    for (i = 0; i < this->tamanho-1; i++) {
	        sentinela = sentinela->getProximo();
	    }
	    sentinela->setProximo(this->head);
	}

/*!
* Remove e retorna o elemento presente no inicio da lista
*/
	T retiraDoInicio() {
	    T valorRetirado = ListaEnc<T>::retiraDoInicio();
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
        return valorRetirado;
	}

/*!
* Remove o elemento presente no início da lista
*/
	void eliminaDoInicio() {
	    ListaEnc<T>::eliminaDoInicio();
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
	}

/*!
* Adiciona um novo elemento em determinada posicao da lista
* 
* @param dado O dado a ser adicionado na lista
* @param pos A posicao que o elemento será adicionado
*/
	void adicionaNaPosicao(const T& dado, int pos) {
	    ListaEnc<T>::adicionaNaPosicao(dado, pos);
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
	}

/*!
* Retorna a posicao de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	int posicao(const T& dado) const {
	    return ListaEnc<T>::posicao(dado);
	}

/*!
* Retorna a posicao de memória de um determinado dado
* 
* @param dado O dado a ser procurado na lista
*/
	T* posicaoMem(const T& dado) const {
	    return ListaEnc<T>::posicaoMem(dado);
	}

/*!
* Verifica, e retorna, se um determinado dado está na lista
* 
* @param dado O dado a ser procurado na lista
*/
	bool contem(const T& dado) {
	    return ListaEnc<T>::contem(dado);
	}

/*!
* Retira, e retorna, um dado de determinada posicao
* 
* @param pos A posicao que contem o dado a ser retirado
*/
	T retiraDaPosicao(int pos) {
	    T valorRetornado = ListaEnc<T>::retiraDaPosicao(pos);
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
        return valorRetornado;
	}

/*!
* Adiciona um novo elemento no final da lista
* 
* @param dado O dado a ser adicionado na lista
*/
	void adiciona(const T& dado) {
	    if (this->listaVazia()) {
            return this->adicionaNoInicio(dado);
        }
        int i;
        Elemento<T> *auxiliar = this->head;
        for (i = 0; i < this->tamanho-1; i++) {
            auxiliar = auxiliar->getProximo();
        }
        sentinela = auxiliar->getProximo();
        Elemento<T> *novo = new Elemento<T>(dado, sentinela);
        auxiliar->setProximo(novo);
        this->tamanho++;
	}

/*!
* Retira o ultimo elemento da lista
*/
	T retira() {
	    T valorRetornado = ListaEnc<T>::retira();
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
        return valorRetornado;
	}

/*!
* Retira um determinado dado da lista
* 
* @param dado O dado a ser procurado e removido na lista
*/
	T retiraEspecifico(const T& dado) {
	    T valorRetornado = ListaEnc<T>::retiraEspecifico(dado);
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
        return valorRetornado;
	}

/*!
* Retorna o dado presente em determinada posicao
* 
* @param pos A posicao a ser procurada na lista
*/
	T mostra(int pos) {
	    return ListaEnc<T>::mostra(pos);
	}

/*!
* Adiciona um novo elemento na ordem seguida pela lista
* 
* @param data O dado a ser adicionado na lista
*/
	void adicionaEmOrdem(const T& data) {
	    ListaEnc<T>::adicionaEmOrdem(data);
	    sentinela = this->head;
	    int i;
        for (i = 0; i < this->tamanho-1; i++) {
            sentinela = sentinela->getProximo();
        }
        sentinela->setProximo(this->head);
	}

/*!
* Retorna a posicao do ultimo elemento da lista
*/
	int verUltimo() {
	    return ListaEnc<T>::verUltimo();
	}

/*!
* Retorna se a lista está vazia
*/
	bool listaVazia() const {
	    return ListaEnc<T>::listaVazia();
	}

/*!
* Verifica se dois determinados dados são iguais
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool igual(T dado1, T dado2) {
	    return ListaEnc<T>::igual(dado1, dado2);
	}

/*!
* Verifica se um dado é maior do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool maior(T dado1, T dado2) {
	    return ListaEnc<T>::maior(dado1, dado2);
	}

/*!
* Verifica se um dado é menor do que outro
* 
* @param dado1 O primeiro dado a ser comparado
* @param dado2 O segundo dado a ser comparado
*/
	bool menor(T dado1, T dado2) {
	    return ListaEnc<T>::menor(dado1, dado2);
	}

/*!
* Destroi a lista e seus elementos da memória
*/
	void destroiLista() {
	    ListaEnc<T>::destroiLista();
	}
};
