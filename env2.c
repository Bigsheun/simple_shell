#include "main.h"

/**
* extract_name - extract name portion of environment string
* @env_str: environment string
*
* Description: no use for it as yet
* Return: extracted name
*/
char *extract_name(char *env_str)
{
	int i = 0, len;
	char *ret;

	while (env_str[i] && env_str[i] != '=')
		i++;
	ret = malloc(sizeof(char) * (i + 1));

	len = i;
	i = 0;
	while (i < len)
		ret[i] = env_str[i];
	ret[len] = '\0';

	return (ret);
}

/**
* extract_value - extract value from environment string
* @env_str: environment string
*
* Return: extracted value
*/
char *extract_value(char *env_str)
{
	int i = 0, index;
	char *ret;

	while (env_str[i] && env_str[i] != '=')
		i++;

	index = (env_str[i]) ? i + 1 : i;
	ret = _strdup(&env_str[index]);

	return (ret);

}

/**
* _mysetenv - sets the environment copy
* @info: structure containts stuff
*
* Return: action code
*/
int _mysetenv(info_t *info)
{
	char **args;
	unsigned int len;

	args = info->cmd_buf;
	if ((len = s_array_len(args)) != 3)
	{
		_eputs("wrong argument count for 'setenv' ");
		eprint_number(len);
		return (1);
	}
		
	_setenv(info, args[1], args[2]);

	return (1);
}

/**
* _mygetenv - gets an item from environment copy
* @info: structure contains the environment list
*
* Return: action code
*/
int _mygetenv(info_t *info)
{
	char *value, **args;
	unsigned int len;

	args = info->cmd_buf;
	if ((len = s_array_len(args)) != 2)
	{
		_eputs("wrong argument count for 'getenv' ");
		eprint_number(len);
		return (1);
	}
	value = _getenv(info, args[1]);
	/*info->str_result = value;*/
	write_stringz(value);

	return (1);
}
