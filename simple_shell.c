#include <stdio.h>
#include "outputs.h"
#include "string_utils.h"
#include "inbuilt_cmd.h"
#include "simple_shell.h"

/**
* main - c-program entry point
* @argc: command-line count
* @argv: array of command-line strings
* @envp: array of enviironment strings
*
* Return: 0 success
*/
int main(int argc, char **argv,	char **envp)
{
	char *input = NULL, *cmd;
	size_t n = 0, count;

	if (argc > 1)
	{
		write_stringz(argv[1]);
		write_stringz("parameters are not accepted \n");
	}

	write_stringz("$ ");
	count = getline(&input, &n, stdin);
	while (input[0] != '\n' && (int)count != -1)
	{
		str_replace(input, '\n', ' ');
		cmd = strtok(input, " ");

		if (is_inbuilt(cmd))
			perform_inbuilt_cmd(cmd, input, envp);
		else
			write_stringz("external commands not yet implemented");
		/*end-if*/
		write_stringz("\n");

		write_stringz("$ ");
		count = getline(&input, &n, stdin);
	}

	return (0);
}
