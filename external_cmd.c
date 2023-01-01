#include "main.h"
/**
* perform_external_cmd - executes external commands
* @info: structure contains command
* @envp: array of environment strings
*
* Return: description
*/
int perform_external_cmd(info_t *info, const char **envp)
{
	pid_t child_pid;
	char *cmd;

	child_pid = fork();
/*===============child=process=============================*/
	if (child_pid == 0)
	{
		cmd = get_absolute_path(info, info->cmd_buf[0]);
		if (cmd == NULL)
		{
			cmd = find_cmd(info, info->cmd_buf[0]);
			if (cmd == NULL)
			{
				info->fname = info->argv[0];
				print_error(info, "command not found");
				exit(1);
			}
		}

		if (cmd != NULL && is_cmd(cmd))
		{
			execve(
				(const char *) cmd,
				(char *const*) info->cmd_buf,
				(char *const*) envp
			);
			exit(1); /*in-case*/
		}
	}
/*============================================================*/
	wait(NULL);
	return (0);
}

/**
* is_cmd - is it executable
* @path: path to file
*
* Return: yes
*/
int is_cmd(char *path)
{

	if (access(path, F_OK) != -1)
		if (access(path, X_OK) != -1)
			return (1);

	return (0);
}

/**
* find_cmd - searches PATH to match path
* @info: command-line count
* @path: command-line count
*
* Return: stuff
*/
char *find_cmd(info_t *info, char *path)
{
	char **path_array, *path_str, *cmd;
	int len, i;

	path_str = _getenv(info, "PATH");

	len = wordcount(path_str, ":");
	path_array = split_arg(path_str, ":");

	i = 0;
	while (i < len)
	{
		cmd = path_join(path_array[i], path);
		if (is_cmd(cmd))
			return (cmd);

		free(cmd);
		i++;
	}

	return (NULL);
}
