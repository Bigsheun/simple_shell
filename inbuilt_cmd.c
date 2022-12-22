#include "main.h"
#include <stdlib.h>
/**
* is_inbuilt - checks if argument is in list of
* @cmd: string argument
*
* Return: true/false
*/
short is_inbuilt(char *cmd)
{
	builtin_table *cmd_list;
	int i = 0;

	cmd_list = get_builtin_cmd_tbl();
	while (cmd_list[i].type != NULL)
	{
		if (!_strcmp(cmd_list[i].type, cmd))
			return (1);
		i++;
	}

	return (0);
}

/**
* perform_inbuilt_cmd - calls the appropriate function
* for inbuilt commands
* @cmd: command
* @cmd_line: command string
* @envp: array of command-line strings
* 
* Return: return status
*/
int  perform_inbuilt_cmd(info_t *info)
{
	builtin_table *b_table = get_builtin_cmd_tbl();
	int i = 0;

	while (b_table[i].type != NULL)
	{
		if (!_strcmp(b_table[i].type, info->arg))
			return (b_table[i].func(info));
		i++;
	}

	return (1);
}
/**
* get_builtin_cmd_tbl - Provides table of inbuilt commands
* Prevents inconsistencies. Keeps the code dry
*

* Return: array of builtin_table (records)
*/
builtin_table *get_builtin_cmd_tbl()
{
	static	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"pwd", _mypwd},
		{"cd", _mycd},
		{"setenv", _mysetenv},
		{"getenv", _mygetenv},
		{NULL, NULL}
	};

	return (builtintbl);
}