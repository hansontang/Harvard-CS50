#include <cs50.h>
#include <stdio.h>
int main()
{
    // TODO:Prompt for start size
    int a;
    do
    {
        a = get_int("start size: ");
    }
    while (a < 9);
    // TODO:Prompt for end size
    int b;
    do
    {
        b = get_int("end size: ");
    }
    while (b < a);
    // TODO:Calculate number of years until reaach threshold
    int c = 0;
    while (b > a)
    {
        a = a + (a / 3) - (a / 4);
        c++;
    }
    // TODO:Print number of years
    printf("Years: %i\n", c);
}