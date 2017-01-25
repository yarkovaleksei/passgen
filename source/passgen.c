/* passgen.c */

#include "h/main.h"
#include "h/passgen.h"


char getChar(char *symbols)
{
	return symbols[rand () % strlen(symbols)];
}


char *getPassword(char *symbols, int length)
{
	int counter = 0;
	int isTyped = 0;
	char *result = malloc(length + 1);

	if(length < 1)
	{
		while(isTyped != 1)
		{
			printf("%s\n", _("Type in a password length"));
			isTyped = scanf("%d", &length);
		}
	}

	while(counter < length)
	{
		result[counter] = getChar(symbols);
		counter++;
	}

	strcat(result, "\0");
	return result;
}


const struct passgen PassGen = {
	.getPassword = getPassword,
	.getChar = getChar
};
