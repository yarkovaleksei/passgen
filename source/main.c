/* main.c */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "h/passgen.h"

int main (int argc, char const *argv[])
{
    int i;
    int length = 25;
    char *password;

    if(argc <= 1) {
        printf("Usage: \npassgen -h[--help]\n");
        return 0;
    }

    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        printf("You requested help message.\n");
        return 0;
    }
    else if(!strcmp(argv[1], "-l") || !strcmp(argv[1], "--length")) {
        if(argc > 1) {
            sscanf(argv[2],"%d",&length);
        }
    }

	password = generate_password(length, "ABCDEF0123456789");

    printf("%s\n", password);

    return 0;
}
