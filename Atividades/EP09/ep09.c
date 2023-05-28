#include <stdio.h>
#include <stdlib.h>

void matriz(int linha, int coluna, char ***matriz) {
  int i, j;

  *matriz = malloc(sizeof(char *) * linha);

  for (i = 0; i < linha; i++) {
    (*matriz)[i] = malloc(sizeof(char) * coluna);
  }
}

void imprimir(char **mapa, int coluna, int linha) {
  int i, j;
  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      printf("%c ", mapa[i][j]);
    }
    printf("\n");
  }
}

char verificacao(char **mapa, int coluna, int linha) {
  int j = 0, i = 0;
  char comando = mapa[0][0];
  char **verificacao = NULL;

  matriz(linha , coluna , &verificacao);

  while (comando != '*') {
    //condições de .
    if (mapa[i][j] == '.' && comando == '>') {
      if (j == coluna - 1){
        return comando;
      }
      j++;
    }
    else if (mapa[i][j] == '.' && comando == '<') {
      if(j == 0){
        return comando;
      }   
      j--;
    } 
    else if (mapa[i][j] == '.' && comando == 'v') {
      if(i == linha - 1){
        return comando;
      }
      i++;
    }
    else if (mapa[i][j] == '.' && comando == '^') {
      if(i == 0){
        return comando;
      }
      i--;
    }

    //verificação de loop
    else {
      comando = mapa[i][j];
      if (verificacao[i][j] == comando) {
        return comando;
      }
      else {
        verificacao[i][j] = comando;
      }


      //verificação dos comandos
      if (comando == '>'){
        if(j == coluna - 1){
          return comando;
        }
        j++;
      }
      else if (comando == '<'){
        if(j == 0){
          return comando;
        }
        j--;
      }
      else if (comando == '^'){
        if (i == 0){
          return comando;
        }   
        i--;
      }
      else if (comando == 'v'){
        if (i == linha - 1){
          return comando;
        }
        i++;
      }
    }
  }
  return comando;
}

int main() {
  int coluna, linha, i, j;
  char **mapa = NULL;
  //printf("Digite o número de colunas: ");
  scanf("%d", &coluna);
  //printf("Digite o número de linhas: ");
  scanf("%d", &linha);
  getchar();

  matriz(linha , coluna , &mapa);

  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      scanf("%c", &mapa[i][j]);
    }
    getchar();
  }

  //imprimir(mapa, coluna, linha);
  if (verificacao(mapa, coluna, linha) != '*'){
    printf("!\n");
  }
  else{
    printf("%c\n",verificacao(mapa, coluna, linha));
  }
  

  return 0;
}
