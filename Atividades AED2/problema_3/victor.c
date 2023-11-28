#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct candidato{
    int id;
    int votos;
}candidato;

typedef struct votos{
    int primeira;
    int segunda;
    int terceira;
}votos;

int cmpfunc(const void *a, const void *b) {
    candidato *pessoaA = (candidato *)a;
    candidato *pessoaB = (candidato *)b;
    
    return pessoaA->votos - pessoaB->votos;
}

void inicializaCandidatos(candidato candidatos[], int qtdCandidatos){
    for(int i = 0;i<qtdCandidatos; i++){
        candidatos[i].id = i +1;
        candidatos[i].votos = 0;
    }
}

int contaVoto(int voto, int *qtdCandidato1, int *qtdCandidato2, int candidato1, int candidato2){
    if(voto == candidato1){
        (*qtdCandidato1)++;
        return 1;
    }else if(voto == candidato2){
        (*qtdCandidato2)++;
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int eleitores, qtdCandidatos, votosNaoValidos;
    int i;
    
    scanf("%d %d", &eleitores, &qtdCandidatos);

    candidato candidatos[qtdCandidatos];
    votos votos[eleitores];

    inicializaCandidatos(candidatos, qtdCandidatos);

    votosNaoValidos=0;

    for(i = 0; i<eleitores; i++){
        scanf("%d %d %d", &votos[i].primeira, &votos[i].segunda, &votos[i].terceira);
        if(votos[i].primeira >0 && votos[i].primeira<=qtdCandidatos){
            candidatos[(votos[i].primeira)-1].votos = candidatos[(votos[i].primeira)-1].votos + 1;
        }else{
            votosNaoValidos++;
        }
    }
    
    qsort(candidatos, qtdCandidatos, sizeof (candidato), cmpfunc);
    float porcentagem = candidatos[qtdCandidatos-1].votos;
    porcentagem = porcentagem/(eleitores-votosNaoValidos)*100;

    if(isnan(porcentagem)){
        printf("0\n");
    }else if(candidatos[qtdCandidatos-1].votos == candidatos[qtdCandidatos-2].votos){
        if(candidatos[qtdCandidatos-1].id < candidatos[qtdCandidatos-2].id){
            printf("%d %.2f\n", candidatos[qtdCandidatos-1].id, porcentagem);
        }else{
            printf("%d %.2f\n", candidatos[qtdCandidatos-2].id, porcentagem);
        }
    }else{
        printf("%d %.2f\n", candidatos[qtdCandidatos-1].id, porcentagem);
    }

    if(porcentagem<50){
        int candidato1, candidato2;
        int qtdCandidato1 = 0;
        int qtdCandidato2 = 0;

        votosNaoValidos = 0;

        candidato1 = candidatos[qtdCandidatos-1].id;
        if(candidatos[qtdCandidatos-2].votos==candidatos[qtdCandidatos-3].votos){
            if(candidatos[qtdCandidatos-2].id<candidatos[qtdCandidatos-3].id){
                candidato2 = candidatos[qtdCandidatos-2].id;
            }else{
                candidato2 = candidatos[qtdCandidatos-3].id;
            }
        }else{
            candidato2 = candidatos[qtdCandidatos-2].id;
        }

        for(i = 0; i<eleitores; i++){
            if(contaVoto(votos[i].primeira, &qtdCandidato1, &qtdCandidato2, candidato1, candidato2));
            else if(contaVoto(votos[i].segunda, &qtdCandidato1, &qtdCandidato2, candidato1, candidato2));
            else if(contaVoto(votos[i].terceira, &qtdCandidato1, &qtdCandidato2, candidato1, candidato2));
            else votosNaoValidos++;
        }

        float porcentagem1 = qtdCandidato1;
        porcentagem1 = porcentagem1/(eleitores-votosNaoValidos)*100;
        
        float porcentagem2 = qtdCandidato2;
        porcentagem2 = porcentagem2/(eleitores-votosNaoValidos)*100;

        if(isnan(porcentagem1) || isnan(porcentagem2)){
            printf("0\n");
        }else if(qtdCandidato1==qtdCandidato2){
            if(candidato1<candidato2){
                printf("%d %.2f\n", candidato1, porcentagem1);
            }else{
                printf("%d %.2f\n", candidato2, porcentagem2);
            }
        }else if(qtdCandidato1>qtdCandidato2){
            printf("%d %.2f\n", candidato1, porcentagem1);
        }else{
            printf("%d %.2f\n", candidato2, porcentagem2);
        }
    }

    return 0;
}