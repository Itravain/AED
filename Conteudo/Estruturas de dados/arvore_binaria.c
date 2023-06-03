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
      raiz->direita = insert_1(raiz->direita, num);
    }
    else{
      raiz->esquerda = insert_1(raiz->esquerda, num);
    }
    return raiz;
  }
}


void adicionar_num_vetor (int num, int vetor_arvore[]){
  if (vetor_arvore[0] == 0){
    vetor_arvore[1] = num;
  }
  else{
    vetor_arvore[vetor_arvore[0] + 1] = num;
  }
  vetor_arvore[0] += 1; 
}

void imprimir_erd(NoArv *raiz){
  if (raiz){
    imprimir_erd(raiz->esquerda);
    printf("%d ", raiz->num);
    imprimir_erd(raiz->direita);
  }
}

void alocar_erd(NoArv *raiz, int vetor_arvore[]){
  if (raiz){
    alocar_erd(raiz->esquerda, vetor_arvore);
    adicionar_num_vetor(raiz->num, vetor_arvore);
    alocar_erd(raiz->direita, vetor_arvore);
  }
}

int altura(NoArv *raiz){
  int esq, dir;
    if(raiz == NULL){
        return -1;
    }
    else{
        esq = altura(raiz->esquerda);
        dir = altura(raiz->direita);
        if(dir < esq){
            return ++esq;
        }
        else{
            return ++dir;
        }
    }
}

int qtd_elementos(NoArv *raiz){
  if (raiz){
    return 1 + qtd_elementos(raiz->esquerda) + qtd_elementos(raiz->direita);
  }
  else{
    return 0;
  }
}

int main(){
  NoArv *raiz = NULL;
  int* vetor_arvore = NULL;
  int num = 1;
  
  while (num > 0) {
    printf("Digite um número para adicionar a árvore: ");
    scanf("%d", &num);
    if (num != -1) {
      raiz = insert_1(raiz, num); 
    }

    //imprimir a árvore
    else if (num == -1){
      vetor_arvore = (int*)malloc((qtd_elementos(raiz)+1) * sizeof(int));
      alocar_erd(raiz, vetor_arvore);
      for (int i = 1; i <= qtd_elementos(raiz); i++){
        printf("%d ", vetor_arvore[i]);
      }
    }
    else if (num == 0){
      printf("Altura da árvore: %d\n", altura(raiz));
    }
  }

  return 0;
}
