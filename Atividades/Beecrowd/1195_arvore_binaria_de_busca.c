#include <stdio.h>
#include <stdlib.h>

//estrutura da arvore
typedef struct noarv{
  int num;
  struct noarv *esquerda;
  struct noarv *direita;

}NoArv;

//funcao para inserir um numero na arvore
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

//funcao para adicionar um numero no vetor 
void adicionar_num_vetor (int num, int vetor_arvore[]){
  if (vetor_arvore[0] == 0){
    vetor_arvore[1] = num;
  }
  else{
    vetor_arvore[vetor_arvore[0] + 1] = num;
  }
  vetor_arvore[0] += 1; 
}

//funcao para alocar os elementos da arvore em um vetor
void alocar_erd(NoArv *raiz, int vetor_arvore[]){
  if (raiz){
    alocar_erd(raiz->esquerda, vetor_arvore);
    adicionar_num_vetor(raiz->num, vetor_arvore);
    alocar_erd(raiz->direita, vetor_arvore);
  }
}

void alocar_red(NoArv *raiz, int vetor_arvore[]){
  if (raiz){
    adicionar_num_vetor(raiz->num, vetor_arvore);
    alocar_red(raiz->esquerda, vetor_arvore);
    alocar_red(raiz->direita, vetor_arvore);
  }
}

void alocar_edr(NoArv *raiz, int vetor_arvore[]){
  if (raiz){
    alocar_edr(raiz->esquerda, vetor_arvore);
    alocar_edr(raiz->direita, vetor_arvore);
    adicionar_num_vetor(raiz->num, vetor_arvore);
  }
}

int main(){
    int qtd_casos, qtd_numeros, i, j, num;
    NoArv* arvore = NULL;
    NoArv** matriz_arvore = NULL;
    int *vetor_arvore = NULL;

    
    //printf("Digite a quantidade de casos de teste: ");
    scanf("%d", &qtd_casos);

    matriz_arvore = malloc(sizeof(NoArv*)*qtd_casos); 

    for ( i = 0; i < qtd_casos; i++){
        matriz_arvore[i] = NULL;
    }
    
    for(i = 0; i < qtd_casos; i++){  
        //printf("Digite a quantidade de numeros: "); 
        scanf("%d", &qtd_numeros);

        for(j = 0; j < qtd_numeros; j++){
            scanf("%d", &num);
            matriz_arvore[i] = insert_1(matriz_arvore[i], num);
        }

        vetor_arvore = malloc(sizeof(int)*(qtd_numeros + 1));
        alocar_red(matriz_arvore[i], vetor_arvore);
        printf("Case %d:\nPre.:", i+1);
        for(j = 1; j <= qtd_numeros; j++){
            printf(" %d", vetor_arvore[j]);
        }
        vetor_arvore[0] = 0;
        printf("\n");

        printf("In..:");
        alocar_erd(matriz_arvore[i], vetor_arvore);
        for(j = 1; j <= qtd_numeros; j++){
            printf(" %d", vetor_arvore[j]);
        }
        vetor_arvore[0] = 0;
        printf("\n");

        printf("Post:");
        alocar_edr(matriz_arvore[i], vetor_arvore);
        for(j = 1; j <= qtd_numeros; j++){
            printf(" %d", vetor_arvore[j]);
        }
        vetor_arvore[0] = 0;
        printf("\n\n");
    }

    return 0;
}