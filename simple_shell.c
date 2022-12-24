#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
* main - c-program entry point
* @argc: command-line count
* @argv: array of command-line strings
* @envp: array of environment strings
*
* Return: 0 success
*/
int main(int argc, char **argv, char **envp)
{
	char *input = NULL, *cmd, **cmd_buffer;
	size_t n = 0, count;
	info_t info = INFO_INIT;

	info.argc = argc;
	info.argv = argv;
	populate_env(&info, envp);

	count = get_line(&input, &n, stdin);
	while ((int)count != -1)
	{
		cmd_buffer = split_arg(input, " \t");
		cmd = cmd_buffer[0];
		if (cmd == NULL)
		{
			count = get_line(&input, &n, stdin);
			continue;
		}
		info.arg = cmd;
		info.cmd_buf = cmd_buffer;

		if (is_inbuilt(cmd))
			perform_inbuilt_cmd(&info);
		else
			perform_external_cmd(&info, (const char **) envp);
		/*end-if*/
		write_stringz("\n");

		count = get_line(&input, &n, stdin);
	}
}

/**
* get_line - safely gets a clean command string from getline
* @lineptr: destination of string
* @count: size of string to get (if not 0)
* @fd: stream to read from
*
* Return: size of string inputed
*/
size_t get_line(char **lineptr, size_t *count, FILE *fd)
{

	if (lineptr[0] != NULL)
	{
		free(lineptr[0]);
		lineptr[0] = NULL;
	}
	count[0] = 0;

	show_prompt();
	getline(lineptr, count, fd);
	str_replace(lineptr[0], '\n', ' ');


	return (count[0]);
}

/**
* show_prompt - display prompt in interactive mode
*
*/
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write_stringz("$ ");
}
