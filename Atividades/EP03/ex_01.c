#include <stdio.h>

// Este algoritmo substitui todos os valores nulos e negativos de um vetor por 1
int main() {
  int array[10];
  int i;

  // Lê os valores do vetor
  for (i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }

  // Substitui os valores nulos e negativos por 1
  for (i = 0; i < 10; i++) {
    if (array[i] <= 0) {
      array[i] = 1;
    }
    printf("X[%d] = %d\n", i, array[i]);
  }

  return 0;
}
