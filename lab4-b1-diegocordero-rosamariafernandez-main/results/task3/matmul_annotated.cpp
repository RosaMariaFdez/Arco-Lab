#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <omp.h>

using namespace std;

int main();
void timestamp();

int main()
{
    printf("HILOS DISPONIBLES: %d\n",omp_get_num_procs());
#define SIZE 300
#define THREADS 8
    auto a = new double[SIZE][SIZE];
    double angle;
    auto b = new double[SIZE][SIZE];
    auto c = new double[SIZE][SIZE];
    int i;
    int j;
    int k;
    int n = SIZE;
    double pi = 3.141592653589793;
    double s;
    int thread_num;
    double wtime;

    timestamp();

    cout << "\n";
    cout << "MATMUL:\n";
    cout << "  C = A * B.\n";
    cout << "  Order N                 = " << n << "\n";

    // TODO: Print the number of processors avilable
    // TODO: Print the number of threads available

    //
    //  Loop 1: Evaluate A.
    //
    s = 1.0 / sqrt((double)(n));


    // TODO: Paralellize 
    #pragma omp paralell num_threads(THREADS)
    for (i = 0; i < n; i++)
    {
        #pragma omp for
        for (j = 0; j < n; j++)
        {   
            #pragma omp critical
            {
            angle = 2.0 * pi * i * j / (double)n;
            a[i][j] = s * (sin(angle) + cos(angle));
            }
        }     
    }
    //
    //  Loop 1: Evaluate B.
    //
    // TODO: Paralellize 
    #pragma omp paralell num_threads(THREADS)
    for (i = 0; i < n; i++)
    {
       #pragma omp for
        for (j = 0; j < n; j++)
        {   
            #pragma omp critical
        {
            b[i][j] = a[i][j];
        }
        }

    }
   

    //
    //  Loop 3: Compute C = A * B.
    //
    // TODO: Paralellize 
    wtime = omp_get_wtime();
    #pragma omp paralell num_threads(THREADS)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            #pragma omp for
            for (k = 0; k < n; k++)
            {
                #pragma omp critical
                {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }

            }
        }
        
    }


    wtime = omp_get_wtime() - wtime;
    cout << "  Elapsed seconds = " << wtime << "\n";
    cout << "  C(100,100)  = " << c[99][99] << "\n";


    //
    //  Terminate.
    //
    cout << "\n";
    cout << "Matmul:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
    timestamp();
    return 0;
}

void timestamp()
{
#define TIME_SIZE 40

    static char time_buffer[TIME_SIZE];
    const struct std::tm *tm_ptr;
    std::time_t now;

    now = std::time(NULL);
    tm_ptr = std::localtime(&now);

    std::strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr);

    std::cout << time_buffer << "\n";

    return;
#undef TIME_SIZE
}
