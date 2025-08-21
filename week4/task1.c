#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int is_prime(int num) {
    /*Returns 1 if the number is a prime, and 0 if the number is not a prime
    Works for numbers n: n > 2*/
    if (num % 2 == 0) return 0;

    int limit = (int) sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void display (int i, int n, FILE * pFile){
    /* Display i in terminal for low n, and in pFile for large n*/
    if (n < 1000){
        printf("%d ", i);
    }
    else {
        fprintf(pFile, "%d ", i);
    }
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    FILE *pFile;
    pFile = fopen("primes.txt", "w");

    if (n > 2) {//extra loop could be avoided but would involve checking every number rather than only odd numbers doubling computation length
        display(2, n, pFile);
    }

    for (int i = 3; i < n; i+=2){
        if (is_prime(i)){
            display(i, n, pFile);
        }
    }

    return 0;
}