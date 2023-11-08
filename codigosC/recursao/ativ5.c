/*Crie uma função recursiva em C chamada torre_hanoi que resolva o problema das 
Torres de Hanói com recursão. A função deve receber o número de discos e as 
torres de origem, destino e auxiliar como parâmetros.
Mover n - 1 discos da torre de origem para uma torre auxiliar, usando a torre de 
destino como torre auxiliar.
Mover o disco restante (o maior disco) da torre de origem para a torre de destino.
Mover os n - 1 discos da torre auxiliar para a torre de destino, usando a 
torre de origem como torre auxiliar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 50

void começar(int numDiscos, int *torre){
    int i;
    for (i = numDiscos; i > 0; i++){
        torre[i] = i+1;
    }
}

int torreHanoi(int numDiscos, int *torreOrigem, int *torreAuxiliar, int *torreDestino){

}

int main(){
    int res, numDiscos, quanti;
    int torreOrigem[MAX];
    int torreAuxiliar[MAX];
    int torreDestino[MAX];
    printf("\n%s\n", INICIO);
    printf("Digite o numero de discos: ");
    scanf("%d", &numDiscos);
    começar(numDiscos,torreOrigem);
    res = torreHanoi(numDiscos,torreOrigem,torreAuxiliar,torreDestino);
    printf("\n%s\n", RESULTADO);
    
    printf("\n%s\n", CORTE);
    return 0;
}