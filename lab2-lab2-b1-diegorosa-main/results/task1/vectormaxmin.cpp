#include <iostream>

#include <cstdlib>

#include <omp.h> 
 

using namespace std;


int maximo(int v[], int n)

{

    int max;
    for (int i = 0; i < n; i++)

        if (i == 0 || max < v[i])

            max = v[i];

 

    return max;

}

 

int minimo(int v[], int n)

{

    int min;

 

    for (int i = 0; i < n; i++)

        if (i == 0 || min > v[i])

            min = v[i];

 

    return min;

}
int main()
{
float a = omp_get_wtime(); 
int v[7]={4,7,2,8,1,9,0};
printf("%d\n",maximo(v,7));
printf("%d\n",minimo(v,7));
float z = omp_get_wtime(); 
printf("El programa ha tardado %0.10f segundos \n", z-a); 
return 0;
}