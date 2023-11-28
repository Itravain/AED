#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int alg_busca(char frase[], int n){
  int qtd = 0, pos_pal, pos_frase = 0;
  char zelda[6] = "zelda";
  int m = 5;

  while(qtd == 0 && pos_frase < n){
    pos_pal = 0;
    while(zelda[pos_pal] == frase[pos_frase] || zelda[pos_pal]-32 == frase[pos_frase]){
      pos_pal++, pos_frase++;
      if (pos_pal == 5){
        qtd++;
      }
    }
    pos_frase++;
  } 
  return qtd;
}



int main(void) {
  int m, n;
  char *frase = (char *)malloc(10001 * sizeof(char));
  //printf("Escreva uma frase: ");
  scanf("%s", frase);
  //scanf("%10001[^\n]", frase);
  n = strlen(frase);
  
  if(alg_busca(frase, n) == 1){
    printf("Link Bolado\n");
  }
  else{
    printf("Link Tranquilo\n");
  }
  alg_busca(frase, m);


  
  return 0;
}
