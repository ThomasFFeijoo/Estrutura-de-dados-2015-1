// Copyright [2015] <Thomas>
//! Implementação de uma fila
/*!
 * \author Thomas Fernandes Feijoo
 * \since 21/03/2015
 * \version 1.0
 */

#include "Pilha.hpp"
template <typename T>

/*! A classe a seguir implementa uma pilha */
class Fila {
 private:
int tamanhoMaximo; /*!< Variável a qual armazena o valor máximo do tamanho da fila */
int topoFila; /*!< Variável a qual armazena a posição do topo da fila */
Pilha<T> *vetorFila; /*!< Vetor que armazena os dados da fila */

 public:
//! Construtor de uma fila padrão
/*! Este construtor instancia uma fila utlizando o tamanhoMaximoPadrao */
    Fila() {
    	this-> topoFila = -1;
    	this-> tamanhoMaximo = tamanhoMaximoPadrao;
    	this-> vetorFila = new Pilha<T>(tamanhoMaximoPadrao);
	}

//! Construtor de uma fila configurável
/*! Este construtor inicia uma fila com tamanho "tam" 
\e posição inicial como -1*/
	Fila<T>(int tam) {
        this-> topoFila = -1;
        this-> tamanhoMaximo = tam;
        this-> vetorFila = new Pilha<T>(tam);
    }

//! Método o qual inclui um dado na fila.*/
	void inclui(T dado) {
	this-> vetorFila-> empilha(dado);
	}

//! Método o qual retira um dado da fila.
/*! 
\Retira o primeiro dado da fila, ao passo que desloca 
\os outros dados uma posição para frente.
\Retorna o primeiro dado da fila.
*/
	T retira() {
	if (this-> vetorFila->PilhaVazia()) {
	    throw "A fila encontra-se vazia";
    } else {
        T dado = this->vetorFila->getVetor(0);
        for (int a = 0; a < this->topoFila; a++) {
        this->vetorFila[a] = this->vetorFila[a+1];
        }
        this->vetorFila-> desempilha();
        return dado;
    }
	}

//! Método o qual retorna o ultimo dado da fila */
	T ultimo() {
    	return this-> vetorFila-> topo();
	}

//! Método o qual retorna a ultima posição da fila */
	int getUltimo() {
	    return this-> vetorFila-> getPosTopo();
	}

//! Método que verifica se a fila está cheia */
	bool filaCheia() {
	    return this-> vetorFila-> PilhaCheia();
	}
//! Método que verifica se a fila está vazia */
	bool filaVazia() {
	    return this-> vetorFila-> PilhaVazia();
	}

//! Função que remove todos os elementos armazenados na fila */
	void inicializaFila() {
	    return this-> vetorFila-> limparPilha();
    }
};

