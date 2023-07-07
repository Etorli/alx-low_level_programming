#include "main.h"
/**
 * _strncat - concatenates two strings
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int j;
	int i;

	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0;
	while (i < n && src[i] != '\0')
	{
	dest[j] = src[i];
	j++;
	i++;
	}
	dest[j] = '\0';
	return (dest);
}

