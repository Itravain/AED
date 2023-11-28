#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No_t;

int pont_to_int(No_t *num){
    return num->valor;
}
No_t *empilhar(int num, No_t *topo){
    No_t *novo = (No_t*) malloc(sizeof(No_t));

    if(novo){
        novo->proximo = topo;
        novo->valor = num;
        return novo;
    }
    else{
        printf("Não foi possível alocar memória.\n");
        return NULL;
    }    
}
No_t *desempilhar(No_t **p_topo){
    if(p_topo){
        No_t *remove = *p_topo;
        *p_topo = remove->proximo;
        return remove;

    }
    printf("\nEsta pilha não tem nenhum elemento\n");
    return NULL;
    
}
void adicionar_fila(int num, No_t **fila){
    No_t *aux, *novo = malloc(sizeof(No_t));

    if(novo != NULL){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        }
            
        else{
            aux = *fila;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else
        printf("Não foi possível alocar memória\n");
}
No_t* remove_fila(No_t **p_fila){
    No_t *remover = NULL;

    if(*p_fila != NULL){
        remover = *p_fila;
        *p_fila = remover->proximo;
    }
    return remover;
}

int main(){
    int n_repet = 0, i, opt, num;
    int pilha = 1, fila = 1, fila_prioridade = 1; 
    //ponteiros
    No_t *topo_pilha = NULL, *inicio_fila = NULL;


    do{
        printf("Número de repetições: ");
        scanf("%d", &n_repet);
        getchar();

        for ( i = 0; i < n_repet; i++){
            scanf("%d %d", &opt, &num);
            if (opt == 1)
            {
                topo_pilha = empilhar(num, topo_pilha);
                adicionar_fila(num, &inicio_fila);
                //adicionar_fila_prioridade(num);
            }
            //casos de remoção
            else if (opt == 2)
            {
                if (pont_to_int(desempilhar(&topo_pilha)) != num){
                    pilha = 0;
                }
                else if (pont_to_int(remove_fila(&inicio_fila)) != num){
                    fila = 0;
                }   
                /*else if (remove_fila_prioridade(num) != num){
                    fila_prioridade = 0;
                }*/
                          
            }
        }
    } while (opt != 0);
    
   
    
    return 0;
}