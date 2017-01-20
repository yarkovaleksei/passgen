/* passgen.c */

#include "h/passgen.h"

char getChar(char *symbols)
{
	return symbols[random () % strlen(symbols)];
}

char *genpass(char *symbols, int length)
{
	srandom(time(NULL));
	int counter = 0;
	char *result = malloc(length + 1);

	if(length < 1) {
		printf("Type in a password Length \n");
		scanf("%d", &length);
	}

	while(counter < length)
	{
		result[counter] = getChar(symbols);
		counter++;
	}

	return result;
}
