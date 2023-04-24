#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No_t;

void adicionar_fila(No_t **fila, int num){
    No_t *aux, *novo = malloc(sizeof(No_t));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No_t* remover_da_fila(No_t **fila){
    No_t *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

int main(){
    No_t *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            adicionar_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            // imprimir a fila
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invaluda!\n");
        }

    }while(opcao != 0);

    return 0;
}