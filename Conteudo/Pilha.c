#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No_t;
 
int leitura_numero(){
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    return numero;
}

void imprimir_numero(No_t *no){
    if(no){
        printf("\nO número é: %d\n", no->valor);
    }else{
        printf("Ainda não existem elementos na pilha\n");
    }
}


No_t *empilhar(No_t *topo){
    No_t *novo = (No_t*) malloc(sizeof(No_t));

    if(novo){
        novo->proximo = topo;
        novo->valor = leitura_numero();
        return novo;
    }
    else{
        printf("Não foi possível alocar memória.");
        return NULL;
    }    
}

No_t *desempilhar(No_t **p_topo){
    if(*p_topo){
        No_t *remove = *p_topo;
        *p_topo = remove->proximo;
        return remove;

    }
    printf("\nEsta pilha não tem nenhum elemento\n");
    return NULL;
    
}


int main(void){
    int opcao;
    No_t *topo = NULL;
    
    do{
        printf("---------------------------------\n0 para sair\n1 Para empilhar\n2 Para desempilhar\n3 para imprimir\n------------------------------\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
            
        case 2:
            imprimir_numero(desempilhar(&topo));
            break;

        case 3:
            imprimir_numero(topo);
            break;
                
        default:
            if (opcao != 0){
                printf("Opção invalida!");
            }
            break;
        }
        


        
    }while(opcao != 0);

    return 0;
}