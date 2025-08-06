#include <stdio.h>
int main()
{
    char text_1[100], text_2[100], text_3[100];
    char *ta, *tb;
    int i;
    /* set message to be an array */
    /* of characters; initialize it */
    /* to the constant string "..." */
    /* let the compiler decide on */
    /* its size by using []*/
    char message[] = "Hello, I am a string; what are you?";
    printf("Original message: %s\n", message);
    /* copy the message to text_1 */
    /* the hard way */
    i = 0;
    while ((text_1[i] = message[i]) != '\0')
    {
        i++;
        printf("Text_1 at iteration %d: %s\n", i, text_1);
    }
    printf("Text_1: %s\n", text_1);
    /* use explicit pointer arithmetic */
    ta = message;
    tb = text_2;
    while ((*tb++ = *ta++) != '\0')
        /* increment both pointers (later, for now use their value), get the value of each pointer, assignment and return, compare returned value with terminating string*/
        ;
    printf("Text_2: %s\n", text_2);
    return (0);
}