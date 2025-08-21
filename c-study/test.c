#include <stdio.h>

int main()
{
    int x = 2;
    char myChar = 'x';
    char myString[] = "This is a string"; /* myString is a pointer to the location of the first char in the string*/
    printf("%d", x);
    printf("%c", myChar);
    printf("%s", myString); /*the printf function must*/
    return 0;
}
