/*Desenvolva um programa que simule a execução de processos utilizando 
uma estrutura de fila (FIFO) ou prioridade (comparando tempos de 
execução).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 1000
#define TAMNOME 100

struct Processo{
    char nome[TAMNOME];
    int id;
    int prioridade;
    int tempoExecucao;
    int indicador;
};
typedef struct Processo Processo;

void startLista(Processo **lista1, Processo **lista2, Processo **lista3, int quanti){
    *lista1 = (Processo *)calloc(quanti, sizeof(Processo));
    *lista2 = (Processo *)calloc(quanti, sizeof(Processo));
    *lista3 = (Processo *)calloc(quanti, sizeof(Processo));
    if (*lista1 && *lista2 && *lista3) {
        for (int i = 0; i < quanti; i++) {
            (*lista1)[i].indicador = 0;
            (*lista2)[i].indicador = 0;
            (*lista3)[i].indicador = 0;
        }
    }
}

void imprimirLista(Processo *lista1, Processo *lista2, Processo *lista3, int quanti){
    int i;
    printf("| Prioridade 1: ");
    for (i = 0; i < quanti; i++){
        if (lista1[i].indicador != 0){
            /* code */
        }
        
        
    }
    
}

int menu() {
    int op;
    printf("\n1 - Criar Processo\n");
    printf("2 - Matar Processo\n");
    printf("3 - Sair\n");
    do {
        printf("Escolha sua opção: ");
        scanf("%d", &op);
    } while(op < 1 || op > 3);
    return op;
}

int main() {
    Processo pri1[MAX];
    Processo pri2[MAX];
    Processo pri3[MAX];
    int quanti;
    int op;
    printf("\n%s\n", INICIO);
    printf("Qual e o tamanho maximo da fila de processos?: ");
    scanf("%d", &quanti);
    startLista(pri1,pri2,pri3,quanti);
    //imprimir o que esta em execuçao
    do{
        op = menu();
        switch (op){
        case 1:
            inserirProcesso();
            break;
        
        case 2:
            excluirProcesso();
            break;
        
        case 3:
            return 0;
            break;
        
        default:
            break;
        }
    } while ((op >= 1) || (op <= 3));
    return 0;
}