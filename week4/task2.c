#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 16 //prevents creating too many by accident
//0.7926 seconds (6 threads), 2.1650 seconds (1 thread)

typedef struct {
    int start, end;   // range [start, end) assigned to this thread
    int *primes;      // array of primes found in this range
    int count;        // number of primes found
} ThreadData;

int is_prime(int num) {
    int limit = (int) sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void* find_primes(void* arg) {
    /*
    . is used when you have a struct variable directly.
    -> is used when you have a pointer to a struct.

    (*data).primes same as data->primes
    */
    ThreadData* data = (ThreadData*) arg;   // unpack thread data - if you tried using arg directly, the compiler wouldn’t know what fields exist, because it just sees a void*
    data->count = 0;

    // Allocate enough space for worst-case (every number is prime in range).
    data->primes = malloc((data->end - data->start) * sizeof(int));

    if (data->start == 2) {
        data->primes[data->count++] = 2;
    }
    if (data->start % 2 == 0) {
        data->start += 1;
    }

    for (int i = data->start; i < data->end; i+=2) {
        if (is_prime(i)) {
            data->primes[data->count++] = i;  // store prime
        }
    }
    return NULL;
}

int main() {
    int n, num_threads;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter number of threads (<= %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) num_threads = MAX_THREADS;

    pthread_t threads[MAX_THREADS]; //array of thread identifiers
    ThreadData thread_data[MAX_THREADS]; //array of structs (one struct per thread)

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // store the time into start

    if (n < 2) return 0;
    if (n == 2) return printf("2");

    int chunk = n / num_threads; // how many numbers per thread (static scheduling)
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = (i == 0) ? 2 : i * chunk;
        thread_data[i].end = (i == num_threads - 1) ? n : (i + 1) * chunk; // last thread covers any remainder for n
        pthread_create(&threads[i], NULL, find_primes, &thread_data[i]); // starts theead, runs find_primes(), passing thread_data[i]
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL); //waits for each thread to finish and ensures results are ready before merging
    }

    FILE *fp = NULL; // Avoid seg fault
    if (n > 100000) { // Write to file if n is large
        fp = fopen("primes2.txt", "w");
        if (!fp) {
            perror("File open failed");
            return EXIT_FAILURE;
        }
    }

    // Since ranges are already ordered, concatenation preserves ascending order
    for (int i = 0; i < num_threads; i++) {
        for (int j = 0; j < thread_data[i].count; j++) {
            if (fp)
                fprintf(fp, "%d\n", thread_data[i].primes[j]);
            else
                printf("%d\n", thread_data[i].primes[j]);
            
        }
        free(thread_data[i].primes); // free memory allocated by each thread
    }
    if (fp) fclose(fp);

    clock_gettime(CLOCK_MONOTONIC, &end); // store clock time into end
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nTime taken: %.4f seconds\n", elapsed);

    return 0;
}
