#include <stdio.h>
#include <stdlib.h>

typedef struct noarv{
  int num;
  struct noarv *esquerda;
  struct noarv *direita;

}NoArv;

NoArv *insert_1(NoArv *raiz, int num){
  if (raiz == NULL) {
    NoArv *novo_no = malloc(sizeof(NoArv));
    novo_no->num = num;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
  }
  else{
    if (raiz->num < num) {
      raiz->esquerda = insert_1(raiz->esquerda, num);
    }
    else{
      raiz->direita = insert_1(raiz->direita, num);
    }
    return raiz;
  } 
}

void imprimir_erd(NoArv *raiz){
  if (raiz){
    imprimir_erd(raiz->esquerda);
    printf("%d ", raiz->num);
    imprimir_erd(raiz->direita);
  }
}

int main(){
  NoArv *raiz = NULL;
  int num = -2;
  
  while (num != 0) {
    printf("Digite um número para adicionar a árvore: ");
    scanf("%d", &num);
    if (num != -1) {
      raiz = insert_1(raiz, num); 
    }
    else{
      imprimir_erd(raiz);
    }
  }

  return 0;
}
