// Copyright [2015] <Thomas>
// !Implementação de uma Lista
/*!
 * \author: Thomas Fernandes Feijoo
 * \since 28/03/2015
 * \version 1.0
 */

const int tamanhoMaximoPadrao = 100;/*! Uma constante a qual armazena um tamanho Maximo padrao para a lista.*/
/*!Constantes que facilitam a identificação de uma exception.*/
const int ERROLISTACHEIA = -1;
const int ERROLISTAVAZIA = -2;
const int ERROPOSICAO = -3;
template<typename T>

/*! A classe a seguir implementa uma lista */
class Lista {
 public:
T* dados;/*!< Vetor que armazena os dados da lista */
int ultimo;/*!< Variável a qual armazena a posição do ultimo elemento da lista */
int tamanhoMaximo;/*!< Variável a qual armazena o valor máximo do tamanho da lista */

//! Construtor de uma lista padrão
/*! Este construtor instancia uma lista utlizando o tamanhoMaximoPadrao */
	Lista() {
	this-> dados = new T[tamanhoMaximoPadrao];
	this-> ultimo = -1;
	this-> tamanhoMaximo = tamanhoMaximoPadrao;
	}

//! Construtor de uma lista configurável
/*! Este construtor inicia uma lista com tamanho "tam" e posição inicial como -1*/
	explicit Lista(int tam) {
	if(tam < 0) { /* Não é possível criar uma lista com tamanho negativo */
	    throw "Valor Inválido!";
	} else {
	this-> dados = new T[tam];
	this-> ultimo = -1;
	this-> tamanhoMaximo = tam;
	}
	}

//! Método o qual adiciona um dado no final da lista
/*!
\parametro genérico "dado" será um novo dado inserido no topo da lista
\enquanto a posicao "ultimo" é acrescido em 1 
*/ 
	void adiciona(T dado) {
    if (listaCheia()) {/* Não é possível um dado numa lista cheia */
	    throw ERROLISTACHEIA;
	    } else {
	        this -> ultimo += 1;
	        this->dados[ultimo] = dado;
	    }
	}

//! Método o qual adiciona um dado no inicio da lista.
/*!
\parametro genérico "dado" será um novo dado inserido no inicio da lista
\fazendo com que todos os dados sejam deslocados 1 posição para trás
\ao passo que o "último" é incrementado em 1     
*/
	void adicionaNoInicio(T dado) {
	int posicaoAuxiliar; /* Variável que auxilia no deslocamento de posições*/
	if (listaCheia()) {/* Não é possível um dado numa lista cheia */
	    throw ERROLISTACHEIA;
	} else {
	    this-> ultimo += 1;
	    posicaoAuxiliar = this-> ultimo;
	    while (posicaoAuxiliar > 0) {
	    this->dados[posicaoAuxiliar] = this->dados[posicaoAuxiliar-1];
	    posicaoAuxiliar -= 1;
	    }
	    this->dados[0] = dado;
	}
	}

//! Método o qual adiciona um dado em determinada posição da lista.
/*!
\parametro genérico "dado" será um novo dado inserido
\em determinada "posicao" da lista
\fazendo com que todos os dados a partir de tal posicao 
\sejam deslocados 1 posição para trás
\ao passo que o "último" é incrementado em 1     
*/ 
    void adicionaNaPosicao(T dado, int posicao) {
	int posicaoAuxiliar;/* Variável que auxilia no deslocamento de posições*/
	if (listaCheia()) {/* Não é possível um dado numa lista cheia */
	    throw ERROLISTACHEIA;
	} else {
	    if (posicao >= this->tamanhoMaximo || posicao < 0) {/* Não é possível um dado numa posicao inexistente */
	        throw ERROPOSICAO;
	    } else {
	    this->ultimo += 1;
	    posicaoAuxiliar = this->ultimo;
	    while (posicaoAuxiliar > posicao) {
	        this->dados[posicaoAuxiliar] = this->dados[posicaoAuxiliar-1];
	        posicaoAuxiliar -= 1;
	    }
	    }
	    this->dados[posicao] = dado;
	}
	}

//! Método o qual adiciona um dado em ordem na lista.
/*!
\parametro genérico "dado" será um novo dado inserido
\na lista seguindo determinada ordem de posicao.
\É verificado em qual posicao o novo dado deve ser adicionado,
\e essa posicao e o dado são repassados para o metodo adicionaNaPosicao()
\fazer a adicao
*/ 
	void adicionaEmOrdem(T dado) {
	    int posicaoAuxiliar;/* Variável que auxilia na verificacao de posições*/
	    if (listaCheia()) {/* Não é possível um dado numa lista cheia */
            throw ERROLISTACHEIA;
        } else {
            posicaoAuxiliar = 0;
            while (posicaoAuxiliar <= this->ultimo &&
                dado > this->dados[posicaoAuxiliar]) {
            posicaoAuxiliar += 1;
            }
            adicionaNaPosicao(dado, posicaoAuxiliar);
        }
	}

//! Método o qual retira um dado do final da lista.
/*!
\retira e da um return no dado retirado
*/ 
	T retira() {/* Não é retirar um dado de uma lista vazia*/
	    if (listaVazia()) {
	     throw ERROLISTAVAZIA;
	    } else {
	    this->ultimo -= 1;
	    return this->dados[ultimo +1];
	    }
	}

//! Método o qual retira um dado do inicio da lista.
/*!
\um "dado" será retirado da lista, ao passo que todos os outros dados
\presentes na lista serão deslocados 1 posicao para a frente
\e a posicao "ultimo" decrementada em 1
\retorna o dado retirado
*/ 
	T retiraDoInicio() {
	int posicaoAuxiliar;/* Variável que auxilia no deslocamento de posições*/
	int valorRetirado;/* Variável que armazena o valor que foi retirado*/
	    if (listaVazia()) {/* Não é retirar um dado de uma lista vazia*/
	        throw ERROLISTAVAZIA;
	    } else {
	        this-> ultimo -= 1;
	        valorRetirado = this->dados[0];
	        posicaoAuxiliar = 0;
	        while (posicaoAuxiliar <= ultimo) {
	            this->dados[posicaoAuxiliar] = this->dados[posicaoAuxiliar+1];
	            posicaoAuxiliar += 1;
	        }
	        return valorRetirado;
	    }
	}

//! Método o qual retira um dado de determinada posição da lista.
/*!
\um "dado" será retirado de determinada posicao da lista,
\e assim todos os outros dados presentes depois dele serão deslocados
\1 posicao para a frente, e a posicao "ultimo" será decrementada em 1 
\retorna o dado retirado
*/
	T retiraDaPosicao(int posicao) {
    int posicaoAuxiliar;/* Variável que auxilia no deslocamento de posições*/
    int valorRetirado;/* Variável que o valor que foi retirado*/
    if (posicao > this->ultimo || posicao < 0) {/* Não é retirar um dado de uma posicao inexistente*/
        throw ERROPOSICAO;
    } else {
        if (listaVazia()) {/* Não é retirar um dado de uma lista vazia*/
            throw ERROLISTAVAZIA;
        } else {
        this->ultimo -= 1;
        valorRetirado = this->dados[posicao];
        posicaoAuxiliar = posicao;
        while (posicaoAuxiliar <= this->ultimo) {
            this->dados[posicaoAuxiliar] = this->dados[posicaoAuxiliar -1];
            posicaoAuxiliar += 1;
        }
        }
        return valorRetirado;
    }
	}

//! Método o qual retira um dado especifico da lista.
/*!
\um "dado" especifico será retirado da lista após sua posicao
\ser descoberta pelo método "posicao()" e repassada para o metodo
\"retiraDaPosicao()"
\retorna o dado retirado
*/
	T retiraEspecifico(T dado) {
	    int posicaoAuxiliar;/* Variável que armazena a posicao de um dado*/
	    if (listaVazia()) {/* Não é retirar um dado de uma lista vazia*/
	        throw ERROLISTAVAZIA;
	    } else {
	        posicaoAuxiliar = posicao(dado);
	        if (posicaoAuxiliar < 0) {/* Não é retirar um dado de uma posicao inexistente*/
	            throw ERROPOSICAO;
	        } else {
	            return retiraDaPosicao(posicaoAuxiliar);
	        }
	    }
	}

//! Método o qual retorna a posicao de um "dado" na lista.
	int posicao(T dado) {
	    int posicaoAuxiliar;/* Variável que auxilia na comparacao de dados*/
	    posicaoAuxiliar = 0;
	    while (posicaoAuxiliar <= this->ultimo &&
	        !(igual(dado, this->dados[posicaoAuxiliar]))) {
	            posicaoAuxiliar += 1;
	        }
        if (posicaoAuxiliar > this->ultimo) {/* posicao auxiliar ultrapassou o ultimo pois dado nao foi encontrado*/
            throw ERROPOSICAO;
        } else {
            return posicaoAuxiliar;
        }
	}

//! Método o qual verifica se a lista contém determinado "dado".
/*!
\retorna um boolean
*/
	bool contem(T dado) {
	int posicaoAuxiliar;/* Variável que auxilia na verificacao dos dados*/
	bool encontrado = false;
	    for (posicaoAuxiliar = 0; posicaoAuxiliar <= this->ultimo; posicaoAuxiliar++) {
	        if (this->dados[posicaoAuxiliar] == dado) {
	        encontrado = true;
	        break;
	        }
	    }
	    return encontrado;
	}

//! Método o qual compara dois dados para descobrir se são iguais.
/*!
\retorna um boolean
*/
	bool igual(T dado1, T dado2) {
	    return dado1 == dado2;
	}

//! Método o qual compara dois dados para descobrir qual é maior.
/*!
\retorna um boolean
*/
	bool maior(T dado1, T dado2) {
	    return dado1 > dado2;
	}

//! Método o qual compara dois dados para descobrir qual é menor.
/*!
\retorna um boolean
*/
	bool menor(T dado1, T dado2) {
	    return dado1 < dado2;
	}

//! Método o qual faz a verificacao se a lista esta cheia.
/*!
\retorna um boolean
*/
	bool listaCheia() {
	    return (this->ultimo == this->tamanhoMaximo - 1);
	}

//! Método o qual faz a verificacao se a lista esta cheia.
/*!
\retorna um boolean
*/
	bool listaVazia() {
	    return (this->ultimo == -1);
    }

//! Método o qual reinicializa o conteudo da lista.
/*!
\retorna um boolean
*/
	void destroiLista() {
	    this->ultimo = -1;
	}
};
