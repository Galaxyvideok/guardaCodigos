/* Implemente uma função recursiva em C chamada potencia que calcule a 
elevado à potência b, onde a e b são números inteiros positivos. 
Certifique-se de tratar os casos especiais, como quando b é 
zero (a^0 = 1) e quando a é zero (0^b = 0).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"

int fatorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * fatorial(n-1);
    }
}

int main(){
    int res,n;
    printf("\n%s\n", INICIO);
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    res = fatorial(n);
    printf("\n%s\n", RESULTADO);
    printf("O maior do vetor e: %d\n",res);
    printf("\n%s\n", CORTE);
    return 0;
}