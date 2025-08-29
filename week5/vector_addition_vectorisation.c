#include <immintrin.h>
#include <stdio.h>

int main() {
    float a[8] = {1,2,3,4,5,6,7,8};
    float b[8] = {2,2,2,2,2,2,2,2};
    float c[8];

    //Takes advantage of AVX hardware
    __m256 va = _mm256_loadu_ps(a);   // load array a into a 256-bit vector register (8 numbers * 32bits per num)
    __m256 vb = _mm256_loadu_ps(b);   
    __m256 vc = _mm256_mul_ps(va, vb); // multiply element-wise using vector optimistion, returns vector
    _mm256_storeu_ps(c, vc);          // store vector result into array c

    for (int i = 0; i < 8; i++) {
        printf("%f\n", c[i]);
    }
    return 0;
}

// Command: gcc -O2 -mavx vector_addition_vectorisation.c -o va_v
