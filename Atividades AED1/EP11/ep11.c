#include <stdio.h>
#include <stdlib.h>

typedef struct no_hash {
    int chave;
    struct no_hash *prox;
} no_hash;

// Função que cria uma tabela hash
no_hash **cria_hash(int tam_hash) {
    no_hash **hash = (no_hash **)malloc(tam_hash * sizeof(no_hash *));
    for (int i = 0; i < tam_hash; i++) {
        hash[i] = NULL;
    }
    return hash;
}

// Limpar a tabela hash
void limpa_hash(no_hash **hash, int tam_hash) {
    for (int i = 0; i < tam_hash; i++) {
        no_hash *aux = hash[i];
        while (aux != NULL) {
            no_hash *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
    }
    free(hash);
}

// Função de dispersão
int funcao_dispersao(int chave, int tam_hash) {
    return chave % tam_hash;
}

// Função que insere uma chave na tabela hash usando encadeamento exterior
void insere_hash(no_hash **hash, int tam_hash, int chave) {
    int pos = funcao_dispersao(chave, tam_hash);
    no_hash *novo = (no_hash *)malloc(sizeof(no_hash));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->chave = chave;
    novo->prox = NULL;
    if (hash[pos] == NULL) {
        hash[pos] = novo;
    } else {
        no_hash *aux = hash[pos];
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// Função para imprimir a tabela hash
void imprime_hash(no_hash **hash, int tam_hash) {
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        no_hash *aux = hash[i];
        while (aux != NULL) {
            printf("%d -> ", aux->chave);
            aux = aux->prox;
        }
        printf("\\\n");
    }
}

int main() {
    int qtd_casos, tam_hash, qtd_chaves, chave;

    scanf("%d", &qtd_casos);
    for (int i = 0; i < qtd_casos; i++) {
        scanf("%d %d", &tam_hash, &qtd_chaves);

        no_hash **hash = cria_hash(tam_hash);

        for (int j = 0; j < qtd_chaves; j++) {
            scanf("%d", &chave);
            insere_hash(hash, tam_hash, chave);
        }
        imprime_hash(hash, tam_hash);
        limpa_hash(hash, tam_hash);
        
        if (i < qtd_casos - 1){
            printf("\n");
        }
        
    }

    return 0;
}
