#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int zelda(char frase[], int n){
	char palavra[6] = "zelda";
	int pos_palavra, pos_frase = 0, qtd = 0;

	while(qtd == 0 && pos_frase <= n && n<5){
	pos_palavra = 0;
		while (frase[pos_frase] == palavra[pos_palavra] || palavra[pos_palavra]-32 == frase[pos_frase]) {
		pos_frase++, pos_palavra++;
			if (pos_palavra == 5) {
				qtd++;
			}
			pos_frase++;
		}
	}
	return qtd;
}


int main(void){
	char *frase = (char *)malloc(10001 * sizeof(char));
	int n;

	printf("Digite uma frase: ");
	scanf("%s", frase);

	n = strlen(frase);
	printf("A frase possui %d caracteres.\n", n);
	if(zelda(frase, n) == 1){
		printf("Link de boa\n");

	}
	else{
		printf("Link Bolado\n");
	}

	return 0;
}
