#include <stdio.h>
#include <cs50.h>

int main()
{
    long cardNumber;
    int n1, n2, n3, n4, n5, n6, n7, n8, /* n9, n10, n11, n12, n13, n14, */ nT;

    do
    {
        cardNumber = get_long_long("Number: ");
    }
    while (cardNumber < 0);

    printf("AMEX\n");

    if ((cardNumber / 100000000000000) < 1)
    {
        printf("INVALID\n");
    }
    else
    {
        n1 = ((cardNumber / 10) % 10) * 2;
        printf("n1, %i\n", n1);
        n2 = ((cardNumber / 1000) % 10) * 2;
        printf("n2, %i\n", n2);
        n3 = ((cardNumber / 100000) % 10) * 2;
        printf("n3, %i\n", n3);
        n4 = ((cardNumber / 10000000) % 10) * 2;
        printf("n4, %i\n", n4);
        n5 = ((cardNumber / 1000000000) % 10) * 2;
        printf("n5, %i\n", n5);
        n6 = ((cardNumber / 100000000000) % 10) * 2;
        printf("n6, %i\n", n6);
        n7 = ((cardNumber / 10000000000000) % 10) * 2;
        printf("n7, %i\n", n7);

        if (n1 > 9) { n1 = (n1 / 10) + (n1 % 10); }
        if (n2 > 9) { n2 = (n2 / 10) + (n2 % 10); }
        if (n3 > 9) { n3 = (n3 / 10) + (n3 % 10); }
        if (n4 > 9) { n4 = (n4 / 10) + (n4 % 10); }
        if (n5 > 9) { n5 = (n5 / 10) + (n5 % 10); }
        if (n6 > 9) { n6 = (n6 / 10) + (n6 % 10); }
        if (n7 > 9) { n7 = (n7 / 10) + (n7 % 10); }

        nT = n1 + n2 + n3 + n4 + n5 + n6 + n7;

        printf("nT, %i\n", nT);

            //test 378282246310005

        n1 = ((cardNumber / 1) % 10);
        printf("n1, %i\n", n1);
        n2 = ((cardNumber / 100) % 10);
        printf("n2, %i\n", n2);
        n3 = ((cardNumber / 10000) % 10);
        printf("n3, %i\n", n3);
        n4 = ((cardNumber / 1000000) % 10);
        printf("n4, %i\n", n4);
        n5 = ((cardNumber / 100000000) % 10);
        printf("n5, %i\n", n5);
        n6 = ((cardNumber / 10000000000) % 10);
        printf("n6, %i\n", n6);
        n7 = ((cardNumber / 1000000000000) % 10);
        printf("n7, %i\n", n7);
        n8 = ((cardNumber / 100000000000000) % 10);
        printf("n8, %i\n", n8);

        nT = nT + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;

        printf("nT, %i\n", nT);

        if ((nT % 10) != 0)
        {
            printf("INVALID\n");
        }
        else if (cardNumber >= 340000000000000 || cardNumber >= 370000000000000)
        {
            printf("AMEX\n");
        }
        else if (cardNumber >= 510000000000000 && cardNumber < 560000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if (cardNumber >= 400000000000000 && cardNumber < 500000000000000)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
