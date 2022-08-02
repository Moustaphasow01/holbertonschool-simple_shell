#include "simple_shell.h"

/**
 * _strcpy - copy a string to destiny
 *
 * @dest: destiny to copy
 * @src: source string
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
	return (dest);
}


/**
 * _strlen - calculates the length of a string
 *
 * @str: string
 * Return: length of the string
 */

int _strlen(char *s)
{
int i;

i = 0;

while (s[i] != '\0')
{
i++;
}

return (i);
}
