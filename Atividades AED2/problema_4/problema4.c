#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListaAno {
    int ano;
    struct ListaAno *prox;
} ListaAno;

typedef struct Node {
    ListaAno *ano_projeto;
    char nome[16];
    int altura;
    struct Node *dir;
    struct Node *esq;
} Node;

ListaAno* inserirLista(ListaAno* lista, int numero) {
    ListaAno *novo = malloc(sizeof(ListaAno));
    novo->prox = NULL;
    novo->ano = numero;

    ListaAno *aux = lista;

    if(lista == NULL){
        return novo;
    }
    else{
        while (aux->prox != NULL){
            aux = aux->prox;
        }
    }
    aux->prox = novo;
    return lista;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Node *N) {
    return (N == NULL) ? 0 : N->altura;
}

int calcularBalanceamento(Node *no) {
    return (no == NULL) ? 0 : altura(no->esq) - altura(no->dir);
}

Node* rotacaoDireita(Node *v) {
    Node *raiz = v->esq;
    v->esq = raiz->dir;
    raiz->dir = v;
    raiz->dir->altura = 1 + max(altura(raiz->dir->esq), altura(raiz->dir->dir));
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    return raiz;
}

Node* rotacaoEsquerda(Node *v) {
    Node *raiz = v->dir;
    v->dir = raiz->esq;
    raiz->esq = v;
    raiz->esq->altura = 1 + max(altura(raiz->esq->esq), altura(raiz->esq->dir));
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    return raiz;
}


Node* inserir(Node* raiz, char *nome, int ano_projeto) {
    if (raiz == NULL) {
        Node *novo = malloc(sizeof(Node));
        strcpy(novo->nome, nome);
        novo->altura = 1;
        novo->ano_projeto = inserirLista(NULL, ano_projeto);
        novo->esq = NULL; 
        novo->dir = NULL;
        return novo;
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao > 0) {
        raiz->dir = inserir(raiz->dir, nome, ano_projeto);
    }
    else if(comparacao < 0){
        raiz->esq = inserir(raiz->esq, nome, ano_projeto);
    }
    else{
        raiz->ano_projeto = inserirLista(raiz->ano_projeto, ano_projeto);
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int balance = calcularBalanceamento(raiz);

    if (balance > 1 && strcmp(nome, raiz->esq->nome) < 0)
        return rotacaoDireita(raiz);

    if (balance < -1 && strcmp(nome, raiz->dir->nome) > 0)
        return rotacaoEsquerda(raiz);

    if (balance > 1 && strcmp(nome, raiz->esq->nome) > 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && strcmp(nome, raiz->dir->nome) < 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void buscar(Node *raiz, char nome[16]) {
    if (raiz == NULL) {
        printf("0\n");
    } else {
        int comparacao = strcmp(raiz->nome, nome);
        if (comparacao > 0) {
            buscar(raiz->esq, nome);
        } else if (comparacao < 0) {
            buscar(raiz->dir, nome);
        } else {
            printf("%d ", raiz->altura);
            ListaAno *aux = raiz->ano_projeto;
            while (aux != NULL) {
                printf("%d", aux->ano);
                aux = aux->prox;
                if (aux != NULL) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}
void imprimir_inordem(Node *raiz) {
    if (raiz != NULL) {
        imprimir_inordem(raiz->esq);
        printf("%s(%d) ", raiz->nome, raiz->altura);
        imprimir_inordem(raiz->dir);
    }
}

void imprimir_preordem(Node *raiz) {
    if (raiz != NULL) {
        printf("%s(%d) ", raiz->nome, raiz->altura);
        imprimir_preordem(raiz->esq);
        imprimir_preordem(raiz->dir);
    }
}

int main() {
    Node *raiz = NULL;
    int entrada = -1, ano_projeto = 0;
    char nome[16];

    while (entrada != 0) {
        scanf("%d", &entrada);
        if (entrada == 1) {
            scanf("%s %d", nome, &ano_projeto);
            raiz = inserir(raiz, nome, ano_projeto);
        } else if (entrada == 2) {
            scanf("%s", nome);
            buscar(raiz, nome);
        }
    }

    return 0;
}