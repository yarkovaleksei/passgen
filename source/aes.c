/**
 * Compile: gcc -lmcrypt aes.c -o aes
 */
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mcrypt.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>


char* pad_str(char *text)
{
	int size = strlen(text);
	int x = size % 16;
	int padlength = 16 - x;
	int newLength = size + padlength;

	char *newText;
	newText = malloc(newLength);

	strncpy(newText, text, newLength);

	for(int x = size; x < newLength; x++)
	{
		newText[x] = ' ';
	}

	return newText;
}

int test()
{
	char * plaintext = "test"; // Needs to be padded to 16

	plaintext = pad_str(plaintext);

	char* IV = "0123456789abcdef"; // Needs to be 16

	char *key = "fedcba9876543210"; // Needs to be padded to 16
	int keysize = 16; // 128 bits
	char* buffer;
	int buffer_len = 16;

	buffer = calloc(1, buffer_len);
	strncpy(buffer, plaintext, buffer_len);

	MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
	int blocksize = mcrypt_enc_get_block_size(td);

	if( buffer_len % blocksize != 0 )
	{
		return 1;
	}

	mcrypt_generic_init(td, key, keysize, IV);
	mcrypt_generic(td, buffer, buffer_len);  // Also mdecrypt_generic.
	mcrypt_generic_deinit (td);
	mcrypt_module_close(td);

	unsigned char display;

	printf("HEX Encrypted:");
	for (int x=0; x<buffer_len; x++)
	{
		display = buffer[x];
		printf("%02X", display);
	}
	printf("\n");

	return 0;
}
*/
