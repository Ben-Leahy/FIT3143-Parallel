#include <stdio.h>

int main()
{
    /*Basic conditional*/
    int ALWAYS_1 = 1;
    int sometimes_1 = 1;
    if (ALWAYS_1 == sometimes_1)
    {
        printf("ALWAYS_1 does equal sometimes_1");
    }
    else if (ALWAYS_1 <= sometimes_1)
    {
        printf("ALWAYS_1 is less than sometimes_1");
    }
    else
    {
        printf("ALWAYS_1 is more than sometimes_1");
    }

    /* Case statement*/
    char currentMonth[] = "August";
    switch (currentMonth)
    {
    case "January" {
        printf("It's jan");
        break;
    } default:
    {
        printf("Since there are only two months, and it's not Jan, then it's Feb");
    }
    }

    /* Case statement 2*/
    switch (currentMonth)
    {
    case currentMonth != "January" {
        printf("It's not jan");
    } case currentMonth != "Febuary" {
        printf("It's not feb");
    } default:
    {
        printf("It must be March (I can't be bothered writing more switch cases)");
    }
    }
}