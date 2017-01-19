/* passgen.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_password(int length, char *symbols)
{
    srandom(time(NULL));
    int counter = 0;
    char* result;
    char* default_symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char randChar;

    if(length < 1) {
        printf("Type in a password Length \n");
        scanf("%d", &length);
    }

    while(counter < length)
    {
        randChar = symbols[random () % strlen(symbols)];
        //printf("%c", randChar);
        result[counter] = randChar;
        counter++;
    }
    //printf("\n"); // Stops the output from being on the same line as the prompt
    return result;
}