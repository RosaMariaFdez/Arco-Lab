/* Programa secuencial que calcula la suma de los elementos de un vector v[i] 
 * y la almacena en la variable sum */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <omp.h>
#define N 50 // Probar distintos tamaños de vector 

int main() 
{ 
    int i, sum = 0; 
    int v[N];    
    float a = omp_get_wtime();
    // Damos valores aleatorios al vector (entre 0 y 99) 
    srand (time(NULL)); // Semilla de números aleatorios 
    #pragma omp parallel for schedule(static, 8)
    for (i = 0; i < N; i++) v[i] = 1;//rand()%100; 

    // Cálculo del sumatorio 
    #pragma omp parallel for schedule(static, 8)  
    for (i = 0; i < N; i++) 
        #pragma omp atomic update
            sum += v[i]; 

              

    // Como comprobación, se visualizan los valores del vector y la suma 
    printf("\nVector de números: \n "); 
    //#pragma omp parallel for schedule(static, 4)
    //for (i = 0; i < N; i++) printf("%d \t",v[i]);
    
	printf("\n La suma es: %d \n\n", sum); 
    float z = omp_get_wtime(); 

    printf("El programa ha tardado %0.10f segundos \n", z-a);
} 
