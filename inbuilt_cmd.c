#include "inbuilt_cmd.h"
#include "string_utils.h"
#include "outputs.h"
#include <stdlib.h>
/**
* is_inbuilt - checks if argument is in list of
* @cmd: string argument
*
* Return: true/false
*/
short is_inbuilt(char *cmd)
{
	char *cmd_list[] = {"env", "ls", "exit", "pwd", NULL};
	int i = 0;

	while (cmd_list[i] != NULL)
	{
		if (!_strcmp(cmd_list[i], cmd))
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
*/
void perform_inbuilt_cmd(
	char *cmd,
	char *cmd_line __attribute__((unused)),
	char **envp
)
{
	if (!_strcmp(cmd, "env"))
		write_strz_array(envp);
	else if (!_strcmp(cmd, "exit"))
		exit(0);
	else
		write_stringz("other inbuilt commands pending");
	/*end-if*/
}
