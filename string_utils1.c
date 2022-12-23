#include "main.h"
/**
* _strcmp - compare
* @s1: first
* @s2: second
*
* Return: difference
*/
int _strcmp(char *s1, char *s2)
{
	int i, ret;

	i = 0;
	while ((ret = s1[i] - s2[i]) == 0 && s1[i] != '\0' && s2[i] != '\0')
		++i;

	return (ret);
}

/**
* str_replace - replace occurrence of a given character with another
* @s: String to search
* @find: character to find
* @repl: character to replace with
*
*/
void str_replace(char *s, char find, char repl)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			s[i] = repl;
		++i;
	}

}

/**
 * starts_with - checks if haystack starts with needle
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
int starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (0);
	return (1);
}

/**
 * str_dup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *str_dup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;

	return (ret);
}
