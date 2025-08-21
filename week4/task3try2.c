#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

// check primality
int is_prime(int num)
{
    if (num < 2)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;

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

    // Start clock
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // store the time into start

    // Other clock
    double start2 = omp_get_wtime();

    // allocate array to mark primes
    int *primes = malloc((n + 1) * sizeof(int));
    if (!primes)
    {
        perror("malloc failed");
        return 1;
    }

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

    // sequential output (guaranteed sorted)
    FILE *pFile = fopen("primes.txt", "w");
    if (!pFile)
    {
        perror("fopen failed");
        free(primes);
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            if (n < 1000)
            {
                printf("%d ", i);
            }
            else
            {
                fprintf(pFile, "%d ", i);
            }
        }
    }

    fclose(pFile);
    free(primes);

    // End clock
    clock_gettime(CLOCK_MONOTONIC, &end); // store clock time into end
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nTime taken: %.4f seconds\n", elapsed);

    // End other clock
    double end2 = omp_get_wtime();
    printf("\nExecution time: %f seconds\n", end2 - start2);

    return 0;
}
