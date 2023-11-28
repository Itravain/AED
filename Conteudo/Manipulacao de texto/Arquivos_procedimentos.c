#include <stdio.h>
#include <stdlib.h>
#include <string.h>

escrever(char arquivo[]){
    FILE *arq;
    char letra, frase[600];

    arq = fopen(arquivo , "w");
    if(arq){
        printf("Escreva um texto para ser escrito no arquivo: ");
        scanf("%600[^\n]", frase);
        do{
            //scanf("%c", &letra);
            //fputc(letra, arq);
            fputs(frase, arq);
            fputc('\n', arq);
            scanf("%600[^\n]", frase);
            getchar();
            
        } while (strlen(frase) > 1);
        fclose(arq);
    }
    else
    {
        printf("Não foi possível abrir o arquivo");
    }   
}

ler(char arquivo[]){
    FILE *arq;
    char letra, frase[500];

    arq = fopen(arquivo, "r");

    if(arq){
        do
        {
            //letra = fgetc(arq);
            //printf("%c", letra);
            printf("%s", frase);
            fgets(frase,500,arq);   
        } while (!feof(arq));
        fclose(arq);
    }
    else{
        printf("Não foi possível abrir o arquivo");
    }

}

int main (){
    FILE *arquivo;
    int cond;

    escrever("teste.txt");
    printf("Digite 1 para mostrar o arquivo: ");
    scanf("%d", &cond);
    if (cond == 1){
        ler("teste.txt");
    }
    



    return 0;
}