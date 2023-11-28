#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noarv{
  char letra;
  struct noarv *esquerda;
  struct noarv *direita;

}NoArv;

NoArv *insert_1(NoArv *raiz, char letra){
  if (raiz == NULL) {
    NoArv *novo_no = malloc(sizeof(NoArv));
    novo_no->letra = letra;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
  }
  else{
    if (letra < raiz->letra) {
      raiz->esquerda = insert_1(raiz->esquerda, letra);
    }
    else{
      raiz->direita = insert_1(raiz->direita, letra);
    }
    return raiz;
  } 
}

NoArv* procura(NoArv *raiz, char letra){
    if(raiz){
        if(letra == raiz->letra)
            return raiz;
        else if(letra < raiz->letra)
            return procura(raiz->esquerda, letra);
        else
            return procura(raiz->direita, letra);
    }
    return NULL;
}

void imprimir_red_prefixa(NoArv *raiz){
  if (raiz){
    printf("%c ", raiz->letra);
    imprimir_red_prefixa(raiz->esquerda);   
    imprimir_red_prefixa(raiz->direita);
  }
}

void imprimir_erd_infixa(NoArv *raiz){
  if (raiz){
    imprimir_erd_infixa(raiz->esquerda);
    printf("%c ", raiz->letra);
    imprimir_erd_infixa(raiz->direita);
  }
}

void imprimir_edr_posfixa(NoArv *raiz){
  if (raiz){
    imprimir_edr_posfixa(raiz->esquerda);
    imprimir_edr_posfixa(raiz->direita);
    printf("%c ", raiz->letra);

  }
}

int main(){
    NoArv *raiz = NULL, *search;   
    char option[9], letra;

    while (scanf("%s", &option) == 1){
        //printf("[I] insert [P]search [INFIXA] [PREFIXA] [POSFIXA]\n");
        getchar();
        if(strcmp("I", option) == 0){
            scanf("%c", &letra);
            raiz = insert_1(raiz, letra);
        }
        else if (strcmp("P", option) == 0){
            scanf("%c", &letra);
            search = procura(raiz, letra);
            if (search){
                printf("%c existe\n", letra);
            }
            else{
                printf("%c nao existe\n", letra);
            }
            
        }
        else if (strcmp("INFIXA", option) == 0){
            imprimir_erd_infixa(raiz);
            printf("\n");
        }
        else if (strcmp("PREFIXA", option) == 0){
            imprimir_red_prefixa(raiz);
            printf("\n");
        }
        else if (strcmp("POSFIXA", option) == 0){
            imprimir_edr_posfixa(raiz);
            printf("\n");
        }
        
    }
      
  return 0;
}
