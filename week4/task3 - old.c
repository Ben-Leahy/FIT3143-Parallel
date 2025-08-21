#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>   // <-- OpenMP header

int is_prime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    int limit = (int) sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    FILE *pFile = fopen("primes.txt", "w");
    if (!pFile) {
        perror("File opening failed");
        return 1;
    }

    // Print/write 2 separately (only even prime)
    if (n > 2) {
        if (n < 1000) printf("%d ", 2);
        else fprintf(pFile, "%d ", 2);
    }

    // Parallel region
    #pragma omp parallel
    {
        // Each thread will collect its local primes to avoid race conditions
        char primes[1024 * 1024]; // 1 MB local primes per thread
        int buf_index = 0;

        #pragma omp for schedule(dynamic, 100) nowait
        for (int i = 3; i < n; i += 2) {
            if (is_prime(i)) {
                // Store in primes instead of writing directly
                // primes[buf_index] is the value in primes at index buf_index. Then &primes[buf_index] is the address of it. So write i into it, then increment the buf_index byt eh number of characters i is. 
                buf_index += sprintf(&primes[buf_index], "%d ", i); // -> primes += i.toString()
            }
        }

        // Critical section: flush primes to output
        #pragma omp critical // in the order the threads were run
        {
            if (n < 1000) {
                printf("%s", primes);
            } else {
                fprintf(pFile, "%s", primes);
            }
        }
    }
    fclose(pFile);
    return 0;
}
