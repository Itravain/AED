#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila *fila = criarFila();

    inserirFila(fila, 8);
    inserirFila(fila, 2);
    inserirFila(fila, 3);
    imprimirFila(fila);
    removerFila(fila);
    inserirFila(fila, 90);
    imprimirFila(fila);
    
    



    return 0;
}