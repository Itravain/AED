#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
}No;

void inserir_inicio(No **p_inicio_lista, int num_novo){
    No *novo_no = malloc(sizeof(No));
    if (novo_no){
        novo_no -> num = num_novo;
        novo_no -> prox = *p_inicio_lista;
        *p_inicio_lista = novo_no;
    }
    else{
        printf("Não foi possível alocar memória para inserir no inicio da lista");
    }        
}



void inserir_fim(No **p_inicio_lista, int num_novo){
    No *aux, *novo_no = malloc(sizeof(No));

    //condicional para saber se a memória do novo no foi alocada com sucesso
    if (novo_no){
        //Criando um novo no
        novo_no->num = num_novo; 
        novo_no->prox = NULL;

        //se o inicio da estiver preenchido
        if(*p_inicio_lista == NULL){
            *p_inicio_lista = novo_no;
        }
        else{
            //O ponteiro auxiliar recebe o início da lista
            aux = *p_inicio_lista;
            while (aux->prox){
                aux = aux->prox; 
            }
            (*aux).prox = novo_no; 
        }
    }
    else{
        printf("Não foi possível alocar memória para inserir no final da lista. ");
    }
}

void inserir_meio(No **p_inicio_lista, int novo_num, int ref){
    No *novo_no = malloc(sizeof(No));

    if (novo_no){
        novo_no->num = novo_num;

        if (*p_inicio_lista == NULL){
            novo_no->prox = NULL;
            *p_inicio_lista = novo_no;
        }
        else{
            No *aux;
            aux = *p_inicio_lista;
            while (aux->prox && aux->num != ref){
                aux = aux->prox;
            }
            novo_no->prox = aux->prox;
            aux->prox = novo_no;
        }

    }
    else{
        printf("Não foi possível alocar memótia para um novo nó\n");
    }
}

void imprimir_lista(No **lista){
    No *aux = *lista;
    int i = 1;

    while (aux){
        printf("o %d° numero: %d\n", i++, aux->num);
        aux = aux->prox; 
    }

}


int main(void){
    No *lista_inicio = malloc(sizeof(No)); 
    lista_inicio = NULL;
    inserir_inicio(&lista_inicio, 12);
    printf("O primeiro elemento da lista é: %d.\n", lista_inicio->num);
    inserir_inicio(&lista_inicio, 14);
    printf("O primeiro elemento da lista é: %d.\n", lista_inicio->num);
    inserir_meio(&lista_inicio, 13, 14);
    imprimir_lista(&lista_inicio);



    return 0;
}