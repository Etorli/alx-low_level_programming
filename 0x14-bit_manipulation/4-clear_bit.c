#include "main.h"

/**
 * clear_bit - this sets the value of given bit to 10
 * @n:the pointer to number to change
 * @index: the index of bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
