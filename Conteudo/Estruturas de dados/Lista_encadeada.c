#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista encadeada
typedef struct Node {
    char* nome;
    struct Node* proximo;
} Node;

// Função para inserir um elemento no início da lista
void insere_no_inicio(Node** inicio, char* nome) {
    // Aloca espaço na memória para o novo nó
    Node* novo_no = (Node*)malloc(sizeof(Node));
    
    // Aloca espaço na memória para a string do novo nó
    novo_no->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    
    // Copia a string passada como argumento para o novo nó
    strcpy(novo_no->nome, nome);
    
    // Define o próximo nó como o atual início da lista
    novo_no->proximo = *inicio;
    
    // Define o novo nó como o início da lista
    *inicio = novo_no;
}

// Função para imprimir os elementos da lista
void imprime_lista(Node* inicio) {
    // Percorre a lista enquanto houver nós
    while (inicio != NULL) {
        // Imprime a string do nó atual
        printf("%s ", inicio->nome);
        
        // Avança para o próximo nó
        inicio = inicio->proximo;
    }
    
    // Imprime uma quebra de linha ao final
    printf("\n");
}

int main() {
    // Define o início da lista como nulo
    Node* inicio = NULL;
    
    // Insere elementos na lista
    insere_no_inicio(&inicio, "João");
    insere_no_inicio(&inicio, "Maria");
    insere_no_inicio(&inicio, "Pedro");
    
    // Imprime a lista
    imprime_lista(inicio);
    
    // Remove elementos da lista
    //remove_do_inicio(&inicio);
    //remove_do_inicio(&inicio);
    
    return 0;
}