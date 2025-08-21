#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

// check primality
int is_prime(int num)
/*Returns 1 if the number is a prime, and 0 if the number is not a prime*/
{
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    int limit = (int)sqrt(num);
    for (int i = 3; i <= limit; i += 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int largeN = 1000;

    // Start clock
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // store the time into start

    // allocate array to mark primes -> dynamically
    int *primes = malloc((n + 1) * sizeof(int));

// parallel loop: mark primes
#pragma omp parallel for schedule(dynamic)
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            primes[i] = 1;
        }
        else
        {
            primes[i] = 0;
        }
    }
// End parallel part

    FILE *pFile = fopen("primes.txt", "w");

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            if (n < largeN){
                printf("%d\n", i);
            }
            else {
                fprintf(pFile, "%d\n", i);
            }
        }
    }

    fclose(pFile);
    free(primes); // we have already moved the contents of each thread's primes into the output file/ printed to terminal

    // End clock
    clock_gettime(CLOCK_MONOTONIC, &end); // store clock time into end
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nTime taken: %.4f seconds\n", elapsed);

    return 0;
}
