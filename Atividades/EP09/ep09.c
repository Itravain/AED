#include <stdio.h>
#include <stdlib.h>

void imprimir(char **mapa, int coluna, int linha){
  int i, j;
  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      printf("%c ", mapa[i][j]);
    }
    printf("\n");
  }
}

void matriz(int linha, int coluna, char **matriz){
  int i, j;

  matriz = malloc(sizeof(char*) * linha);

  for (i = 0; i < linha; i++) {
    matriz[i] = malloc(sizeof(char) * coluna);
  }
}

char verificacao(char **mapa, int coluna, int linha){
  int j = 0, i = 0;
  char comando;
  char **verificacao = NULL;

  matriz(linha, coluna, verificacao);

  while (comando != '*') {
    if (mapa[i][j] == '.' && comando == '>'){
      j++;
    }
    else if (mapa[i][j] == '.' && comando == '<'){
      j--;
    }
    else if (mapa[i][j] == '.' && comando == 'v'){
      i++;
    }
    else if (mapa[i][j] == '.' && comando == '^'){
      i--;
    }
    else if (mapa[i][j] == '>'){
      comando = '>';
      if (verificacao[i][j] == comando){
        return comando;
      }
      else{
        verificacao[i][j] = comando;
      }
      j++;
    }
    else if (mapa[i][j] == '<'){
      comando = '<';
      verificacao[i][j] = '<';
      j--;
    }
    else if (mapa[i][j] == '^'){
      comando = '^';
      verificacao[i][j] = '^';
      i--;
    }
    else if (mapa[i][j] == 'v'){
      comando = 'v';
      verificacao[i][j] = 'v';
      i++;
    }
  }
  return comando;
}

int main (){
  int coluna, linha, i, j;
  char** mapa = NULL;
  scanf("%d", &coluna);
  scanf("%d", &linha);
  getchar();

  matriz(linha, coluna, mapa);
  
  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      scanf("%c", &mapa[i][j]);
      getchar();
    }
  }

  imprimir(mapa, coluna, linha); 

  return 0;
}
