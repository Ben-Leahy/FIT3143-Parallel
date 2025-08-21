#include <stdio.h>

int main()
{
    printf("This is our calculator application. It adds together two numbers");
    float num1, num2;
    printf("Enter your first number");
    scanf("%lf", &num1);

    printf("Enter your second number");
    scanf("%lf", &num2);

    float sum = num1 + num2;
    printf("%f + %f = %f", num1, num2, sum);
    return 0;
}