#include <stdio.h>
#include <string.h>

void organizar_string(char string[50][100], int size){
    char aux[50];
    int i, j;

    for (i = 0; i < size - 1; i++) {
        if (strcmp(string[i], string[i+1]) > 0){
            j = i;
            do{
                strcpy(aux, string[j]);
                strcpy(string[j], string[j+1]);
                strcpy(string[j+1], aux);                
                j--;
            } while (strcmp(string[j], string[j+1])> 0 && j >= 0);
        }
    }   
}

int main (void){
    int qt, pos, i;
    char nomes[50][100];
    

    //leitura da quantidade de nomes inseridos e a posição desejada
    scanf("%d %d", &qt, &pos);
    getchar();

    for ( i = 0; i < qt; i++)
    {
        //leitura dos nomes
        fgets(nomes[i], 50 ,stdin);

    }

    //organizar a lista de nomes
    organizar_string(nomes, qt);

    printf("%s", nomes[pos-1]);

    return 0;
}