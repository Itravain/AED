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

//funcao para imprimir a arvore em ordem crescente
void imprimir_erd(NoArv *raiz){
  if (raiz){
    imprimir_erd(raiz->esquerda);
    printf("%d ", raiz->num);
    imprimir_erd(raiz->direita);
  }
}

//funcao para calcular a altura da arvore
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

//funcao para contar a quantidade de elementos da arvore
int qtd_elementos(NoArv *raiz){
  if (raiz){
    return 1 + qtd_elementos(raiz->esquerda) + qtd_elementos(raiz->direita);
  }
  else{
    return 0;
  }
}

//funcao para remover raiz da arvore
NoArv *remover_raiz(NoArv *raiz){
  NoArv *aux = raiz;
  NoArv *pai = NULL;
  //caso a arvore esteja vazia
  if (raiz->esquerda == NULL && raiz->direita == NULL){
    free(raiz);
    return NULL;
  }
  //caso a arvore tenha apenas um elemento
  else if (raiz->esquerda == NULL){
    raiz = raiz->direita;
    free(aux);
    return raiz;
  }
  //caso a arvore tenha apenas um elemento
  else if (raiz->direita == NULL){
    raiz = raiz->esquerda;
    free(aux);
    return raiz;
  }
  //caso a arvore tenha dois elementos
  else{
    aux = raiz->esquerda;
    while (aux->direita != NULL){
      pai = aux;
      aux = aux->direita;
    }
    if (pai != NULL){
      pai->direita = aux->esquerda;
      aux->esquerda = raiz->esquerda;
    }
    aux->direita = raiz->direita;
    free(raiz);
    return aux;
  }
}

//funcao para remover no da arvore 
NoArv *remover_no(NoArv *raiz, int num){
  NoArv *aux = raiz;
  NoArv *pai = NULL;
  //caso a arvore esteja vazia
  if (raiz == NULL){
    return NULL;
  }
  else if (raiz->num == num){
    return remover_raiz(raiz);
  }
  else{
    //encontrar o no a ser removido
    while (aux != NULL && aux->num != num){
      pai = aux;
      if (aux->num < num){
        aux = aux->direita;
      }
      else{
        aux = aux->esquerda;
      }
    }
    if (aux == NULL){
      return raiz;
    }
    //caso o no a ser removido seja uma folha
    else if (aux->esquerda == NULL && aux->direita == NULL){
      if (pai->esquerda == aux){
        pai->esquerda = NULL;
      }
      else{
        pai->direita = NULL;
      }
      free(aux);
      return raiz;
    }
    //caso o no a ser removido tenha apenas um filho
    else if (aux->esquerda == NULL){
      if (pai->esquerda == aux){
        pai->esquerda = aux->direita;
      }
      else{
        pai->direita = aux->direita;
      }
      free(aux);
      return raiz;
    }
    //caso o no a ser removido tenha apenas um filho
    else if (aux->direita == NULL){
      if (pai->esquerda == aux){
        pai->esquerda = aux->esquerda;
      }
      else{
        pai->direita = aux->esquerda;
      }
      free(aux);
      return raiz;
    }
    //caso o no a ser removido tenha dois filhos
    else{
      NoArv *aux2 = aux->esquerda;
      NoArv *pai2 = aux;
      //encontrar o maior elemento da subarvore esquerda
      while (aux2->direita != NULL){
        pai2 = aux2;
        aux2 = aux2->direita;
      }
      //caso o maior elemento da subarvore esquerda seja o filho do no a ser removido
      if (pai2 != aux){
        pai2->direita = aux2->esquerda;
        aux2->esquerda = aux->esquerda;
      }
      //caso o maior elemento da subarvore esquerda seja o filho da raiz
      aux2->direita = aux->direita;
      if (pai->esquerda == aux){
        pai->esquerda = aux2;
      }
      //caso o maior elemento da subarvore esquerda seja o filho da raiz
      else{
        pai->direita = aux2;
      }
      //liberar o no a ser removido
      free(aux);
      return raiz;
    }
  }
}

//busca em arvore binaria
NoArv *busca(NoArv *raiz, int num){
  if (raiz == NULL){
    return NULL;
  }
  else if (raiz->num == num){
    return raiz;
  }
  else{
    if (raiz->num < num){
      return busca(raiz->direita, num);
    }
    else{
      return busca(raiz->esquerda, num);
    }
  }
}

//desalocar a arvore
void desalocar_arvore(NoArv *raiz){
  if (raiz){
    desalocar_arvore(raiz->esquerda);
    desalocar_arvore(raiz->direita);
    free(raiz);
  }
}

int main(){
  NoArv *raiz = NULL;
  int* vetor_arvore = NULL;
  int num = 1;
  

  //switch case para escolher a opcao desejada
  while (num != 0){
    printf("\nDigite 1 para adicionar um número na árvore\n");
    printf("Digite 2 para remover um número da árvore\n");
    printf("Digite 3 para imprimir a árvore em ordem crescente\n");
    printf("Digite 4 para imprimir a altura da árvore\n");
    printf("Digite 5 para imprimir a quantidade de elementos da árvore\n");
    printf("Digite 6 para verificar se um elemento existe na árvore\n");
    printf("Digite 0 para sair\n");
    scanf("%d", &num);
    switch (num){
      case 1:
        printf("Digite um número para adicionar a árvore: ");
        scanf("%d", &num);
        raiz = insert_1(raiz, num);
        break;
      case 2:
        printf("Digite um número para remover da árvore: ");
        scanf("%d", &num);
        raiz = remover_no(raiz, num);
        break;
      case 3:
        imprimir_erd(raiz);
        break;
      case 4:
        printf("Altura da árvore: %d\n", altura(raiz));
        break;
      case 5:
        printf("Quantidade de elementos da árvore: %d\n", qtd_elementos(raiz));
        break;
      //case 6 para verificar se um elemento existe na arvore
      case 6:
        printf("Digite um número para verificar se existe na árvore: ");
        scanf("%d", &num);
        if (busca(raiz, num) != NULL){
          printf("O número %d existe na árvore\n", num);
        }
        else{
          printf("O número %d não existe na árvore\n", num);
        }
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  }
  return 0;
}
