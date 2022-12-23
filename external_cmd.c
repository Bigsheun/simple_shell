#include "main.h"
/**
* perform_external_cmd - executes external commands
* @info: structure contains command
* @envp: array of environment strings
*
* Return: description
*/
int perform_external_cmd(info_t *info, char **envp)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		exit(1);
	}
	if (child_pid == 0)
	{
		execve(
			get_absolute_path(info, info->cmd_buf[0]),
			info->cmd_buf, envp
		);

		/* TODO: PUT ERROR FUNCTION */
	}

	return (0);
}
