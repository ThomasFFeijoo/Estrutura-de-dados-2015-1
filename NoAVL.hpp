// Copyright [2015] <Thomas>
//! Implementação de um Nó AVL que tem a capacidade de
// representar uma Árvore AVL
/*!
* \author Thomas Fernandes Feijoo
* \since 25/05/2015
* \version 1.0
*/
#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>

template <typename T>
class NoAVL  {
 private:
    int altura;  //!< Representa a altura do nó AVL
    T* dado;  //!< atributo que representa o valor do nó
    NoAVL<T>* esquerda;  //!< atributo que aponta para o nó da esquerda
    NoAVL<T>* direita;  //!< atributo que aponta para o nó da direita
    std::vector<NoAVL<T>* > elementos;  //!< Elementos acessados durante
                                        // o percurso realizado

/*!
* Construtor de um Nó AVL
*/
 public:
    explicit NoAVL(const T& dado) {
        this->altura = 0;
        this->dado = new T(dado);
        this->esquerda = NULL;
        this->direita = NULL;
    }

/*!
* Destrutor de um Nó AVL
*/
    virtual ~NoAVL() {
        this->altura = -1;
        delete this->esquerda;
        delete this->direita;
        delete this->dado;
    }

/*!
* Retorna a altura do nó
*/
    int getAltura() {
        return this->altura;
    }

/*!
* Retorna os elementos percorridos
*/
    std::vector<NoAVL<T>* > getElementos() {
        return this->elementos;
    }

/*!
* Retorna nó conectado a sua esquerda
*/
    NoAVL<T>* getEsquerda() {
        return this->esquerda;
    }

/*!
* Retorna nó conectado a sua direita
*/
    NoAVL<T>* getDireita() {
        return this->direita;
    }

/*!
* Insere um determinado dado na árvore
* 
* @param dado Dado a ser inserido na árvore
* @param arv Árvore em que o dado vai ser inserido
*/
    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv) {
        NoAVL<T>* novo;
         if (dado < *(arv->getDado())) {
             if (arv->getEsquerda() == NULL) {
                 novo = new NoAVL<T>(dado);
                 arv->esquerda = novo;
             } else {
                 arv->esquerda = this->inserir(dado, arv->getEsquerda());
             }
         } else if (dado > *(arv->getDado())) {
             if (arv->getDireita() == NULL) {
                 novo = new NoAVL<T>(dado);
                 arv->direita = novo;
             } else {
                 arv->direita = this->inserir(dado, arv->getDireita());
             }
             }
         return balancear(arv);
    }

/*! 
* Retorna o valor de desbalanceamento da árvre.
*
* @param raiz A raiz da árvore que será analisada.
*/
int fator(NoAVL<T>* raiz) {
    if (raiz->getEsquerda() == NULL && raiz->getDireita() == NULL) {
        return -1;
    } else if (raiz->getEsquerda() != NULL && raiz->getDireita() != NULL) {
        this->atualizaAltura(raiz->getEsquerda());
        this->atualizaAltura(raiz->getDireita());
        return (raiz->getEsquerda()->getAltura() -
                    raiz->getDireita()->getAltura());
    } else if (raiz->getEsquerda() != NULL) {
        this->atualizaAltura(raiz->getEsquerda());
        return (raiz->getEsquerda()->getAltura() + 1);
    } else {
        this->atualizaAltura(raiz->getDireita());
        return (-1 - raiz->getDireita()->getAltura());
    }
}

/*!
* Método que faz o balanceamento se necessario e com qual rotação realizar, se
* necessária, após um dado ser inserido ou removido
* @param auxiliar Árvore que será balanceada
*/
    NoAVL<T>* balancear(NoAVL<T>* auxiliar) {
        int balancoPai, balancoFilhoEsq, balancoFilhoDir;
    balancoPai = this->fator(auxiliar);
    if (auxiliar->getDireita() != NULL && balancoPai < -1) {
        balancoFilhoDir = this->fator(auxiliar->getDireita());
        if (balancoFilhoDir == 1) {
            auxiliar->direita = this->simp_roda_esq(auxiliar->getDireita());
        }
        auxiliar = this->simp_roda_dir(auxiliar);
    } else if (auxiliar->getEsquerda() != NULL && balancoPai > 1) {
        balancoFilhoEsq = this->fator(auxiliar->getEsquerda());
        if (balancoFilhoEsq == -1) {
            auxiliar->esquerda = this->simp_roda_dir(auxiliar->getEsquerda());
        }
        auxiliar = this->simp_roda_esq(auxiliar);
    }
    this->atualizaAltura(auxiliar);
    return auxiliar;
    }

/*!
* Realiza uma rotação simples à esquerda e retorna o resultado da rotação.
* @param nodo O nodo que será rebalanceado.
*/
    NoAVL<T>* simp_roda_esq(NoAVL<T>* nodo) {
        NoAVL<T>* temporario;

        temporario = nodo->getEsquerda();
        nodo->esquerda = temporario->getDireita();
        temporario->direita = nodo;

        this->atualizaAltura(temporario);
        this->atualizaAltura(nodo);
        return temporario;
    }

/*!
*Realiza uma rotação simples à direita e retorna o resultado da rotação.
* @param nodo O nodo que será rebalanceado.
*/
    NoAVL<T>* simp_roda_dir(NoAVL<T>* nodo) {
        NoAVL<T>* temporario;

        temporario = nodo->getDireita();
        nodo->direita = temporario->getEsquerda();
        temporario->esquerda = nodo;

        this->atualizaAltura(temporario);
        this->atualizaAltura(nodo);
        return temporario;
    }

/*! Realiza uma rotação dupla à esquerda e retorna o resultado da rotação.
* @param nodo O nodo que será rebalanceado.
*/
    NoAVL<T>* dup_roda_esq(NoAVL<T>* nodo) {
        nodo->esquerda = this->simp_roda_dir(nodo->getEsquerda());
        return this->simp_roda_esq(nodo);
    }

/*! Realiza uma rotação dupla à direita e retorna o resultado da rotação.
* @param nodo O nodo que será rebalanceado.
*/
    NoAVL<T>* dup_roda_dir(NoAVL<T>* nodo) {
        nodo->direita = this->simp_roda_esq(nodo->getDireita());
        return this->simp_roda_dir(nodo);
    }

/*! Atualiza a altura da raiz baseado nas alturas de seus filhos 
* @Param raiz O nodo que será atualizado.
*/
    void atualizaAltura(NoAVL<T>* raiz) {
        raiz->altura = this->maximo(raiz->getEsquerda(), raiz->getDireita()) +1;
    }

/*!
* Remove um determinado dado da árvore 
* 
* @param dado Dado a ser removido da árvore
* @param arv Árvore a qual será iniciada a busca pelo dado a ser removido
*/
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado) {
        NoAVL<T>* temporario;
        NoAVL<T>* filho;
        if (arv == NULL) {
            return arv;
        } else if (dado < *(arv->getDado())) {
                arv->esquerda = this->remover(arv->getEsquerda(), dado);
                return balancear(arv);
            } else if (dado > *(arv->getDado())) {
                    arv->direita = this->remover(arv->getDireita(), dado);
                    return balancear(arv);
                } else if (arv->getDireita() != NULL &&
                            arv->getEsquerda() != NULL) {
                        temporario = this->minimo(arv->getDireita());
                        arv->dado = new T(static_cast<T const&>(*(temporario->
                                                                   getDado())));
                        arv->direita = remover(arv->getDireita(),
                                                *(temporario->getDado()));
                        return balancear(arv);
                    } else if (arv->getDireita() != NULL) {
                        filho = arv->getDireita();
                        return balancear(filho);
                        } else if (arv->esquerda != NULL) {
                                filho = arv->getEsquerda();
                                return balancear(filho);
                            }
        delete arv;
        return NULL;
    }

/*!
* Retorna o valor mínimo guardado na árvore
*
* @param nodo Árvore em que o valor mínimo vai ser buscado
*/
    NoAVL<T>* minimo(NoAVL<T>* nodo) {
        if (nodo->getEsquerda() == NULL) {
            return nodo;
        }
        return this->minimo(nodo->getEsquerda());
    }

/*!
* Retorna o dado do Nó
*/
    T* getDado() {
        return this->dado;
    }

/*!
* Busca um determinado dado na árvore
* 
* @param dado Dado a ser buscado na árvore
* @param arv Árvore que o dado vai ser buscado
*/
    T* busca(const T& dado, NoAVL<T>* arv) {
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
* Retorna a altura máxima entre dois nodos
*
* @param nodo1 Nó que terá altura comparada com o segundo nodo
* @param nodo2 Nó que terá altura comparada com o primeiro nodo
*/
    int maximo(NoAVL<T>* nodo1, NoAVL<T>* nodo2) {
        if (nodo1 == NULL && nodo2 == NULL) {
            return -1;
        } else if (nodo1 == NULL) {
            return nodo2->getAltura();
        } else if (nodo2 == NULL) {
            return nodo1->getAltura();
        } else if (nodo1->getAltura() > nodo2->getAltura()) {
            return nodo1->getAltura();
        } else {
            return nodo2->getAltura();
        }
    }

/*!
* Realiza um percurso de pré-ordem (raiz primeiro, depois
* filho da esquerda e depois filho da direita)
*
* @param nodo Nodo que será adicionado a lista
*/
    void preOrdem(NoAVL<T>* nodo) {
        if (nodo == NULL) {
             return;
        }
        this->elementos.push_back(nodo);
        this->posOrdem(nodo->getEsquerda());
        this->posOrdem(nodo->getDireita());
    }

/*!
* Realiza um percurso em-ordem (filho da esquerda
* primeiro, depois raiz e depois filho da direita)
*
* @param nodo Nodo que será adicionado a lista
*/
    void emOrdem(NoAVL<T>* nodo) {
        if (nodo == NULL) {
             return;
        }
        this->posOrdem(nodo->getEsquerda());
        this->elementos.push_back(nodo);
        this->posOrdem(nodo->getDireita());
    }

/*!
* Realiza um percurso de pós-ordem (filho da esquerda primeiro, depois
* filho da direita e depois raiz)
*
* @param nodo Nodo que será adicionado a lista
*/
    void posOrdem(NoAVL<T>* nodo) {
        if (nodo == NULL) {
             return;
        }
        this->posOrdem(nodo->getEsquerda());
        this->posOrdem(nodo->getDireita());
        this->elementos.push_back(nodo);
    }
};

#endif /* NO_AVL_HPP */
