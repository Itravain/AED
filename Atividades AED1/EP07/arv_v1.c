#include <stdio.h>
#include <stdlib.h>

typedef struct noarv {
  char letra;
  struct noarv *esquerda;
  struct noarv *direita;

} NoArv;

//funcao para calcular a altura da arvore
int ind_in_order(char in_order[], char letra){
  int cont = 0;
  while (in_order[cont] != letra){
    cont++;
  }
  return cont;
}

void insert(NoArv **raiz, char letra, char in_order[]) {
  NoArv* novo_no = *raiz;
  while(novo_no){
    if(ind_in_order(in_order, letra) < ind_in_order(in_order, novo_no->letra)){
      raiz = &novo_no->esquerda;
    }
    else{
      raiz = &novo_no->direita;
    }
    novo_no = *raiz;
  }
  novo_no = malloc(sizeof(NoArv));
  novo_no->direita = NULL;
  novo_no->esquerda = NULL;
  novo_no->letra = letra;
  *raiz = novo_no;
}

void imprimir_edr(NoArv *raiz) {
  if(raiz){
    imprimir_edr(raiz->esquerda);
    imprimir_edr(raiz->direita);
    printf("%c", raiz->letra);
  }
  
}

int main(){
  NoArv* raiz;
  int qtd, rep, i, j;
  char* pre_order;
  char* in_order;

  //printf("Quantas vezes o programa irá se repetir: ");
  scanf("%d", &rep);

  for (i = 0; i < rep; i++){
    raiz = NULL;
    pre_order = malloc(sizeof(char) * (2001));
    in_order = malloc(sizeof(char) * (2001));

    //printf("Tam pre in: ");
    scanf("%d %s %s", &qtd, pre_order, in_order);
    
    //printf("Os caracteres digitados foram: \n%s\n%s\n", pre_order, in_order);
    for (j = 0; j < qtd; j++)
    {
      insert(&raiz, pre_order[j], in_order);
    }
    
    imprimir_edr(raiz);
    printf("\n");

    free(raiz);
    free(pre_order);
    free(in_order);
  }
  

  return 0;
}
