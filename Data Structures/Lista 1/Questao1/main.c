#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* inserir_ordenado(int* vetor, int tamanho, int novoElemento){

    vetor = realloc(vetor, (tamanho + 1) * sizeof(int));

    if(vetor == NULL){
        printf("Erro ao realocar o vetor!\n");
        exit(1);
    }

    int index = tamanho -1;

    printf("\n");

    while(index >= 0 && vetor[index] > novoElemento){

        printf("%d é maior que %d - Seguindo para o novo elemento..\n", vetor[index], novoElemento);

        vetor[index + 1] = vetor[index];
        index--;
    }

    //printf("\nIndex:%d\n", index);

    vetor[index + 1] = novoElemento;

    return vetor;
}

void percorre_vetor(int* vetor, int tamanho){
    printf("\nVetor -> [");

    for(int index = 0;index < tamanho;index++){
        if(index+1 == tamanho){
            printf("%d]\n", vetor[index]);
        }
        else{
            printf("%d,", vetor[index]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int tamanho = 5;
    int* vetor = malloc(tamanho * sizeof(int));

    vetor[0] = 1;
    vetor[1] = 3;
    vetor[2] = 5;
    vetor[3] = 7;
    vetor[4] = 9;

    int novoElemento = 5;

    percorre_vetor(vetor, tamanho);

    vetor = inserir_ordenado(vetor, tamanho, novoElemento);

    percorre_vetor(vetor, tamanho + 1);
}
