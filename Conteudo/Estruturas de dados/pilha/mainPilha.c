#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha *pilha;

    pilha = criarPilha();
    empilhar(pilha, 3);
    imprimirPilha(pilha);
    empilhar(pilha, 10);
    imprimirPilha(pilha);
    desempilhar(pilha);
    imprimirPilha(pilha);
    desempilhar(pilha);
    imprimirPilha(pilha);
    desempilhar(pilha);
    imprimirPilha(pilha);

    return 0;
}