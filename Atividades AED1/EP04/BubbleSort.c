#include <stdio.h>
#include <string.h>

void organizar_string(char string[50][100], int size){
    char aux[50];
    int i, finish = 0;

    do {
        finish = 1;
        for (i = 0; i < size - 1; i++) {
            if (strcmp(string[i], string[i+1]) > 0) {
                strcpy(aux, string[i+1]);
                strcpy(string[i+1], string[i]);
                strcpy(string[i], aux);
                finish = 0;
            }
        }
    } while (!finish);
    
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
