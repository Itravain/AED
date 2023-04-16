#include <stdio.h>
#define MAX 10
#define NULO -1

typedef struct no
{
    int cont;
    int proximo;
}No;


void print(No num[], int ultimo){
    int i;
    for (i = ultimo + 1; i != NULO; i = num[i].proximo){
        printf("%d\n", num[i].cont);
    }
    
}


int main(void){
    //Criar um no 
    No num[MAX];

    //Iniciando uma lista 
    int inicio, ultimo = 0;
    for (int i = 0; i < MAX; i++){
        num[i].proximo = i + 1; 
        num[i].cont = 0;
    }
    num[MAX - 1].proximo = NULO;

    print(num, inicio);

    return 0;
}
