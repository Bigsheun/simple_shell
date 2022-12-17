#include "outputs.h"
#include "string_utils.h"
#include "inbuilt_cmd.h"
#include "simple_shell.h"

/**
* main - c-program entry point
* @argc: command-line count
* @argv: array of command-line strings
* @envp: array of environment strings
*
* Return: 0 success
*/
int main(int argc, char **argv,	char **envp)
{
	char *input = NULL, *cmd;
	size_t n = 0, count;

	/*find something to do with argc and argv*/
	if (argc > 1)
		do_nothing(argv[1]);

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

/**
* do_nothing - does nothing to string
* @s: string
*
* Description: I use this function 
* so I will not have to use __attribute__((unused))
* on argc and argv 
* makes program harder to read
* program will not compile if some arguments are not used
*/
void do_nothing(char *s)
{
	s[0] = s[0] + '\0';
}