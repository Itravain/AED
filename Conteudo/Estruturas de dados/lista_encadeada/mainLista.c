#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    Lista *lista = criarLista();

    removerLista(lista, 2);
    inserirInicioLista(lista, 2);
    inserirInicioLista(lista, 4);
    inserirInicioLista(lista, 123);
    imprimirLista(lista);
    inserirFimLista(lista, 90);
    imprimirLista(lista);
    removerLista(lista, 17);
    imprimirLista(lista);
    

    return 0;
}