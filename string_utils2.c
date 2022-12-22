/**
* _strlen - a function that works like strlen
* @s: string
*
* Return: length of string
*/
int _strlen(char *s)
{
	int len = 0;

	while ('\0' != *(s++))
		len++;
	return (len);
}


/**
* _strcpy - works like strcpy
* @dest: destination
* @src: source
*
* Return: dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
* _strcat - catenate string
* @dest: destination
* @src: source
*
* Return: dest
*/

char *_strcat(char *dest, char *src)
{
	int i, end;

	end = 0;
	while (dest[end] != '\0')
		++end;
	i = 0;
	while (src[i] != '\0')
	{
		dest[end + i] = src[i];
		++i;
	}
	dest[end + i] = '\0';

	return (dest);
}

