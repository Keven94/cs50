#include <stdio.h>
#include <cs50.h>

int main()
{
    long cardNumber;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, /* n10, n11, n12, n13, n14, */ nT;

    do
    {
        cardNumber = get_long_long("Number: ");
    }
    while (cardNumber < 0);

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
        n8 = ((cardNumber / 1000000000000000) % 10) * 2;
        printf("n7, %i\n", n8);

        if (n1 > 9) { n1 = (n1 / 10) + (n1 % 10); }
        if (n2 > 9) { n2 = (n2 / 10) + (n2 % 10); }
        if (n3 > 9) { n3 = (n3 / 10) + (n3 % 10); }
        if (n4 > 9) { n4 = (n4 / 10) + (n4 % 10); }
        if (n5 > 9) { n5 = (n5 / 10) + (n5 % 10); }
        if (n6 > 9) { n6 = (n6 / 10) + (n6 % 10); }
        if (n7 > 9) { n7 = (n7 / 10) + (n7 % 10); }
        if (n8 > 9) { n8 = (n8 / 10) + (n8 % 10); }

        nT = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;

        printf("nT, %i\n", nT);

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
        n9 = ((cardNumber / 10000000000000000) % 10);
        printf("n9, %i\n", n9);

        nT = nT + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9;

        printf("nT, %i\n", nT);
        printf("last digit in that sum: %i\n", nT % 10);

        if ((nT % 10) != 0)
        {
            printf("INVALID\n");
        }
        else if ((cardNumber >= 340000000000000 && cardNumber < 350000000000000) || (cardNumber >= 370000000000000 && cardNumber <= 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (cardNumber >= 5100000000000000 && cardNumber < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if (cardNumber >= 4000000000000000 && cardNumber < 5000000000000000)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

/*
:) credit.c exists.
:) credit.c compiles.
:) identifies 378282246310005 as AMEX
:) identifies 371449635398431 as AMEX
:( identifies 5555555555554444 as MASTERCARD
    expected "MASTERCARD\n", not "AMEX\n"
:( identifies 5105105105105100 as MASTERCARD
    expected "MASTERCARD\n", not "AMEX\n"
:( identifies 4111111111111111 as VISA
    expected "VISA\n", not "AMEX\n"
:( identifies 4012888888881881 as VISA
    expected "VISA\n", not "AMEX\n"
:) identifies 1234567890 as INVALID
:( identifies 369421438430814 as INVALID
    expected "INVALID\n", not "AMEX\n"
:) identifies 4062901840 as INVALID
:( identifies 5673598276138003 as INVALID
    expected "INVALID\n", not "AMEX\n"
:( identifies 4111111111111113 as INVALID
    expected "INVALID\n", not "AMEX\n"
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""
*/
