#include <stdio.h>
#include <stdlib.h>


int main(void){
    FILE *doc;
    char c;

    doc = fopen("teste.txt", "w");

    if (doc){
        while (c != '\n'){
            scanf("%c", &c);
            fputc(c, doc);
        }
        fclose(doc);
    }
    else{
        printf("Falha ao abrir arquivo.");
    }

    return 0;
}