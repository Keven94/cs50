#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int c;
    //ALPHABETICAL INDEX
    string alphaU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphaL = "abcdefghijklmnopqrstuvwxyz";

    //If program is executed without any command-line arguments or
    //with more than one command-line argument, program should print an error message
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    //convert that string to an actual int
    int k = atoi(argv[1]);

    //prompt the user for a string of plaintext
    printf("plaintext:  ");
    string p = get_string("");


    printf("ciphertext: ");

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        //Check if character in the string is a letter
        if (isalpha(p[i]))
        {
            //Check if Upercase letter
            if (isupper(p[i]))
            {
                //tranform ASCII into ALPHABETICAL index & print
                c = ((p[i] - 65) + k) % 26;
                printf("%c", alphaU[c]);
            }

            //CHeck if lowercase letter
            if (islower(p[i]))
            {
                //tranform ASCII into ALPHABETICAL index & print
                c = ((p[i] - 97) + k) % 26;
                printf("%c", alphaL[c]);
            }
        }

        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
