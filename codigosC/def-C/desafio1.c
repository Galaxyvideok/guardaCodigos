/*Implemente um algoritmo básico de criptografia, como o ciframento de César
, para codificar e decodificar mensagens.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define TAM 62
#define TAM2 1000

void limparBuffer(){
    int ch;
    do{
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int pesquisar(int *vetor, int quanti, int pesq) {
    int i;
    for (i = 0; i < quanti; i++) {
        if (i == quanti){
            i = 0;
        }
        if (vetor[i] == pesq) {
            return vetor[i];
        }
    }
    return -1;
}

void criptografar(char *frase,int quanti,int *alfabeto,char *resposta){
    int i;
    int temporario[quanti];
    for (i = 0; i < quanti; i++){
        temporario[i] = pesquisar(alfabeto,TAM,atoi(&frase[i+3]));
        resposta[i] = sprintf();
    }
}

int menu() {
	int op;
	printf("\n\nMENU\n\n");
	printf("1 - Criptografar\n");
	printf("2 - Descriptografar\n");
	printf("3 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
	} while(op < 1 || op > 3);
	return op;
}

int main() {
    int op;
    int alfabeto[TAM] = {64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 
    76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 
    92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 
    116, 117, 118, 119, 120, 121, 122, 123, 124, 125};
    char frase[TAM2];
    printf("Digite a frase: ");
    scanf(" %999[^\n]s", frase);
    int quanti = strlen(frase);
    char resposta[quanti+1];
    do{
        op = menu();
        switch (op){
        case 1:
            criptografar(frase,quanti,alfabeto,resposta);
            printf("A resposta e: %s", resposta);
            break;
        
        case 2:
            // descriptografar(frase,quanti,alfabeto,resposta);
            break;
        
        case 3:
            exit(-1);
            break;
        
        default:
            break;
        }
        return 0;
    } while (op > 0 || op > 4);
}