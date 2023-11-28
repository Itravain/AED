#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//funcoes para fila------------------------------------------------------------------------------------------------------------------------------------------------
typedef struct matriz{
    int linha;
    int coluna;
}Matriz;

typedef struct no{
    int coluna;
    int linha;
    struct no *proximo;
}No;


void criarFila(No **inicio_fila, No **fim_fila){
    *inicio_fila = NULL;
    *fim_fila = NULL; 
}


void inserirFila(No **inico_fila, No **fim_fila, int coluna, int linha){
    No *novo = malloc(sizeof(No));
    novo->coluna = coluna;
    novo->linha = linha;
    novo->proximo = NULL;

    if(*inico_fila == NULL){
        *inico_fila = novo;
        *fim_fila = novo;
    }else{
        (*fim_fila)->proximo = novo;
        *fim_fila = novo;
    }
}

int encontrarFila(No *inicio_fila, int coluna, int linha){
    No *aux = inicio_fila;
    while(aux != NULL){
        if(aux->coluna == coluna && aux->linha == linha){
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

void removerFila(No **inicio_fila, No **fim_fila){
    No *aux = *inicio_fila;
    if(*inicio_fila == *fim_fila){
        *inicio_fila = NULL;
        *fim_fila = NULL;
    }else{
        *inicio_fila = (*inicio_fila)->proximo;
    }
    free(aux);
}



//funcoes para leitura e verificacao------------------------------------------------------------------------------------------------------------------------------------------------
Matriz leituraTamanho(){
    Matriz tamanho;
    scanf("%d %d", &tamanho.coluna, &tamanho.linha);
    getchar();
    return tamanho;
}

char **criarMatriz(int linhas, int colunas){
    char **matriz = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(char)*(colunas + 1));
    }
    return matriz;
} 


char **leitura(Matriz *tamanho){
    char **mapa = criarMatriz(tamanho->linha, tamanho->coluna);

    for(int i = 0; i< tamanho->linha; i++){
        scanf("%s", mapa[i]);
        getchar();
    }
    return mapa;
}

int **criarVerificacao(Matriz tamanho){
    int **matriz = calloc(tamanho.linha, sizeof(int*));
    for(int i = 0; i < tamanho.linha; i++){
        matriz[i] = calloc(tamanho.coluna, sizeof(int));
    }
    return matriz;
}

Matriz encontrarPosIn(char **mapa, Matriz tamanho){
    Matriz posInicial;
    for(int i = 0; i < tamanho.linha; i++){
        for(int j = 0; j < tamanho.coluna; j++){
            if(mapa[i][j] == '@'){
                posInicial.linha = i;
                posInicial.coluna = j;
                return posInicial;
            }
        }
    }
    return posInicial;

}

//funcoes para imprimir------------------------------------------------------------------------------------------------------------------------------------------------
void imprimirVerificacao(int **matriz, Matriz tamanho){
    for(int i = 0; i < tamanho.linha; i++){
        for(int j = 0; j < tamanho.coluna; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}   

void imprimirMapa(char **mapa, Matriz tamanho){
    for(int i = 0; i < tamanho.linha; i++){
        printf("%s\n", mapa[i]);
    }
}

void imprimirFila(No *inicio_fila){
    No *aux = inicio_fila;
    int contador = 1;
    while(aux != NULL){
        printf("%d: linha %d coluna %d\n", contador++, aux->linha, aux->coluna);
        aux = aux->proximo;
    }
}

//funcao para calcular o numero de posicoes acessiveis------------------------------------------------------------------------------------------------------------------------------------------------
int posicoesAcessiveis(int **verificacao, char **mapa, Matriz posInicial, Matriz tamanho){
    int espacoAcessivel = 0;
    int coluna = posInicial.coluna, linha = posInicial.linha;
    No *inicio_fila, *fim_fila;

    criarFila(&inicio_fila, &fim_fila);
    inserirFila(&inicio_fila, &fim_fila, coluna, linha);
    int contador = 0;

    while(inicio_fila != NULL){
        coluna = inicio_fila->coluna;
        linha = inicio_fila->linha;     
        
        verificacao[linha][coluna] = 1;
     
        if(linha > 0){
            if(mapa[linha-1][coluna] == '.' && verificacao[linha-1][coluna] == 0 && encontrarFila(inicio_fila, coluna, linha - 1) == 0){
                inserirFila(&inicio_fila, &fim_fila, coluna, linha - 1);
            }
        }
        
        if(coluna < tamanho.coluna - 1){
            if (mapa[linha][coluna + 1] == '.' && verificacao[linha][coluna + 1] == 0 && encontrarFila(inicio_fila, coluna + 1, linha) == 0){
                inserirFila(&inicio_fila, &fim_fila, coluna + 1, linha);
            }   
        }
        
        if(linha < tamanho.linha - 1){
            if (mapa[linha + 1][coluna] == '.' && verificacao[linha + 1][coluna] == 0 && encontrarFila(inicio_fila, coluna, linha + 1) == 0){
                inserirFila(&inicio_fila, &fim_fila, coluna, linha + 1);
            }
        }
        
        if(coluna > 0){
            if (mapa[linha][coluna - 1] == '.' && verificacao[linha][coluna - 1] == 0 && encontrarFila(inicio_fila, coluna - 1, linha) == 0){
                inserirFila(&inicio_fila, &fim_fila, coluna - 1, linha);
            }
        }
        espacoAcessivel++;
        


        removerFila(&inicio_fila, &fim_fila);
    }

    return espacoAcessivel;

}

int main(){
    int espacoAcessavel = 0;
    char **mapa;
    int **verificacao;
    Matriz tamanho, posInicial;
    
    tamanho = leituraTamanho();
    mapa = leitura(&tamanho);
    posInicial = encontrarPosIn(mapa, tamanho);
    //printf("linha:%d coluna:%d\n", posInicial.linha, posInicial.coluna);
    //imprimirMapa(mapa, tamanho);
    //printf("qtd linhas: %d qtd colunas: %d\n", tamanho.linha, tamanho.coluna);
    
    verificacao = criarVerificacao(tamanho);
    espacoAcessavel = posicoesAcessiveis(verificacao, mapa, posInicial, tamanho);

    printf("%d\n", espacoAcessavel);

    return 0;
}