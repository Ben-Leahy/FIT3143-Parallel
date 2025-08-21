#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int is_prime(int num) {
    // if (num < 2) return 0;
    // if (num == 2) return 1;
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

    if (n > 2) {//extra loop could be avoided but would involve checking every number rather than only odd numbers doubling computation length
        printf("%d ", 2);
    }
    for (int i = 3; i < n; i+=2){
        if (is_prime(i)){
            printf("%d ", i);
        }
    }

    return 0;
}