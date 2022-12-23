#include "main.h"

/**
* _myexit - exits the shell
* @info: compulsory info table for all commands
*
* Return: never returns, but the functions must conform
*/
int _myexit(info_t *info)
{
	exit(0);
	return (0);
}

/**
* _myenv - prints list of environment variables
* @info: structure contains environment
*
* Return: zero = success for now
*/
int _myenv(info_t *info)
{
	print_list(info->env);
	return (0);
}

/**
* _mycd - changes current working directory
* @info: command information structure
*
* Return: zero for success for now
*/
int _mycd(info_t *info)
{
	return (0);
}

/**
* _mypwd - display current working directory
* @info: command structure contains the env where PWD is recorded
*
* Return: zero = success for now
*/
int _mypwd(info_t *info)
{
	return (0);
}
