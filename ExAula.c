#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h> 

// Objetivo: Faça um programa que sorteie 6 números distintos e os armazene em um vetor. O vetor deve estar ordenado em ordem crescente.
// Caso algum número seja repetido no sorteio, o mesmo deve ser ignorado e será sorteado um novo valor. Mostre o resultado para o usuário.


// Função para trocar elementos no vetor:
void swap(int *a, int *b) {
    int temporaria = *a;
    *a = *b;
    *b = temporaria;
}

// Função 'partition' usada para dividir o vetor:   
int partition(int numerosSorteados[], int baixo, int alto) {
    // Seleção do pivô (número mais alto (mais à direita) do subvetor):
    int pivo = numerosSorteados[alto];
    int i = (baixo - 1);

    // Looping (percorrer o vetor para garantir que os elementos menores que o pivô fiquem a esquerda de 'i'):
    for (int j = baixo; j <= alto - 1; j++) {
        if (numerosSorteados[j] < pivo) {
            i++;
            swap(&numerosSorteados[i], &numerosSorteados[j]);
        }
    }

    // Mudança do pivô para a posição correta (após os elementos menores que ele):
    swap(&numerosSorteados[i + 1], &numerosSorteados[alto]);
    return (i + 1);
}

//  Quick sort:
void quickSort(int numerosSorteados[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(numerosSorteados, baixo, alto);

        // Ordena os elementos a partir do pivô:
        quickSort(numerosSorteados, baixo, pi - 1);
        quickSort(numerosSorteados, pi + 1, alto);
    }
}

int main() {

// Vetor:
    int numerosSorteados[6];
    // Tamanho do vetor:
    int minimo = 1;
    int maximo = 10;

// Inicialização do sorteador:
    srand(time(NULL));

// Looping (sorteio):
    for (int i = 0; i < 6; i++) {

        bool repetido;

        do {
            repetido = false;
            int novoNumero = rand() % (maximo - minimo + 1) + minimo;

            // Looping de verificação (se novoNumero está em numerosSorteados):
            for (int j = 0; j < i; j++) {
                if (numerosSorteados[j] == novoNumero) {
                    repetido = true;

                    break;
                }
            }

            if (!repetido) {
                numerosSorteados[i] = novoNumero;
            }
        } 
        
        while (repetido);
    }

    quickSort(numerosSorteados, 0, 5);

// Demonstração p usuário:
    printf("Os numeros que foram sorteados sao: ");

    for (int i = 0; i < 6; i++) {
        printf("%d ", numerosSorteados[i]);
    }

    printf("\n");

    return 0;
}