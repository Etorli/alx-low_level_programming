#include "main.h"

/**
 * get_endianness - checks for a little or big endian machine
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
