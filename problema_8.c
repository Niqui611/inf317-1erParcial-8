#include <stdio.h>
#include <omp.h>

#define N 20 // Número de términos en la serie
#define M 4  // Número de procesadores (vectores)

int main() {
    int i;
    int vector[M][N/M]; // Definición de M vectores para almacenar los términos

    // Cálculo de la serie utilizando OpenMP
    #pragma omp parallel for num_threads(M) shared(vector)
    for (i = 0; i < N; i++) {
        int thread_num = omp_get_thread_num();
        vector[thread_num][i % (N/M)] = (i + 1) * 2; // Calcula el término y lo asigna al vector correspondiente
    }

    // Imprimir los términos de cada vector
    printf("Términos en los vectores:\n");
    for (i = 0; i < M; i++) {
        printf("Vector %d: ", i);
        for (int j = 0; j < N/M; j++) {
            printf("%d ", vector[i][j]);
        }
        printf("\n");
    }

    return 0;
}
