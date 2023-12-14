void intercalar(int *vetor, int ini1, int fim1, int ini2, int fim2){
    int tam = fim2 - ini1 + 1;
    int *vetorAux = (int*) malloc (tam * sizeof(int));
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