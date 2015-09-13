// Copyright [2015] <Thomas>
//! Implementação de uma pilha
/*!
 * \author Thomas Fernandes Feijoo
 * \since 21/03/2015
 * \version 1.0
 */

const int tamanhoMaximoPadrao = 50; /*! Uma constante a qual armazena um tamanho Maximo padrao para a pilha.*/
template<typename T>

/*! A classe a seguir implementa uma pilha */
class Pilha {
 private:
T* vetor; /*!< Vetor que armazena os dados da pilha */
int topoPilha; /*!< Variável a qual armazena a posição do topo da pilha */
int tamanhoMaximo; /*!< Variável a qual armazena o valor máximo do tamanho da Pilha */

 public:
//! Construtor de uma pilha padrão
/*! Este construtor instancia uma pilha utlizando o tamanhoMaximoPadrao */
    Pilha() {
        this->topoPilha = -1;
        this->vetor = new T[tamanhoMaximoPadrao];
        this->tamanhoMaximo = tamanhoMaximoPadrao;
     }

//! Construtor de uma pilha configurável
/*! Este construtor inicia uma pilha com tamanho "t" e posição inicial como -1*/
    Pilha<T>(int t) {
        if (t < 0) { /* Não é possível criar uma pilha com tamanho negativo */
            throw "Valor inválido";
    }
        this->topoPilha = -1;
        this->vetor = new T[t];
        this->tamanhoMaximo = t;
    }

//! Método o qual empilha um dado na pilha.
 /*!
 \parametro genérico "dado" será um novo dado inserido no topo da fila
 \enquanto o topo é acrescido em 1 
 */ 
	void empilha(T dado) {
	    if (PilhaCheia()) { /*Não é possível empilhar um dado novo numa pilha cheia */
	        throw "A Pilha está cheia";
	}    else {
	    this->topoPilha += 1;
	    this->vetor[topoPilha] = dado;
	}
	}

//! Método o qual desempilha um dado na pilha.
 /*!
 \Retira o dado que estava no topo da pilha e retorna-o
 \O topo da pilha é reduzido em 1
 */ 
	T desempilha() {
	    if (PilhaVazia()) { /*Não é possivel desempilhar uma pilha vazia */
	        throw "A Pilha está vazia";
	}   else {
	    this->topoPilha -= 1;
	    return (vetor[topoPilha+1]);
	}
	}

//! Método o qual retorna o dado do topo da pilha */
	T topo() {
	    if (PilhaVazia()) { /*Não é possivel retornar o topo de uma pilha vazia */
	        throw "A Pilha está vazia";
	}   else {
	    return (vetor[topoPilha]);
	    }
	}

//! Método o qual retorna a posição do topo da pilha */
	int getPosTopo() {
        if (PilhaVazia()) { /*Não é possivel retornar a posição do topo de uma pilha vazia */
            throw "A Pilha está vazia";
    }   else {
        return this-> topoPilha;
    }
	}

//! Método o qual limpa a lista
 /*!
 \Remove todos os elementos presentes na pilha
 */
	void limparPilha() {
	    this->topoPilha = -1;
	}

//! Método que verifica se a pilha está vazia
 /*!
 \verifica se todas as posições da pilha estão vazias
 \retorna um boolean
 */
	bool PilhaVazia() {
	    return (topoPilha == -1);
	}

//! Método que verifica se a pilha está cheia
 /*!
 \verifica se todos as posições da pilha estão cheias
 \retorna um boolean
 */
	bool PilhaCheia() {
	return (topoPilha == tamanhoMaximo -1);
	}

//! Método o qual pega o valor "i" de uma posição determinada do vetor
/*!
\O método retorna o dado guardado na posição "i" do vetor
*/
	T getVetor(int i) {
	return vetor[i];
	}
};
