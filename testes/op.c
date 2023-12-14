#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INICIO "--------INICIO--------"
#define RESULTADO "-----------RESULTADO-----------"
#define CORTE "-------------------------------------"
#define MAX 6

void trocar(int *vetor, int element1, int element2){
    int aux;
    aux = vetor[element1];
    vetor[element1] = vetor[element2];
    vetor[element2] = aux;
}

int pesquisar(int *vetor, int quanti, int pesq){
    int i;
    for (i = 0; i < quanti; i++){
        if (vetor[i] == pesq){
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *vetor, int inicio, int fim, int pesq){
    int meio = (inicio+fim)/2;
    if (vetor[meio] == pesq){
        return meio;
    }else if (inicio >= fim){
        return -1;
    }else if (pesq > vetor[meio]){
        return buscaBinaria(vetor,meio,fim,pesq);
    }else{
        return buscaBinaria(vetor,inicio,meio,pesq);
    }
}

void insertSort(int *vetor,int quanti){
    int i, j;
    int valor;
    int trocas = 0;
    for (i = 1; i < quanti; i++){
        valor = vetor[i];
        j = i - 1;
        while ((j >= 0)&&(vetor[j] > valor)){
            vetor[j+1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j+1] = valor;
    }
    printf("\nNumero de trocas: %d\n", trocas);
}

void insertSort20(int *vetor, int quanti, int ini, int h, int *trocas){
    int i, j;
    int valor;
    for (i = ini + h; i < quanti; i = i + h){
        valor = vetor[i];
        j = i - h;
        while ((j >= 0)&&(vetor[j] > valor)){
            vetor[j+h] = vetor[j];
            j = j - h;
            (*trocas)++;
        }
        vetor[j+h] = valor;
    }    
}

void shellSort(int *vetor, int quanti){
    int i, h;
    int trocas = 0;
    //iniciar o h
    for (h = 1; h <= quanti; h = 3*h - 1){
        /* code */
    }
    //diminuir o h conforme ele vai executando as trocas ao entrar no 2 for
    // executando as trocas no insertion
    for (h = (h - 1)/3; h >= 1; h = (h - 1)/3){
        for (i = 0; i < quanti; i++){
            insertSort20(vetor,quanti,i,h,&trocas);
        }
    }
    printf("\nNumero de trocas: %d\n", trocas);
}

void bubbleSort(int *vetor, int quanti){
    int i, aux, trocas, soma = 0;
    do{
        trocas = 0;
        for (i = 0; i < quanti; i++){
            if (vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                trocas++;
            }
        }
        quanti--;
        soma += trocas;
    } while (trocas > 0);
    printf("\nNumero de trocas: %d\n", soma);
}

void bubbleSortREC(int * vet, int n) {
    int i, aux, trocas;
    trocas = 0;
    for (i = 0; i < n-1; i++) {
        if ( vet[i] > vet[i+1]) {
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            trocas++;
        }
    }
    if ( trocas > 0 ) {
        bubbleSortREC(vet,n-1);
    }
}

void shakeSort(int *vetor, int quanti){
    int i, j, aux, trocas, soma = 0;
    int ini = 0;
    int fim = quanti - 1;
    do{
        trocas = 0;
        for (i = ini,j = fim; i < fim; i++,j--){
            if (vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                trocas++;
            }
            if (vetor[j] < vetor[j-1]){
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                trocas++;
            }
        }
        ini++;
        fim--;
        soma += trocas;
    } while (trocas > 0);
    printf("\nNumero de trocas: %d\n", soma);
}

void shakeSortREC(int * vet, int ini, int n) {
    int i, f, aux, trocas;
    int fim = n - 1;
    trocas = 0;
    for (i = ini,  f = fim ; i < fim; i++, f--) {
        if ( vet[i] > vet[i+1]) {
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            trocas++;
        }
        if ( vet[f] < vet[f-1]) {
            aux = vet[f];
            vet[f] = vet[f-1];
            vet[f-1] = aux;
            trocas++;
        }
    }
    if ( trocas > 0 ) {
        shakeSortREC(vet, ini+1, n-1);
    }
}

void combSort(int *vetor, int quanti){
    int i, h, aux, trocas, soma = 0;
    h = quanti;
    do{
        h = h/1.3;
        if ((h == 9)||(h == 10)){
            h = 11;
        }else if (h == 0){
            h = 1;
        }
        trocas = 0;
        for (i = 0; i < quanti - h; i++){
            if (vetor[i] > vetor[i+h]){
                aux = vetor[i];
                vetor[i] = vetor[i+h];
                vetor[i+h] = aux;
                trocas++;
            }
        }
        if (h == 1){
            quanti--;
        }
        soma += trocas;
    } while ((trocas > 0)||(h > 1));
    printf("\nNumero de trocas: %d\n", soma);
}

void combSortREC(int * vet, int n, int h) {
    int i, aux, trocas;
     
        // TROCAR o H
        h = h / 1.3;
        if ( ( h == 9) || ( h == 10) ) {
            h = 11;
        } else if ( h == 0) {
            h = 1;
        } 
        
        printf("\nH = %d", h);
        
        trocas = 0;
        for (i = 0; i < n-h; i++) {
            if ( vet[i] > vet[i+h]) {
                // TROCAR
                aux = vet[i];
                vet[i] = vet[i+h];
                vet[i+h] = aux;
                trocas++;
            }
        }
        
        if ( h > 1 ) {
            combSortREC(vet, n, h);
        } else if ( trocas > 0 ) {
            combSortREC(vet, n-1, h);            
        }
        
}

int particao(int *vetor, int ini, int fim){
    int pivo, i, f, trocas = 0;
    pivo = vetor[ini];
    i = ini + 1;
    f = fim;
    while ( i <= f ){
        if (vetor[i] < pivo){
            i++;
        }else if (vetor[f] >= pivo){
            f--;
        }else{
            trocar(vetor,i,f);
            i++;
            f--;
            trocas++;
        }
    }
    trocar(vetor,ini,f);
    trocas++;
    printf("\nNumero de trocas: %d\n", trocas);
    return f;
}

void quickSort(int *vetor, int ini, int fim){
    int indicePivo;
    if (ini < fim){
        indicePivo = particao(vetor,ini,fim);
        quickSort(vetor,ini, indicePivo - 1);
        quickSort(vetor,indicePivo + 1, fim);
    }
}

// int pesquisarMaior(int *vetor, int quanti){
//     int i;
//     int maior = 0;
//     for (i = 0; i < quanti; i++){
//         if (vetor[i] > vetor[maior]){
//             maior = i;
//         }
        
//     }
//     return maior;
// }

// void selectSort(int *vetor, int quanti){
//     int indiceMaior;
//     int f;
//     for (f = quanti; f > 1; f--){
//         indiceMaior = pesquisarMaior(vetor,f);
//         if (indiceMaior != f - 1){
//             trocar(vetor,indiceMaior,f-1);
//         }
        
//     }
// }

// void atualizarHeap(int *vetor, int raiz, int quanti){
//     int filhoEsquerda = 2*raiz + 1;
//     int filhoDireita = 2*raiz + 2;
//     int max;
//     if (){
//         /* code */
//     }
    
// }

// void construir(){

// }

// void heapSort(int *vetor, int quanti){

//     construir()
//     while (quanti){
//         /* code */
//     }
    
    
    
// }

int maiorValor(int *vetor, int quanti){
    int maior = 0;
    int i;
    for (i = 0; i < quanti; i++){
        if (vetor[i] > vetor[maior]){
            maior = i;
        }
    }
    return maior;
}

void trocar2(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    printf("Troca:\n");
}

int filhoEsquerda(int raiz){
    return 2 * raiz + 1;
}

int filhoDireita(int raiz){
    return 2 * raiz + 2;
}

void atualizarHeap(int *vetor, int quanti, int indiceRaiz){
    int esquerda = filhoEsquerda(indiceRaiz);
    int direita = filhoDireita(indiceRaiz);
    int max;
    if (esquerda > quanti - 1){
        return;
    }else if (direita > quanti - 1){
        max = esquerda;
    }else{
        if (vetor[esquerda] > vetor[direita]){
            max = esquerda;
        }else{
            max = direita;
        }
    }
    if (vetor[max] > vetor[indiceRaiz]){
        trocar2(&vetor[max], &vetor[indiceRaiz]);
        atualizarHeap(vetor, quanti, max);
    }
}

void contruirHeap(int *vetor, int n){
    int i;
    for (i = n/2 - 1; i >= 0; i--){
        atualizarHeap(vetor,n,i);
    }
    
}

void heapSort(int *vetor, int quanti){
    int i;
        contruirHeap(vetor,quanti);
    for (i = quanti-1; i > 0; i--){
        trocar2(&vetor[i],&vetor[0]);
        atualizarHeap(vetor,i,0);
    }
    
}

void selectSort(int *vetor, int quanti){
    int indiceMaior;
    if (quanti > 1){
        indiceMaior = maiorValor(vetor,quanti);
        trocar(vetor,indiceMaior,quanti-1);
        selectSort(vetor,quanti-1);
    }
}

void selectSortNormal(int *vetor, int quanti){
    int indiceMaior;
    int f;
    int trocas = 0;
    for (f = quanti; f > 1; f--){
        indiceMaior = maiorValor(vetor,f);
        if (indiceMaior != f - 1){
            trocar(vetor,indiceMaior,f-1);
            trocas++;
        }
    }
    printf("\nNumero de trocas: %d\n", trocas);
}

void intercalar(int *vetor, int ini1, int fim1, int ini2, int fim2){
    int tam = fim2 - ini1 + 1;
    int vetorAux = (int) malloc (tam * sizeof(int));
    int i1 = ini1;
    int i2 = ini2;
    int k = 0;
    while ((i1 <= fim1) && (i2 <= fim2)) {
        if (vetor[i1] <= vetor[i2]){
            vetorAux[k] = vetor[i1];
            k++;
            i1++;
        } else {
            vetorAux[k] = vetor[i2];
            k++;
            i2++;
        }
    }
    while (i1 <= fim1){
        vetorAux[k] = vetor[i1];
        k++;
        i1++;
    }
    while (i2 <= fim2){
        vetorAux[k] = vetor[i2];
        k++;
        i2++;
    }
    // Copiar blocos de memória
    memcpy(&vetor[ini1], vetorAux, tam * sizeof(int));
    free(vetorAux);
}   

void mergeSort(int *vetor, int ini, int fim){
    int meio;
    //CONDIÇAO DE PARADA
    if (ini < fim){
        //DIVIDE AO MEIO
        meio = (ini + fim)/2;
        //ORDENAR O PRIMEIRO LADO
        mergeSort(vetor,ini,meio);
        //ORDENAR O SEGUNDO LADO
        mergeSort(vetor,meio+1,fim);
        //INTERCALAR
        intercalar(vetor,ini,meio,meio+1,fim);
    }
}

void imprimirVetor(int *vet, int quanti){
    int i;
    for (i = 0; i < quanti; i++){
        printf(" %d ", vet[i]);
    }
}

int main() {
    int vetor[MAX] = {1,2,3,8,9,1};
    int quanti = 6;
    // int indiceRes = 0;
    // int pesq;
    printf("\n%s\n", INICIO);
    // printf("Digite o numero que deseja pesquisar: ");
    // scanf("%d", &pesq);
    // indiceRes = pesquisar(vetor,quanti,pesq);
    // indiceRes = buscaBinaria(vetor,0,quanti-1,pesq);
    // if (indiceRes != -1){
    //     printf("O numero encontrado foi: %d no indice %d\n",vetor[indiceRes],indiceRes);
    // }else{
    //     printf("Numero não encontrado.");
    // }
    printf("\nVetor Antes: \n");
    imprimirVetor(vetor, quanti);
    // insertSort(vetor,quanti);
    // shellSort(vetor,quanti);
    // bubbleSort(vetor,quanti);
    // bubbleSortREC(vetor,quanti);
    // shakeSort(vetor,quanti);
    // shakeSortREC(vetor,0,quanti);
    // combSort(vetor,quanti);
    // combSortREC(vetor,quanti,quanti);
    // quickSort(vetor, 0, quanti-1);
    // selectSort(vetor,quanti);

    // mergeSort(vetor,0,quanti-1);
    printf("\nVetor Depois: \n");
    imprimirVetor(vetor,quanti);
    return 0;
}
