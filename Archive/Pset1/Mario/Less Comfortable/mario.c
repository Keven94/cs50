#include <stdio.h>
#include <cs50.h>

int main()
{
    int h;

    //prompt the user for the half-pyramid’s height, a non-negative integer no greater than 23
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h > 23);

    for (int i = 0; i < h; i++)
    {
        for (int j = i; j < h - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("#\n");
    }
}
