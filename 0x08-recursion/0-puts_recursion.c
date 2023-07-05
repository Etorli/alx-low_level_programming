#include "main.h"
/**
 * _puts_recursion - function like();
 *@s: input
 *Return: Always 0 (Success)
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_puchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_puchar ('\n');


}
