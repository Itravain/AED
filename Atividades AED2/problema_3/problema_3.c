#include <stdio.h>
typedef struct votos{
    int op_um;
    int op_dois;
    int op_tres;
}Votos;

typedef struct candidatos{
    int numero_candidato;
    int qtd_votos;
}Candidatos;

int validacao_voto(int qtd_candidatos, int voto){
    if (voto > qtd_candidatos){
        return 0;
    }
    return 1;
}

void inicializar_vetor_candidato(Candidatos candidatos[], int qtd_candidatos){
    for(int i = 0; i < qtd_candidatos; i++){
        candidatos[i].numero_candidato = i + 1;
        candidatos[i].qtd_votos = 0;
    }
}

int main() {
    int qtd_eleitores, qtd_candidatos;
    double votos_validos = 0.0, votos_validos_segundo = 0.0;

    scanf("%d %d", &qtd_eleitores, &qtd_candidatos);

    Votos votos[qtd_eleitores];
    Candidatos candidatos_primeiro_turno[qtd_candidatos];
    inicializar_vetor_candidato(candidatos_primeiro_turno, qtd_candidatos);

    for(int i = 0; i < qtd_eleitores; i++){
        scanf("%d %d %d", &votos[i].op_um, &votos[i].op_dois, &votos[i].op_tres);
        if(validacao_voto(qtd_candidatos, votos[i].op_um)){
            votos_validos++;
            candidatos_primeiro_turno[votos[i].op_um - 1].qtd_votos++;
        }
    }

//escolher candidato mais votado no primeiro turno
    Candidatos candidato_mais_votado;
    Candidatos segundo_candidato_mais_votado;
    candidato_mais_votado.qtd_votos = 0;
    segundo_candidato_mais_votado.qtd_votos = 0;


    for (int i = 0; i < qtd_candidatos; i++){
        if (candidatos_primeiro_turno[i].qtd_votos > candidato_mais_votado.qtd_votos){
            segundo_candidato_mais_votado = candidato_mais_votado;
            candidato_mais_votado = candidatos_primeiro_turno[i];
        } else if (candidatos_primeiro_turno[i].qtd_votos > segundo_candidato_mais_votado.qtd_votos &&
                candidatos_primeiro_turno[i].qtd_votos < candidato_mais_votado.qtd_votos){
            segundo_candidato_mais_votado = candidatos_primeiro_turno[i];
        }
    }

    double porcentagem_primeiro_turno = ((double)candidato_mais_votado.qtd_votos / votos_validos) * 100;
    printf("%d %.2f\n", candidato_mais_votado.numero_candidato, porcentagem_primeiro_turno);


    if (porcentagem_primeiro_turno <= 50.0){
        Candidatos candidatos_segundo_turno[2];
   
        inicializar_vetor_candidato(candidatos_segundo_turno, 2);
        candidatos_segundo_turno[0] = candidato_mais_votado;
        candidatos_segundo_turno[1] = segundo_candidato_mais_votado;

        votos_validos = 0;
        
        for (int i = 0; i < qtd_eleitores; i++){
            if(validacao_voto(qtd_candidatos, votos[i].op_um) && votos[i].op_um == candidatos_segundo_turno[0].numero_candidato || votos[i].op_um == candidatos_segundo_turno[1].numero_candidato){
                candidatos_segundo_turno[votos[i].op_dois - 1].qtd_votos++;
                votos_validos++;
            }
            else if (validacao_voto(qtd_candidatos, votos[i].op_dois) && votos[i].op_dois == candidatos_segundo_turno[0].numero_candidato || votos[i].op_dois == candidatos_segundo_turno[1].numero_candidato){
                candidatos_segundo_turno[votos[i].op_dois - 1].qtd_votos++;
                votos_validos++;
            }
            else if (validacao_voto(qtd_candidatos, votos[i].op_tres) && votos[i].op_tres == candidatos_segundo_turno[0].numero_candidato || votos[i].op_tres == candidatos_segundo_turno[1].numero_candidato){
                candidatos_segundo_turno[votos[i].op_tres - 1].qtd_votos++;
                votos_validos++;
            }
        }
        
        if(candidatos_segundo_turno[0].qtd_votos> candidatos_segundo_turno[1].qtd_votos){
            candidato_mais_votado = candidatos_segundo_turno[0];
        }
        else{
            candidato_mais_votado = candidatos_segundo_turno[1];
        }

        printf("%d %.2f\n", candidato_mais_votado.numero_candidato, ((double)candidato_mais_votado.qtd_votos / votos_validos) * 100);

    }



    return 0;
}