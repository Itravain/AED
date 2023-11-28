#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *doc;
    char letra;

    doc = fopen("teste.txt", "r");
    if (doc){
        while(!feof(doc)){
            letra = fgetc(doc);
            printf("%c", letra);
        }
        printf("\n");
        fclose(doc);
    }
    else{
        printf("Não foi possível abrir o arquivo.\n");
    }



    return 0;
}