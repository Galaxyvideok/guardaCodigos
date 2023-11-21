/*Crie um programa que encontre todas as ocorrências de um padrão 
específico em um texto fornecido pelo usuário, usando a técnica 
de busca de padrões.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 10000

int pesquisar(char *texto, char *palavra, int quanti2){
    int i,j = 0, recebe, guarda, res = 0;
    char fragmento[quanti2];
    for (i = 0; texto[i] != '\0'; i++){
        fragmento[j] = texto[i];
        j++;
        guarda = strlen(fragmento);
        if (guarda == quanti2){
            recebe = strcmp(fragmento,palavra);
            if (recebe == 0){
                res++;
            }
            j = 0;
        }
        
    }
    return res;
}

int main() {
    char texto[MAX];
    char palavra[MAX];
    int quanti2;
    int cont = 0;
    printf("\n%s\n", INICIO);
    printf("Digite o texto aqui: ");
    scanf(" %9999[^\n]s", texto);
    printf("%s\n", CORTE);
    printf("Digite a palavra ou letra que deseja pesquisar: ");
    scanf(" %9999[^\n]s", palavra);
    quanti2 = strlen(palavra);
    cont = pesquisar(texto,palavra,quanti2);
    printf("\n%s\n", RESULTADO);
    printf("A quantidade de vezes que '%s' apareçe e : %d",palavra,cont);
    printf("\n%s\n", CORTE);
    return 0;
}