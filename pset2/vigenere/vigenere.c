#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //ALPHABETICAL INDEX
    string alphaU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphaL = "abcdefghijklmnopqrstuvwxyz";

    //declaration of variables
    int c, i, j;

    //If program is executed without any command-line arguments or
    //with more than one command-line argument, program should print an error message
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //convert argv into a string
    string key = argv[1];

    //make sure the key is all letters
    for (i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    //prompt the user for a string of plaintext
    printf("plaintext:  ");
    string p = get_string("");

    //Output the ciphertext.
    printf("ciphertext: ");

    //for loop to wrap around the key and change each letter of the plaintext at the same time
    for (i = 0, j = 0; i < strlen(p); i++)
    {
        //if position 'j' is equal to the lenght of the key, restart the count (position)
        if (j == strlen(key))
        {
            j = 0;
        }

        //Check if character in the plaintext string is a letter
        if (isalpha(p[i]))
        {
            //Check if Upercase letter
            if (isupper(p[i]))
            {
                //Make matching key character into an upercase letter in case of lower to do the right math
                if (islower(key[j]))
                {
                    key[j] = toupper(key[j]);
                }

                //tranform ASCII into ALPHABETICAL index & print (http://www.asciichart.com/)
                c = ((p[i] + key[j]) - (65 * 2)) % 26;
                printf("%c", alphaU[c]);
            }

            //Check if lowercase letter
            if (islower(p[i]))
            {
                //Make matching key character into an lower case letter in case of uper to do the right math
                if (isupper(key[j]))
                {
                    key[j] = tolower(key[j]);
                }

                //tranform ASCII into ALPHABETICAL index & print (http://www.asciichart.com/)
                c = ((p[i] + key[j]) - (97 * 2)) % 26;
                printf("%c", alphaL[c]);
            }

            //go to the next character in the key
            j++;
        }

        //if no character detected in the plainthext, keep it the same.
        else
        {
            printf("%c", p[i]);
        }
    }

    //print new line after ciphertext
    printf("\n");
}
