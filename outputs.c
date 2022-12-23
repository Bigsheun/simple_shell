#include <unistd.h>
/**
* write_stringz - outputs a null terminated string
* @s: string to output
*
*/
void write_stringz(char *s)
{
	while (s[0] != '\0')
		write(1, s++, 1);
}

/**
* write_strz_array - prints a null terminated arra
* of null terminated strings
* @sa: String of array
*/
void write_strz_array(char **sa)
{
	int i;

	for (i = 0 ; sa[i] != NULL; i++)
	{
		write_stringz(sa[i]);
		write_stringz("\n");
	}
}
/**
* s_array_len - gets length of null terminate string array
* @arr: array
*
* Return: length
*/
unsigned int s_array_len(char **arr)
{
	unsigned int count = 0, i = 0;

	while (arr[i++] != NULL)
		count++;

	return (count);
}
