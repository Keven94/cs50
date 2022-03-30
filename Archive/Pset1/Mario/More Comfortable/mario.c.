#include <stdio.h>
#include <cs50.h>

int main()
{
    int h;

    do                                      //check if the height is between the valid numbers
    {
        h = get_int("Height: ");
    }

    while (h < 0 || h > 23);

    for (int i = 0; i < h; i++)             //height
    {
        for (int j = h - 1; j > i; j--)     //space before the first #
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)     //number of #s after the space
        {
            printf("#");
        }

        printf("  ");                       //2 space gap

        for (int k = 0; k < i + 1; k++)     //right side of the row
        {
            printf("#");
        }

        printf("\n");                       //new line for the next set of rows
    }
}
