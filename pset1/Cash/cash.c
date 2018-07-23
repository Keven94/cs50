#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    double change;
    int coins;
    int change2;

    //Prompt user for a valid amount of change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //initialize variable
    coins = 0;

    //By putting (int) in front of roundf(), we're clearly saying that whatever return value comes out of roundf() is going to be cast to an integer.
    change2 = (int) roundf(change * 100);

    //math to get amount of coins to use
    while (change2 > 0)
    {
        if (change2 >= 25)
        {
            coins = change2 / 25;
            change2 = change2 % 25;
        }
        else if (change2 >= 10)
        {
            coins = coins + (change2 / 10);
            change2 = change2 % 10;
        }
        else if (change2 >= 5)
        {
            coins = coins + (change2 / 5);
            change2 = change2 % 5;
        }
        else if (change2 >= 1)
        {
            coins = coins + (change2 / 1);
            change2 = change2 % 1;
        }
    }

    //printing final number of coins
    printf("%i\n", coins);
}
