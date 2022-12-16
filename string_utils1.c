
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
