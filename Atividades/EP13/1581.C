#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int rep, casos, verificacao;
    char idioma[21], verific_idioma[21];

    //printf("Digite a quantidade de repeticoes: ");
    scanf("%d", &rep);
    getchar();

    for(int i = 0; i < rep; i++){
        //printf("Digite a quantidade de palavras desta repeticao: "); 
        scanf("%d", &casos);
        getchar();

        verificacao = 1;
        
        for (int j = 0; j < casos; j++){
            scanf("%s", &idioma);
            getchar();

            if(j == 0){
                strcpy(verific_idioma, idioma);
            }
            else{
                if (strcmp(idioma, verific_idioma) != 0){
                    verificacao = 0;
                }    
            }
            
        }   
        if (verificacao == 0){
            printf("ingles\n");
        }
        else{
            printf("%s\n", idioma);
        }        
    }
    


    return 0;
}