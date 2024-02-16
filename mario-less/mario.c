#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a, b, c;
    do
    {
        a = get_int("Height: ");
    }
    while (a < 1 || a > 8);

    for (b = 1; b <= a; b++)
    {
        for (c = 1; c <= a - b; c++)
        {
            printf(" ");
        }

        for (c = 1; c <= b; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}