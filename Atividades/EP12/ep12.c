#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qtd_casos, qtd_palavras, peso_atual = 0, i, j, k;
    char palavra[51];

    //printf("Digite a quantidade de casos: ");
    scanf("%d", &qtd_casos);

    // loop para a quantidade de casos
    for (i = 0; i < qtd_casos; i++) {
        //printf("Digite a quantidade de palavras: ");
        scanf("%d", &qtd_palavras);

        // loop para a quantidade de palavras no caso
        for (j = 0; j < qtd_palavras; j++) {
            scanf("%s", palavra);

            // loop para o cálculo do peso da palavra
            for (k = 0; k < strlen(palavra); k++) {
                peso_atual += (((int)palavra[k] - 65) + j + k);
            }
        }

        printf("%d", peso_atual);

        if (i < qtd_casos) {
            printf("\n");
        }

        peso_atual = 0;
    }

    return 0;
}
