/*Crie uma função recursiva em C chamada contagem_de_modo que conte o 
número de maneiras de representar um número n como uma soma de inteiros 
positivos, considerando diferentes permutações. Por exemplo, para n = 4, 
existem cinco maneiras de representá-lo: 4, 3+1, 2+2, 2+1+1 e 1+1+1+1.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"

int contagemModo(int n){
    if (n == 1){
        return 1;
    }else{
        return 1 + contagemModo(n-1);
    } 
}

int main(){
    int res, n;
    // int cont;
    printf("\n%s\n", INICIO);
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    // cont = 0;
    printf("\n%s\n", RESULTADO);
    res = contagemModo(n);
    printf("A quantidade de modos que %d pode ser escrito e: %d\n",n,res);
    printf("\n%s\n", CORTE);
    return 0;
}