#include "main.h"

/**
 * wordcount - fct that count the number of word from user's input
 *
 * @str: input's string
 *
 * Return: Number of words
 */
size_t wordcount(char *str)
{
	size_t i = 0, words = 0;
	int flag = OUT;

	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			if (str[i] == '\n')
				str[i] = '\0';
			flag = OUT;
		}
		else if (flag == OUT)
		{
			flag = IN;
			words++;
		}
		i++;
	}
	return (words);
}