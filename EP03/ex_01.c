#include <stdio.h>

int leitura(int array[10]){
    int i;
    for(i=0; i<10; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &array[i]);
    }
    
}

int main(){
    int array[10];





    return 0;
}