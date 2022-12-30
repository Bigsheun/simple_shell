#include "main.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}

	_eputchar(BUF_FLUSH);
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* eprint_number - prints an integer
* @n: number
*/
void eprint_number(int n)
{
	unsigned int m;

	if (n < 0)
	{
		_eputchar('-');
		m = -n;
	}
	else
		m = n;
	/*end-if*/

	if (m / 10 > 0)
		eprint_number(m / 10);
	/*end-if*/
	_eputchar(m % 10 + '0');
	_eputchar(BUF_FLUSH);
}

/**
* print_error - prints an error message
* @info: the parameter info struct
* @estr: string containing specified error
*/
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	_eputs(info->cmd_buf[0]);
	_eputs(": ");
	_eputs(estr);
}
