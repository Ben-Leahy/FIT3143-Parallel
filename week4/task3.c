#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

// 0.6375 seconds

// check primality
int is_prime(int num)
/*Returns 1 if the number is a prime, and 0 if the number is not a prime*/
{
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

    // allocate n bytes worth of memory to mark numbers as prime or not prime. Starts at 1
    int *primes = malloc((n + 1) * sizeof(int));

    // Handle small cases to allow us to skip even numbers
    if (n < 2)
        return 0;
    primes[2] = 1; // include prime 2 so we can skip all other evens

// parallel loop: mark primes
#pragma omp parallel for schedule(dynamic)
    for (int i = 3; i <= n; i += 2)
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

    FILE *pFile = fopen("primes3.txt", "w");

    // Print prime 2
    (n < largeN) ? printf("%d\n", 2) : fprintf(pFile, "%d\n", 2); // Finish accounting for the only even prime

    for (int i = 3; i <= n; i += 2)
    {
        if (primes[i])
        {
            if (n < largeN)
            {
                printf("%d\n", i);
            }
            else
            {
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

// Time task 1: 2.4313 seconds
// Time task 2: 0.7926 seconds (6 threads)
// Time task 3: 0.6375 seconds (6 threads)