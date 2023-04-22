#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No_t;


No_t *empilhar(int num, No_t *topo){
    No_t *novo = (No_t*) malloc(sizeof(No_t));

    if(novo){
        novo->proximo = topo;
        novo->valor = num;
        return novo;
    }
    else{
        printf("Não foi possível alocar memória.");
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


int main(){
    int n_repet, i, opt, num;
    int pilha = 1, fila = 1, fila_prioridade = 1; 
    //ponteiros
    No_t *topo_pilha = NULL;
    
    do{
        for ( i = 0; i < n_repet; i++){
            scanf("%d %d", &opt, &num);
            if (opt == 1)
            {
                topo_pilha = empilhar(num, topo_pilha);
                //adicionar_fila(num);
                //adicionar_fila_prioridade(num);
            }
            //casos de remoção
            else if (opt == 2)
            {
                if (desempilhar(&topo_pilha) != num){
                    pilha = 0;
                }
                else if (remove_fila(num) != num){
                    fila = 0;
                }   
                else if (remove_fila_prioridade(num) != num){
                    fila_prioridade = 0;
                }
                          
            }
        }
    } while (opt != "z");
    
   
    
    return 0;
}