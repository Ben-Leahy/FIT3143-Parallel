#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <immintrin.h>   // AVX intrinsics

int main() {
    // At runtime, assign memory in heap for vectors. 
    // The first param means the storage adress will be a multiple of this number. It should be a power of 2. 
    // The second param is just the size in bytes. 
    int n = 32;   
    float *a = (float*) aligned_alloc(32, n * sizeof(float));
    float *b = (float*) aligned_alloc(32, n * sizeof(float));
    float *c = (float*) aligned_alloc(32, n * sizeof(float));

    // Ignore this in our analysis, we assume we would be passed this in as a parameter. 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = i*i - 1;
    }

    // Each thread processes a sub-vector of n=8 
    //(if our total vector was not a multiple of 8 then the final thread would be assigned a vector of n <8)
    // Save by computing multiple 8 number vector parts in parallel. Cost is thread creation overhead.
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n; i += 8) {
        __m256 vec_a = _mm256_loadu_ps(&a[i]);
        __m256 vec_b = _mm256_loadu_ps(&b[i]);

        // Save on instruction and operand fetch and decode.
        __m256 vec_c = _mm256_mul_ps(vec_a, vec_b);

        _mm256_storeu_ps(&c[i], vec_c);
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("c[%d] = %f\n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}