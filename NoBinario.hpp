// Copyright [2015] <Thomas>
//! Implementação de um Nó Binário que tem a capacidade de
// representar uma Árvore Binária
/*!
* \author Thomas Fernandes Feijoo
* \since 18/05/2015
* \version 1.0
*/
#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class NoBinario {
 protected:
    T* dado;  //!< atributo que representa o valor do nó
    NoBinario<T>* esquerda;  //!< atributo que aponta para o nó da esquerda
    NoBinario<T>* direita;  //!< atributo que aponta para o nó da direita
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado
/*!
* Construtor de um Nó Binário
*/
 public:
    NoBinario<T>(const T& dado) {
        this->dado = new T(dado);
        this->esquerda = NULL;
        this->direita = NULL;
    }

/*!
* Destrutor de um Nó Binário
*/
    virtual ~NoBinario() {
        delete this->dado;
        delete this->esquerda;
        delete this->direita;
    }

/*!
* Retorna o dado do Nó
*/
    T* getDado() {
        return this->dado;
    }

/*!
* Retorna os elementos percorridos pelos métodos preOrdem, emOrdem e posOrdem
*/
    std::vector< NoBinario<T>* > getElementos() {
        return this->elementos;
    }

/*!
* Retorna o filho da esquerda
*/
    NoBinario<T>* getEsquerda() {
        return this->esquerda;
    }

/*!
* Retorna o filho da direita
*/
    NoBinario<T>* getDireita() {
        return this->direita;
    }

/*!
* Busca um determinado dado na árvore
* 
* @param dado Dado a ser buscado na árvore
* @param arv Árvore que o dado vai ser buscado
*/
    T* busca(const T& dado, NoBinario<T>* arv) {
        while (arv != NULL && *(arv->getDado()) != dado) {
            if (*(arv->getDado()) < dado) {
                arv = arv->getDireita();
            } else {
                arv = arv->getEsquerda();
            }
        }
        if (arv == NULL) {
            throw "Não encontrado";
        }
        return arv->getDado();
    }

/*!
* Insere um determinado dado na árvore
* 
* @param dado Dado a ser inserido na árvore
* @param arv Árvore em que o dado vai ser inserido
*/
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
        NoBinario<T>* novo;
        if (dado < *(arv->getDado())) {
            if (arv->getEsquerda() == NULL) {
                novo = new NoBinario<T>(dado);
                arv->esquerda = novo;
            } else {
                arv->esquerda = this->inserir(dado, arv->getEsquerda());
            }
        } else if (dado > *(arv->getDado())) {
            if (arv->getDireita() == NULL) {
                novo = new NoBinario<T>(dado);
                arv->direita = novo;
            } else {
                arv->direita = this->inserir(dado, arv->getDireita());
            }
            }
        return arv;
    }

/*!
* Remove um determinado dado da árvore 
* 
* @param dado Dado a ser removido da árvore
* @param arv Árvore a qual será iniciada a busca pelo dado a ser removido
*/
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
        NoBinario<T>* temporario;
        NoBinario<T>* filho;
        if (arv == NULL) {
            return arv;
        } else if (dado < *(arv->getDado())) {
                arv->esquerda = this->remover(arv->getEsquerda(), dado);
                return arv;
            } else if (dado > *(arv->getDado())) {
                    arv->direita = this->remover(arv->getDireita(), dado);
                    return arv;
                } else if (arv->getDireita() != NULL &&
                            arv->getEsquerda() != NULL) {
                        temporario = this->minimo(arv->getDireita());
                        arv->dado = temporario->getDado();
                        arv->direita = remover(arv->direita,
                                                *(temporario->getDado()));
                        return arv;
                    } else {
                        temporario = arv;
                        if (arv->direita != NULL) {
                            filho = arv->direita;
                            return filho;
                        } else if (arv->esquerda != NULL) {
                                filho = arv->esquerda;
                                return filho;
                            } else {
                                delete arv;
                                return NULL;
                            }
                        }
    }

/*!
* Retorna o valor mínimo guardado na árvore
*
* @param arv Árvore em que o valor mínimo vai ser buscado
*/
    NoBinario<T>* minimo(NoBinario<T>* nodo) {
        if (nodo->getEsquerda() == NULL) {
            return nodo;
        }
        return this->minimo(nodo->getEsquerda());
    }

/*!
* Realiza um percurso de pré-ordem (raiz primeiro, depois
* filho da esquerda e depois filho da direita)
*
* @param arv Árvore em que o percurso deve ser realizado
*/
    void preOrdem(NoBinario<T>* nodo) {
        if (nodo == NULL) {
            return;
        }
        this->elementos.push_back(nodo);
        this->preOrdem(nodo->getEsquerda());
        this->preOrdem(nodo->getDireita());
    }

/*!
* Realiza um percurso em-ordem (filho da esquerda
* primeiro, depois raiz e depois filho da direita)
*
* @param arv Árvore em que o percurso deve ser realizado
*/
    void emOrdem(NoBinario<T>* nodo) {
        if (nodo == NULL) {
            return;
        }
        this->emOrdem(nodo->getEsquerda());
        this->elementos.push_back(nodo);
        this->emOrdem(nodo->getDireita());
    }

/*!
* Realiza um percurso de pós-ordem (filho da esquerda primeiro, depois
* filho da direita e depois raiz)
*
* @param arv Árvore em que o percurso deve ser realizado
*/
    void posOrdem(NoBinario<T>* nodo) {
        if (nodo == NULL) {
            return;
        }
        this->posOrdem(nodo->getEsquerda());
        this->posOrdem(nodo->getDireita());
        this->elementos.push_back(nodo);
    }
};

#endif /* NO_BINARIO_HPP */
