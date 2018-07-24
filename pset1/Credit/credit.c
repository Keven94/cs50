#include <stdio.h>
#include <cs50.h>

int main()
{
    long cardNumber;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, nT;

    //Check if valid positive number
    do
    {
        cardNumber = get_long_long("Number: ");
    }
    while (cardNumber < 0);

    //Multiply every other digit by 2, starting with the number’s second-to-last digit
    n1 = ((cardNumber / 10) % 10) * 2;
    n2 = ((cardNumber / 1000) % 10) * 2;
    n3 = ((cardNumber / 100000) % 10) * 2;
    n4 = ((cardNumber / 10000000) % 10) * 2;
    n5 = ((cardNumber / 1000000000) % 10) * 2;
    n6 = ((cardNumber / 100000000000) % 10) * 2;
    n7 = ((cardNumber / 10000000000000) % 10) * 2;
    n8 = ((cardNumber / 1000000000000000) % 10) * 2;

    //Get the products' digits of each number
    if (n1 > 9)
    {
        n1 = (n1 / 10) + (n1 % 10);
    }
    if (n2 > 9)
    {
        n2 = (n2 / 10) + (n2 % 10);
    }
    if (n3 > 9)
    {
        n3 = (n3 / 10) + (n3 % 10);
    }
    if (n4 > 9)
    {
        n4 = (n4 / 10) + (n4 % 10);
    }
    if (n5 > 9)
    {
        n5 = (n5 / 10) + (n5 % 10);
    }
    if (n6 > 9)
    {
        n6 = (n6 / 10) + (n6 % 10);
    }
    if (n7 > 9)
    {
        n7 = (n7 / 10) + (n7 % 10);
    }
    if (n8 > 9)
    {
        n8 = (n8 / 10) + (n8 % 10);
    }

    //Add those products' digits (i.e., not the products themselves) together:
    nT = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;

    //digits that weren’t multiplied by 2
    n1 = ((cardNumber / 1) % 10);
    n2 = ((cardNumber / 100) % 10);
    n3 = ((cardNumber / 10000) % 10);
    n4 = ((cardNumber / 1000000) % 10);
    n5 = ((cardNumber / 100000000) % 10);
    n6 = ((cardNumber / 10000000000) % 10);
    n7 = ((cardNumber / 1000000000000) % 10);
    n8 = ((cardNumber / 100000000000000) % 10);
    n9 = ((cardNumber / 10000000000000000) % 10);

    //Add that sum to the sum of the digits that weren’t multiplied by 2
    nT = nT + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9;

    //total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid
    if ((nT % 10) != 0)
    {
        printf("INVALID\n");
    }

    //American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9)
    else if ((cardNumber >= 340000000000000 && cardNumber < 350000000000000) || (cardNumber >= 370000000000000
             && cardNumber <= 380000000000000))
    {
        printf("AMEX\n");
    }
    else if (cardNumber >= 5100000000000000 && cardNumber < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }
    else if ((cardNumber >= 4000000000000000 && cardNumber < 5000000000000000) || (cardNumber >= 4000000000000
             && cardNumber < 5000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

/* 
Tests
:) credit.c exists.
:) credit.c compiles.
:) identifies 378282246310005 as AMEX
:) identifies 371449635398431 as AMEX
:) identifies 5555555555554444 as MASTERCARD
:) identifies 5105105105105100 as MASTERCARD
:) identifies 4111111111111111 as VISA
:) identifies 4012888888881881 as VISA
:) identifies 1234567890 as INVALID
:) identifies 369421438430814 as INVALID
:) identifies 4062901840 as INVALID
:) identifies 5673598276138003 as INVALID
:) identifies 4111111111111113 as INVALID
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""
*/
