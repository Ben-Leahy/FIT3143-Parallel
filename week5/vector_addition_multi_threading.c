#include <stdio.h>

int main() {
    // Ie use case here could be finding E[X]. Obv not normal use case for vectors but just for fun
    float a[8] = {1,2,3,4,5,6,7,8};
    float b[8] = {0.1, 0.3, 0.05, 0.2, 0.05, 0.01, 0.01, 0.01};
    float c[8];

    // Fetching and decodingh the same opcode each time. 
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < 8; i++) {
        c[i] = a[i] * b[i];
    }
    
    // Ignore this in terms of our analysis, just for printing.
    for (int i = 0; i < 8; i++) {
        printf("%f\n", c[i]);
    }

    return 0;
}